#include "mainwindow.h"
#include "carica.h"
#include "salva.h"
#include "autenticazione_dialog.h"
#include "file_mancanti.h"
#include "tab_widget_base.h"
#include "tab_widget_premium.h"
#include "tab_widget_amministratore.h"

#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QIcon>
#include <QAction>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>
#include <QCloseEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    //titolo, dimensioni, icona e posizionamento della mainWindow
       setWindowTitle("Client Overview");
       setWindowIcon(QIcon("./Hotel.png"));
       setMinimumSize(800,600);
       resize(1000,600);
       setGeometry(
           QStyle::alignedRect(
               Qt::LeftToRight,
               Qt::AlignCenter,
               size(),
               qApp->desktop()->availableGeometry()
           )
       );
       carica = new Carica();
       //Carico i dati dei clienti e quelli degli utenti
       //erroreCaricaUtenti=""; erroreCaricaClienti="";
       u = new Utenti(); c = new Clienti();
       //inserisci(*u,erroreCaricaUtenti); carica(*c,erroreCaricaClienti);
       carica->clienti(c);
       carica->utenti(u);
       //booleano, indica la presenza di modifiche ai contenitori non salvate su file
       DaSalvare= false;
       //menu Help
       about = new QMenu("Help");
       QAction* qtab = new QAction("About Qt",this);
       connect(qtab,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
       QAction* cambia = new QAction("Seleziona Utente",this);
       connect(cambia,SIGNAL(triggered()),this,SLOT(cambiaUtente()));
       about->addAction(cambia);
       about->addAction(qtab);
       menuBar()->addMenu(about);

       //menu modifica
       modifica = new QMenu("Modifica");
       aggiungicliente = new QAction("Aggiungi Cliente",this);
       aggiungiutente = new QAction("Aggiungi Utente",this);
       modifica->addAction(aggiungicliente);
       modifica->addAction(aggiungiutente);
       menuBar()->addMenu(modifica);
       aggiungicliente->setDisabled(true);
       aggiungiutente->setDisabled(true);

       //menu salva
       salvaAction = new QAction("Salva",this);
       salva = new QMenu("Salva");
       salva->addAction(salvaAction);
       menuBar()->addMenu(salva);
       salvaAction->setDisabled(true);
       connect(salvaAction,SIGNAL(triggered()),this,SLOT(salvaTutto()));
       //costruisco un widget temporaneo che sarà il padre dei tre tipi di widget principali della gui
       //in questo modo posso decidere che contenuto mostrare in base al tipo di utende autenticato
       w = new QWidget();

       //testo principale della gui al momento dell'avvio
       QLabel* seleziona = new QLabel("Vai in \" Help \" --> \" Seleziona utente \" per iniziare");
       seleziona->setAlignment(Qt::AlignCenter);
       setCentralWidget(seleziona);


}
void MainWindow::draw_admin() {
    //elimino il QWidget di costruzione oppure quello di una precedente autenticazione in modo
    //da poter cambiare utenza senza dover riavviare il programma
    delete w;
    w = new QWidget(this);
    setCentralWidget(w);
    //imposto un layout al QWidget e costruisco un widget specifico per l'utente amministratore
    QVBoxLayout* lay = new QVBoxLayout();
    w->setLayout(lay);
    TabWidgetAmministratore* amm = new TabWidgetAmministratore(u,c);
    lay->addWidget(amm);
    //amm è figlio di w, cosicché quando invoco la delete su w vengano eliminati anche tutti i sui figli (amm e discendenti)
    //aggiunta di nuovo cliente / utente
    connect(aggiungicliente,SIGNAL(triggered()),amm,SLOT(aggiungiCliente()));
    connect(aggiungiutente,SIGNAL(triggered()),amm,SLOT(aggiungiUtente()));
    connect(amm,SIGNAL(daSalvare()),this,SLOT(impostaDaSalvare()));
    //abilitazione delle funzionalità di aggiunta e salvataggio
    aggiungicliente->setDisabled(false);
    aggiungiutente->setDisabled(false);
    salvaAction->setDisabled(false);
}

void MainWindow::draw_premium() {
    //vedi draw_admin
    delete w;
    w = new QWidget(this);
    setCentralWidget(w);

    QVBoxLayout* lay = new QVBoxLayout();
    TabWidgetPremium* prem = new TabWidgetPremium(c);
    lay->addWidget(prem);
    w->setLayout(lay);
    //disabilito le funzionalità di aggiunta cliente/utente e salvataggio
    aggiungicliente->setDisabled(true);
    aggiungiutente->setDisabled(true);
    salvaAction->setDisabled(true);
}

void MainWindow::draw_base() {
    //vedi draw_admin
    delete w;
    w = new QWidget(this);
    setCentralWidget(w);

    QVBoxLayout* lay = new QVBoxLayout();
    TabWidgetBase* base = new TabWidgetBase(c);
    lay->addWidget(base);
    w->setLayout(lay);
    //disabilito le funzionalità di aggiunta cliente/utente e salvataggio
    aggiungicliente->setDisabled(true);
    aggiungiutente->setDisabled(true);
    salvaAction->setDisabled(true);
}

void MainWindow::cambiaUtente(){
    //se gli utenti o i clienti non sono stati caricati correttamente faccio un altro tentativo,
    //se non ho successo apro una finestra di dialogo che da alcune info all'utente
    //altrimenti apro la finestra di dialogo per l'autenticazione del nuovo utente
    if(!carica->clienti()) carica->clienti(c);
    if(!carica->utenti()) carica->utenti(u);
    if(carica->utenti() && carica->clienti()){
        AutenticazioneDialog* nuovoUtente = new AutenticazioneDialog(this,u);
        connect(nuovoUtente,SIGNAL(amministratoreOk()),this,SLOT(draw_admin()));
        connect(nuovoUtente,SIGNAL(baseOk()),this,SLOT(draw_base()));
        connect(nuovoUtente,SIGNAL(premiumOk()),this,SLOT(draw_premium()));
        nuovoUtente->show();
    }
    else{
        FileMancanti* m = new FileMancanti(this);
        m->show();
    }
}
void MainWindow::salvaTutto(){
    sal->clienti(c);
    sal->utenti(u);
    DaSalvare = false;
}
void MainWindow::impostaDaSalvare(){
    DaSalvare = true;
}
//avvisa l'utente che si sta cercando di chiudere il programma quando alcune modifiche non sono
//salvare permanentemente su file
void MainWindow::closeEvent(QCloseEvent* event){
    if(DaSalvare){
        event->ignore();
        if(QMessageBox::Yes == QMessageBox:: question(this, "Salvataggio dati", "Le modifiche non sono state salvate permanentemente.\nDesideri uscire comunque?", QMessageBox::Yes | QMessageBox::No))
            event->accept();
    }
}
// c, u, carica e sal sono puntatori ad oggetti allocati sullo heap, quindi devo preoccuparmi di deallocarli all'uscita per non lasciare garbage.
MainWindow::~MainWindow(){
    delete c;
    delete u;
    delete carica;
    delete sal;
}

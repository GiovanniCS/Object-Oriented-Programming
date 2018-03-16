#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class QMenu;
class QMenuBar;
class Clienti;
class Utenti;
class Carica;
class Salva;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    bool DaSalvare;
    Carica* carica;
    Salva* sal;
    Clienti* c; Utenti* u;
    QWidget* w;
    QMenu* about;
    QMenu* modifica;
    QMenu* salva;
    QAction* salvaAction;
    QAction* aggiungicliente;
    QAction* aggiungiutente;
    //std::string erroreCaricaUtenti, erroreCaricaClienti;
public slots:
    void impostaDaSalvare();
    void draw_admin();
    void draw_premium();
    void draw_base();
    void salvaTutto();
    void cambiaUtente();
protected:
    void closeEvent(QCloseEvent*);
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

 void handleButton0();
 void handleButton1();
 void handleButton2();
 void handleButton3();
 void handleButton4();
 void handleButton5();
 void handleButton6();
 void handleButton7();
 void handleButton8();
 void handleButton9();
 void handleButtonA();
 void handleButtonB();
 void handleButtonC();
 void handleButtonD();
 void handleButtonAst();
 void handleButtonNum();

 void play(QString number);
 void tone(QByteArray *bytebuf);

 private:

 QPushButton* m_pButton0;
 QPushButton* m_pButton1;
 QPushButton* m_pButton2;
 QPushButton* m_pButton3;
 QPushButton* m_pButton4;
 QPushButton* m_pButton5;
 QPushButton* m_pButton6;
 QPushButton* m_pButton7;
 QPushButton* m_pButton8;
 QPushButton* m_pButton9;
 QPushButton* m_pButtonA;
 QPushButton* m_pButtonB;
 QPushButton* m_pButtonC;
 QPushButton* m_pButtonD;
 QPushButton* m_pButtonAst;
 QPushButton* m_pButtonNum;
};

#endif // MAINWINDOW_H

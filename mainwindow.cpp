#include "mainwindow.h"

#include <QCoreApplication>

#include <QBuffer>
#include <QAudioOutput>
#include <QByteArray>
#include <QtMath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Create the buttons
    m_pButton0 = new QPushButton("0", this);
    m_pButton1 = new QPushButton("1", this);
    m_pButton2 = new QPushButton("2", this);
    m_pButton3 = new QPushButton("3", this);
    m_pButton4 = new QPushButton("4", this);
    m_pButton5 = new QPushButton("5", this);
    m_pButton6 = new QPushButton("6", this);
    m_pButton7 = new QPushButton("7", this);
    m_pButton8 = new QPushButton("8", this);
    m_pButton9 = new QPushButton("9", this);
    m_pButtonA = new QPushButton("A", this);
    m_pButtonB = new QPushButton("B", this);
    m_pButtonC = new QPushButton("C", this);
    m_pButtonD = new QPushButton("D", this);
    m_pButtonAst = new QPushButton("*", this);
    m_pButtonNum = new QPushButton("#", this);

    //set size and location of the button
    m_pButton1->setGeometry(QRect( QPoint(100, 100), QSize(50, 50) ));
    m_pButton2->setGeometry(QRect( QPoint(150, 100), QSize(50, 50) ));
    m_pButton3->setGeometry(QRect( QPoint(200, 100), QSize(50, 50) ));
    m_pButtonA->setGeometry(QRect( QPoint(250, 100), QSize(50, 50) ));
    m_pButton4->setGeometry(QRect( QPoint(100, 150), QSize(50, 50) ));
    m_pButton5->setGeometry(QRect( QPoint(150, 150), QSize(50, 50) ));
    m_pButton6->setGeometry(QRect( QPoint(200, 150), QSize(50, 50) ));
    m_pButtonB->setGeometry(QRect( QPoint(250, 150), QSize(50, 50) ));
    m_pButton7->setGeometry(QRect( QPoint(100, 200), QSize(50, 50) ));
    m_pButton8->setGeometry(QRect( QPoint(150, 200), QSize(50, 50) ));
    m_pButton9->setGeometry(QRect( QPoint(200, 200), QSize(50, 50) ));
    m_pButtonC->setGeometry(QRect( QPoint(250, 200), QSize(50, 50) ));
    m_pButtonAst->setGeometry(QRect( QPoint(100, 250), QSize(50, 50) ));
    m_pButton0->setGeometry(QRect( QPoint(150, 250), QSize(50, 50) ));
    m_pButtonNum->setGeometry(QRect( QPoint(200, 250), QSize(50, 50) ));
    m_pButtonD->setGeometry(QRect( QPoint(250, 250), QSize(50, 50) ));

    //Connect buttons signal to appropriate slot
    connect(m_pButton0, SIGNAL (released()),this, SLOT (handleButton0()));
    connect(m_pButton1, SIGNAL (released()),this, SLOT (handleButton1()));
    connect(m_pButton2, SIGNAL (released()),this, SLOT (handleButton2()));
    connect(m_pButton3, SIGNAL (released()),this, SLOT (handleButton3()));
    connect(m_pButton4, SIGNAL (released()),this, SLOT (handleButton4()));
    connect(m_pButton5, SIGNAL (released()),this, SLOT (handleButton5()));
    connect(m_pButton6, SIGNAL (released()),this, SLOT (handleButton6()));
    connect(m_pButton7, SIGNAL (released()),this, SLOT (handleButton7()));
    connect(m_pButton8, SIGNAL (released()),this, SLOT (handleButton8()));
    connect(m_pButton9, SIGNAL (released()),this, SLOT (handleButton9()));
    connect(m_pButtonA, SIGNAL (released()),this, SLOT (handleButtonA()));
    connect(m_pButtonB, SIGNAL (released()),this, SLOT (handleButtonB()));
    connect(m_pButtonC, SIGNAL (released()),this, SLOT (handleButtonC()));
    connect(m_pButtonD, SIGNAL (released()),this, SLOT (handleButtonD()));
    connect(m_pButtonAst, SIGNAL (released()),this, SLOT (handleButtonAst()));
    connect(m_pButtonNum, SIGNAL (released()),this, SLOT (handleButtonNum()));
}


void MainWindow::handleButton0()
 {
     play("0");

 }

void MainWindow::handleButton1()
 {
     play("1");

 }

void MainWindow::handleButton2()
 {
     play("2");

 }

void MainWindow::handleButton3()
 {
     play("3");

 }

void MainWindow::handleButton4()
 {
     play("4");

 }

void MainWindow::handleButton5()
 {
     play("5");

 }

void MainWindow::handleButton6()
 {
     play("6");

 }

void MainWindow::handleButton7()
 {
     play("7");

 }

void MainWindow::handleButton8()
 {
     play("8");

 }

void MainWindow::handleButton9()
 {
     play("9");

 }

void MainWindow::handleButtonA()
 {
     play("A");

 }

void MainWindow::handleButtonB()
 {
     play("B");

 }

void MainWindow::handleButtonC()
 {
     play("C");

 }

void MainWindow::handleButtonD()
 {
     play("D");

 }

void MainWindow::handleButtonAst()
 {
     play("*");

 }

void MainWindow::handleButtonNum()
 {
     play("#");

 }

void MainWindow::play(QString number){
    constexpr double SAMPLE_RATE = 44100;

    // Set parameters for the output sound
    double duration = 0.2;
    double amplitude = 0.8;
    double frequency1 = 0;
    double frequency2 = 0;
    double f1 = 0;
    double f2 = 0;
    double sample = 0;

    if(QString::compare("1",number)==0 || QString::compare("4",number)==0 || QString::compare("7",number)==0 || QString::compare("*",number)==0){
        frequency1 = 1209;
    }
    else if(QString::compare("2",number)==0 || QString::compare("5",number)==0 || QString::compare("8",number)==0 || QString::compare("0",number)==0){
        frequency1 = 1336;
    }
    else if(QString::compare("3",number)==0 || QString::compare("6",number)==0 || QString::compare("9",number)==0 || QString::compare("#",number)==0){
        frequency1 = 1477;
    }
    else if(QString::compare("A",number)==0 || QString::compare("B",number)==0 || QString::compare("C",number)==0 || QString::compare("D",number)==0){
        frequency1 = 1633;
    }

    //Set frequency 2
    if(QString::compare("1",number)==0 || QString::compare("2",number)==0 || QString::compare("3",number)==0 || QString::compare("A",number)==0){
        frequency2 = 697;
    }
    else if(QString::compare("4",number)==0 || QString::compare("5",number)==0 || QString::compare("6",number)==0 || QString::compare("B",number)==0){
        frequency2 = 770;
    }
    else if(QString::compare("7",number)==0 || QString::compare("8",number)==0 || QString::compare("9",number)==0 || QString::compare("C",number)==0){
        frequency2 = 852;
    }
    else if(QString::compare("*",number)==0 || QString::compare("0",number)==0 || QString::compare("#",number)==0 || QString::compare("D",number)==0){
        frequency2 = 941;
    }


    f1 = frequency1 / SAMPLE_RATE;
    f2 = frequency2 / SAMPLE_RATE;
    sample = 0;

    QByteArray *bytebuf = new QByteArray();
    bytebuf->resize(duration * SAMPLE_RATE);

    // Generate the required samples
    for (double t = 0; t < duration*SAMPLE_RATE; t += 1){

        sample = amplitude * sin(2*M_PI*f1*t) + amplitude * sin(2*M_PI*f2*t);

        //Save sample in file
        bytebuf->insert(t,(quint8)sample);

    }

    tone(bytebuf);

}

void MainWindow::tone(QByteArray *bytebuf){
    // Make a QBuffer from our QByteArray
    QBuffer* input = new QBuffer(bytebuf);
    input->open(QIODevice::ReadOnly);

    QAudioFormat format;
    // Set up the format
    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format)) {
        qWarning()<<"Raw audio format not supported by backend, cannot play audio.";
    }

    QAudioOutput* audio = new QAudioOutput(format);
    audio->setBufferSize(16384);
    audio->start(input);

    QEventLoop loop;
       QObject::connect(audio, SIGNAL(stateChanged(QAudio::State)), &loop, SLOT(quit()));
       do{
           loop.exec();
       }while(audio->state() == QAudio::ActiveState);


}

MainWindow::~MainWindow()
{

}

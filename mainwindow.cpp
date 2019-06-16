/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2010  Pablo Alvarado
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file   mainwindow.cpp
 *         Implements the equalizer H(w) computation
 * \author Pablo Alvarado
 * \date   2010.12.12
 *
 * $Id: equalizer.cpp $
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jack.h"
#include <string>
#include "unistd.h"
#include <QDebug>


#undef _DSP_DEBUG
#define _DSP_DEBUG

#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif


/**
 * Precision used by trimming
 */
const float MainWindow::Epsilon = 0.001;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    verbose_(false),
    dspChanged_(true)

{
    ui->setupUi(this);

    /*
     * Set up a timer 4 times in a second to check if the user
     * changed the equalizer values, and if so, then create a new
     * filter response
     */
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_->start(250);

    dsp_ = new dspSystem;

    hanged = true;
    volume = 0;
    number = "";

    timer = new QTimer();
    connect( timer, SIGNAL( timeout() ), this, SLOT( onTimeout() ) );

    sound = new QSound("");




}


MainWindow::~MainWindow()
{
    jack::close();
    delete timer_;
    delete ui;
    delete dsp_;
}

void MainWindow::update() {
    if(dspChanged_){
        _debug("Updating" << std::endl);

        dspChanged_=false;
    }
    
}

void MainWindow::updateNumber(QString num){

    number = number + num;
    ui->txtNumber->setText(number);
}

void MainWindow::call(){

}



void MainWindow::on_volumeSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    volume = value;
    dsp_->updateVolume(value);
    ;
}


void MainWindow::on_fileButton_clicked() {}


void MainWindow::on_fileEdit_returnPressed() {}


void MainWindow::on_m_pButton1_clicked()
{
    if(hanged == false){
        QSound::play("keys/1.wav");
        updateNumber("1");
    }

}

void MainWindow::on_m_pButton2_clicked()
{
    if(hanged == false){
        QSound::play("keys/2.wav");
        updateNumber("2");
    }

}


void MainWindow::on_m_pButton3_clicked()
{
    if(hanged == false){
        QSound::play("keys/3.wav");
        updateNumber("3");
    }

}

void MainWindow::on_m_pButtonA_clicked()
{
    if(hanged == false){
        QSound::play("keys/A.wav");
    }

}

void MainWindow::on_m_pButton4_clicked()
{
    if(hanged == false){
        QSound::play("keys/4.wav");
        updateNumber("4");
    }

}

void MainWindow::on_m_pButton5_clicked()
{
    if(hanged == false){
        QSound::play("keys/5.wav");
        updateNumber("5");
    }

}

void MainWindow::on_m_pButton6_clicked()
{
    if(hanged == false){
        QSound::play("keys/6.wav");
        updateNumber("6");
    }

}

void MainWindow::on_m_pButtonB_clicked()
{
    if(hanged == false){
        QSound::play("keys/B.wav");
    }

}

void MainWindow::on_m_pButton7_clicked()
{
    if(hanged == false){
        QSound::play("keys/7.wav");
        updateNumber("7");
    }

}

void MainWindow::on_m_pButton8_clicked()
{
    if(hanged == false){
        QSound::play("keys/8.wav");
        updateNumber("8");
    }

}

void MainWindow::on_m_pButton9_clicked()
{
    if(hanged == false){
        QSound::play("keys/9.wav");
        updateNumber("9");
    }

}

void MainWindow::on_m_pButtonC_clicked()
{
    if(hanged == false){
        QSound::play("keys/C.wav");
    }

}

void MainWindow::on_m_pButtonAst_clicked()
{
    if(hanged == false){
        QSound::play("keys/Ast.wav");
        updateNumber("*");
    }

}

void MainWindow::on_m_pButton0_clicked()
{
    if(hanged == false){
        QSound::play("keys/0.wav");
        updateNumber("0");
    }

}

void MainWindow::on_m_pButtonNum_clicked()
{
    if(hanged == false){

        updateNumber("#");

        //listNumber = "*"+number;
        listNumber = number;
        listNumber.insert(0,"*");
        sound->play("keys/Num.wav");
        timer->start(1000);  // In milliseconds.


    }

}

void MainWindow::onTimeout()
{
    printf(" AQUI ");
    if( sound->isFinished() )
    {
        timer->stop();
        if(listNumber.size()>0){

            QString n = listNumber.at(0);
            QString path = "keys/"+n+"t.wav";

            printf("%s",path.toLocal8Bit().data());


            sound->play(path);
            listNumber.remove(0,1);
            timer->start(80);  // In milliseconds.
        }
        else{
            number = "";
        }

    }
}

void MainWindow::on_m_pButtonD_clicked()
{
    if(hanged == false){
        QSound::play("keys/D.wav");
    }
}


void MainWindow::on_m_pButtonHang_clicked()
{
    if(hanged){
        jack::init(dsp_);
        hanged = false;
        dsp_->updateVolume(volume);
        ui->m_pButtonHang->setText("Colgar");
        ui->txtNumber->setEnabled(true);
    }
    else{
        jack::close();
        hanged = true;
        ui->m_pButtonHang->setText("Descolgar");
        ui->txtNumber->setEnabled(false);
    }


}


void MainWindow::on_txtNumber_textChanged()
{
    number = ui->txtNumber->toPlainText();
}

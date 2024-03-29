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
 * \file   mainwindow.h
 *         Implements the equalizer H(w) computation
 * \author Pablo Alvarado/Jose Miguel Barboza
 * \date   2010.12.12/2017.05.26
 *
 * $Id: mainwindow.h $
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBuffer>
#include <QAudioOutput>
#include <QByteArray>
#include <QTimer>
#include <QFileDialog>
#include <QSound>

#include "dspsystem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int volumeGain;
    /**
      *Tolerance value
      */
    static const float Epsilon;

     /**
      * Verbose flag
      */
     bool verbose_;

     /**
      * Enable Disable Mic Flag
      */
      bool hanged;

      /**
       * Volume
       */
      int volume;

      /**
       * Number
       */
      QString number;
      QString listNumber;

      QVector<QString> reg;


     /**
      * Timer used to recompute the filter once the user changes the
      * values
      */
     QTimer *timer_;

     /**
      * List of selected files so far
      */
     QStringList selectedFiles_;

     /**
      * Pointer to an inherited class of processor, which does
      * all the real work.
      */
     dspSystem* dsp_;

     /**
      *DSP change
      */
     bool dspChanged_;

     void updateNumber(QString number);

     void call(QString num);




    QTimer* timer;
    QSound * sound;

   private slots:
     void on_fileEdit_returnPressed();
     void on_fileButton_clicked();
     void on_volumeSlider_valueChanged(int value);


     void update();

     void on_m_pButton1_clicked();
     void on_m_pButtonHang_clicked();
     void on_m_pButton2_clicked();
     void on_m_pButton3_clicked();
     void on_m_pButtonA_clicked();
     void on_m_pButton4_clicked();
     void on_m_pButton5_clicked();
     void on_m_pButton6_clicked();
     void on_m_pButtonB_clicked();
     void on_m_pButton7_clicked();
     void on_m_pButton8_clicked();
     void on_m_pButton9_clicked();
     void on_m_pButtonC_clicked();
     void on_m_pButtonAst_clicked();
     void on_m_pButton0_clicked();
     void on_m_pButtonNum_clicked();
     void on_m_pButtonD_clicked();
     void on_txtNumber_textChanged();

     void onTimeout();


};




#endif // MAINWINDOW_H

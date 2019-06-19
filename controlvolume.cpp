/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2017  Pablo Alvarado
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
 * \file   controlVolume.cpp
 *         Implements control volumen in the time domain
 * \author Jose Miguel Barboza
 * \date   2017.31.05
 *
 * $Id: controlVolume.cpp $
 */

#include "controlvolume.h"
#include <cmath>

#undef _DSP_DEBUG
#define _DSP_DEBUG

#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif

/*
 * Constructor
 */

controlVolume::controlVolume(){
}


/*
 * Destructor
 */

controlVolume::~controlVolume(){

}


/*
 * Init the filter operation
 */

void controlVolume::filter(int blockSize, int volumeGain, float *in, float *out){

    //printf("block size: %d",blockSize);

    pFile = fopen ("myfile.txt","a");



    float *out2;
    int Muestra = 0;
    for (int n=0; n<blockSize;++n){
        out[n]=(volumeGain)*in[n]*0.02;
        fprintf (pFile, "%f ",out[n]);
    }
    fclose (pFile);
    DetMuestra(in, Muestra);

}

void controlVolume::DetMuestra(float *entrada, int NMuestra){




    float salida1=0;
    float salida2=0;

    mFile = fopen("Muestra.txt","a");
    int CantMuestras = 1024;	// Cantidad de muestras de la trama
    float error = 0.1;	// Referencia para Tanque RC
    float wn1_uno = 0;
    float wn1_dos = 0;
    float wn2_uno = 0;
    float wn2_dos = 0;
    float k1 = 0.007073522215300758614331400053742981981;	// Ganancia
    float k2 = 0.014048380811045075786114288973749353318;
    int b0 = 1;	// Constante de la entrada
    int b1 = 0;	// Constante de la entrada retrasda una muestra
    int b2 = -1;	// Constante de la entrada retrasada dos muestras
    float a11 = -1.968082049714432679721198837796691805124;	// Constante de la salida retrasada una muestra
    float a21 =  0.985852955569398559099170142872026190162;	// Constante de la saluda retrasada dos muestras
    float a12 = -1.930341470705124296003418749023694545031;	// Constante de la salida retrasada una muestra
    float a22 =  0.971903238377909928225051316985627636313;
    float energia1 = 0;	// Variable que guarda la energia de la señal
    float energia2 = 0;
    int Muestra1 = 0;
    int Muestra2 = 0;

    for(int i= 0; i<1024; i++){	// Implementacion del filtro
        const float wn1 = *entrada++ - (a11*wn1_uno+a21*wn1_dos);
        salida1 = k1*(b0*wn1 + b1*wn1_uno + b2*wn1_dos);
        const float wn2 = *entrada++ - (a12*wn2_uno+a22*wn2_dos);
        salida2 = k2*(b0*wn2 + b1*wn2_uno + b2*wn2_dos);
        //printf("SALIDAAAA %f",misalida[i]);
        wn1_dos = wn1_uno;
        wn1_uno = wn1;
        wn2_dos = wn2_uno;
        wn2_uno = wn2;

        if(salida1*salida1 > error){
            energia1 = energia1 + salida1*salida1;
            //printf("Energia: %f",energia);
            if(energia1 < 20 && energia1 > 10){
               Muestra1 = i;
               printf(" Mi muestra es: %d",i);
            }
        }
        if(salida2*salida2 > error){
            energia2 = energia2 + salida2*salida2;
            //printf("Energia: %f",energia);
            if(energia2 < 20 && energia2 > 10){
               Muestra2 = i;
               printf(" Mi muestra es: %d",i);
            }
        }
        if(Muestra1*Muestra2 != 0){
            NMuestra = (Muestra1 + Muestra2)/2;
            printf(" Muestra= %d ", NMuestra);
        }

    }
    //printf(" Energia= %f", energia);
    fclose (mFile);
}

void controlVolume::filter_697(float *entrada, int flag){
    int referencia = 500;	// Referencia para validar el tono
    int CantMuestras = 3528;	// Cantidad de muestras de la trama
    float error = 0.01;	// Referencia para Tanque RC
    float *ptrIn = entrada;
    float *ptrEnd = entrada + CantMuestras;
    float *ptrOut;	// Salida del filtro
    float wn_uno = 0;
    float wn_dos = 0;
    float k = 0.007073522215300343148058903608443870326;	// Ganancia
    int b0 = 1;	// Constante de la entrada
    int b1 = 0;	// Constante de la entrada retrasda una muestra
    int b2 = -1;	// Constante de la entrada retrasada dos muestras
    float a1 = -1.976119281912332992234837547584902495146;	// Constante de la salida retrasada una muestra
    float a2 =  0.985852955569399447277589842997258529067;	// Constante de la saluda retrasada dos muestras
    float energia = 0;	// Variable que guarda la energia de la señal
    *salida = 0;	// Variable para validar la señal
    while(ptrIn != ptrEnd){	// Implementacion del filtro
        const float wn = *ptrIn++ - (a1*wn_uno+a2*wn_dos);
        *ptrOut++ = b0*wn + b1*wn_uno + b2*wn_dos;
        wn_dos = wn_uno;
        wn_uno = wn;
        if((*ptrOut)*(*ptrOut) < error){
            *salida = *salida - energia/1764;
            if(*salida < referencia && energia > referencia){
                flag = 1;
                break;
            }
        }
        else{
            energia = energia + (*ptrOut)*(*ptrOut);
            *salida = energia;
        }
    }
}

void controlVolume::filter_770(float *entrada, int flag){
    int referencia = 500;	// Referencia para validar el tono
    int CantMuestras = 3528;	// Cantidad de muestras de la trama
    float error = 0.01;	// Referencia para Tanque RC
    float *ptrIn = entrada;
    float *ptrEnd = entrada + CantMuestras;
    float *ptrOut;	// Salida del filtro
    float wn_uno = 0;
    float wn_dos = 0;
    float k = 0.00707352221530087484080429049981830758;	// Ganancia
    int b0 = 1;	// Constante de la entrada
    int b1 = 0;	// Constante de la entrada retrasda una muestra
    int b2 = -1;	// Constante de la entrada retrasada dos muestras
    float a1 = -1.973964660990097819137645274167880415916;	// Constante de la salida retrasada una muestra
    float a2 =  0.985852955569398226032262755325064063072;	// Constante de la saluda retrasada dos muestras
    float energia = 0;	// Variable que guarda la energia de la señal
    *salida = 0;	// Variable para validar la señal
    while(ptrIn != ptrEnd){	// Implementacion del filtro
        const float wn = *ptrIn++ - (a1*wn_uno+a2*wn_dos);
        *ptrOut++ = b0*wn + b1*wn_uno + b2*wn_dos;
        wn_dos = wn_uno;
        wn_uno = wn;
        if((*ptrOut)*(*ptrOut) < error){
            *salida = *salida - energia/1764;
            if(*salida < referencia && energia > referencia){
                flag = 1;
                break;
            }
        }
        else{
            energia = energia + (*ptrOut)*(*ptrOut);
            *salida = energia;
        }
    }
}

void controlVolume::filter_852(float *entrada, int flag){
    int referencia = 500;	// Referencia para validar el tono
    int CantMuestras = 3528;	// Cantidad de muestras de la trama
    float error = 0.01;	// Referencia para Tanque RC
    float *ptrIn = entrada;
    float *ptrEnd = entrada + CantMuestras;
    float *ptrOut;	// Salida del filtro
    float wn_uno = 0;
    float wn_dos = 0;
    float k = 0.007073522215300863565101696650572193903;	// Ganancia
    int b0 = 1;	// Constante de la entrada
    int b1 = 0;	// Constante de la entrada retrasda una muestra
    int b2 = -1;	// Constante de la entrada retrasada dos muestras
    float a1 = -1.971289770106245731184912983735557645559;	// Constante de la salida retrasada una muestra
    float a2 =  0.985852955569398226032262755325064063072;	// Constante de la saluda retrasada dos muestras
    float energia = 0;	// Variable que guarda la energia de la señal
    *salida = 0;	// Variable para validar la señal
    while(ptrIn != ptrEnd){	// Implementacion del filtro
        const float wn = *ptrIn++ - (a1*wn_uno+a2*wn_dos);
        *ptrOut++ = b0*wn + b1*wn_uno + b2*wn_dos;
        wn_dos = wn_uno;
        wn_uno = wn;
        if((*ptrOut)*(*ptrOut) < error){
            *salida = *salida - energia/1764;
            if(*salida < referencia && energia > referencia){
                flag = 1;
                break;
            }
        }
        else{
            energia = energia + (*ptrOut)*(*ptrOut);
            *salida = energia;
        }
    }
}

void controlVolume::filter_941(float *entrada, int flag){
    int referencia = 500;	// Referencia para validar el tono
    int CantMuestras = 3528;	// Cantidad de muestras de la trama
    float error = 0.01;	// Referencia para Tanque RC
    float *ptrIn = entrada;
    float *ptrEnd = entrada + CantMuestras;
    float *ptrOut;	// Salida del filtro
    float wn_uno = 0;
    float wn_dos = 0;
    float k = 0.007073522215300758614331400053742981981;	// Ganancia
    int b0 = 1;	// Constante de la entrada
    int b1 = 0;	// Constante de la entrada retrasda una muestra
    int b2 = -1;	// Constante de la entrada retrasada dos muestras
    float a1 = -1.968082049714432679721198837796691805124;	// Constante de la salida retrasada una muestra
    float a2 =  0.985852955569398559099170142872026190162;	// Constante de la saluda retrasada dos muestras
    float energia = 0;	// Variable que guarda la energia de la señal
    *salida = 0;	// Variable para validar la señal
    while(ptrIn != ptrEnd){	// Implementacion del filtro
        const float wn = *ptrIn++ - (a1*wn_uno+a2*wn_dos);
        *ptrOut++ = b0*wn + b1*wn_uno + b2*wn_dos;
        wn_dos = wn_uno;
        wn_uno = wn;
        if((*ptrOut)*(*ptrOut) < error){
            *salida = *salida - energia/1764;
            if(*salida < referencia && energia > referencia){
                flag = 1;
                break;
            }
        }
        else{
            energia = energia + (*ptrOut)*(*ptrOut);
            *salida = energia;
        }
    }
}

void controlVolume::filter_1209(float *entrada, int flag){
    int referencia = 500;	// Referencia para validar el tono
    int CantMuestras = 3528;	// Cantidad de muestras de la trama
    float error = 0.01;	// Referencia para Tanque RC
    float *ptrIn = entrada;
    float *ptrEnd = entrada + CantMuestras;
    float *ptrOut;	// Salida del filtro
    float wn_uno = 0;
    float wn_dos = 0;
    float k = 0.014048380811045287422378358144214871572;	// Ganancia
    int b0 = 1;	// Constante de la entrada
    int b1 = 0;	// Constante de la entrada retrasda una muestra
    int b2 = -1;	// Constante de la entrada retrasada dos muestras
    float a1 = -1.942918327039865777905447430384811013937;	// Constante de la salida retrasada una muestra
    float a2 =  0.971903238377909484135841466923011466861;	// Constante de la saluda retrasada dos muestras
    float energia = 0;	// Variable que guarda la energia de la señal
    *salida = 0;	// Variable para validar la señal
    while(ptrIn != ptrEnd){	// Implementacion del filtro
        const float wn = *ptrIn++ - (a1*wn_uno+a2*wn_dos);
        *ptrOut++ = b0*wn + b1*wn_uno + b2*wn_dos;
        wn_dos = wn_uno;
        wn_uno = wn;
        if((*ptrOut)*(*ptrOut) < error){
            *salida = *salida - energia/1764;
            if(*salida < referencia && energia > referencia){
                flag = 1;
                break;
            }
        }
        else{
            energia = energia + (*ptrOut)*(*ptrOut);
            *salida = energia;
        }
    }
}

void controlVolume::filter_1336(float *entrada, int flag){
    int referencia = 500;	// Referencia para validar el tono
    int CantMuestras = 3528;	// Cantidad de muestras de la trama
    float error = 0.01;	// Referencia para Tanque RC
    float *ptrIn = entrada;
    float *ptrEnd = entrada + CantMuestras;
    float *ptrOut;	// Salida del filtro
    float wn_uno = 0;
    float wn_dos = 0;
    float k = 0.014048380811045608346221413853527337778;	// Ganancia
    int b0 = 1;	// Constante de la entrada
    int b1 = 0;	// Constante de la entrada retrasda una muestra
    int b2 = -1;	// Constante de la entrada retrasada dos muestras
    float a1 = -1.936484253615310180407504958566278219223;	// Constante de la salida retrasada una muestra
    float a2 =  0.971903238377908706979724229313433170319;	// Constante de la saluda retrasada dos muestras
    float energia = 0;	// Variable que guarda la energia de la señal
    *salida = 0;	// Variable para validar la señal
    while(ptrIn != ptrEnd){	// Implementacion del filtro
        const float wn = *ptrIn++ - (a1*wn_uno+a2*wn_dos);
        *ptrOut++ = b0*wn + b1*wn_uno + b2*wn_dos;
        wn_dos = wn_uno;
        wn_uno = wn;
        if((*ptrOut)*(*ptrOut) < error){
            *salida = *salida - energia/1764;
            if(*salida < referencia && energia > referencia){
                flag = 1;
                break;
            }
        }
        else{
            energia = energia + (*ptrOut)*(*ptrOut);
            *salida = energia;
        }
    }
}

void controlVolume::filter_1477(float *entrada, int flag){
    int referencia = 500;	// Referencia para validar el tono
    int CantMuestras = 3528;	// Cantidad de muestras de la trama
    float error = 0.01;	// Referencia para Tanque RC
    float *ptrIn = entrada;
    float *ptrEnd = entrada + CantMuestras;
    float *ptrOut;	// Salida del filtro
    float wn_uno = 0;
    float wn_dos = 0;
    float k = 0.014048380811045075786114288973749353318;	// Ganancia
    int b0 = 1;	// Constante de la entrada
    int b1 = 0;	// Constante de la entrada retrasda una muestra
    int b2 = -1;	// Constante de la entrada retrasada dos muestras
    float a1 = -1.930341470705124296003418749023694545031;	// Constante de la salida retrasada una muestra
    float a2 =  0.971903238377909928225051316985627636313;	// Constante de la saluda retrasada dos muestras
    float energia = 0;	// Variable que guarda la energia de la señal
    *salida = 0;	// Variable para validar la señal
    while(ptrIn != ptrEnd){	// Implementacion del filtro
        const float wn = *ptrIn++ - (a1*wn_uno+a2*wn_dos);
        *ptrOut++ = b0*wn + b1*wn_uno + b2*wn_dos;
        wn_dos = wn_uno;
        wn_uno = wn;
        if((*ptrOut)*(*ptrOut) < error){
            *salida = *salida - energia/1764;
            if(*salida < referencia && energia > referencia){
                flag = 1;
                break;
            }
        }
        else{
            energia = energia + (*ptrOut)*(*ptrOut);
            *salida = energia;
        }
    }
}

void controlVolume::FiltradoT(float *Trama, int numero){
    int num[6];
    filter_697(Trama, num[0]);
    filter_770(Trama, num[1]);
    filter_852(Trama, num[2]);
    filter_941(Trama, num[3]);
    filter_1209(Trama, num[4]);
    filter_1336(Trama, num[5]);
    filter_1477(Trama, num[6]);
    if(num[0]&&num[4]){
        numero = 1;
    }
    else if (num[0]&&num[5]) {
        numero = 2;
    }
    else if (num[0]&&num[6]) {
        numero = 3;
    }
    else if (num[1]&&num[4]) {
        numero = 4;
    }
    else if (num[1]&&num[5]) {
        numero = 5;
    }
    else if (num[1]&&num[6]) {
        numero = 6;
    }
    else if (num[2]&&num[4]) {
        numero = 7;
    }
    else if (num[2]&&num[5]) {
        numero = 8;
    }
    else if (num[2]&&num[6]) {
        numero = 9;
    }
    else if (num[3]&&num[4]) {
        numero = 10;
    }
    else if (num[3]&&num[5]) {
        numero = 0;
    }
    else if (num[3]&&num[6]) {
        numero = 11;
    }
}

void controlVolume::Validacion(float *Trama, int TramaProc, int IDCorrecto){
    int numero = -1;
    FiltradoT(Trama, numero);
    TramaProc = 1;
    if(numero == 9){
        FiltradoT(Trama, numero);
        TramaProc = 1;
        if(numero == 9){
            FiltradoT(Trama, numero);
            TramaProc = 1;
            if(numero == 1){
                IDCorrecto = 1;
            }
        }
    }
    else if(numero == 8){
        FiltradoT(Trama, numero);
        TramaProc = 1;
        if(numero == 5){
            FiltradoT(Trama, numero);
            TramaProc = 1;
            if(numero == 5){
                FiltradoT(Trama, numero);
                TramaProc = 1;
                if(numero == 3){
                    FiltradoT(Trama, numero);
                    TramaProc = 1;
                    if(numero == 6){
                        FiltradoT(Trama, numero);
                        TramaProc = 1;
                        if(numero == 2){
                            FiltradoT(Trama, numero);
                            TramaProc = 1;
                            if(numero == 1){
                                FiltradoT(Trama, numero);
                                TramaProc = 1;
                                if(numero == 0){
                                    IDCorrecto = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        IDCorrecto = -1;
    }

}

/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2017  Jose Miguel Barboza
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
 * \file   controlVolume.h
 *         Implements control volumen in the time domain
 * \author Jose Miguel Barboza
 * \date   2017.31.05
 *
 * $Id: controlVolume.cpp $
 */


#ifndef CONTROLVOLUME_H
#define CONTROLVOLUME_H
#include "stdio.h"

/**
 * Control Volume class
 *
 * This filter has control in the volume gain of the signal.
 *
 * The filter follows the difference equation
 * \f[
 * y(n)=\cvGain x(n)
 * \f]
 */

class controlVolume {
public:
    /**
     * Constructor
     */
    controlVolume();

    /**
     * Destructor
     */
    ~controlVolume();

   /**
    * Filter the in buffer and leave the result in out
    */
   void filter(int blockSize,
               int volumeGain,
               float* in,
               float* out);
   // Filtros para frecuencias bajas
   void filter_697(float *entrada, int flag);
   void filter_770(float *entrada, int flag);
   void filter_852(float *entrada, int flag);
   void filter_941(float *entrada, int flag);
   // Filtros para frecuencias altas
   void filter_1209(float *entrada, int flag);
   void filter_1336(float *entrada, int flag);
   void filter_1477(float *entrada, int flag);

   void DetMuestra(float *entrada, int NMuestra);

   void Validacion(float *Trama, int IDCorrecto);

   void FiltradoT(float *Trama, int numero);

private:
   FILE * pFile;
   FILE * mFile;

};


#endif // CONTROLVOLUME_H

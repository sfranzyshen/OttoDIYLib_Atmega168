#ifndef Otto_gestures_h
#define Otto_gestures_h

//***********************************************************************************
//*********************************GESTURE DEFINES***********************************
//***********************************************************************************           

#define OttoHappy 		0
#define OttoSuperHappy 	1
#define OttoSad 		2
#define OttoSleeping 	3
#define OttoFart 		4
#define OttoConfused 	5
#define OttoLove 		6
#define OttoAngry 		7
#define OttoFretful 	8
#define OttoMagic 		9
#define OttoWave 		10
#define OttoVictory 	11
#define OttoFail 		12


//"PROGMEM_readAnything.h"   FROM http://www.gammon.com.au/progmem
// modified for OTTO use by Paul Van De Veen along with all PROGMEM mouths and gestures
#include <Arduino.h>  // for type definitions

template <typename T> void PROGMEM_readAnything (const T * sce, T& dest)
  {
  memcpy_P (&dest, sce, sizeof (T));
  }

template <typename T> T PROGMEM_getAnything (const T * sce)
  {
  static T temp;
  memcpy_P (&temp, sce, sizeof (T));
  return temp;
  }

#endif

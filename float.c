#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"


int is_special ( float f ) {
  //check if exp is all one or all zero ==> -225, 255 or 0
  int check = get_E(f);
  if (check == 128 || check == 382 || check == -127){
    return 1;
  }
  return 0;

}


float get_M  ( float f ) {
  int *ptr = &f;
  int temp = *ptr;
  int foo;
  float mantissa = 1.0;
  int i;
  for(i=22; i>=0; i--){
    foo = temp&1 << i;
    if (foo != 0){
      mantissa += powf(2, -1*(23-i));
    }
  }
  return mantissa;
}


int get_s ( float f ) {
  if (f < 0){
    return -1;
  }
	return 1;
}



int get_E ( float f ) {
  int *p = &f;
  int tmp = *p;
  int bar, i;
  int exp = 0; 
  //exp uses bits 23 - 30 (8 bits)
  for (i=30; i>=23; i--){
    bar = tmp&1 << i;
    if(bar != 0){
      exp += (int) (powf(2, i-23));
    }
  }
  //by definition of E = exp - bias (which is 127 for single precision)
  int E = exp - 127;
    return E;
}













      



    
    

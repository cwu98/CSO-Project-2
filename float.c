#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"


int is_special ( float f ) {
  //check if exp is all one or all zero ==> -225, 255 
  int check = get_E(f);
  if (check == 255){
    return 1;
  }
  return 0;

}


float get_M  ( float f ) {
  int *ptr = &f;
  int temp = *ptr;
  int foo;
  float mantissa;
  float frac = 0.0;
  int i;
  int Eval = get_E(f);
  for(i=22; i>=0; i--){
    foo = temp&1 << i;
    if (foo != 0){//1 at the bit position
      frac += powf(2, -1*(23-i)); //calculate frac
    }
  }
  if(Eval == -126){//denormalized, exp all 0s
    mantissa = 0.0 + frac;
  }
  else if(Eval == 255){//special values
    if(frac!=0){//nan
      mantissa = 0.0 + frac;
    }
    else if(frac == 0){//inf
      mantissa = 0.0 + frac;
    }
  }
  else{
    mantissa = 1.0 + frac; //add 1.0 to frac to get mantissa
  }
  return mantissa;
}


int get_s ( float f ) {
  if (signbit(f)){ //signbit is used because it returns -1 for -nan
    return -1;
  }
	return 1;
}



int get_E ( float f ) {
  int *p = &f;
  int tmp = *p;
  int bar, i, E;
  int exp = 0; 
  //exp uses bits 23 - 30 (8 bits)
  for (i=30; i>=23; i--){
    bar = tmp&1 << i;
    if(bar != 0){ //1 at the bit location
      exp += (int) (powf(2, i-23)); //calculate exp
    }
  }
  if(exp == 0){ //denormalized, all zero
  
    E = 1 - 127; //E = 1-bias 
  }
  else if(exp == 255 || exp == -255){ //special values
    E = 255; 
  }
  else{ //by definition of E = exp - bias (which is 127 for single precision)
    E = exp - 127;
  }

    return E;
}













      



    
    

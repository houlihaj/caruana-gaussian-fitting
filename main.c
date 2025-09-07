// Name: main.c
// Description: Example file to exercise the Caruana Gaussian fitting algorithm.
// Author: John Houlihan

//------------------------------------------------------------------------------------
// MIT License
//
// Copyright (c) 2025 John Houlihan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//------------------------------------------------------------------------------------

#include  <stdio.h>
#include  <string.h>
#include  "polyfit.h"


// Buffer to hold a string representation of a polynomial:
#define POLY_STRING_BF_SZ   (256)
char polyStringBf[POLY_STRING_BF_SZ];


//--------------------------------------------------------
// main()
//--------------------------------------------------------
/* Gaussian data that we want to find the best-fit parameters for */
double x_dat[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
double y_dat[] = { 3.518, 13.710, 38.425, 75.267, 98.833, 88.621, 53.079, 21.589, 6.107, 1.051 };
double y_dat_ln[] = { 1.258, 2.618, 3.649, 4.321, 4.593, 4.484, 3.972, 3.072, 1.809, 0.0498 };


int main()
{
  int rVal;
 
  //---------------------Second-order poly fit---------------------------
  int num_dat_points = 10;
  int num_coefficients = 3;
  double best_fit_coeffs[num_coefficients];
  rVal = polyfit( num_dat_points, x_dat, y_dat_ln, num_coefficients, best_fit_coeffs);
  if( 0 == rVal)
  { 
    polyToString( polyStringBf, POLY_STRING_BF_SZ, num_coefficients, best_fit_coeffs );
  }
  else
  {
    snprintf( polyStringBf, POLY_STRING_BF_SZ, "error = %d", rVal );
  }
  printf( "Test 2 produced %s\n", polyStringBf);
}


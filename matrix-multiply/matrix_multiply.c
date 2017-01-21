//*****************************************************************************
//
// This program calculates the product of a square matrix with itself:
//
// B = A * A
//
// Please keep all code in this single file.
//
//
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
   
   // check command line arguments
   if ( argc != 3 ) {
      printf("This program computes the product of n x n matrix with itself\n");
      printf("Usage: ./matrix_multiply filename n\n");
      exit(0);
   }

   // TODO: parse input arguments

   // TODO: dynamically allocate space for matrix_A (input matrix) in 1d array
   int * matrix_A;  // declare input matrix

   // TODO: call function to read data from file and copy into matrix_A

   // TODO: dynamically allocate space for matrix_B (output matrix) in 1d array
   int * matrix_B;  // declare output matrix

   // TODO: call function to perform matrix multiplication ( matrix_B = matrix_A * matrix_A )
   
   // TODO: call function to write results (matrix_B) to stdout

   // TODO: free space allocated for matrix_A and matrix_B

   return 0;

}
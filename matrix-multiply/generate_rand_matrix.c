#include <stdio.h>
#include <stdlib.h> // srand and rand
#include <time.h>

int main(int argc, char ** argv)
{
   // check command line arguments
   if ( argc != 2 ) {
      printf("This program generates a random n x n matrix of ints.\n");
      printf("Usage: ./generate_rand_matrix n\n");
      exit(-1);
   }

   time_t t;
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   int i,r,j,n;
 
   n = atoi(argv[1]);
  
   for ( i=0 ; i<n ; i++ ) {
      for ( j=0; j<n ; j++ ) {
         r = rand() % 200;
         printf("%d ",r);
      }
      printf("\n");
   }
 
   return 0;
}
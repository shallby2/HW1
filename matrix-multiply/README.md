# Matrix Multiply

Boilerplate code for matrix multiplication assignment.

## Building Code

To build the binary simply type:

	make

There is an additional source file that will be useful for creating random matrices
of various sizes for testing. To build this file type:

	make generate_rand_matrix

## Generating New Matrices from the Command Line

Use the `generate_rand_matrix` program to generate matrices of different sizes. For example:

```
$ ./generate_rand_matrix 3 > 3_3_mat.dat
```

will create a 3x3 matrix. Please use the .dat file extension for these files since these are
not tracked in this repository (see the .gitignore). This ensures that you don't push a huge
data file to GitHub, which can be painfully slow and cause other headaches.

## Passing File Name from Command Line

Try something like this for passing file name from the Linux command line:

```C
. 
.
.
void read_data(char * file, int * mat, int mat_len)
{
   FILE *fp_in;
   fp_in = fopen(file,"r");
   .
   .
   .
}

int main(int argc, char ** argv)
{
.
.
.
  char * filename = argv[1];
  read_data(filename, matrix_A, n);
.
.
.
}
```  

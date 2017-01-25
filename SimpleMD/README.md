# Simple MD Program

* This is a very basic NVE moleculer dynamics program that will
be used for the course I teach in the spring.

* This program borrows heavily from David Keffer's "The Working Person's 
Guide to Molecular Dynamics Simulations", although I have written the program in a different
language and also expanded/replaced certain parts of the program.

* The idea for the class is that students will start with this basic
serial version of the code and then add parallel support with PThreads,
OpenMP, MPI, CUDA, or whatever.

## Project Layout

- **bin/**: binary built to this directory.
- **images/**: photo gallery of simulation snapshots.
- **inc/**: contains header files with function prototypes, struct definitions, etc.
- **obj/**: object files stored in this directory.
- **src/**: source files.
- **Makefile**: automated build script.
- **simulate.sh**: shell script with examples for running program.

## Building Program

To build simply type:

```
make
```

If this is your first time to build the program you should see:

```
$ make
gcc -Iinc -lm -Wall -c src/atoms.c -o obj/atoms.o
gcc -Iinc -lm -Wall -c src/cl_parse.c -o obj/cl_parse.o
gcc -Iinc -lm -Wall -c src/energy_force.c -o obj/energy_force.o
gcc -Iinc -lm -Wall -c src/initialization.c -o obj/initialization.o
gcc -Iinc -lm -Wall -c src/integrator.c -o obj/integrator.o
gcc -Iinc -lm -Wall -c src/mddriver.c -o obj/mddriver.o
gcc -Iinc -lm -Wall -c src/params.c -o obj/params.o
gcc -Iinc -lm -Wall -c src/print_traj.c -o obj/print_traj.o
gcc -Iinc -lm -Wall -c src/props.c -o obj/props.o
gcc -Iinc -lm -Wall -c src/timer.c -o obj/timer.o
gcc -lm  obj/atoms.o obj/cl_parse.o obj/energy_force.o obj/initialization.o obj/integrator.o obj/mddriver.o obj/params.o obj/print_traj.o obj/props.o obj/timer.o -o bin/run_md
```

If you have not edited any files since last running make, then you should see:

```
$ make
make: `bin/run_md' is up to date.
```

Make automates the build process, so if you only edit a single source file, only that source file will be recompiled. If you want to blow away all the object files and the program binary, you can run:

```
$ make cleanall
```

while

```
$ make clean
```

will remove just the binary in **bin/**.

Make sure to add the Intel Cluster Studio compiler to your 
environment if you're using the icc command to build your project:

```
$ setpkgs -a intel_cluster_studio_compiler
```

You will also need to uncomment the Intel compiler section of your Makefile and comment
out the GCC section if you would like to build the program with the Intel compiler.

## Usage

To run from the project root directory simply type:

```
bin/run_md
```

This will run the program with default parameters. To see a list of command-line options and a list of defaults, pass **--help** as a command-line argument:

```
$ bin/run_md --help
Usage: ./run_md [-N <n_particles>] [-ts <n_timesteps>] [-xyz <xyz_file_output_frequency>] [-o <thermo_output_frequency>]
Defaults:
n_particles: 100
n_timesteps: 10000
xyz_file_output_fequency: 100
thermo_output_frequency: 100
```

The project root directory also contains a Bash script for running a number of pre-determined simulations. To run with the default parameters simply type:

```
bash simulate.sh
```

This script it very useful since it will also output the statistics from the simulation. Feel free to modify the script to add different simulation sizes
and so on. It currently supports a number of different system sizes. For example, the following will run a 500-atom simulation:

```
bash simulate.sh 500
``` 

## Output

Below is an example of the output from a simulation with the default parameters using GCC 4.4.7 with level-three optimizations on a Intel Xeon E5-2420 @ 1.90GHz.

```
$ bash simulate.sh 
running: bin/run_md -N 125
=======Command line arguments=======
N_atoms: 125
n_timesteps: 10000
xyz_file_output_frequency: 100
thermo_output_frequency: 100
====================================
box length: 2.419e+01 Angstrom
density: 8.832e-03 molecules/Ang^3
Beginning simulation....
 Timestep     KE          PE        TotE        Temp   Pressure
      0   3.883e-01  -8.432e-01  -4.54901e-01  150.00  -7.240e-05
    100   2.993e-01  -7.532e-01  -4.53882e-01  115.61  -1.451e-05
    200   3.768e-01  -8.302e-01  -4.53379e-01  145.57  -2.100e-05
    300   3.674e-01  -8.206e-01  -4.53206e-01  141.94  -9.777e-07
    400   3.757e-01  -8.289e-01  -4.53198e-01  145.13  -3.206e-07
    500   3.811e-01  -8.343e-01  -4.53237e-01  147.20  -2.854e-06
    600   3.820e-01  -8.353e-01  -4.53291e-01  147.57  -1.068e-05
    700   3.846e-01  -8.378e-01  -4.53229e-01  148.57  -1.323e-05
    800   3.717e-01  -8.249e-01  -4.53206e-01  143.57  -4.952e-06
    900   3.824e-01  -8.356e-01  -4.53238e-01  147.70  -3.114e-06
   1000   3.977e-01  -8.509e-01  -4.53236e-01  153.63  -8.068e-06
   1100   3.912e-01  -8.443e-01  -4.53143e-01  151.11  -5.170e-06
   1200   3.702e-01  -8.234e-01  -4.53193e-01  142.99  6.898e-06
   1300   4.066e-01  -8.598e-01  -4.53168e-01  157.06  -8.603e-06
   1400   3.850e-01  -8.382e-01  -4.53200e-01  148.72  -1.078e-06
   1500   3.789e-01  -8.322e-01  -4.53256e-01  146.36  5.144e-06
   1600   3.836e-01  -8.368e-01  -4.53214e-01  148.19  -9.577e-07
   1700   3.828e-01  -8.360e-01  -4.53242e-01  147.86  -1.031e-05
   1800   3.852e-01  -8.385e-01  -4.53230e-01  148.82  -1.317e-05
   1900   3.703e-01  -8.236e-01  -4.53233e-01  143.06  -1.489e-06
   2000   3.697e-01  -8.230e-01  -4.53289e-01  142.81  -7.809e-07
   2100   3.661e-01  -8.193e-01  -4.53262e-01  141.41  2.728e-06
   2200   3.775e-01  -8.307e-01  -4.53239e-01  145.81  3.245e-07
   2300   3.903e-01  -8.436e-01  -4.53314e-01  150.78  -6.714e-06
   2400   3.843e-01  -8.376e-01  -4.53250e-01  148.46  -6.300e-06
   2500   3.738e-01  -8.271e-01  -4.53281e-01  144.40  4.131e-06
   2600   3.742e-01  -8.274e-01  -4.53271e-01  144.53  2.372e-06
   2700   3.856e-01  -8.388e-01  -4.53263e-01  148.94  -1.209e-05
   2800   3.747e-01  -8.279e-01  -4.53197e-01  144.74  -9.370e-06
   2900   3.725e-01  -8.256e-01  -4.53165e-01  143.88  -5.435e-06
   3000   3.886e-01  -8.418e-01  -4.53203e-01  150.11  -1.365e-05
   3100   3.682e-01  -8.214e-01  -4.53215e-01  142.22  -8.675e-07
   3200   3.773e-01  -8.305e-01  -4.53228e-01  145.73  -2.878e-06
   3300   3.982e-01  -8.514e-01  -4.53218e-01  153.83  -1.067e-05
   3400   3.859e-01  -8.390e-01  -4.53188e-01  149.05  -2.026e-06
   3500   4.048e-01  -8.581e-01  -4.53233e-01  156.39  -1.382e-05
   3600   3.767e-01  -8.299e-01  -4.53162e-01  145.52  -9.338e-07
   3700   3.772e-01  -8.305e-01  -4.53275e-01  145.72  9.548e-07
   3800   3.856e-01  -8.389e-01  -4.53298e-01  148.95  -7.583e-06
   3900   3.816e-01  -8.349e-01  -4.53269e-01  147.42  -5.201e-06
   4000   3.689e-01  -8.221e-01  -4.53260e-01  142.50  2.588e-06
   4100   3.913e-01  -8.446e-01  -4.53277e-01  151.15  -7.793e-06
   4200   3.571e-01  -8.102e-01  -4.53180e-01  137.93  4.534e-06
   4300   3.935e-01  -8.468e-01  -4.53249e-01  152.01  -8.910e-06
   4400   3.844e-01  -8.375e-01  -4.53185e-01  148.47  -4.212e-06
   4500   3.945e-01  -8.478e-01  -4.53268e-01  152.39  -5.564e-06
   4600   3.877e-01  -8.410e-01  -4.53265e-01  149.78  5.143e-06
   4700   3.718e-01  -8.250e-01  -4.53226e-01  143.60  1.081e-05
   4800   3.753e-01  -8.286e-01  -4.53246e-01  144.99  1.653e-06
   4900   4.047e-01  -8.579e-01  -4.53179e-01  156.32  -2.015e-05
   5000   3.657e-01  -8.189e-01  -4.53269e-01  141.26  -5.397e-06
   5100   3.687e-01  -8.219e-01  -4.53214e-01  142.44  -8.976e-06
   5200   4.017e-01  -8.550e-01  -4.53206e-01  155.19  -2.023e-05
   5300   3.840e-01  -8.372e-01  -4.53195e-01  148.34  -8.310e-07
   5400   3.771e-01  -8.303e-01  -4.53261e-01  145.66  9.870e-06
   5500   4.108e-01  -8.641e-01  -4.53248e-01  158.70  -6.100e-07
   5600   4.039e-01  -8.572e-01  -4.53283e-01  156.01  -5.700e-06
   5700   3.822e-01  -8.354e-01  -4.53248e-01  147.63  3.072e-07
   5800   3.957e-01  -8.490e-01  -4.53250e-01  152.87  -8.919e-06
   5900   3.902e-01  -8.434e-01  -4.53227e-01  150.73  -5.960e-06
   6000   3.999e-01  -8.531e-01  -4.53259e-01  154.46  -6.931e-06
   6100   3.774e-01  -8.306e-01  -4.53222e-01  145.78  5.562e-06
   6200   3.829e-01  -8.361e-01  -4.53259e-01  147.90  -3.432e-08
   6300   3.779e-01  -8.311e-01  -4.53211e-01  145.96  -1.683e-06
   6400   3.814e-01  -8.347e-01  -4.53249e-01  147.35  -7.794e-06
   6500   3.668e-01  -8.200e-01  -4.53221e-01  141.70  -2.600e-06
   6600   3.686e-01  -8.218e-01  -4.53173e-01  142.38  -3.471e-06
   6700   3.719e-01  -8.251e-01  -4.53193e-01  143.66  -6.436e-06
   6800   3.420e-01  -7.952e-01  -4.53231e-01  132.10  2.769e-06
   6900   3.790e-01  -8.323e-01  -4.53291e-01  146.41  -1.383e-05
   7000   3.904e-01  -8.436e-01  -4.53245e-01  150.81  -1.452e-05
   7100   3.791e-01  -8.323e-01  -4.53250e-01  146.43  -1.029e-05
   7200   3.745e-01  -8.277e-01  -4.53223e-01  144.67  -1.095e-05
   7300   3.710e-01  -8.243e-01  -4.53237e-01  143.33  -8.638e-06
   7400   3.761e-01  -8.293e-01  -4.53205e-01  145.28  -6.744e-06
   7500   3.950e-01  -8.482e-01  -4.53208e-01  152.59  -6.202e-06
   7600   4.083e-01  -8.615e-01  -4.53156e-01  157.73  -1.528e-05
   7700   3.740e-01  -8.273e-01  -4.53254e-01  144.48  -8.850e-06
   7800   3.816e-01  -8.349e-01  -4.53259e-01  147.41  -9.286e-06
   7900   3.594e-01  -8.127e-01  -4.53259e-01  138.84  5.225e-06
   8000   3.703e-01  -8.236e-01  -4.53264e-01  143.05  -4.347e-06
   8100   3.987e-01  -8.520e-01  -4.53266e-01  154.02  -1.507e-05
   8200   3.842e-01  -8.375e-01  -4.53295e-01  148.42  -2.643e-06
   8300   3.865e-01  -8.398e-01  -4.53309e-01  149.30  -1.902e-06
   8400   3.672e-01  -8.206e-01  -4.53340e-01  141.86  3.746e-06
   8500   3.912e-01  -8.445e-01  -4.53305e-01  151.10  -1.368e-05
   8600   3.541e-01  -8.073e-01  -4.53219e-01  136.77  1.253e-06
   8700   3.619e-01  -8.151e-01  -4.53286e-01  139.78  8.027e-07
   8800   3.770e-01  -8.303e-01  -4.53315e-01  145.62  6.424e-07
   8900   3.792e-01  -8.325e-01  -4.53292e-01  146.47  -1.489e-06
   9000   3.850e-01  -8.383e-01  -4.53300e-01  148.72  -5.511e-06
   9100   3.861e-01  -8.393e-01  -4.53250e-01  149.13  -2.016e-06
   9200   3.665e-01  -8.197e-01  -4.53227e-01  141.56  6.983e-06
   9300   4.053e-01  -8.586e-01  -4.53293e-01  156.57  -1.502e-05
   9400   3.898e-01  -8.431e-01  -4.53328e-01  150.56  -1.219e-05
   9500   3.876e-01  -8.408e-01  -4.53261e-01  149.71  -6.488e-06
   9600   3.821e-01  -8.355e-01  -4.53317e-01  147.61  -2.960e-07
   9700   3.784e-01  -8.317e-01  -4.53227e-01  146.18  8.597e-06
   9800   3.617e-01  -8.150e-01  -4.53240e-01  139.74  1.317e-05
   9900   3.842e-01  -8.375e-01  -4.53243e-01  148.42  -9.204e-08
  10000   4.177e-01  -8.709e-01  -4.53289e-01  161.34  -1.079e-05
Simulation Complete!
Total simulation time:              2.544 secs
Force/energy time:                  2.502 secs (98.34%)
Position/velocity update time:      0.021 secs ( 0.81%)
Thermo/trajectory output time:      0.020 secs ( 0.77%)
********Thermo stats (mean/std)********
KE: 0.38074 / 0.0151959
PE: -0.834004 / 0.0151766
TotE: -0.453266 / 0.000180299
Temp: 147.075 / 5.87141
Pres: -5.08239e-06 / 9.64316e-06
```

## Viewing Simulation

Copy the traj.xyz file to your local machine and visualize the simulation with free 
software like Visual Molecular Dynamic (http://www.ks.uiuc.edu/Research/vmd/). Here are a few example
snapshots:

### 125 Atoms 
![125 atoms](/SimpleMD/images/125atoms.png?raw=true "125 Atoms")

### 5000 Atoms 
![5000 atoms](/SimpleMD/images/5000atoms.png?raw=true "5000 Atoms")

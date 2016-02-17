# The compiler; using icpc (Intel C++ compiler)
CC = icpc

# Compiler Flags:
# -O2: 		recommended by Intel when using SIMD instructions,
# 		and tests with OpenMP and SIMD shows it has an
# 		improvement (at least for Intel architecture) over
# 		using the O3 optimization flag
#
# -o:		used to name the binary file (ex. -o TSP)
#
# -g:		allows debugging information to the binary file
#
# -debug inline-debug-info
#
# -Wall:	enables all warnings for the compiler
#
# -omp:		links the compiler to OpenMP
#
# -mkl:		links the compiler to the Intel Math Kernel Library (MKL)
#  		NOTE - some of the flags to go with the -mkl link are
#  			1) =parallel (for -qopenmp or -tbb)
#  			2) =sequentia (sequential version of MKL)
#  			3) =cluster (links with cluster components of MKL)
CFLAGS = 

# Libraries to include
LIBS = -L/opt/intel/lib/intel64_lin -L/opt/intel/lib/intel64_lin_mic

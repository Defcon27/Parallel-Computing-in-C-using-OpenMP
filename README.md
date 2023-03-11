# Parallel-Computing-in-C-using-OpenMP

[![GitHub last commit](https://img.shields.io/github/last-commit/Defcon27/Parallel-Computing-in-C-using-OpenMP?color=green&logo=github&style=flat)](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP) 
<img src="https://img.shields.io/badge/%20Language%20-%2300599C.svg?&style=flat&logo=c&logoColor=white"/>
<img src="https://img.shields.io/badge/OpenMP-05747d?&style=flat"/>
<img src="https://img.shields.io/badge/-Open%20MPI-007ac1"/>
[![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/Defcon27/Parallel-Computing-in-C-using-OpenMP?color=red&logo=c&style=flat)](https:/Defcon27/Parallel-Computing-in-C-using-OpenMP)

<br>

This Repository contains C implementation of various algorithms parallellized for computing using OpenMP. The Repo covers many concepts of OpenMP using C from using clauses and constructs in OpenMP to parallelize algorithms. The parallelized implementations in this repo range from operations on arrays, matrices, sorting algorithms to mathematical constants estimations.

<br>

## Table of Contents

- [Clauses](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/tree/master/Clauses)
- [Constructs](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/tree/master/Constructs)
- [Arrays](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/tree/master/Arrays)
- [Matrices](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/tree/master/Matrices)
- [Sorting](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/tree/master/Sorting)
- [π Estimation](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/blob/master/pi_estimation_integration.c)
- [Euler's - e Estimation](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/blob/master/exponent_e_estimation.c)
- [Sine Estimation](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/blob/master/sine_x_estimation.c)
- [Open MPI](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/tree/master/Open%20MPI)

<br>

## Instructions to Run

* #### OpenMP  
  * `cd` into code directory
  * Run `gcc -fopenmp filename.c -o exec` to create executable
  * Run `exec`to execute
  
* #### Open MPI  
  * `cd` into code directory
  * Run `mpicc filename.c -o exec` to create executable
  * Run `mpirun -np t ./exec`to execute (t -> number of threads)



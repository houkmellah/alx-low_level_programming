#!/bin/bash

gcc -c *.c
ar rc liball *.o
ranlib liball.a

#!/bin/bash

NAME=rings

/usr/bin/fpc -dEVAL -vw -XS -O2 -o$NAME grader.pas

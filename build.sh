#!/bin/bash


export PREFIX="$HOME/project/aysh_os/tools/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

make clean && make all



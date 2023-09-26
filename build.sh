#!/bin/bash

export PREFIX="$HOME/project/ayush_os/tools/i686-elf-tools-linux"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

make clean && make all



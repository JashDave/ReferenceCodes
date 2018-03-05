#!/bin/bash

#This line gives the absolute path of this file's parent directory. Can be used to do relative refrencing from this path
MYPATH="$(cd "$(dirname "$0")";pwd)"
echo "Abs path to this file's parent directory -> $MYPATH"

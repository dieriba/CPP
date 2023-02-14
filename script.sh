#!/bin/bash

file_name=$1
file_number=$2;
for ((i=1;  i<9; i++)); do
    mkdir "$file_name$(($file_number+i))"
done

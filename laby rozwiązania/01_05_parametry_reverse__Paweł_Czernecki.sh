#!/bin/bash

params=($*)

n=$#

for (( i=$n-1; i>=0; i-- ))
do
        echo "${params[$i]} "
done

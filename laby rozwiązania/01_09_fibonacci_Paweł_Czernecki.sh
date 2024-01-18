#!/bin/bash

prevprevnumber=0
prevnumber=0 
currnumber=1

foo=$1

for ((i=1; i<foo  ; i++))
do
	prevprevnumber=$prevnumber
	prevnumber=$currnumber
	currnumber=$(($prevprevnumber+$prevnumber))
done

echo $currnumber

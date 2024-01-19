#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <range X> <range Y>"
    exit 1
fi

range_x=$1
range_y=$2

questions=0
correct_answers=0
incorrect_answers=0

start_time=$(date +%s)

echo "Wpisz 0, aby zakonczyc quiz \n"

while true 
do
    num1=$((1 + $RANDOM % range_x))
    num2=$((1 + $RANDOM % range_y))

    read -p "$num1 * $num2 = " answer

    if [ "$answer" -le 0 ]; then
        break
    fi

    ((questions++))

    if [ "$answer" -eq "$((num1 * num2))" ]; then
        echo "Dobra odpowiedz!"
        ((correct_answers++))
    else
        echo "Zla odpowiedz"
        ((incorrect_answers++))
    fi
done

end_time=$(date +%s)
total_time=$((end_time - start_time))

echo "Zakonczono quiz"
echo "Liczba pytan: $questions"
echo "Poprawne odp: $correct_answers"
echo "Niepoprawne odp: $incorrect_answers"
echo "Czas rozwiazywania: $total_time sekund"
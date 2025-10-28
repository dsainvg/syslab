#!/bin/bash

if [ $# -lt 2 ]; then 
    echo "Usage: $0 filename regexp" 
    exit 1 
fi

pattern="(.*)($2)(.*)"
nmatch=0

while read -r line; do
    T=(); M=()
    while true; do
        if [[ ! $line =~ $pattern ]]; then
            T+=("$line")
            break
        fi
        T+=("${BASH_REMATCH[3]}")
        M+=("${BASH_REMATCH[2]}")
        line="${BASH_REMATCH[1]}"
    done
    l=$(( ${#T[@]} - 1 ))
    nmatch=$(( nmatch + 1 ))
    echo -n "${T[$l]}"
    for (( i=l-1; i>=0; --i )) do
        echo -n "[${M[$i]}]${T[$i]}"
    done
    echo
done < $1

echo "+++ Total number of matches = $((nmatch - 1))"
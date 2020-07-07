#!/bin/bash
if [ -z "$target" ]; then
    echo "NO target"
    echo $target
    exit 1
fi

targetout=$target"_out"
targetin=$target"_in"
targetcpp=$target".cpp"
targetexe=$target".out"

if [[ $# > 0 ]]; then
    if [ $1 == "vin" ]; then
	vi $targetin$2.txt
    elif [ $1 == "vout" ]; then
	vi $targetout$2.txt
    elif [ $1 == "e" ]; then
	./$targetexe
    elif [ $1 == "ed" ]; then
	if [[ $# > 1 ]]; then
	    ./$targetexe |diff $targetout$2.txt -
	else
	    ./$targetexe |diff $targetout.txt -
	fi
    elif [ $1 == "em" ]; then
	clang++ makein.cpp -o makein.out -g
    elif [ $1 == "et" ]; then
	clang++ test.cpp -o test.out -g
    elif [ $1 == "v" ]; then
	vi $targetcpp
    elif [ $1 == "vm" ]; then
	vi makein.cpp
    elif [ $1 == "vt" ]; then
	vi test.cpp
    elif [ $1 == "cm" ]; then
	clang++ makein.cpp -o makin.out -g
    elif [ $1 == "ct" ]; then
	clang++ test.cpp -o test.out -g
    fi
else
    ctags -R
    clang++ $targetcpp -o $targetexe -g
fi

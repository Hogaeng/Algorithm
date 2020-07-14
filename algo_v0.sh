#!/bin/bash
if [ -z "$target" ]; then
    echo "NO target"
    exit 1
fi

targetout=$target"_out"
targetin=$target"_in"
targetcpp=$target".cpp"
targetexe=$target".out"
makeincpp="makein.cpp"
makeinexe="makein.out"
testcpp="test.cpp"
testexe="test.out"

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
	./$makeinexe
    elif [ $1 == "et" ]; then
	./$testexe
    elif [ $1 == "v" ]; then
	vi $targetcpp
    elif [ $1 == "vm" ]; then
	vi makein.cpp
    elif [ $1 == "vt" ]; then
	vi test.cpp
    elif [ $1 == "cm" ]; then
	clang++ $makeincpp -o $makinexe -g
    elif [ $1 == "ct" ]; then
	clang++ $testcpp -o $testexe -g
    fi
else
    ctags -R
    clang++ $targetcpp -o $targetexe -g
fi

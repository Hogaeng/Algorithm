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
	echo "vi "$targetin$2".txt"
    elif [ $1 == "vout" ]; then
	echo "vi "$targetout$2".txt"
    elif [ $1 == "e" ]; then
	echo "./"$targetexe
    elif [ $1 == "ed" ]; then
	if [[ $# > 1 ]]; then
	    echo "./"$targetexe"|diff "$targetout$2".txt -"
	else
	    echo "./"$targetexe"|diff "$targetout".txt -"
	fi
    elif [ $1 == "em" ]; then
	echo "clang++ makein.cpp -o makein.out -g"
    elif [ $1 == "et" ]; then
	echo "clang++ test.cpp -o test.out -g"
    elif [ $1 == "v" ]; then
	echo "vi "$targetcpp
    elif [ $1 == "vm" ]; then
	echo "vi makein.cpp"
    elif [ $1 == "vt" ]; then
	echo "vi test.cpp"
    elif [ $1 == "cm" ]; then
	echo "clang++ makein.cpp -o makin.out -g"
    elif [ $1 == "ct" ]; then
	echo "clang++ makein.cpp -o makin.out -g"
    fi
else
    echo "ctags -R"
    echo "clang++ "$targetcpp" -o "$targetexe" -g"
fi

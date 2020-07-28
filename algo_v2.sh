#!/bin/bash
if [ -z "$target" ]; then
    echo "NO target"
    exit 1
fi
if [ -z "$targetn" ]; then
    echo "NO targetn"
    exit 1
fi

targetfol=$targetn"_"$target
targetout=$targetfol/$target"_out"
targetin=$targetfol/$target"_in"
targetfff=$targetfol/$target"."$targete
targetold=$targetfol/$target".old."$targete
makeinfff=$targetfol/"makein."$targete
testfff=$targetfol/"test."$targete

makefile(){
    if ! [ -f $2 ]; then
	echo "package "$targetfol\;>>$2
	echo "public class "$1" {">>$2
	echo "    public static void main(String args[]) {">>$2
	echo "    }">>$2
	echo "}">>$2
    fi
}

if [ "$targete" == "cpp" ]; then
    targetexe_e=".out"
elif [ "$targete" == "java" ]; then
    targetexe_e=""
elif [ "$targete" == "py" ]; then
    targetexe_e=".py"
else
    echo "NO targete"
    exit 1
fi

if ! [ -d $targetfol ]; then
    mkdir $targetfol
fi
if ! [ -f $targetfff ]; then
    if [ "$targete" == "java" ]; then
	touch $targetfff
	makefile $target $targetfff
    else
	cp format.$targete $targetfff
	if [ "$targete" == "cpp" ]; then
	    sed -i '' '3s/format/'$target'/' $targetfff
	fi
    fi
fi

targetexe=$targetfol/$target$targetexe_e
makeinexe=$targetfol/"makein"$targetexe_e
testexe=$targetfol/"test"$targetexe_e

if [[ $# > 0 ]]; then
    if [ $1 == "vin" ]; then
	vi $targetin$2.txt
    elif [ $1 == "vout" ]; then
	vi $targetout$2.txt
    elif [ $1 == "e" ]; then
	if [ "$targete" == "cpp" ]; then
	    ./$targetexe
	elif [ "$targete" == "java" ]; then
	    java $targetexe
	elif [ "$targete" == "py" ]; then
	    python3 $targetexe
	fi
    elif [ $1 == "ed" ]; then
	if [[ $# > 1 ]]; then
	    if [ "$targete" == "cpp" ]; then
		./$targetexe | diff $targetout$2.txt -
	    elif [ "$targete" == "java" ]; then
		java $targetexe | diff $targetout$2.txt -
	    elif [ "$targete" == "py" ]; then
		python3 $targetexe | diff $targetout$2.txt -
	    fi
	else
	    if [ "$targete" == "cpp" ]; then
		./$targetexe | diff $targetout.txt -
	    elif [ "$targete" == "java" ]; then
		java $targetexe | diff $targetout.txt -
	    elif [ "$targete" == "py" ]; then
		python3 $targetexe | diff $targetout.txt -
	    fi
	fi
    elif [ $1 == "em" ]; then
	if [ "$targete" == "cpp" ]; then
	    ./$makeinexe
	elif [ "$targete" == "java" ]; then
	    java $makeinexe
	elif [ "$targete" == "py" ]; then
	    python3 $makeinexe
	fi
    elif [ $1 == "et" ]; then
	if [ "$targete" == "cpp" ]; then
	    ./$testexe
	elif [ "$targete" == "java" ]; then
	    java $testexe
	elif [ "$targete" == "py" ]; then
	    python3 $testexe
	fi
    elif [ $1 == "v" ]; then
	vi $targetfff
    elif [ $1 == "l" ]; then
	ls $targetfol
    elif [ $1 == "vm" ]; then
	if [ "$targete" == "java" ]; then
	    makefile "makein" $makeinfff
	fi
	vi $makeinfff
    elif [ $1 == "vt" ]; then
	if [ "$targete" == "java" ]; then
	    makefile "test" $testfff
	fi
	vi $testfff
    elif [ $1 == "cm" ]; then
	if [ "$targete" == "cpp" ]; then
	    clang++ $makeinfff -o $makinexe -g
	elif [ "$targete" == "java" ]; then
	    javac $makeinfff
	elif [ "$targete" == "py" ]; then
	    python3 $makeinfff
	fi
    elif [ $1 == "ct" ]; then
	if [ "$targete" == "cpp" ]; then
	    clang++ $testfff -o $testexe -g
	elif [ "$targete" == "java" ]; then
	    javac $testfff
	elif [ "$targete" == "py" ]; then
	    python3 $testfff
	fi
    fi
else
    if [ "$targete" == "cpp" ]; then
	ctags -R
	clang++ $targetfff -o $targetexe -g
    elif [ "$targete" == "java" ]; then
	javac $targetfff
    elif [ "$targete" == "py" ]; then
	python3 $targetexe
    fi
fi

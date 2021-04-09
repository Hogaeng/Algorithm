#!/bin/bash
source config
if [ -z "$target" ]; then
	echo "NO target"
	exit 1
fi
if [ -z "$targetn" ]; then
	echo "NO targetn"
	exit 1
fi

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

targetfol=$targetn"_"$target
targetout=$targetfol/$target"_out"
targetin=$targetfol/$target"_in"
replace_targetin=$targetfol\\/$target"_in"
targetfff=$targetfol/$target"."$targete
if [ "$targete" == "java" ]; then
	targetfff=$targetfol/$"Main."$targete
fi
targetold=$targetfol/$target".old."$targete
if [ "$targete" == "java" ]; then
	targetold=$targetfol/$"Main.old."$targete
fi
makeinfff=$targetfol/"makein."$targete
testfff=$targetfol/"test."$targete

makefile(){
if ! [ -d $targetfol ]; then
	mkdir $targetfol
fi
if ! [ -f $targetfff ]; then
	cp format.$targete $targetfff
	sed -i "s/targetin/$replace_targetin/g" $targetfff
	sed -i "s/targetfol/$targetfol/g" $targetfff
fi
}

makefile
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
	elif [ $1 == "i" ]; then
		makefile
	elif [ $1 == "l" ]; then
		ls $targetfol
	elif [ $1 == "vm" ]; then
		vi $makeinfff
	elif [ $1 == "vt" ]; then
		vi $testfff
	elif [ $1 == "c" ]; then
		if [ "$targete" == "cpp" ]; then
			ctags -R
			clang++ $targetfff -o $targetexe -g
		elif [ "$targete" == "java" ]; then
			javac $targetfff
		elif [ "$targete" == "py" ]; then
			python3 $targetexe
		fi
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
	elif [ $1 == "g" ]; then
		if [ "$targete" == "cpp" ]; then
			lldb $targetexe
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

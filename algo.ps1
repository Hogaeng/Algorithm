./config

$targetfol=$targetn+"_"+$target
if($targete -eq "java"){
    $target="*"
}
$targetout=$targetfol+"/"+$target+"_out"
$targetin=$targetfol+"/"+$target+"_in"
$targetfff=$targetfol+"/"+$target+"."+$targete
$targetold=$targetfol+"/"+$target+".old."+$targete
$makeinfff=$targetfol+"/"+"makein."+$targete
$testfff=$targetfol+"/"+"test."+$targete

if($targete -eq "cpp"){
    $targetexe_e=".exe"
}
elseif($targete -eq "java"){
    $target="Main"
    $targetexe_e=""
}
elseif($targete -eq "python"){
    $targetexe_e=".py"
}
$targetexe=$targetfol+"/"+$target+$targetexe_e
$makeinexe=$targetfol+"/"+"makein"+$targetexe_e
$testexe=$targetfol+"/"+"test"+$targetexe_e

if($targete -eq "cpp"){
    if($args[0] -eq "c"){
        g++ $targetfff -o $targetexe -g
    }
    if($args[0] -eq "e"){
        . $targetexe
    }
}
elseif($targete -eq "java"){
    if($args[0] -eq "c"){
        javac $targetfff
    }
    if($args[0] -eq "e"){
        java $targetexe
    }
}
elseif($targete -eq "python"){

    if($args[0] -eq "e"){
        python $targetexe
    }
}
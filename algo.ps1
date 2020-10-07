./config

$targetfol=$targetn+"_"+$target

$targetout=$targetfol+"/"+$target+"_out"
$targetin=$targetfol+"/"+$target+"_in"
$targetfff=$targetfol+"/"+$target+"."+$targete
$targetold=$targetfol+"/"+$target+".old."+$targete
$makeinfff=$targetfol+"/"+"makein."+$targete
$testfff=$targetfol+"/"+"test."+$targete

$targetexe_e=".exe"
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
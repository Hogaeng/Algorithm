./config

$targetfol=$targetn+"_"+$target
$targetout=$targetfol+"/"+$target+"_out"
$targetin=$targetfol+"/"+$target+"_in"
$targetfff=$targetfol+"/"+$target+"."+$targete
if($targete -eq "java"){
    $targetfff=$targetfol+"/"+"Main."+$targete
}
$targetall=$targetfol+"/"+"*."+$targete
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

if($args[0] -eq "i"){
    if (-not(Test-Path -Path $targetfol)){
        mkdir $targetfol
    }
    if (-not(Test-Path -Path $targetfff -PathType Leaf)){
        cp format'.'$targete $targetfff
        ((Get-Content -path format'.'$targete) -replace 'targetfol',$targetfol -replace 'targetin', $targetin)  | Set-Content -Path $targetfff
    }
    if (-not(Test-Path -Path $targetin'.txt' -PathType Leaf)){
        New-Item $targetin'.txt' -type file
    }
}

if($targete -eq "cpp"){
    if($args[0] -eq "c"){
        g++ $targetfff -o $targetexe -g
    }
    elseif($args[0] -eq "e"){
        . $targetexe
    }
}
elseif($targete -eq "java"){
    if($args[0] -eq "c"){
        javac $targetfff
    }
    elseif($args[0] -eq "e"){
        java $targetexe
    }
    elseif($args[0] -eq "i"){
    }
}
elseif($targete -eq "python"){
    if($args[0] -eq "e"){
        python $targetexe
    }
}
<#
설정법:
    (어드민에서) Set-ExecutionPolicy unrestricted
    vim $profile.CurrentUserAllHosts
    > function m{ ./algo $args }
    끄고 다시 키기
#>

Set-Variable -Name "target" -Value "basic\\arraylist" -Scope global
Set-Variable -Name "targetn" -Value "" -Scope global
Set-Variable -Name "targete" -Value "java" -Scope global
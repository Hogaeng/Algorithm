<#
설정법:
    (어드민에서) Set-ExecutionPolicy unrestricted
    vim $profile.CurrentUserAllHosts
    > function m{ ./algo $args }
    끄고 다시 키기
#>
Set-Variable -Name "targetn" -Value "a" -Scope global
Set-Variable -Name "target" -Value "FENCE" -Scope global
Set-Variable -Name "targete" -Value "py" -Scope global
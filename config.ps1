<#
설정법:
    (어드민에서) Set-ExecutionPolicy unrestricted
    vim $profile.CurrentUserAllHosts
    > function m{ ./algo $args }
    끄고 다시 키기
#>

Set-Variable -Name "target" -Value "firegalaxy" -Scope global
Set-Variable -Name "targetn" -Value "forager" -Scope global
Set-Variable -Name "targete" -Value "cpp" -Scope global
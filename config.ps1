<#
설정법:
    (어드민에서) Set-ExecutionPolicy unrestricted
    vim $profile.CurrentUserAllHosts
    > function m{ ./algo $args }
    끄고 다시 키기
#>

Set-Variable -Name "target" -Value "yabdrone" -Scope global
Set-Variable -Name "targetn" -Value "17780" -Scope global
Set-Variable -Name "targete" -Value "cpp" -Scope global
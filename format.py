import os
import sys
file_cin=False
if file_cin:
    sys.stdin=open("0000_format/format_in.txt",'r')
tmp=1
if file_cin:
    tmp=input()
    tmp=int(tmp)
for i in range(0,tmp):
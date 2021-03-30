import os
import sys
file_cin=True
if file_cin:
    sys.stdin=open("2920_melody/melody_in.txt",'r')
tmp=1
if file_cin:
    tmp=input()
    tmp=int(tmp)
for i in range(0,tmp):
    li=list(map(int,input().split()))
    j=0
    answer=""
    while j<7:
        if j==0:
            if li[j]-li[j+1]==1:
                answer="descending"
            elif li[j]-li[j+1]==-1:
                answer="ascending"
            else:
                answer="mixed"
                break
        else:
            if answer=="descending":
                if li[j]-li[j+1]!=1:
                    answer="mixed"
                    break
            if answer=="ascending":
                if li[j]-li[j+1]!=-1:
                    answer="mixed"
                    break
        j+=1
    print(answer)
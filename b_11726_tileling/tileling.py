import os
import sys
#file_cin=True
file_cin=False
if __name__ == "__main__":
    if file_cin:
        sys.stdin=open("b_11726_tileling/tileling_in.txt",'r')
    tmp=1
    if file_cin:
        tmp=input()
        tmp=int(tmp)
    for i in range(0,tmp):
        t=int(input())
        a,b=1,2
        for _ in range(t-2):
            a,b=b,(a+b)%10007
        if t<2:
            print(a)
        else:
            print(b)
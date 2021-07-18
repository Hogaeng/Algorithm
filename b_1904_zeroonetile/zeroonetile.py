import os
import sys
file_cin=True
if __name__ == "__main__":    
    if file_cin:
        sys.stdin=open("b_1904_zeroonetile/zeroonetile_in.txt",'r')
    tmp=1
    if file_cin:
        tmp=input()
        tmp=int(tmp)
    for i in range(0,tmp):
        t=int(input())
        a,b=1,2
        for _ in range(t-2):
            a,b=b,(a+b)%15746
        if t<2:
            print(a)
        else :
            print(b)
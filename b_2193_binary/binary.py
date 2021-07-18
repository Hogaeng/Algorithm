import os
import sys
file_cin=False
b=[1,1]
def recur(n):
    global b
    if n<3:
        return b[n-1]
    else:
        t=-1
        if len(b)<n:
            t=recur(n-1)+recur(n-2)
            b.append(t)
        else:
            t=b[n-1]
        return t 
if __name__ == "__main__":
    if file_cin:
        sys.stdin=open("b_2193_binary/binary_in.txt",'r')
    tmp=1
    if file_cin:
        tmp=input()
        tmp=int(tmp)
    for i in range(0,tmp):
        t=int(input())
        print(recur(t))
        b=[1,1]
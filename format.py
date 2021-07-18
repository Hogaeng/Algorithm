import os
import sys
file_cin=True
if __name__ == "__main__":    
    if file_cin:
        sys.stdin=open("targetin.txt",'r')
    tmp=1
    if file_cin:
        tmp=input()
        tmp=int(tmp)
    for i in range(0,tmp):
        #Type your code here.
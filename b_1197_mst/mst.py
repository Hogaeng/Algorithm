import os
import sys
file_cin=True
if __name__ == "__main__":    
    if file_cin:
        sys.stdin=open("b_1197_mst/mst_in.txt",'r')
    tmp=1
    if file_cin:
        tmp=int(input())
    for z in range(0,tmp):
        n,m=input().split()
        dist={}
        inputTree=[[]]
        for i in range(1,n+1):
            inputTree.append([])
            dist[i]=2147483647
        for i in range(m):
            s,e,v=input().split()
            s=int(s);e=int(e);v=int(v)
            inputTree[s].append([e,v])
            inputTree[e].append([s,v])
        outputTree=[[]]
        outputTreev=[[]]
        
import os
import sys
file_cin=True
def tryit(myMap,li,n,m):
    cnt=0
    d=[[0,1],[1,0],[0,-1],[-1,0],[0,0]]
    for x,li_map in enumerate(myMap):
        for y,e in enumerate(li_map):
            letclick=False
            if x==0:
                letclick=True if li[y]==1 else False
            else:
                letclick=True if myMap[x-1][y]==1 else False
            if letclick==True:
                cnt+=1
                for z in range(5):
                    dx,dy=x+d[z][0],y+d[z][1]
                    if dx>-1 and dx<n and dy>-1 and dy<m:
                        myMap[dx][dy]=0 if myMap[dx][dy]==1 else 1
                iszero=0
                for i in range(n*m):
                    iszero+=myMap[int(i/m)][int(i%m)]
                if iszero==0:
                    return cnt
    return 123456789
def flip(myMap, n, m) :
    rperm=it.product([0,1],repeat=m)
    b=123456789
    for li in rperm:
        clone_myMap=myMap.copy()
        t=tryit(clone_myMap,list(li),n,m)
        if b>t:
            b=t
            
    if b==123456789:
        return -1
    else:
        return b

if __name__ == "__main__":    
    if file_cin:
        sys.stdin=open("forager_firegalaxy/firegalaxy_in.txt",'r')
    tmp=1
    if file_cin:
        tmp=input()
        tmp=int(tmp)
    for i in range(0,tmp):
        #Type your code here.

import os
import sys
file_cin=True
c=[]
def rcomb(lev,pivot,li,n,r,p):
    if lev==r:
        res=0
        for i in li:
            x,y=int(li[i]/p),li[i]%p
            res+=max(res,c[x][y])
        return res
    else:
        res=0
        for i in range(pivot,n):
            li.append(i)
            res=max(res,rcomb(lev+1,i+1,li,n,r,p))
            del li[-1]
        return res
if __name__ == "__main__":    
    if file_cin:
        sys.stdin=open("6_ihwa_cafe/cafe_in.txt",'r')
    tmp=1
    if file_cin:
        tmp=input()
        tmp=int(tmp)
    for z in range(0,tmp):
        k,n=input().split()
        k=int(k)
        n=int(n)
        b=[]
        for i in range(n):
            b.append(list(map(int,input().split())))
        d=[[0,0],[1,0],[1,1],[0,1]]
        for i in range(n):
            for j in range(n):
                tmp=[]
                tmp_cnt=0
                for k in range(4):
                    x,y=d[k][0],d[k][1]
                    if i+x>-1 and i+x<n and j+y>-1 and j+y<n:
                        tmp_cnt+=b[i+x][j+y]
                tmp.append(tmp_cnt)
            c.append(tmp)
        res=rcomb(0,0,[],len(c)*len(c[0]),2,len(c))
        print(res)
                    
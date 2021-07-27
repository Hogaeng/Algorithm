import os
import sys
file_cin=True
def recur(l,r,h):
    rest=0
    if l==r:
        return h[l]
    m=int((l+r)/2)
    res=max(recur(l,m,h),recur(m+1,r,h))
    ml,mr=m,m+1
    thr=min(h[ml],h[mr])
    res=max(res,thr*(mr-ml+1))
    while l<ml or mr<r:
        if mr<r and (ml==l or h[ml-1]<h[mr+1]):
            mr+=1
            thr=min(thr,h[mr])
        else:
            ml-=1
            thr=min(thr,h[ml])
        res=max(res,thr*(mr-ml+1))
    return res
def getRect(heights) :
    '''
    n개의 판자의 높이가 주어질 때, 이를 적당히 잘라 얻을 수 있는 직사각형의 최대 넓이를 반환하는 함수를 작성하세요.
    '''
    return recur(0,len(heights)-1,heights)
if __name__ == "__main__":    
    if file_cin:
        sys.stdin=open("a_FENCE/FENCE_in.txt",'r')
    tmp=1
    if file_cin:
        tmp=input()
        tmp=int(tmp)
    for i in range(0,tmp):
        #Type your code here.

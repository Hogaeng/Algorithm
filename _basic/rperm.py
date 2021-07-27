import os
cnt=0
#순열
def rperm(lev,li,n,r):
    global cnt
    if lev==r:
        c=0
        for i,e in enumerate(li):
            print(li[i],end=" ")
            c+=1
            if c>=r:
                break;
        print()
        cnt+=1
    else:
        for i in range(lev,n):
            li[lev],li[i]=li[i],li[lev]
            rperm(lev+1,li,n,r)
            li[lev],li[i]=li[i],li[lev]
#조합
def rcomb(lev,pivot,li,n,r):
    global cnt
    if lev==r:
        print(li)
        cnt+=1
    else:
        for i in range(pivot,n):
            li.append(i)
            rcomb(lev+1,i+1,li,n,r)
            del li[-1]
#중복순열(이라고 쓰고 전구놀이 라고 읽는다)
def rpi(lev,li,n,r):
    global cnt
    if lev==r:
        print(li)
        cnt+=1
    else:
        for i in range(0,n):
            li.append(i)
            rpi(lev+1,li,n,r)
            del li[-1]
#중복조합
def rhomo(lev,pivot,li,n,r):
    global cnt
    if lev==r:
        print(li)
        cnt+=1
    else:
        for i in range(pivot,n):
            li.append(i)
            rhomo(lev+1,i,li,n,r)
            del li[-1]
if __name__ == "__main__":
    n,r=4,2
    li=list(range(n))
    rperm(0,li,n,r)
    #rpi(0,[],n,r)
    #rcomb(0,0,[],n,r)
    #rhomo(0,0,[],n,r)
    print(cnt)
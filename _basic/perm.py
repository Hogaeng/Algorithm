import os
import itertools as it
if __name__ == "__main__":
    n,r=4,2
    li=list(range(n))
    '''
    perm=it.permutations(li,r)
    for i in perm:
        print(i)
    comb=it.combinations(li,r)
    for i in comb:
        print(i)
    rperm=it.product(li,repeat=r)
    for i in rperm:
        print(list(i))
    rcomb=it.combinations_with_replacement(li,r)
    for i in rcomb:
        print(i)
    '''
    for i,e in enumerate(li):
        if i<3:
            li[i+1]+=1
        print(e," ",li[i])
            
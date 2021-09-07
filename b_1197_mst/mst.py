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
        n,m=input().split()#노드, 간선
        n,m=int(n),int(m)
        dist={}
        startnode=0
        inputTree=[[]]
        outputTree=[[]]
        visited=[False]
        for i in range(1,n+1):
            inputTree.append([])
            outputTree.append([])
            visited.append(False)
        for i in range(m):
            s,e,v=input().split()
            s,e,v=int(s),int(e),int(v)
            inputTree[s].append([v,e])
            inputTree[e].append([v,s])
            startnode=s
        answer=0
        q=[[0,0,startnode]]#가중치,출발노드,도착노드
        while len(q)>0:
            v,s,e=q[0][0],q[0][1],q[0][2]
            q=q[1:]
            if visited[e]:
                continue
            visited[e]=True
            answer+=v
            if s>0:
                outputTree[s].append([v,e])
                outputTree[e].append([v,s])
            for epair in inputTree[e]:
                nv,ne=epair[0],epair[1]
                q.append([nv,e,ne])
            q.sort()
        print(answer)
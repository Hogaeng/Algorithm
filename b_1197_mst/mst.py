import sys
import heapq
file_cin=True
if __name__ == "__main__":    
    if file_cin:
        sys.stdin=open("b_1197_mst/mst_in.txt",'r')
    tmp=1
    if file_cin:
        tmp=input()
        tmp=int(tmp)
    for z in range(0,tmp):
        n,m=map(int, input().split())
        inputTree=[[] for _ in range(n+1)]
        outputTree=[[] for _ in range(n+1)]
        visited=[False for _ in range(n+1)]
        startnode=0
        for i in range(m):
            s,e,v=map(int, input().split())
            inputTree[s].append([v,e])
            inputTree[e].append([v,s])
            startnode=s
        #q=[[0,0,startnode]]
        q=[[0,startnode]]
        answer=0
        vcnt=0
        cnt=0
        while len(q)>0:
            if vcnt==n:
                break;
            #v,s,e=heapq.heappop(q)
            v,e=heapq.heappop(q)
            #print(v,s,e);print(q)
            if not visited[e]:
                visited[e]=True
                answer+=v
                vcnt+=1
                '''
                if s>0:
                    outputTree[e].append([v,s])
                    outputTree[s].append([v,e])
                '''
                for epair in inputTree[e]:
                    heapq.heappush(q,epair)
                cnt+=1
            #print(q);print()
        print(answer)
        print(cnt)
        #for output in outputTree:print(output)
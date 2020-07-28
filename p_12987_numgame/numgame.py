def solution(A, B):
    answer = 0
    aInd = len(A)-1
    bInd = len(B)-1
    bdoneInd = -1
    A.sort()
    B.sort()
    while(bInd<len(B) and bInd>-1):
        if bInd<bdoneInd:
            bInd-=1
            continue
        if B[bInd]>A[aInd]:
            answer+=1
        else:
            bdoneInd+=1
            bInd+=1
        #print(answer,aInd,bdoneInd)
        aInd-=1
        bInd-=1
        
    return answer

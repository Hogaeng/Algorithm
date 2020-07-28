from heapq import heappush, heappop,heapify
def solution(scoville, K):
    answer = 0
    heap = []
    smallest = 0
    nextsmallest = 0
    
    for item in scoville:
        heappush(heap,item)
    
    while(len(heap)>1):
        smallest = heappop(heap)
        if smallest < K:
            nextsmallest = heappop(heap)
            heappush(heap,smallest+nextsmallest*2)
            answer+=1
        else:
            heappush(heap,smallest)
            break
    if len(heap) == 1:
        answer = -1
        
    """
    append = scoville.append
    scoville.sort()
    while(True):
        if scoville[0] < K:
            if len(scoville)==1:
                answer=-1
                break
            else:
                append(scoville[0] + scoville[1]*2)
                del scoville[0]
                del scoville[0]
                answer+=1
        else:
            #answerFlag = True
            break
        scoville.sort()
    """
    return answer

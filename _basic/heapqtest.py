import heapq
from random import randrange
lst=[[3,4,5],[3,5,6],[1,3,4],[1,2,3]]
heapq.heapify(lst)
print(lst)
print(heapq.heappop(lst))
print(lst)
print(heapq.heappop(lst))
print(lst)
lst0000=[[randrange(1,10001) for _ in range(3)] for _ in range(100000)]
print('start')
for i in range(10000):
    if i%100==0:print(i)
    heapq.heapify(lst0000)
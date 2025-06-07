# Define a class that implements the __lt__ method to customize the sorting order
import heapq

class StringLength:
    def __init__(self, string):
        self.string = string

    def __lt__(self, other):
        return len(self.string) < len(other.string)


# Create a heap of strings
heap = []
heapq.heappush(heap, StringLength("apple"))
heapq.heappush(heap, StringLength("banana"))
heapq.heappush(heap, StringLength("cherry"))
heapq.heappush(heap, StringLength("date"))
heapq.heappush(heap, StringLength("elderberry"))
heapq.heappush(heap, StringLength("fig"))
heapq.heappush(heap, StringLength("grape"))
heapq.heappush(heap, StringLength("honeydew"))
heapq.heappush(heap, StringLength("kiwi"))
heapq.heappush(heap, StringLength("lemon"))

# Pop elements from the heap
while heap:
    print(heapq.heappop(heap).string)

"""
The output will be:
fig
date
kiwi
grape
lemon
apple
cherry
banana
honeydew
elderberry
"""
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freqs = [0]*26
        for t in tasks:
            freqs[ord(t) - ord('A')] +=1
        max_freq = max(freqs)
        max_freq_count = 0
        for f in freqs:
            if f == max_freq:
                max_freq_count +=1
        
        return max((n+1)*(max_freq-1)+max_freq_count, len(tasks))
    """
    https://medium.com/@satyem77/task-scheduler-leetcode-39d579f3440
    https://leetcode.com/problems/task-scheduler/solutions/104496/python-solution-with-greedy-and-heapq-python-3/
    """
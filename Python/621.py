class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        freq = [0]*26
        for t in tasks:
            freq[ord(t)-ord('A')] +=1
        m_freq = max(freq)
        m_cnt = freq.count(m_freq)
        predict = (m_freq-1)*n + m_freq + m_cnt-1
        return max(predict, len(tasks))

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        step = len(s)
        s_count = collections.Counter(s)
        t_count = collections.Counter(t)
        for key, val in s_count.items():
            step -= min(val, t_count[key])
        return step

class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0]*n
        stack = [] # (id, time)
        for log in logs:
            items = log.split(':')
            id, state, time = int(items[0]), items[1], int(items[2])
            if state == "start":
                stack.append((id, time))
            else:
                time_spent = time - stack[-1][1] + 1
                res[id] += time_spent
                stack.pop()
                if stack:
                    prev_id = stack[-1][0]
                    res[prev_id] -= time_spent
        return res

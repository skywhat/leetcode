class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        to_routes = collections.defaultdict(list)

        for i, route in enumerate(routes):
            for stop in route:
                to_routes[stop].append(i)
        
        step = 0
        q = deque([source])
        seen = set([source])
        while q:
            size = len(q)
            for _ in range(size):
                stop = q.popleft()
                if stop == target:
                    return step
                for next_route in to_routes[stop]:
                    for next_stop in routes[next_route]:
                        if next_stop in seen:
                            continue
                        q.append(next_stop)
                        seen.add(next_stop)
                    # we tried this route, stop trying this route to save time
                    routes[next_route] = []
            step +=1
        return -1


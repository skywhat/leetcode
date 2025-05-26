class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        graph = collections.defaultdict(list)
        n = len(parents)
        # build graph containing child for every node
        for i in range(1, n):
            graph[parents[i]].append(i)
        
        score_count = collections.defaultdict(int)

        def count_node(node):
            product = 1
            total = 0
            for child in graph[node]:
                total_child = count_node(child)
                product *= total_child
                total += total_child
            # product the last value coming from up-root subtree, but it might be non-existing.
            product *= max(1, n-1-total)
            score_count[product] +=1
            # return the total number of nodes for the tree rooting froom `node`
            return total + 1
        count_node(0)
        max_score = max(score_count.keys())
        return score_count[max_score]


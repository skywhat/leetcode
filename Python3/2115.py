class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        graph = defaultdict(list)
        supset = set(supplies)
        n = len(recipes)
        indegree = defaultdict(int)
        # the graph is missing item => recipe
        # when indegree[missing item] == 0, represents the item is ready for the dependent recipe
        for i, recipe in enumerate(recipes):
            for item in ingredients[i]:
                if item not in supset:
                    graph[item].append(recipe)
                    indegree[recipe] +=1
        
        q = deque()
        # it accumulates the recipe with sufficient supplies, which means their indegree == 0
        for recipe in recipes:
            if indegree[recipe] == 0:
                q.append(recipe)
        
        res = []
        while q:
            item = q.popleft()
            res.append(item)
            for next in graph[item]:
                indegree[next] -=1
                if indegree[next] == 0:
                    q.append(next)
        return res

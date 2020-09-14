#dfs
class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.elems = []
        def dfs(ls):
            for l in ls:
                if l.isInteger():
                    self.elems.append(l.getInteger())
                else:
                    dfs(l.getList())
        dfs(nestedList)
        self.pos = -1

    def next(self):
        """
        :rtype: int
        """
        self.pos +=1
        return self.elems[self.pos]


    def hasNext(self):
        """
        :rtype: bool
        """
        return self.pos < len(self.elems) -1


#stack
class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.elems = []
        for i in range(len(nestedList)-1, -1, -1):
            self.elems.append(nestedList[i])


    def next(self):
        """
        :rtype: int
        """
        l = self.elems.pop()
        return l.getInteger()


    def hasNext(self):
        """
        :rtype: bool
        """
        while self.elems:
            l = self.elems[-1]
            if l.isInteger():
                return True
            self.elems.pop()
            ls = l.getList()
            for i in range(len(ls)-1, -1, -1):
                self.elems.append(ls[i])
        return False

class SQL:

    def __init__(self, names: List[str], columns: List[int]):
        self.t = {}
        self.ids = {}
        self.ncolumns = {}
        for i, name in enumerate(names):
            self.ncolumns[name] = columns[i]
            self.t[name] = {}
            self.ids[name] = 1

    def ins(self, name: str, row: List[str]) -> bool:
        if name not in self.t:
            return False
        if len(row) != self.ncolumns[name]:
            return False
        avail_id = self.ids[name]
        self.ids[name] +=1
        self.t[name][avail_id] = row
        return True

    def rmv(self, name: str, rowId: int) -> None:
        if name not in self.t:
            return
        if rowId not in self.t[name]:
            return
        del self.t[name][rowId]
        return

    def sel(self, name: str, rowId: int, columnId: int) -> str:
        if name not in self.t:
            return "<null>"
        if rowId not in self.t[name]:
            return "<null>"
        if columnId -1 >= self.ncolumns[name]:
            return "<null>"
        return self.t[name][rowId][columnId-1]

    def exp(self, name: str) -> List[str]:
        if name not in self.t:
            return []
        rowids = sorted(self.t[name])
        res = []
        for rowid in rowids:
            res.append(str(rowid)+"," + ",".join(self.t[name][rowid]))
        return res


# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# param_1 = obj.ins(name,row)
# obj.rmv(name,rowId)
# param_3 = obj.sel(name,rowId,columnId)
# param_4 = obj.exp(name)

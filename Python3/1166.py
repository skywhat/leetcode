class FileSystem:

    def __init__(self):
        self.m = {}

    def createPath(self, path: str, value: int) -> bool:
        items = path.strip('/').split('/')
        prefix = ""
        for i in range(len(items)-1):
            if prefix != "":
                prefix += "/"
            prefix += items[i]
            if prefix not in self.m:
                return False
        prefix = prefix + "/" + items[-1] if len(items) > 1 else items[-1]
        if prefix in self.m:
            return False
        self.m[prefix] = value
        return True



    def get(self, path: str) -> int:
        new_path = path.strip('/')
        return self.m.get(new_path, -1)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)

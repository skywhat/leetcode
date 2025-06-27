class Logger:

    def __init__(self):
        self.hashmap = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self.hashmap:
            self.hashmap[message] = timestamp
            return True
        
        if self.hashmap[message] + 10 > timestamp:
            return False
        self.hashmap[message] = timestamp
        return True

# time complexity: O(1)
# space complexity: O(n) n is the number of unique messages

# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)


class Logger:

    def __init__(self):
        self.t = [0]*10
        self.sets = [set() for _ in range(10)]

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        idx = timestamp % 10
        if self.t[idx] != timestamp:
            self.t[idx] = timestamp
            self.sets[idx].clear()
        
        for i in range(10):
            if message in self.sets[i]:
                if self.t[i] + 10 > timestamp:
                    return False
        
        self.sets[idx].add(message)
        return True

# time complexity: O(1)
# space complexity: it will remove the message at timestamp % 10, so ideally you only store messages from the last 10 seconds.
# So the space complexity is O(m), m is the number of unique messages in the last 10 seconds.


class Logger:

    def __init__(self):
        self.old = {}
        self.new = {}
        self.time_new = 0

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if self.time_new + 20 <= timestamp:
            self.old = {}
            self.new = {}
            self.time_new = timestamp
        elif self.time_new + 10 <= timestamp:
            self.old = self.new.copy()
            self.new = {}
            self.time_new = timestamp
        
        if message in self.new:
            return False
        if message in self.old and self.old[message] + 10 > timestamp:
            return False
        self.new[message] = timestamp 
        return True


# ["Logger","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage"]

# [[],[1,"foo"],[2,"bar"],[3,"foo"],[8,"bar"],[10,"foo"],[11,"foo"],[15,"foo"],[24,"foo"],[33,"bar"],[34,"bar"]]

# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)

# current message: foo at timestamp: 1 => True
# new_map: {'foo': 1}
# old_map {}
# time_new 1
# current message: bar at timestamp: 2 => True
# new_map: {'foo': 1, 'bar': 2}
# old_map {}
# time_new 1
# current message: foo at timestamp: 3 => False
# new_map: {'foo': 1, 'bar': 2}
# old_map {}
# time_new 1
# current message: bar at timestamp: 8 => False
# new_map: {'foo': 1, 'bar': 2}
# old_map {}
# time_new 1
# current message: foo at timestamp: 10 => False
# new_map: {'foo': 1, 'bar': 2}
# old_map {}
# time_new 1
# current message: foo at timestamp: 11 => True
# new_map: {'foo': 11}
# old_map {'foo': 1, 'bar': 2}
# time_new 11
# current message: foo at timestamp: 15 => False
# new_map: {'foo': 11}
# old_map {'foo': 1, 'bar': 2}
# time_new 11
# current message: foo at timestamp: 24 => True
# new_map: {'foo': 24}
# old_map {'foo': 11}
# time_new 24
# current message: bar at timestamp: 33 => True
# new_map: {'foo': 24, 'bar': 33}
# old_map {'foo': 11}
# time_new 24
# current message: bar at timestamp: 34 => False
# new_map: {}
# old_map {'foo': 24, 'bar': 33}
# time_new 34

# time_new: the start time of the current 10-second window
# old_map: the messages in the last 10-second window [time_new, time_new + 10]
# new_map: the messages in the current 10-second window [time_new -10, time_new]
# when the current 10-second window is over, we will clear the new_map and set the time_new to the start time of the next 10-second window
# and we will copy the old_map to the new_map
# and we will add the message to the new_map
# and we will return True if the message is not in the new_map and the message is not in the old_map or the message is in the old_map and the timestamp is greater than the timestamp of the message in the old_map + 10
# and we will return False otherwise

# time complexity: O(1)
# space complexity: O(m) m is the number of unique messages in the last 20 seconds.
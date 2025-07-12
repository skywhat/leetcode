class Subscription:
    def __init__(self, unsubscribe_callback):
        self.callback = unsubscribe_callback

    def unsubscribe(self):
        self.callback(self)


class Subject:
    def __init__(self):
        self.mapping = {}
    
    def publish(self, value):
        for callback in self.mapping.values():
            callback(value)
    
    def _unsubscribe(self, subscription):
        self.mapping.pop(subscription)

    def subscribe(self, callback):
        subscription = Subscription(self._unsubscribe)

        self.mapping[subscription] = callback
        return subscription



if __name__ == "__main__":
    subject = Subject()
    subscription1 = subject.subscribe(lambda x: print(x))
    subscription2 = subject.subscribe(lambda x:print(x+10))
    print("print 1 and 11")
    subject.publish(1)
    print("print 12 after unsubscribe subscription1")
    subscription1.unsubscribe()
    subject.publish(2)
    subscription2.unsubscribe()
    print("print nothing after unsubscribe subscription2")
    subject.publish(3)
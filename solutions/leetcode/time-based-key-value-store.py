class TimeMap:
    def __init__(self):
        self.store = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.store:
            self.store[key]  = []
        self.store[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store or self.store[key][0][0] > timestamp:
            return ""
        l = 0
        r = len(self.store[key])
        while l < r:
            m = (l + r) // 2
            curr = self.store[key][m][0]
            if curr <= timestamp:
                l = m + 1
            else:
                r = m
        return self.store[key][r - 1][1]

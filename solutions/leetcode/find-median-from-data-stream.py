from queue import PriorityQueue

class MedianFinder:
  def __init__(self):
    self.l, self.r = PriorityQueue(), PriorityQueue()
    self.median = None
    
  def addNum(self, num: int) -> None:
    if self.median == None:
      self.median = num
      self.l.put(-1 * num)
    else:
      self.l.put(-1 * num)
      self.r.put(-1 * self.l.get())
      if self.r.qsize() > self.l.qsize():
        self.l.put(-1 * self.r.get())
     
      l = self.l.get()
      if self.l.qsize() + 1 == self.r.qsize():
        r = self.r.get()
        self.median = (-1 * l + r) / 2
        self.r.put(r)
      else:
        self.median = -1 * l
      self.l.put(l)
    print(self.median)

  def findMedian(self) -> float:
    return self.median

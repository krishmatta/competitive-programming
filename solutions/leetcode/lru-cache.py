class Node:
  def __init__(self, key, value):
    self.key = key
    self.value = value
    self.back = None
    self.front = None

class LRUCache:
  def __init__(self, capacity: int):
    self.capacity = capacity
    self.sz = 0
    self.head = None
    self.tail = None
    self.dict = {}

  def remove_node(self, node):
    del self.dict[node.key]
    
    if self.head == node:
      self.head = node.front
    else:
      node.back.front = node.front
      
    if self.tail == node:
      self.tail = node.back
    else:
      node.front.back = node.back
    self.sz -= 1

  def insert_node(self, node):
    self.dict[node.key] = node
    if self.head == None:
      self.head = node
      self.tail = node
    else:
      node.back = self.tail
      self.tail.front = node
      self.tail = node
    self.sz += 1

  def get(self, key: int) -> int:
    if key not in self.dict:
      return -1
    curr = self.dict[key]
    self.remove_node(curr)
    self.insert_node(curr)
    return curr.value
    

  def put(self, key: int, value: int) -> None:
    curr = Node(key, value)
    if key in self.dict:
      self.remove_node(self.dict[key])
    self.insert_node(curr)
    if self.sz > self.capacity:
      self.remove_node(self.head)

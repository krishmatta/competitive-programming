from queue import PriorityQueue

class Node:
  def __init__(self, item):
    self.item = item
  def __lt__(self, other):
    return self.item.val < other.item.val

class Solution:
  def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    pq = PriorityQueue()
    for list in lists:
      if list is not None:
        pq.put(Node(list))

    ret = ListNode(-1)
    curr = ret
    while not pq.empty():
      now = pq.get().item
      if now.next is not None:
        pq.put(Node(now.next))
      now.next = None
      curr.next = now
      curr = now
    return ret.next

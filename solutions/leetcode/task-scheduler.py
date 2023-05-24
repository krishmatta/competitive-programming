from queue import PriorityQueue

class Solution:
  def leastInterval(self, tasks: List[str], n: int) -> int:
    freq = {}
    for task in tasks:
      if task not in freq:
        freq[task] = 0
      freq[task] += 1

    pq = PriorityQueue()
    for task in freq:
      pq.put((-freq[task], 1))

    time = 0
    while not pq.empty():
      time += 1
      count, cooldown = pq.get()
      if time < cooldown:
        time = cooldown

      if count < -1:
        cooldown = time + n + 1
        add = [(count + 1, cooldown)]
        for _ in range(n):
          if pq.empty():
            break
          new_count, new_cooldown = pq.get()
          time += 1
          if new_count < -1:
            add.append((new_count + 1, time + n + 1))
        for elem in add:
          pq.put(elem)
    return time

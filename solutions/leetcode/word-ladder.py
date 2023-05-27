from queue import Queue

class Solution:
  def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    wordList = set(wordList)
    
    vis = set([beginWord])
    
    q = Queue()
    q.put((1, beginWord))
    
    while not q.empty():
      n, curr = q.get()
      for i in range(len(curr)):
        for letter in alphabet:
          next = curr[:i] + letter + curr[i+1:]
          if next in wordList:
            if next == endWord:
              return n + 1
            if next not in vis:
              vis.add(next)
              q.put((n + 1, next))
    return 0

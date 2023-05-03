class Solution:
  def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    vis = set()
    vis.add((0, 0))
    def is_valid(r, c):
      if r < 0 or r >= len(matrix) or c < 0 or c >= len(matrix[0]) or (r, c) in vis:
        return False
      return True

    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    dir = 0
  
    ret = [matrix[0][0]]
    curr = (0, 0)
    num_vis = 1
    while num_vis < len(matrix) * len(matrix[0]):
      next = (curr[0] + dirs[dir][0], curr[1] + dirs[dir][1])
      if is_valid(*next):
        num_vis += 1
        vis.add(next)
        ret.append(matrix[next[0]][next[1]])
        curr = next
      else:
        dir = (dir + 1) % 4

    return ret

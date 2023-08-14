from queue import Queue

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        vis = set() # i, j, num
        q = Queue()
        q.put((0, 0, k, 0))
        vis.add((0, 0, k))
        while not q.empty():
            i, j, obs, length = q.get()
            if i == len(grid) - 1 and j == len(grid[0]) - 1:
                return length
            for di, dj in dirs:
                ni = i + di
                nj = j + dj
                if ni >= 0 and nj >= 0 and ni < len(grid) and nj < len(grid[0]):
                    if grid[ni][nj] and obs > 0 and (ni, nj, obs - 1) not in vis:
                        vis.add((ni, nj, obs - 1))
                        q.put((ni, nj, obs - 1, length + 1))
                    if not grid[ni][nj] and (ni, nj, obs) not in vis:
                        vis.add((ni, nj, obs))
                        q.put((ni, nj, obs, length + 1))
        return -1

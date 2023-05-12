class Solution:
  def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
    ret = []

    def solve(curr, lvl):
      if curr == None:
          return
      if lvl >= len(ret):
        ret.append(curr.val)
      solve(curr.right, lvl + 1)
      solve(curr.left, lvl + 1)

    solve(root, 0)

    return ret

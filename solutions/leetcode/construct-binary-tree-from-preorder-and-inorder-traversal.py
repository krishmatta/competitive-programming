class Solution:
  def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    def solve(preord, inord):
      if len(preord) == 0 or len(inord) == 0:
        return None
      root = inord.index(preord[0])
      inordL = inord[:root]
      inordR = inord[root+1:]
      preordL = preord[1:len(inordL)+1]
      preordR = preord[len(inordL)+1:]
      return TreeNode(preord[0], solve(preordL, inordL), solve(preordR, inordR))
      
    return solve(preorder, inorder)

class Solution:
  def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    def countNodes(root):
      if root == None:
        return 0
      l = countNodes(root.left)
      r = countNodes(root.right)
      return l + r + 1

    def countTree(root):
      if root == None:
        return None
      curr = countNodes(root)
      return TreeNode(curr, countTree(root.left), countTree(root.right))

    def helper(root, countRoot, k):
      if countRoot.left == None:
        l = 0
      else:
        l = countRoot.left.val
      
      if countRoot.right == None:
        r = 0
      else:
        r = countRoot.right.val

      if k <= l:
        return helper(root.left, countRoot.left, k)
      elif k == l + 1:
        return root.val
      else:
        return helper(root.right, countRoot.right, k - l - 1)
      
    count = countTree(root)
    return helper(root, count, k)

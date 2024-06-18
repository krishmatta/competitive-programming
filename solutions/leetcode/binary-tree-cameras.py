class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        def fill(curr):
            if curr != None:
                fill(curr.left)
                fill(curr.right)
                curr.val = {}
        fill(root)
        def solve(curr, need_camera, has_cover):
            if curr == None:
                if need_camera:
                    return int(1e9)
                return 0
            if (need_camera, has_cover) not in curr.val:
                # Place camera
                ret = [1 + solve(curr.left, False, True) + solve(curr.right, False, True)]
                if not need_camera:
                    # Don't place camera, but need a subtree to have camera
                    ret.append(solve(curr.left, True, False) + solve(curr.right, False, False))
                    ret.append(solve(curr.left, False, False) + solve(curr.right, True, False))
                    # Don't place camera, don't need subtree to have camera
                    if has_cover:
                        ret.append(solve(curr.left, False, False) + solve(curr.right, False, False))
                curr.val[(need_camera, has_cover)] = min(ret)
            return curr.val[(need_camera, has_cover)]
        return solve(root, False, False)

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ppth = None
        qpth = None
        if root.val == p.val:
            ppth = [root]
        if root.val == q.val:
            qpth = [root]
        qu = []
        qu.append([root, [root]])
        while len(qu) and (not ppth or not qpth):
            curr = qu.pop(0)
            if curr[0].left:
                npth = curr[1][:]
                npth.append(curr[0].left)
                if curr[0].left.val == p.val or curr[0].left.val == q.val:
                    if curr[0].left.val == q.val:
                        qpth = npth
                    if curr[0].left.val == p.val:
                        ppth = npth
                qu.append([curr[0].left, npth])
            if curr[0].right:
                npth = curr[1][:]
                npth.append(curr[0].right)
                if curr[0].right.val == p.val or curr[0].right.val == q.val:
                    if curr[0].right.val == q.val:
                        qpth = npth
                    if curr[0].right.val == p.val:
                        ppth = npth
                qu.append([curr[0].right, npth])
        ret = root.val
        for x in range(min(len(ppth), len(qpth))):
            if ppth[x].val == qpth[x].val:
                ret = ppth[x]
        return ret

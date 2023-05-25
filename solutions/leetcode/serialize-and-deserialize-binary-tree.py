from queue import Queue

class Codec:
  def serialize(self, root):
    q = Queue()
    ret = []

    q.put(root)
    while not q.empty():
      curr = q.get()
      if curr is None:
        ret.append(None)
      else:
        ret.append(curr.val)
        q.put(curr.left)
        q.put(curr.right)
    print(ret)
    return str(ret)

  def deserialize(self, data):
    data = [None if x == "None" else int(x) for x in data[1:-1].split(', ')]
    if data[0] == None:
      return None
    tokens = Queue()
    for x in data:
      tokens.put(x)
    process = Queue()
    root = TreeNode(tokens.get())
    process.put(root)
    while not process.empty():
      curr = process.get()
      if not tokens.empty():
        l = tokens.get()
        if l is not None:
          l = TreeNode(l)
          curr.left = l
          process.put(l)
      if not tokens.empty():
        r = tokens.get()
        if r is not None:
          r = TreeNode(r)
          curr.right = r
          process.put(r)
    return root

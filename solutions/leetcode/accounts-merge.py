class Solution:
  def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
    parent = {}
    size = {}
    def find_set(v):
      if v != parent[v]:
        parent[v] = find_set(parent[v])
      return parent[v]

    def make_set(v):
      parent[v] = v
      size[v] = 1

    def union_sets(a, b):
      a = find_set(a)
      b = find_set(b)
      if a != b:
        if size[a] < size[b]:
          b, a = a, b
        parent[b] = a
        size[a] += size[b]

    name = {}
                    
    for account in accounts:
      curr = None
      print(curr)
      for email in account[1:]:
        name[email] = account[0]
        if email in parent:
          nxt = find_set(email)
          if curr is not None:
            union_sets(curr, nxt)
          curr = nxt
        else:
          make_set(email)
          if curr is None:
            curr = email
          else:
            union_sets(curr, email)

    groups = {}
    for email in parent:
      curr_set = find_set(email)
      if curr_set not in groups:
        groups[curr_set] = []
      groups[curr_set].append(email)
      
    ret = []
    for group in groups:
      curr = sorted(groups[group])
      ret.append([name[group]] + curr)
    return ret

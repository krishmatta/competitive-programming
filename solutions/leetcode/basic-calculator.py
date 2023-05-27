class Solution:
  def calculate(self, s: str) -> int:
    ops = ["(", ")", "+", "-"]
    def process(s):
      s = s.replace(" ", "")
      ret = []
      prev = 0
      for i, digit in enumerate(s):
        if digit in ops:
          if prev < i:
            ret.append(s[prev:i])
          ret.append(digit)
          prev = i + 1
      if prev < len(s):
        ret.append(s[prev:])
      return ret

    frame = [(0, "+")]
    expr = process(s)
    for i in range(len(expr)):
      curr = expr[i]
      if curr in ops:
        if curr == "(":
          frame.append((0, "+"))
        if curr == ")":
          last = frame.pop()
          nxt = frame.pop()
          if nxt[1] == "+":
            nxt = (nxt[0] + last[0], "+")
          else:
            nxt = (nxt[0] - last[0], "-")
          frame.append(nxt)
        if curr == "+":
          last = frame.pop()
          frame.append((last[0], "+"))
        if curr == "-":
          last = frame.pop()
          frame.append((last[0], "-"))
      else:
        top = frame.pop()
        nxt = top[0]
        if top[1] == "+":
          nxt += int(curr)
        else:
          nxt -= int(curr)
        frame.append((nxt, "+"))
    return frame[0][0]

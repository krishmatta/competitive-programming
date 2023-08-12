class Solution:
  def maxProfit(self, prices: List[int]) -> int:
      backwards = [0 for _ in range(len(prices))]
      backwards.append(0);
      curr_max = 0
      curr_min = int(1e5)+1
      for i in range(len(prices) - 1, -1, -1):
          if prices[i] > curr_max:
              curr_max = prices[i]
              curr_min = prices[i]
          if prices[i] < curr_min:
              curr_min = prices[i]
          backwards[i] = curr_max - curr_min
          backwards[i] = max(backwards[i], backwards[i + 1])
      backwards.append(0)

      forwards = [0 for _ in range(len(prices))]
      curr_max = 0
      curr_min = int(1e5)+1
      for i in range(len(prices)):
          if prices[i] > curr_max:
              curr_max = prices[i]
          if prices[i] < curr_min:
              curr_max = prices[i]
              curr_min = prices[i]
          forwards[i] = curr_max - curr_min
          if i > 0:
              forwards[i] = max(forwards[i], forwards[i - 1])
          
      ret = 0
      for i in range(len(prices)):
          ret = max(ret, forwards[i] + backwards[i + 1])
      return ret

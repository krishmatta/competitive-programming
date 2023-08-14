class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        freq = [0 for _ in range(2*int(1e4)+2)]
        for x in nums:
            freq[x + int(1e4) + 1] += 1
        for i in range(len(freq) - 1, -1, -1):
            k -= freq[i]
            if k <= 0:
                return i - int(1e4) - 1
        return -1

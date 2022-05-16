class Solution(object):
    def isPalindrome(self, s):
        s = re.sub(r'[^a-zA-Z0-9]', '', s)
        s = s.lower()

        l, r = 0, len(s) - 1
        while(l < r):
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

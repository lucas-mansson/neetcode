class Solution:
    def isPalindrome(self, s: str) -> bool:
        if len(s) == 1 or len(s) == 0:
            return True
            
        s = s.lower()
        left = 0
        right = len(s) - 1

        while left < right:
            leftChar = s[left]
            rightChar = s[right]

            if not leftChar.isalnum():
                left += 1
                continue
            if not rightChar.isalnum():
                right -= 1
                continue

            if leftChar != rightChar:
                return False
            left += 1
            right -= 1

        return True 
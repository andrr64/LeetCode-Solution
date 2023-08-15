"""
url : https://leetcode.com/problems/reverse-integer
"""
# class Solution:
#     def reverse(self, x: int) -> int:
#         negative = x < 0
#         result = 0

#         if negative:
#             x *= -1

#         exp = self.nNumber(x) - 1
#         bonjoour = 0

#         while exp >= 0:
#             real_ = x // (10 ** exp)
#             x -= (real_ * 10 ** exp)
#             real_ *= (10 ** bonjoour)            
#             result += real_

#             bonjoour += 1
#             exp -= 1

#         if negative:
#             result *= -1
#         return result
    
#     def nNumber(self, number):
#         x = 1
#         n = 0
#         while (number / x >= 1):
#             n += 1
#             x *= 10
#         return n

class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        
        result = 0
        negative = x < 0
        
        if negative:
            x *= -1
        
        while x != 0:
            pop = x % 10
            x //= 10
            
            if result > INT_MAX // 10 or (result == INT_MAX // 10 and pop > 7):
                return 0
            
            if result < INT_MIN // 10 or (result == INT_MIN // 10 and pop < -8):
                return 0
            
            result = result * 10 + pop
        
        if negative:
            result *= -1
        
        return result

sol = Solution()
print(sol.reverse(1534236469))

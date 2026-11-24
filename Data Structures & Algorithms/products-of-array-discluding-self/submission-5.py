class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zeroIndices = []
        productOfAllExceptZero = 1
        for i, num in enumerate(nums):
            if num != 0:
                productOfAllExceptZero *= num
            else:
                zeroIndices.append(i)
        

        result = [0] * len(nums)

        if len(zeroIndices) > 1:
            return result
        
        if len(zeroIndices) == 1:
            result[zeroIndices[0]] = productOfAllExceptZero
            return result
        

        for i, num in enumerate(nums):
            if num != 0:
                result[i] = productOfAllExceptZero // num

        return result
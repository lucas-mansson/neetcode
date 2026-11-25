class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        valToIdx = {}

        for i, num in enumerate(nums):
            valToIdx[num] = i
        
        for i, num in enumerate(nums):
            diff = target - num
            if diff in valToIdx: 
                otherIdx = valToIdx[diff]
                if otherIdx == i:
                    continue

                return [
                    min(i, otherIdx),
                    max(i, otherIdx)
                ]

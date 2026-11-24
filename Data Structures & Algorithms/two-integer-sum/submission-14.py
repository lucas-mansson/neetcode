class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Map each value to the index
        valToIdx = {}
        for i, val in enumerate(nums):
            valToIdx[val] = i
        
        print(valToIdx)

        # For each value in the list, check if the 
        for i, val in enumerate(nums):
            diff = target - val
            print(diff)
            if diff in valToIdx:
                other = valToIdx[diff]
                if (other == i):
                    continue
                return [min(other, i), max(other, i)]
        
        
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequencies = {}
        for num in nums:
            if num not in frequencies:
                frequencies[num] = 1
            else:
                frequencies[num] += 1
        
        arr = []
        for num, count in frequencies.items():
            arr.append([count, num])
        arr.sort()
        
        result = []
        while len(result) < k:
            result.append(arr.pop()[1])
        return result


        #return sorted(list(frequencies), reverse=True)[:k]
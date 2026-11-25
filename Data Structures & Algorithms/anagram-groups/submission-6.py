class Solution:
    """
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        for s in strs:
            sortedStr = "".join(sorted(s))
            res[sortedStr].append(s)
        
        return list(res.values())
        """

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        group = {}
        for word in strs:
            currCharCount = [0] * 26
            for c in word:
                currCharCount[ord(c) - ord('a')] += 1
            
            currCharCountTuple = tuple(currCharCount)
            if currCharCountTuple in group:
                group[currCharCountTuple].append(word)
            else:
                group[currCharCountTuple] = [word]
        return list(group.values())
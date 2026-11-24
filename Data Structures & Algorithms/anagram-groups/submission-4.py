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
        res = defaultdict(list)

        for s in strs:
            sortedStr = "".join(sorted(s))
            res[sortedStr].append(s)
        
        return list(res.values())
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s)==0:
            return 0
        prevIndex = {
            s[0]:0
        }
        result = [1]
        maxlen = 1
        for i,c in enumerate(s[1:]):
            last_res = result[-1]
            if prevIndex.get(c,-1) == -1:
                result.append(last_res+1)
            else:
                result.append(min(i+1-prevIndex[c],last_res+1))
            prevIndex[c] = i+1
            if result[-1] >= maxlen:
                maxlen = result[-1]
        
        return maxlen

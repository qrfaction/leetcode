class Solution:
    
    def longestPalindrome(self, s: str) -> str:
        
        if len(s) <= 1:
            return s
        
        s = '@#' + '#'.join(list(s)) + '#$' 
        p = [0]
        
        maxstr = '@'
        center_i = 0
        bound = 0
        for i in range(1,len(s)-1):
            
            if i < bound:
                p.append(min(bound-i,p[2*center_i-i]))
            else:
                p.append(0)
            while s[i-p[i]-1] == s[i+p[i]+1]:
                p[i] += 1
            
            if i + p[i] > bound:
                center_i = i
                bound = i + p[i]
            
            if 2*p[i]+1>len(maxstr):
                maxstr = s[i-p[i]:i+p[i]+1]

        return maxstr.replace("#","")

class Solution(object):
    def lengthOfLastWord(self, s):
        if len(s)==0 or s.isspace():
            return 0
        else:
            l = list(s.split())
            return len(l[-1])
        """
        :type s: str
        :rtype: int
        """
        

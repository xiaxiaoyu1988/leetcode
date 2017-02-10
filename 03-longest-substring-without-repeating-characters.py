class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        tmp = []
        res = 0
        # print '--------------------------------------------'
        for i in s:
            # print 'begin ', i, tmp, len(tmp), res
            res = max(res, len(tmp))
                
            if i in tmp:
                # print i, " in tmp"
                while i in tmp:
                    tmp = tmp[tmp.index(i)+1:]
                    # print i, 'in tmp ', tmp
            tmp.append(i)
            
        return max(res, len(tmp))
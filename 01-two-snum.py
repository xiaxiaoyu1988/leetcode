class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            last = nums[i]
            # print last
            for j, num in enumerate(nums[i+1:]):
                # print j, num
                if last + num == target:
                    return [i,i+1+j]
                
            
        
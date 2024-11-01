class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]

        # A helper function to do the robbing for a linear street of houses
        def rob_linear(houses):
            prev1, prev2 = 0, 0
            for money in houses:
                temp = prev1
                prev1 = max(prev1, prev2 + money)
                prev2 = temp
            return prev1

        # Case 1: Rob houses from 0 to n-2
        case1 = rob_linear(nums[:-1])
        # Case 2: Rob houses from 1 to n-1
        case2 = rob_linear(nums[1:])

        # Return the maximum of the two cases
        return max(case1, case2)
        
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def rob_linear(houses):
            # Base cases for no houses and a single house, respectively
            if not houses:
                return 0
            if len(houses) == 1:
                return houses[0]
            # Create a DP array where dp[i] will be the max amount that can be robbed up to house i
            dp = [0] * len(houses)
            dp[0] = houses[0]
            dp[1] = max(houses[0], houses[1])

            # Fill in the DP table
            for i in range(2, len(houses)):
                # Take the maximum of robbing the current house plus the max value two houses back,
                # or not robbing the current house and just taking the max value from the previous house
                dp[i] = max(dp[i-1], dp[i-2] + houses[i])

            # The max value at the last house is the result
            return dp[-1]

        # Edge case: If there's only one house, we can rob it without worry
        if len(nums) == 1:
            return nums[0]

        # Use rob_linear function to calculate the max money we can rob in each sub-problem
        # Rob houses from `0 to n-2`
        money1 = rob_linear(nums[:-1])
        # Rob houses from `1 to n-1`
        money2 = rob_linear(nums[1:])

        # Return the maximum money of the two linear sub-problems
        return max(money1, money2)
        
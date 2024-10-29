/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    // Initialize the farthest we can reach as 0
    let maxReachable = 0;
    
    // Iterate through the array
    for (let i = 0; i < nums.length; i++) {
        // If the current index is greater than the maximum reachable index, return false
        if (i > maxReachable) {
            return false;
        }
        // Update the maximum reachable index
        maxReachable = Math.max(maxReachable, i + nums[i]);
        
        // If we can reach or exceed the last index, return true
        if (maxReachable >= nums.length - 1) {
            return true;
        }
    }
    
    // If we complete the loop without returning, we reached the last index
    return maxReachable >= nums.length - 1;
};
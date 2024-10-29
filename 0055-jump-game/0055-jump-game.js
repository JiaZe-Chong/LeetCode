/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
     let lastIndex = nums.length - 1;
 let currentFarthest = 0;

 for (let i = 0; i <= currentFarthest; i++) {
       if (i + nums[i] >= lastIndex) {
           return true;
       }
       currentFarthest = Math.max(currentFarthest, i + nums[i]);
   }
   return false;
};
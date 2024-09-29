function removeDuplicates(nums: number[]): number {
    let j = 0;

    for (let i = 0; i < nums.length; i++) {
        if (i < 2 || nums[i] !== nums[j - 2]) {
            nums[j++] = nums[i];
        }
    }

    return j;
};
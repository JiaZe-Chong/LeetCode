function removeDuplicates(nums: number[]): number {
    let j = 0;

    for (let index = 0; index < nums.length; index++) {
        if (index === 0 || nums[index] != nums[j - 2]) {
            nums[j++] = nums[index];
        }
    }

    return j;
};
class Solution {
    public int removeElement(int[] nums, int val) {
         int nextPosition = 0;
    
    for(int i=0; i<nums.length; i++) {
        if(nums[i] != val) {
            nums[nextPosition] = nums[i];
            nextPosition++;
        }
    }
    return nextPosition;
    }
}

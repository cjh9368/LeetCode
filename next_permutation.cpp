class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size() - 1;
        for(; length > 0; length--)
        {
        	if(nums[length - 1] < nums[length])  break;
        }
        if(length == 0)
        {
        	for(int i = 0, j = nums.size() - 1; i < j; i++, j--) swap(nums[i], nums[j]);
        	return;
        }
        int k = nums.size() - 1;
        for(; k >= length; k--)
        {
        	if(nums[k] > nums[length - 1])  break;
        }
        swap(nums[length - 1], nums[k]);
        for(int i = length, j = nums.size() - 1; i < j; i++, j--)  swap(nums[i], nums[j]);
    }
};
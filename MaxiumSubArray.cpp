class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int max = nums[0];
    	int start = 0;
    	int global = 0;
    	for (int i = 0; i < nums.size(); i++)
    	{
    		global = global > 0 ? global + nums[i] : nums[i];
    		max = max > global ? max : global;
    	}
    	return max;
    }
};
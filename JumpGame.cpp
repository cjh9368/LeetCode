class Solution {
public:
    bool canJump(vector<int>& nums) {
    	if(nums.size() == 0)  return true;
        int reach = 1;
        for(int i = 0; i < reach && reach < nums.size(); i++)
        	reach = max(reach, i + nums[i] + 1);
        return reach >= nums.size();
    }
};
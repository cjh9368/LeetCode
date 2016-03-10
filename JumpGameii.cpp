class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0, cur = 0, last = 0;
        for(int i = 0; i < nums.size(); i++)
        {
        	if(i > last)
        	{
        		last = cur;
        		ret++;
        	}
        	cur = max(cur, i + nums[i]);
        }
        return ret;
    }
};
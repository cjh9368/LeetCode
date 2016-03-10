class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        //sort(nums.begin(), nums.end());
        vector<int> item;item.clear();
        helper(nums, 0, item, res);
        return res;
    }
    void helper(vector<int> nums, int index, vector<int>& item, vector<vector<int>>& res)
    {
    	if(index == nums.size())
    	{
    		res.push_back(item);
    		return;
    	}
    	for(int i = index; i < nums.size(); i++)
    	{
    		if(i > index && find(nums, index, i))  continue;
    		swap(nums[index], nums[i]);
    		item.push_back(nums[index]);
    		helper(nums, index + 1, item, res);
    		item.pop_back();
    		swap(nums[index], nums[i]);
    	}
    	
    }
    bool find(vector<int> nums, int start, int end)
    	{
    		for(int i = start; i < end; i++)
    		{
    			if(nums[i] == nums[end])  return true;
    		}
    		return false;
    	}
};
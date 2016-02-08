class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ret; 
        ret.clear();
        sort(nums.begin(),nums.end());
        for (int i = 0; i < (int)nums.size(); ++i)
        {
        	if (i > 0 && nums[i] == nums[i - 1])
        	{
        		continue;
        	}
        	int j,k;
        	j = i + 1;
        	k = (int)nums.size() - 1;
        	while(j < k)
        	{
        		if (j > i + 1 && nums[j] == nums[j - 1])
        		{
        			j++;
        			continue;
        		}
        		if (k < (int)nums.size() - 1 && nums[k] == nums[k + 1])
        		{
        			k--;
        			continue;
        		}

        		int sum = nums[i] + nums[j] + nums[k];
        		if (sum < 0)
        		{
        			j++;
        		}
        		else if (sum > 0)
        		{
        			k--;
        		}
        		else
        		{
        			vector<int> line;
        			line.push_back(nums[i]);
        			line.push_back(nums[j]);
        			line.push_back(nums[k]);
        			ret.push_back(line);
        			j++;
        		}
        	}
        }
        return ret;
    }
};
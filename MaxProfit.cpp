class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int len = prices.size();
    	if(len <= 1) return 0;
    	int cur_sum = 0, res = 0;
    	for(int i = 1; i < len; i++)
    	{
    		if(cur_sum <= 0) cur_sum = prices[i] - prices[i - 1];
    		else cur_sum += prices[i] - prices[i - 1];
    		if(cur_sum > res)  res = cur_sum;
    	}
       return res; 
    }
};
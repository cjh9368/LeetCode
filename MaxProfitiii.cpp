
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       	const int len = prices.size();
       	if(len == 0)  return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        int maxProfitHead[len];
        for(int i = 0; i < len; i++)
        {
        	minPrice = min(minPrice, prices[i]);
        	maxProfit = max(maxProfit, prices[i] - minPrice);
        	maxProfitHead[i] = maxProfit;
        }
        int ret = maxProfitHead[len - 1];
        int maxPrice = prices[len - 1];
        for(int i = len - 2; i >= 0; i--)
        {
        	maxPrice = max(maxPrice, prices[i + 1]);
        	ret = max(ret, maxProfitHead[i] + maxPrice - prices[i + 1]);
        }
        return ret;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i = 0;
    	int maxArea = 0;
    	stack<int> s;
    	heights.push_back(0);
    	while (i < heights.size())
    	{
    		if (s.empty() || heights[s.top()] <= heights[i])   s.push(i++);
    		else
    		{
    			int k = s.top();
    			s.pop();
    			maxArea = max(maxArea, heights[k] * (s.empty() ? i : i - s.top() - 1));
    		}
    	}
    	return maxArea;
    }
};
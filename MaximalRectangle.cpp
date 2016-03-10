class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row_num = matrix.size();
        const int col_num = row_num == 0 ? 0 : matrix[0].size();
        vector<vector<int>> height(row_num, vector<int>(col_num));
        for(int i = 0; i < row_num; i++)
        {
        	for(int j = 0; j < col_num; j++)
        	{
        		if(matrix[i][j] == '0')  height[i][j] = 0;
        		else height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
        	}
        }
        int maxArea = 0;
        for(int i = 0; i < row_num; i++)
        {
        	maxArea = max(maxArea, largestRectangleArea(height[i]));
        }
        return maxArea;
    }
private:
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
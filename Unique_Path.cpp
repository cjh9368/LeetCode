class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
    	if (0 == obstacleGrid.size() || 0 == obstacleGrid[0].size())
    	{
    		return 0;
    	}
    	int* res = new int[obstacleGrid[0].size()];
    	memset(res, 0, sizeof(int) * obstacleGrid[0].size());
    	res[0] = 1;
    	for (int i = 0; i < obstacleGrid.size(); ++i)
    	{
    		for(int j = 0; j < obstacleGrid[0].size(); ++j)
    		{
    			if (obstacleGrid[i][j] == 1)
    			{
    				res[j] = 0;
    			}
    			else
    			{
    				if (j > 0)
    				{
    					res[j] += res[j - 1];
    				}
    			}

    		}
    	}
    	return res[obstacleGrid[0].size() - 1];	
        
    }
};
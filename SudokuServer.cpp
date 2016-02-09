class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
    }

    bool helper(int** board, int i, int j)
    {
    	if(j >= 9)  return helper(board, i + 1, j);
    	if(i >= 9)  return true;
    }
    bool isValid(int** board, int i, int j)
    {
    	for(int k = 0; k < 9; k++)
    	{
    		if(k != j && board[k][j] == board[i][j])   return false;
    	}
    	for(int k = 0; k < 9; k++)
    	{
    		if(k != i && board[i][k] == board[i][j])   return false;
    	}
    	for(int row = i / 3 * 3; row < i / 3 * 3 + 3; row++)
    	{
    		for(int col = j / 3 * 3; col < j / 3 * 3 + 3; col++)
    		{
    			if(row != i || col != j && board[row][col] == board[i][j])   return false;
    		}
    	}
    	
    	return true;
    }
};
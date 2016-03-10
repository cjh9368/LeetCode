class Solution {
public:
    int totalNQueens(int n)
    {
    	totalNum = 0;    
    	upperLimit = (1 << n) - 1;
    	helper(0, 0, 0, 0);

    }

    void helper(int row, int ld, int rd, int index)
    {
    	if (row != upperLimit)
    	{
    		int availablePos, firstAvailablePos;
    		availablePos = upperLimit & (~ (row | ld | rd));
    		while(availablePos)
    		{
    			firstAvailablePos = availablePos & (~availablePos + 1);
    			availablePos = availablePos - firstAvailablePos;
    			helper(row | firstAvailablePos, (ld | firstAvailablePos) << 1,
    			 (rd | firstAvailablePos) >> 1, index + 1);
    		}
    	}
    	else totalNum++;
    }

private:
	int upperLimit;
	int totalNum;
};
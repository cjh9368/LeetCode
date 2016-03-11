class SolutionN_Queens
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		int* queenPos = row;
		memset(col, false, n * sizeof(bool));
		vector<vector<string>> res; res.clear();
		helper(n, 0, queenPos, res);
		return res;
	}
	void helper(int n, int row, int* queenPos, vector<vector<string>>& res)
	{
		if (row == n)
		{
			vector<string> resNow;
			resNow.clear();
			for (int i = 0; i < n; i++)
			{
				string rowI;
				for (int j = 0; j < n; j++)
				{
					if (j == queenPos[i])  rowI += 'Q';
					else rowI += '.';
				}
				resNow.push_back(rowI);
			}
			res.push_back(resNow);
		}
		for (int i = 0; i < n; i++)
		{
			queenPos[row] = i;
			if ((!col[i]) && check(row, queenPos))
			{
				col[i] = true;
				helper(n, row + 1, queenPos, res);
				col[i] = false;
			}
		}
	}

	bool check(int row, int* queenPos)
	{
		for (int i = 0; i < row; i++)
		{
			if (/*queenPos[i] == queenPos[row] ||*/ abs(queenPos[row] - queenPos[i]) == row - i) return false;
		}
		return true;
	}
private:
	bool col[1000];
	int row[1000];
};
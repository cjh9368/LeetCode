class Solution {
public:

	string minWindow(string s, string t) {
		int tCount[256] = { 0 };
		int findCount[256] = { 0 };
		int tLen = t.size(), sLen = s.size();
		for (int i = 0; i < tLen; i++)  tCount[t[i]]++;
		int foundCount = 0;
		queue<int> Q;
		int winStart = -1, winEnd = sLen - 1;
		int start = 0;
		for (int i = 0; i < sLen; i++)
			if (tCount[s[i]] > 0)
			{
				Q.push(i);
				findCount[s[i]]++;
				if (findCount[s[i]] <= tCount[s[i]])  foundCount++;
				if (foundCount == tLen)
				{
					int k ;
					do
					{
						k = Q.front();
						Q.pop();
						findCount[s[k]]--;
					} while (findCount[s[k]] >= tCount[s[k]]);
					if (winEnd - winStart > i - k)
					{
						winStart = k;
						winEnd = i;
					}
					foundCount--;
				}
			}
		return winStart != -1 ? s.substr(winStart, winEnd - winStart + 1) : "";
	}
};
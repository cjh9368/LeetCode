class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> dict;
		unordered_map<string, int>::iterator itr;
		int wordLen = words[0].size(), wordNum = words.size();
		vector<int> res;
		if(s.length() < wordNum * wordLen) return res;
		for (int i = 0; i < words.size(); i++)
		{
			itr = dict.find(words[i]);
			if (itr == dict.end())  dict.insert(pair<string, int>(words[i], 1));
			else  itr->second += 1;
		}
		
		for (int i = 0; i < s.length() - wordLen * wordNum; i++)
		{
			unordered_map<string, int> temp_dict = dict;
			string temp_str = s.substr(i, wordLen * wordNum);
			for (int j = 0; j < wordNum; j++)
			{
				string temp_str1 = temp_str.substr(j * wordLen, wordLen);
				itr = temp_dict.find(temp_str1);
				if (itr == temp_dict.end()) break;
				else
				{
					int occur_num = itr->second - 1;
					if (occur_num < 0) break;
					itr->second = occur_num;
					if (j == wordNum - 1)
					{
						res.push_back(i);
						break;
					}
				}
			}
		}

		return res;
	}
};
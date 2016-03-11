class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	std::vector<string> res;
        if(s.length() == 0)  return res;
        helper(s, 0, 1, res, "");
        return res;
    }
    void helper(string s, int index, int segment, vector<string>& res, string item)
    {
    	if(index >= s.length()) return;
    	if (segment == 4)
    	{
    		string temp_sub = s.substr(index);
    		if(isValid(temp_sub))
    		{
    			res.push_back(item + '.' + temp_sub);
    		}
    		return;
    	}
    	for(int i = 1; i < 4 && index + i <= s.length(); i++)
    	{
    		string temp_sub = s.substr(index, i);
    		if(isValid(temp_sub))
    		{
    			if(segment == 1) helper(s, index + i, segment + 1, res, temp_sub);
    			else helper(s, index + i, segment + 1, res, item + '.' + temp_sub);
    		}

    	}
    }
    bool isValid(string s)
    {
    	if(s.length() > 3)  return false;
    	int num = atoi(s.c_str());
    	if(s[0] == '0' && s.length() > 1) return false;
    	if(num > 255) return false;
    	return true;
    }
};
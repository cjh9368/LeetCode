
#include <stdio.h>
#include <string>
#include <vector>
#include <boost/unordered_set>
using namespace std;
vector<string> wordBreak(string s, unordered_set<string>& wordDict)
{
	std::vector<string> res;
	res.clear();
 	if(s.length() == 0)       return res;
 	helper(s, wordDict, "", res, 0);
 	return res; 
}


void helper(string s, unordered_set<string>& dict, string item, vector<string>& res, int start )
{
	if(start >= s.length()) 
	{
		res.push_back(item);
		return;
	}
	for (int i = start; i < s.length(); ++i)
	{
		string substr1 = s.substr(start, i);
		if (dict.find(substr1) != dict.end())
		{
			item = (item.length() == 0) ? (substr1) : (item + " " + substr1);
			helper(s, dict, item, res, i);
		}
	}
}


int int main(int argc, char const *argv[])
{
	/* code */
	string s = "catsanddog";
	unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
	wordBreak(s, dict);
	return 0;
}
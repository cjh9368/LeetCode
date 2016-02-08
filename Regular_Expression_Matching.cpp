//#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
using namespace std;

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
   		return helper( s, p, 0, 0);
    }
    bool helper(string s, string p, int i, int j)
    {
    	if (0 == p[j])
        {
        	return 0 == s[i];
        } 

        if ('*' != p[j + 1])
        {
        	if (s[i] == p[j] || '.' == p[j] && s[i] != 0 )
        	{
        		return helper( s, p, i + 1, j + 1 ); 
        	}
        	return false;
        }
        else
        {
        	while(s[i] == p[j] || '.' == p[j] && s[i] != 0 )
        	{
        		if (helper( s, p, i, j + 2))
        		{
        			return true;
        		}
        		i++;
        	}
        	return helper( s, p, i, j + 2);

        }
    }
};
bool isMatch(const char *s, const char *p) 
{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    

		if( 0 == *p) return 0 == *s;

		if(*(p+1) != '*')
		{
			if(*p == *s || (*p) == '.' && (*s) != 0)
			{
				return isMatch(s+1, p+1);
			}
			return false;
		}
		else
		{
			while(*p == *s || ((*p) == '.' && (*s) != 0))
			{
				if(isMatch(s, p + 2))
				{
					return true;
				}
				s++;
			}
			return isMatch(s, p + 2);

		}
		
	}
int main(int argc, char const *argv[])
{
	Solution sol1;
	if (sol1.isMatch("aa", "a" ))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	printf("hello\n");
	return 0;
}
/*
* Valid Parentheses
* Date: 2015/11/9
* Tag: stack, string
* Difficulty: Easy
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		char m[256] = { 0 };
		m[')'] = '(';
		m['}'] = '{';
		m[']'] = '[';
		string temp;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i]=='(' || s[i]=='{' || s[i]=='[')
			{
				temp.push_back(s[i]);
			}
			else if (s[i] == ')' || s[i]=='}' || s[i] == ']')
			{
				int l = temp.length();
				if (l && temp[l - 1] == m[s[i]])
					temp.pop_back();
				else
					return false;
			}
		}

		return temp.empty();
	}
};

int main()
{
	Solution s;
	cout << s.isValid("({})") << endl;

	return 0;
}
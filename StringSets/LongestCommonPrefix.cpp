/*
* Longest Common Prefix
* Date: 2015/11/9
* Tag: string
* Difficulty: Easy
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.empty())
		{
			return "";
		}

		string com = strs[0];
		for (int i = 1; i < strs.size(); ++i)
		{
			if (com[0] != strs[i][0])
			{
				return "";
			}

			for (int j = 1; j < min(com.size(), strs[i].size()); ++j)
			{
				if (com[j] !=strs[i][j])
				{
					com = com.substr(0, j);
					break;
				}
			}

			com = (com.size() > strs[i].size()) ? strs[i] : com;
		}

		return com;
	}
};

int main()
{
	vector<string> strs{ "abc", "abcd", "abd" };
	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;

	return 0;
}
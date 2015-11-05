/*
* Longest Substring Without Repeating Characters
* Date: 2015/11/5
* Tag: hash table, two pointers, string
* Difficulty: Medium
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		vector<int> vec(255, -1);
		int max_len = 0;
		int start = -1;
		for (int i = 0; i < s.length(); ++i)
		{
			if (vec[s[i]]> start)
			{
				start = vec[s[i]];
			}
			vec[s[i]] = i;
			max_len = max(max_len, i - start);
		}

		return max_len;
	}
};

int main()
{
	string str("abba");
	Solution s;
	cout << "abcabcbb is: " << s.lengthOfLongestSubstring(str) << endl;

	return 0;
}
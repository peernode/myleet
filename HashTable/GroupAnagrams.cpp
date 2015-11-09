/*
* Group Anagrams
* Date: 2015/11/9
* Tag: Hash Table, string
* Difficulty: Medium
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>> ret;
		if (strs.empty()) return ret;

		unordered_map<string, vector<string>> count;
		int i = 0;
		for (auto s : strs)
		{
			sort(s.begin(), s.end());
			count[s].push_back(strs[i++]);
		}

		for (auto n : count)
		{
			sort(n.second.begin(), n.second.end());
			ret.push_back(n.second);
		}

		return ret;
	}
};

int main()
{
	vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution s;
	vector<vector<string>> ret = s.groupAnagrams(strs);

	return 0;
}


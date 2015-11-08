/*
* Substring with Concatenation of All Words
* Date: 2015/11/8
* Tag: Hash table, two pointers, string
* Difficulty: Hard
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		vector<int> ret;
		if (s.empty() || words.empty())
		{
			return ret;
		}

		map<string, int> wordMap;
		map<string, int> curStr;
		for (int i = 0; i < words.size(); ++i)
			++wordMap[words[i]];

		int count = words.size();
		int wordlen = words[0].size();

		for (int i = 0; i <= (int)s.size() - count*wordlen; ++i)
		{
			curStr.clear();

			int j = 0;
			for (j = 0; j < count; ++j)
			{
				string w = s.substr(i + j*wordlen, wordlen);
				if (wordMap.find(w) == wordMap.end())
				{
					break;
				}

				++curStr[w];
				if (curStr[w] > wordMap[w])
				{
					break;
				}
			}

			if (j == count) ret.push_back(i);
		}

		return ret;
	}
};

int main()
{
	/*vector<string> words{ "foo", "bar" };
	string str("barfoothefoobarman");*/
	vector<string> words{ "word","good","best","good" };
	string str("wordgoodgoodgoodbestword");
	Solution s;
	vector<int> ret = s.findSubstring(str, words);
	for (int i = 0; i < ret.size(); ++i)
		cout << " " << ret[i];

	return 0;
}
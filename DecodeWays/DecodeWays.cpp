/*
* Decode Ways
* Date:  2015/10/31
* Tag: Dynamic Programming, String
* Difficulty: Medium
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		if (s.empty() || s[0]=='0')
		{
			return 0;
		}

		vector<int> d(s.size(), 0);
		d[0] = 1;
		d[1] = 1;

		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] != '0')
			{
				d[i + 1] += d[i];
			}

			int temp = stoi(s.substr(i - 1, 2));
			if (temp>=10 && temp <=26)
			{
				d[i + 1] += d[i - 1];
			}
		}

		return d[s.size()];
	}
};

int main()
{
	Solution s;
	cout << "1230311: " << s.numDecodings("123031") << endl;

	return 0;
}
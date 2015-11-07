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
		/*if (s.empty() || s[0]=='0')
		{
			return 0;
		}

		vector<int> d(s.size()+1, 0);
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

		return d[s.size()];*/
		if (s.empty() || s.front() == '0')//first char should not be '0'
			return 0;
		vector<int> dp(s.size() + 1, 0); //dp[i] corresponding to s[i-1], initialize dp[0], dp[1] = 1;
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] != '0')    // s[i] not '0', can decode itself, decode ways is dp[i]
				dp[i + 1] += dp[i];

			int twodigit = stoi(s.substr(i - 1, 2));
			if (twodigit >= 10 && twodigit <= 26) // decode combined with s[i-1], decode ways dp[i-1]
				dp[i + 1] += dp[i - 1];
		}
		return dp[s.size()];
	}
};

int main()
{
	Solution s;
	cout << "1220311: " << s.numDecodings("122031") << endl;

	return 0;
}
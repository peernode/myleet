/*
* Bulls And Cows
* Date: 2015/11/4
* Tag: Hash Table
* Difficulty: Easy
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string getHint(string secret, string guess)
	{
		int shash[10] = { 0 };
		int ghash[10] = { 0 };
		int bulls = 0;
		for (int i = 0; i < secret.length(); ++i)
		{
			if (secret[i]==guess[i])
			{
				++bulls;
				continue;
			}
			shash[secret[i] - '0']++;
			ghash[guess[i] - '0']++;
		}

		int cows = 0;
		for (int i = 0; i < 10; ++i)
		{
			cows += min(shash[i], ghash[i]);
		}

		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};

int main()
{
	string s1 = "1807";
	string s2 = "7810";
	Solution s;
	cout << "1807 7810 is: " << s.getHint(s1, s2) << endl;

	string s3 = "00112233445566778899";
	string s4 = "16872590340158679432";
	cout << "00112233445566778899 16872590340158679432 is: " << s.getHint(s3, s4) << endl;

	return 0;
}
/*
* Add Binary
* Date: 2015/10/30
* Tag: String, Math
* Difficulty: Easy
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		unsigned int a_len = a.size();
		unsigned int b_len = b.size();
		int carry = 0;
		string ret="";
		for (int a_idx = a_len - 1, b_idx = b_len - 1; a_idx >= 0 || b_idx >= 0; --a_idx, --b_idx)
		{
			if (a_idx >= 0)
			{
				carry += a[a_idx] == '0' ? 0 : 1;

			}

			if (b_idx >= 0 )
			{
				carry += b[b_idx] == '0' ? 0 : 1;
			}

			ret = ((carry % 2) == 0 ? "0" : "1") + ret;
			carry /= 2;
		}

		ret = carry >= 1 ? ("1" + ret) : ret;

		return ret;
	}
};

int main()
{
	string a = "11";
	string b = "1";
	Solution s;
	cout << "result of 11 and 1: " << s.addBinary(a, b) << endl;

	return 0;
}
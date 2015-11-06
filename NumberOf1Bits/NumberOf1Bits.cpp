/*
* Number of 1 Bits
* Date: 2015/11/6
* Tag: Bit Manipulation
* Difficulty: Easy
*/

#include <iostream>
using namespace std;

class Solution
{
public:
	int hammigWeight(unsigned int n)
	{
		int bits=0;
		for (int i = 0; i < 32; i++)
		{
			bits += (n & 1);
			n = n >> 1;
		}

		return bits;
	}
};

int main()
{
	Solution s;
	cout << "11: " << s.hammigWeight(11) << endl;

	return 0;
}
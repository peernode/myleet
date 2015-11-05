/*
* Single Number
* Date: 2015/11/5
* Tag: Bit Manipulation, Hash Table
* Difficulty: Medium
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int bits[32] = { 0 };
		for (int i = 0; i < 32; ++i)
		{
			for (int j = 0; j < nums.size(); ++j)
			{
				int temp = nums[j] >> i;
				bits[i] += (temp & 1);
			}
		}

		for (int i = 0; i < 32; ++i)
		{
			bits[i] %= 2;
		}

		int rst = 0;
		for (int i = 0; i < 32; ++i)
		{
			rst += (bits[i] << i);
		}

		return rst;
	}
};

int main()
{
	vector<int> vec{ 1,1,2,2,3,4,4 };
	Solution s;
	cout << "1,1,2,2,3,4,4 : " << s.singleNumber(vec) << endl;

	return 0;
}
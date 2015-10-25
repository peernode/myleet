/* 
 * HIndex 
 * Date: 2015/10/25
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <limits.h>

using namespace std;

class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		/*
		int target = nums.size() * (nums.size()+1) / 2;
        int sum = 0;
		for (int i : nums) sum += i;
        return target-sum;
		*/
		const int size = 1000;
		bitset<size> bits; 
		for (int i = 0; i < nums.size(); ++i)
		{
			bits[nums[i]] = 1;
		}
		
		int rst = nums.size();
		for (int i = 0; i < nums.size(); ++i)
		{
			if (bits[i] == 0)
			{
				rst = i;
			}
		}

		return rst;
	}
};

int main()
{
	vector<int> vec = { 66,16,40,62,7,14,95,71,74,90,49,3,38,34,99,10,59,28,45,79,8,68,86,67,27,82,70,6,42,96,77,92,36,15,78,44,48,87,98,89,83,84,81,0,76,60,46,1,50,31,88,72,52,4,73,26,9,57,29,19,61,91,18,93,58,12,63,54,85,17,75,41,47,94,80,39,53,2,51,37,35,11,30,32,65,23,43,56,13,20,64,24,33,69,97,22,55,5,25 };
	Solution s;
	cout << s.missingNumber(vec) << endl;
	return 0;
}
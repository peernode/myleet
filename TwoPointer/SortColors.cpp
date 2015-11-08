/*
* Sort Colors
* Date: 2015/11/8
* Tag: Array, Two Pointers, Sort
* Difficulty: Medium
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		int front = 0;
		int index = 0;
		int last = nums.size() - 1;
		while (index <= last)
		{
			if (nums[index] == 0)
			{
				int temp = nums[index];
				nums[index++] = nums[front];
				nums[front++] = temp;
			}
			else if (nums[index] == 2)
			{
				int temp = nums[last];
				nums[last--] = nums[index];
				nums[index] = temp;
			}
			else
				index++;
		}
	}
};

int main()
{
	return 0;
}
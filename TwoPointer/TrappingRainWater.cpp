/*
* Trapping Rain Water
* Date: 2015/11/8
* Tag: Array, Stack, Two Pointer
* Difficulty: Hard
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int trap(vector<int>& height)
	{
		int l = 0;
		int r = height.size() - 1;
		int minHeight = 0;
		int trap = 0;

		while (l < r)
		{
			while (l < r && height[l] <= minHeight)
				trap += minHeight - height[l++];
			while (r > l && height[r] <= minHeight)
				trap += minHeight - height[r--];

			minHeight = min(height[l], height[r]);
		}

		return trap;
	}
};

int main()
{
	vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	Solution s;
	cout << s.trap(height) << endl;

	return 0;
}

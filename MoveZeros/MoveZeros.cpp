/* 
 * Move zeros 
 * Date: 2015/10/25
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void moveZeros(vector<int>& nums)
	{
		int zeros = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); )
		{
			if (*it == 0) {
				++zeros;
				it = nums.erase(it);
			}
			else
			{
				++it;
			}
		}

		while (zeros > 0)
		{
			nums.push_back(0);
			--zeros;
		}
	}
};

int main()
{
	vector<int> vec = { 0, 1, 0, 3, 12 };
	Solution s;
	s.moveZeros(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}

	return 0;
}


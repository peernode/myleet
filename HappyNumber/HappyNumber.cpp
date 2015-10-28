/*
 * Happy Number
 * Date: 2015/10/28
 * Tag: Math, Hash
 */

#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
	bool isHappy(int n)
	{
		if (n == 1 || n == -1)
		{
			return true;
		}

		map<int, int> m;
		m[n] = 1;
		for (; ; )
		{
			int sum = 0;
			for (; n; n/=10)
			{
				int i = n % 10;
				sum += i*i;
			}
			n = sum;
			if (sum == 1) return true;
			if (m[sum]++) return false;
		}
	}
};

int main()
{
	Solution s;
	cout << s.isHappy(19) << endl;
	cout << s.isHappy(20) << endl;

	return 0;
}
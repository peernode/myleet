/*
 * Add Digits
 * 2015/10/28
 * tag: Math
 */

#include<iostream>

using namespace std;

class Solution
{
public:
	int addDigits(int num)
	{
		return 1 + ((num - 1) % 9);
	}
};

int main()
{
	Solution s;
	cout << s.addDigits(1853) << endl;
	
	return 0;
}
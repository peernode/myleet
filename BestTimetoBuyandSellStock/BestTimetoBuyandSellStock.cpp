/*
* BestTimetoBuyandSellStock
* Date: 2015/11/1
* Tag: Dynamic Programming
* Difficulty: Medium
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.empty()) return 0;
		int min_price = prices[0];
		int max_profit = 0;

		for (int i = 1; i < prices.size(); ++i)
		{
			if (prices[i]-min_price > max_profit)
			{
				max_profit = prices[i] - min_price;
			}

			if (prices[i]<min_price)
			{
				min_price = prices[i];
			}
		}

		return max_profit;
	}
};

int main()
{
	vector<int> vec{ 1,3,9,5 };
	Solution s;
	cout << "{1, 3, 9, 5} is: " << s.maxProfit(vec) << endl;

	return 0;
}
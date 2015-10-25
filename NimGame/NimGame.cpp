/* 
 * Nim Game
 * Date: 2015/10/25
*/

#include <iostream>
using namespace std;

class Solution
{
public:
	bool canWinNim(int n)
	{
		return n % 4;
	}
};

int main()
{
	Solution s;
	cout << "can win 3: "<<s.canWinNim(3) << endl;
	cout << "can win 4: " << s.canWinNim(4) << endl;
	cout << "can win 5: " << s.canWinNim(5) << endl;
	cout << "can win 400: " << s.canWinNim(400) << endl;
	cout << "can win 403:" << s.canWinNim(403) << endl;
	return 0;
}
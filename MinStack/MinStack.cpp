/* 
 * MinStack 
 * Date: 2015/10/25
*/

#include <stack>
#include <iostream>
using namespace std;


class MinStack {
public:
	void push(int x) {
		if (s.empty())
		{
			s.push(std::make_pair(x, x));
		}
		else
		{
			int min = s.top().second > x ? x : s.top().second;
			s.push(std::make_pair(x, min));
		}
	}

	void pop() {
		s.pop();
	}

	int top() {
		return s.top().first;
	}

	int getMin() {
		return s.top().second;
	}

private:
	stack<std::pair<int, int> > s;
};

int main()
{
	MinStack st;
	st.push(3);
	st.push(2);
	st.push(6);
	st.push(5);

	for (int i = 0; i < 4;++i)
	{
		cout << st.getMin() << endl;
		st.pop();
	}
	return 0;
}


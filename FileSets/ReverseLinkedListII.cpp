/*
* Reverse Linked List II
* Date: 2015/11/7
* Tag: Linked List
* Difficulty: Medium
*/
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution
{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		ListNode dummy(0);
		ListNode* p = &dummy;
		dummy.next = head;

		for (int i = 1; i < m; ++i) p = p->next;
		head = p->next;

		for (; m < n; ++m)
		{
			ListNode* tmp = head->next;
			head->next = tmp->next;
			tmp->next = p->next;
			p->next = tmp;
		}

		return dummy.next;
	}
};

int main()
{

	return 0;
}


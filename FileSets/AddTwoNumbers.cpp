/*
* Add Two Numbers
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL && l2 == NULL)
		{
			return NULL;
		}

		ListNode* header = NULL;
		bool flag = false;

		ListNode* l3 = NULL;
		int carry = 0;
		while (l1 != NULL || l2 != NULL)
		{
			ListNode* tmp = new ListNode(carry);
			if (l1 != NULL)
			{
				tmp->val += l1->val;
				l1 = l1->next;
			}

			if (l2 != NULL)
			{
				tmp->val += l2->val;
				l2 = l2->next;
			}

			carry = tmp->val / 10;
			tmp->val %= 10;
			if (header == NULL)
			{
				header = tmp;
				l3 = tmp;
			}
			else
			{
				l3->next = tmp;
				l3 = tmp;
			}
		}

		if (carry > 0)
			l3->next = new ListNode(carry);

		return header;
	}
};

void printList(ListNode* node)
{
	while (node != NULL)
	{
		cout << " " << node->val;
		node = node->next;
	}
}


int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	Solution s;
	ListNode* l3 = s.addTwoNumbers(l1, l2);
	printList(l3);
	return 0;
}
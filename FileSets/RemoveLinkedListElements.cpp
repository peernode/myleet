/*
* Remove Linked List Elements
* Date: 2015/11/7
* Tag: Linked List
* Difficulty: Easy
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
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode dummy(0);
		dummy.next = head;

		ListNode* h = &dummy;
		while (h->next != NULL)
		{
			if (h->next->val == val)
			{
				h->next = h->next->next;
			}
			else
			{
				h = h->next;
			}
		}

		return dummy.next;
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
	ListNode* node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(6);
	node->next->next->next = new ListNode(3);
	node->next->next->next->next = new ListNode(6);
	Solution s;
	s.removeElements(node, 6);

	return 0;
}
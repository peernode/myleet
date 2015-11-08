/*
* Partition List
* Date: 2015/11/8
* Tag: Linked List, two pointer
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
	ListNode* partition(ListNode* head, int x)
	{
		ListNode dummy(x-1);
		dummy.next = head;

		ListNode* order = &dummy;
		ListNode* pre = &dummy;
		ListNode* cur = dummy.next;
		while (cur != NULL)
		{
			if (cur->val < x)
			{
				if (order->next == cur)
				{
					order = cur;
					pre = cur;
					cur = cur->next;
				}
				else
				{
					ListNode* tmp = cur->next;
					cur->next = order->next;
					order->next = cur;
					order = cur;

					pre->next = tmp;

					cur = tmp;
				}
				
			}
			else
			{
				pre = cur;
				cur = cur->next;
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
	node->next = new ListNode(4);
	node->next->next = new ListNode(3);
	node->next->next->next = new ListNode(2);
	node->next->next->next->next = new ListNode(5);
	node->next->next->next->next->next = new ListNode(2);

	Solution s;
	printList(s.partition(node, 3));

	return 0;
}
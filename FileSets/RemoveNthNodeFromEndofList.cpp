/*
* Remove Nth Node From End of List
* Date: 2015/11/7
* Tag: Linked List, two pointer
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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (head==NULL)
		{
			return NULL;
		}

		ListNode dummy(0);
		dummy.next = head;

		ListNode* head1 = &dummy;
		ListNode* head2 = &dummy;
		for (int i = 0; i < n; ++i)
		{
			head2 = head2->next;
		}

		while (head2->next != NULL)
		{
			head2 = head2->next;
			head1 = head1->next;
		}

		head1->next = head1->next->next;


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
	Solution s;
	ListNode* node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(3);
	node->next->next->next = new ListNode(4);
	node->next->next->next->next = new ListNode(5);
	node = s.removeNthFromEnd(node, 2);
	printList(node);
	return 0;
}


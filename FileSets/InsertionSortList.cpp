/*
* Insertion Sort List
* Date: 2015/11/7
* Tag: Linked List, sort
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

void printList(ListNode* node)
{
	while (node != NULL)
	{
		cout << " " << node->val;
		node = node->next;
	}
}

class Solution
{
public:
	ListNode* insertionSortList(ListNode* head)
	{
		ListNode dummy(0);

		while (head != NULL)
		{
			ListNode* next_head = head->next;
			ListNode* it = &dummy;
			while (it->next && it->next->val < head->val)
			{
				it = it->next;
			}
			head->next = it->next;
			it->next = head;
			head = next_head;
		}

		return dummy.next;
	}
};

int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	Solution s;
	ListNode* l2 = s.insertionSortList(l1);
	printList(l2);

	return 0;
}
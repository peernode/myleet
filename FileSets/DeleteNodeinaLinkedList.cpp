/*
* Delete Node in a Linked List
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
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	void deleteNode(ListNode* node)
	{
		ListNode* tmp = node->next;
		node->val = tmp->val;
		node->next = tmp->next;

		delete tmp;
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
	ListNode* header = new ListNode(1);
	ListNode* tmp1 = new ListNode(2);
	ListNode* tmp2 = new ListNode(3);
	ListNode* tmp3 = new ListNode(4);
	header->next = tmp1;
	tmp1->next = tmp2;
	tmp2->next = tmp3;
	printList(header);

	Solution s;
	s.deleteNode(tmp2);
	printList(header);

	return 0;
}

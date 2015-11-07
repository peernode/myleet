/*
* Reverse Linked List
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
	ListNode* reverseList(ListNode* head)
	{
		ListNode* cur = head;
		ListNode* h = NULL;

		while (cur)
		{
			ListNode* tmp = cur->next;
			cur->next = h;
			h = cur;
			
			cur = tmp;
		}

		return h;
	}
};

int main()
{
	return 0;
}
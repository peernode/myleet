/*
* Palindrome Linked List
* Date: 2015/11/7
* Tag: Linked List
* Difficulty; Easy
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
	bool isPalindrome(ListNode* head)
	{
		if (!head || !head->next)
			return true;

		ListNode* fast = head, *slow = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		if (fast)
			slow = reverseList(slow->next);
		else
			slow = reverseList(slow);

		while (slow)
		{
			if (head->val != slow->val) return false;
			head = head->next;
			slow = slow->next;
		}


		return true;
	}

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
	Solution s;
	ListNode* node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(2);
	node->next->next->next = new ListNode(2);
	cout << s.isPalindrome(node) << endl;

	return 0;
}
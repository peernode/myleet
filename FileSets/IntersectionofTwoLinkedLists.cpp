/*
* Intersection of Two Linked Lists
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
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		if (headA == NULL || headB == NULL) return NULL;
		ListNode* pa = headA;
		unsigned int lenA = 0;
		while (pa!=NULL)
		{
			++lenA;
			pa = pa->next;
		}
		ListNode* pb = headB;
		unsigned int lenB = 0;
		while (pb != NULL)
		{
			++lenB;
			pb = pb->next;
		}

		if (lenA>lenB)
		{
			int diff = lenA - lenB;
			while (diff>0)
			{
				--diff;
				headA = headA->next;
			}
		}
		else
		{
			int diff = lenB - lenA;
			while (diff>0)
			{
				--diff;
				headB = headB->next;
			}
		}

		while (headA && headB && headA != headB)
		{
			headA = headA->next;
			headB = headB->next;
		}
		
		return headA;
	}
};

int main()
{
	Solution s;
	ListNode* h1 = new ListNode(1);
	h1->next = new ListNode(3);

	ListNode* h2 = new ListNode(2);
	ListNode* sec = s.getIntersectionNode(h1, h2);
	return 0;
}
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
		ListNode *evenHead = head->next, *odd = head, *even = evenHead;
		while (even->next != NULL && even->next->next != NULL) {
			odd->next = even->next;
			even->next = odd->next->next;
			odd = odd->next;
			even = even->next;
		}
		if (even->next != NULL) {
			odd->next = even->next;
			odd = odd->next;
			even->next = NULL;
		}
		odd->next = evenHead;
		return head;
	}
};
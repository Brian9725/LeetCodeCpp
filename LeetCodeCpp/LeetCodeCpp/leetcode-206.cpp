#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *pre = new ListNode(0), *temp = NULL;
		pre->next = head; head = head->next; pre->next->next = NULL;
		while (head) {
			temp = head->next;
			head->next = pre->next;
			pre->next = head;
			head = temp;
		}
		return pre->next;
	}
};
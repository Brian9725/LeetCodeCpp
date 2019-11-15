#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* pre = new ListNode(0);
		pre->next = head; head = pre;
		while (head && head->next) {
			if (head->next->val == val) 
				head->next = head->next->next;
			else
				head = head->next;
		}
		return pre->next;
	}
};
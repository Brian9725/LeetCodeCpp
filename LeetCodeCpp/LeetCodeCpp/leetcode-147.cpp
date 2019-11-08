#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *pre = new ListNode(0), *tempPre = pre, *temp = NULL;
		pre->next = head; head = head->next; pre->next->next = NULL;
		while (head) {
			tempPre = pre; temp = head->next;
			while (tempPre->next && head->val > tempPre->next->val) {
				tempPre = tempPre->next;
			}
			head->next = tempPre->next;
			tempPre->next = head;
			head = temp;
		}
		return pre->next;
	}
};
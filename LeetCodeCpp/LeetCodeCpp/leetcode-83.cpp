#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		//tailָ������������һ��Ԫ��
		ListNode *tail = head, *temp = head->next;
		while (temp) {
			if (temp->val != tail->val) {
				tail->next = temp;
				tail = tail->next;
			}
			temp = temp->next;
		}
		tail->next = NULL;
		return head;
	}
};
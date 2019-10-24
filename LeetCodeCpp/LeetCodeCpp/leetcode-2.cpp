#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//如果l1或者l2其中之一为空，则直接返回另一个
		if (!l2) 
			return l1;
		if (!l1) 
			return l2;
		struct ListNode* result = NULL, *temp = NULL;
		//进位标识符
		int flag = 0;
		//如果l1并且l2不为空，则按顺序将其相加
		while (l1 && l2) {
			if (temp == NULL) 
				temp = new ListNode(0);
			else {
				temp->next = new ListNode(0);
				temp = temp->next;
			}
			temp->next = NULL;
			if (result == NULL) 
				result = temp;
			if (l1->val + l2->val + flag >= 10) {
				temp->val = l1->val + l2->val - 10 + flag;
				flag = 1;
			}
			else {
				temp->val = l1->val + l2->val + flag;
				flag = 0;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		//将还有剩余元素的链赋给l1
		if (!l1) 
			l1 = l2;
		while (l1) {
			if (temp == NULL) 
				temp = new ListNode(0);
			else {
				temp->next = new ListNode(0);
				temp = temp->next;
			}
			temp->next = NULL;
			if (result == NULL) 
				result = temp;
			if (l1->val + flag >= 10) {
				temp->val = l1->val - 10 + flag;
				flag = 1;
			}
			else {
				temp->val = l1->val + flag;
				flag = 0;
			}
			l1 = l1->next;
		}
		if (flag) {
			temp->next = new ListNode(0);
			temp = temp->next;
			temp->next = NULL;
			temp->val = flag;
		}
		return result;
	}
};
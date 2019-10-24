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
		//���l1����l2����֮һΪ�գ���ֱ�ӷ�����һ��
		if (!l2) 
			return l1;
		if (!l1) 
			return l2;
		struct ListNode* result = NULL, *temp = NULL;
		//��λ��ʶ��
		int flag = 0;
		//���l1����l2��Ϊ�գ���˳�������
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
		//������ʣ��Ԫ�ص�������l1
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
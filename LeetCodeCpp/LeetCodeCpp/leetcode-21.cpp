#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		struct ListNode *tempNode = NULL, *result = NULL;
		if (l2 == NULL) {
			return l1;
		}
		if (l1 == NULL) {
			return l2;
		}
		//ѡ����С��ͷ�����Ϊ�µ�ͷ���
		if (l1->val < l2->val) {
			tempNode = l1;
			l1 = l1->next;
		}
		else {
			tempNode = l2;
			l2 = l2->next;
		}
		result = tempNode;
		//ÿ�ν���С�Ľ��ӵ�tempNode����
		while (l1 != NULL && l2 != NULL) {
			if (l1->val > l2->val) {
				tempNode->next = l2;
				l2 = l2->next;
				tempNode = tempNode->next;
			}
			else {
				tempNode->next = l1;
				l1 = l1->next;
				tempNode = tempNode->next;
			}
		}
		//���l1����l2��Ϊ������ӵ������
		if (l1 != NULL) {
			tempNode->next = l1;
		}
		if (l2 != NULL) {
			tempNode->next = l2;
		}
		return result;
	}
};
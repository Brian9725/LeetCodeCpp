#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//���headΪ�գ�����ɾ������������Ϊ���򷵻�NULL
		if (head == NULL || (head->next == NULL && n == 1)) {
			return NULL;
		}
		struct ListNode *tmp1 = new ListNode(0), *tmp2 = new ListNode(0), *pre = new ListNode(0);
		//ʹ��pre��Ϊhead��ǰһ�������ڴ�����Ҫɾ��head�����
		pre->next = head;
		tmp1 = tmp2 = pre;
		//temp2�����n�Σ���ָ���n����㣬��ʱtemp1��temp2֮�����n�����
		for (int i = 0; i < n; i++) {
			tmp2 = tmp2->next;
		}
		//��temp1��temp2ͬʱ����ƶ���temp2��β��ʱ��temp1ָ������n�����
		while (tmp2->next != NULL) {
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		tmp1->next = tmp1->next->next;
		return pre->next;
	}
};
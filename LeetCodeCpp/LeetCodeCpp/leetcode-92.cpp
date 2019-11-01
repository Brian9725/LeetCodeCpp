#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL || m == n)
			return head;
		//pre���Ե�����0�������ڴ�����ת��ͷ���仯�����
		ListNode *pre = new ListNode(0);
		pre->next = head;
		//temp1��ָ���m-1�Ž�㣬head��ָ���m�Ž�㣬temp2��ָ���m+1�Ž�㣬temp3��ָ���n�Ž��
		ListNode *temp1 = pre, *temp2 = head->next, *temp3 = head;
		//��temp3����n-mλ��ʹhead��temp3���n-mλ
		for (int i = 0; i < n - m; i++)
			temp3 = temp3->next;
		//����ָ���ƶ���ָ��λ��
		for (int i = 0; i < m - 1; i++) {
			temp1 = temp1->next;
			head = head->next;
			temp2 = temp2->next;
			temp3 = temp3->next;
		}
		temp1->next = temp3;
		while (head != temp3) {
			head->next = temp3->next;
			temp3->next = head;
			head = temp2;
			temp2 = head->next;
		}
		return pre->next;
	}
};
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return;
		//������ֳɳ����൱��������
		ListNode *front = head, *back = NULL, *tempF = head, *tempB = head;
		while (tempB != NULL) {
			if (tempB->next == NULL) {
				back = tempF->next; break;
			}
			tempF = tempF->next;
			tempB = tempB->next->next;
		}
		if (tempB == NULL)
			back = tempF;
		//����벿������ת��������ת��ı�ͷ��tempB
		tempB = NULL; tempF = back;
		while (tempF != NULL) {
			ListNode *temp = tempF->next;
			tempF->next = tempB; tempB = tempF; tempF = temp;
		}
		//���ƴ������
		ListNode *pre = new ListNode(0); tempF = pre;
		while (tempB != NULL) {
			tempF->next = head; head = head->next;
			tempF->next->next = tempB; tempB = tempB->next;
			tempF = tempF->next->next;
		}
		//ǰ�벿�ֿ��ܱȺ�벿�ֶ�һ�����
		if (head != back) {
			tempF->next = head;
			tempF->next->next = NULL;
		}
		head = pre->next;
	}
};
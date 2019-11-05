#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = 0, lenB = 0;
		ListNode *tempA = headA, *tempB = headB, *result = NULL;
		//���A��B�ĳ���
		while (tempA) {
			lenA++;
			tempA = tempA->next;
		}
		while (tempB) {
			lenB++;
			tempB = tempB->next;
		}
		//������������tempA
		if (lenA < lenB) {
			tempA = headB; tempB = headA;
			int temp = lenA;
			lenA = lenB; lenB = temp;
		}
		else {
			tempA = headA; tempB = headB;
		}
		//��tempA�ӳ�����ͷ��������lenA-lenBλ
		lenA -= lenB;
		while (lenA--) {
			tempA = tempA->next;
		}
		//һ���ж�tempA��tempB�Ƿ����ֱ���ҵ��������
		while (lenB--) {
			if (tempA == tempB) {
				result = tempA; break;
			}
			tempA = tempA->next;
			tempB = tempB->next;
		}
		return result;
	}
};
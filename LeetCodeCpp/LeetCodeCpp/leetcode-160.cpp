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
		//测出A与B的长度
		while (tempA) {
			lenA++;
			tempA = tempA->next;
		}
		while (tempB) {
			lenB++;
			tempB = tempB->next;
		}
		//将长的链表赋给tempA
		if (lenA < lenB) {
			tempA = headB; tempB = headA;
			int temp = lenA;
			lenA = lenB; lenB = temp;
		}
		else {
			tempA = headA; tempB = headB;
		}
		//将tempA从长链表头结点向后移lenA-lenB位
		lenA -= lenB;
		while (lenA--) {
			tempA = tempA->next;
		}
		//一次判断tempA与tempB是否相等直到找到公共结点
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
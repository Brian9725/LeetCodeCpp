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
		//将链表分成长度相当的两部分
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
		//将后半部分链表翻转，并将翻转后的表头给tempB
		tempB = NULL; tempF = back;
		while (tempF != NULL) {
			ListNode *temp = tempF->next;
			tempF->next = tempB; tempB = tempF; tempF = temp;
		}
		//逐个拼接链表
		ListNode *pre = new ListNode(0); tempF = pre;
		while (tempB != NULL) {
			tempF->next = head; head = head->next;
			tempF->next->next = tempB; tempB = tempB->next;
			tempF = tempF->next->next;
		}
		//前半部分可能比后半部分多一个结点
		if (head != back) {
			tempF->next = head;
			tempF->next->next = NULL;
		}
		head = pre->next;
	}
};
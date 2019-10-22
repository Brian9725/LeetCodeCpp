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
		//选出较小的头结点作为新的头结点
		if (l1->val < l2->val) {
			tempNode = l1;
			l1 = l1->next;
		}
		else {
			tempNode = l2;
			l2 = l2->next;
		}
		result = tempNode;
		//每次将较小的结点加到tempNode后面
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
		//如果l1或者l2不为空则将其加到最后面
		if (l1 != NULL) {
			tempNode->next = l1;
		}
		if (l2 != NULL) {
			tempNode->next = l2;
		}
		return result;
	}
};
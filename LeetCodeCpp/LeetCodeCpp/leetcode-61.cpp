#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 0)
			return head;
		//len表示为链表的长度
		int len = 1;
		ListNode *temp = head;
		while (temp->next) {
			temp = temp->next; len++;
		}
		temp->next = head;
		//右移k次相当于将倒数k个结点放在链表头，从head向右移len-k%len次到达倒数第k个结点
		k = len - k % len;
		while (k--) {
			head = head->next;
			temp = temp->next;
		}
		temp->next = NULL;
		return head;
	}
};
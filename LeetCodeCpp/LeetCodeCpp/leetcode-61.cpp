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
		if (head == NULL || k == 0)
			return head;
		//len��ʾΪ����ĳ���
		int len = 1;
		ListNode *temp = head, *tempHead = head, *pre = new ListNode(0);
		while (temp->next) {
			temp = temp->next;
			len++;
		}
		//����k���൱�ڽ�����k������������ͷ����head������len-k%len�ε��ﵹ����k�����
		k = len - k % len;
		if (k == len)
			return head;
		pre->next = head;
		while (k--) {
			head = head->next;
			pre = pre->next;
		}
		pre->next = NULL;
		temp->next = tempHead;
		return head;
	}
};
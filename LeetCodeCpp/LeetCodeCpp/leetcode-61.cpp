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
		//len��ʾΪ����ĳ���
		int len = 1;
		ListNode *temp = head;
		while (temp->next) {
			temp = temp->next; len++;
		}
		temp->next = head;
		//����k���൱�ڽ�����k������������ͷ����head������len-k%len�ε��ﵹ����k�����
		k = len - k % len;
		while (k--) {
			head = head->next;
			temp = temp->next;
		}
		temp->next = NULL;
		return head;
	}
};
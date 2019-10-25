#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;
		//����xС�Ľ��ӵ�small�����У����ڵ���x�ļ���large�У�tempSmallָ��small��������tempLargeָ��large��������
		ListNode *small = new ListNode(0), *large = new ListNode(0), *tempSmall = small, *tempLarge = large, *temp = head;
		small->next = NULL; large->next = NULL;
		while (temp) {
			if (temp->val < x) {
				tempSmall->next = temp;
				tempSmall = tempSmall->next;
			}
			else {
				tempLarge->next = temp;
				tempLarge = tempLarge->next;
			}
			temp = temp->next;
		}
		//���û�б�xС�Ľ�㣬��smallΪ��
		if (small->next) {
			head = small->next;
			tempSmall->next = large->next;
		}
		else
			head = large->next;
		tempLarge->next = NULL;
		return head;
	}
};
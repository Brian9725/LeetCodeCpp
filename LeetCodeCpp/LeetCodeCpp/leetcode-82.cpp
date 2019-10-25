#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		//pre->nextΪ��������ͷ��㣬headָ������������һ��Ԫ��
		ListNode *pre = new ListNode(0), *temp = head;
		pre->next = head;
		head = pre;
		//���ѭ������ʱ���һ����㲢û�з��ʵ���������flag����������һ��Ԫ���Ƿ����ظ�Ԫ��
		bool flag = true;
		while (temp->next) {
			//����������������Ԫ��ֵ���ȣ���ǰһ��������������
			if (temp->next->val != temp->val) {
				head->next = temp;
				head = head->next;
				temp = temp->next;
			}
			else {
				//��temp�ƶ�����һ���͵�ǰ���Ԫ��ֵ��ͬ�Ľ���������ĩβ
				while (temp->next && temp->val == temp->next->val) 
					temp = temp->next;
				//�����ǰ��㲻������ĩβ����˵����ǰԪ�غ�֮ǰ����Ԫ�ز��ظ�
				if (temp->next) {
					temp = temp->next;
					flag = true;
				}
				else
					flag = false;
			}
		}
		//����������һ��Ԫ�ز����ظ�Ԫ�أ��������������
		if (flag) {
			head->next = temp;
			head = head->next;
		}
		head->next = NULL;
		return pre->next;
	}
};
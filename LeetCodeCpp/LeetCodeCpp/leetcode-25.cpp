#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 0 || k == 1)
			return head;
		//temp1ָ���Ѿ���ɽ�������������һ����㣬temp2��temp3ָ��ǰk������ǰ������temp4ָ���k+1�����
		ListNode *temp = NULL, *temp1 = new ListNode(0), *temp2 = NULL, *temp3 = NULL, *temp4 = head;
		temp1->next = head;
		//��headָ���k��Ԫ�أ���k��Ԫ�ؾ���ȫ���������µ�ͷ���
		bool flag = true;
		for (int i = 0; i < k - 1; i++) {
			if (temp4 != NULL)
				temp4 = temp4->next;
			else {
				flag = false;
				break;
			}
		}
		if (flag && temp4 != NULL) {
			head = temp4;
			temp4 = temp1->next;
		}
		else 
			return head;
		//k�����һ�飬ѭ����������β
		while (true) {
			if (temp4 == NULL)
				break;
			bool flag = true;
			temp2 = temp1->next;
			temp3 = temp2->next;
			//��temp4ָ���k+1�����
			temp4 = temp2;
			for (int i = 0; i < k; i++) {
				if (temp4 != NULL)
					temp4 = temp4->next;
				else {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
			temp = temp4;
			//��k�����ӵ�1����ʼ���νӵ�temp4��ǰ��
			while (temp3->next != temp4) {
				temp2->next = temp;
				temp = temp2;
				temp2 = temp3;
				temp3 = temp2->next;
			}
			temp2->next = temp;
			temp3->next = temp2;
			temp1->next = temp3;
			//��temp1�ƶ�����k�����
			while (temp1->next != temp4)
				temp1 = temp1->next;
		}
		return head;
	}

	/*��ǰk����㽻����Ȼ��ݹ�Ժ���������н���
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* pre = head;
		int count = 0;
		//��preָ���k+1�����
		while (pre != NULL && count < k) {
			pre = pre->next;
			count++;
		}
		if (count == k) {
			//�Ժ���������еݹ齻��
			pre = reverseKGroup(pre, k);
			//����ǰ��Ľ��ӵ�pre��ǰ�棬ѭ��k�Σ����k�����ķ�ת
			while (count > 0) {
				ListNode* temp = head->next;
				head->next = pre;
				pre = head;
				head = temp;
				count--;
			}
			head = pre;
		}
		return head;
	}
	*/
};
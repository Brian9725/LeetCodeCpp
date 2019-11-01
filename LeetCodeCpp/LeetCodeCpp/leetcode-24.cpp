#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		//temp2��temp3ָ��ǰ��Ҫ����λ�õ�������㣬temp4ָ�������һ����㣬temp1���������Ѿ���ɽ�������������һ�����
		ListNode *temp1 = NULL, *temp2 = NULL, *temp3 = NULL, *temp4 = NULL;
		temp2 = head; temp3 = temp2->next; temp4 = temp3->next;
		//�Ƚ�ǰ������㽻����Ϊ��ʼ������
		head->next = temp4; temp3->next = head; head = temp3;
		while (temp4 != NULL && temp4->next != NULL) {
			//��ʱ��temp2�Ѿ���������temp3�ĺ��棬temp2�����Ѿ���ɽ�������������һ�����
			temp1 = temp2;
			//��������㽻��
			temp2 = temp4; temp3 = temp2->next; temp4 = temp3->next;
			temp1->next = temp3; temp3->next = temp2; temp2->next = temp4;
		}
		return head;
	}

	/*��ǰ������㽻����Ȼ��ݹ�Ժ���������н���
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *first = head, *second = first->next, *third = second->next;
		second->next = first; head = second;
		first->next = swapPairs(third);
		return head;
	}
	*/
};
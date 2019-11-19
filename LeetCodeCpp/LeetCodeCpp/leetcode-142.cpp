#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//��λ����ָ�������Ľ�㣬����㵽�ý��ĳ�������Ϊ����
	ListNode *hasCycle(ListNode *head) {
		if (head == NULL)
			return NULL;
		//fast�ܵÿ죬slow�ܵ��������fast��׷�ĵ�slow��˵���л�
		ListNode *fast = head, *slow = head;
		while (fast->next && fast->next->next) {
			if (fast->next->next == slow)
				return slow;
			else
				fast = fast->next->next;
			slow = slow->next;
		}
		return NULL;
	}

	ListNode *detectCycle(ListNode *head) {
		ListNode *temp = hasCycle(head), *mHead = head;
		if (temp == NULL)
			return NULL;
		while (mHead != temp) {
			mHead = mHead->next;
			temp = temp->next;
		}
		return mHead;
	}
};
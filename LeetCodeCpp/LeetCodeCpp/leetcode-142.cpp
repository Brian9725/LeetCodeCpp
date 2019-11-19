#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//定位快慢指针相遇的结点，从起点到该结点的长度正好为环长
	ListNode *hasCycle(ListNode *head) {
		if (head == NULL)
			return NULL;
		//fast跑得快，slow跑得慢，如果fast能追的到slow则说明有环
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
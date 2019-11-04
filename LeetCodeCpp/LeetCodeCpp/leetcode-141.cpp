#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return false;
		//fast跑得快，slow跑得慢，如果fast能追的到slow则说明有环
		ListNode *fast = head, *slow = head;
		while (fast->next && fast->next->next) {
			if (fast->next != slow && fast->next->next != slow)
				fast = fast->next->next;
			else
				return true;
			slow = slow->next;
		}
		return false;
	}
};
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//如果head为空，或者删除后整个链表为空则返回NULL
		if (head == NULL || (head->next == NULL && n == 1)) {
			return NULL;
		}
		struct ListNode *tmp1 = new ListNode(0), *tmp2 = new ListNode(0), *pre = new ListNode(0);
		//使用pre作为head的前一个结点便于处于需要删除head的情况
		pre->next = head;
		tmp1 = tmp2 = pre;
		//temp2向后移n次，将指向第n个结点，此时temp1与temp2之间相差n个结点
		for (int i = 0; i < n; i++) {
			tmp2 = tmp2->next;
		}
		//将temp1和temp2同时向后移动，temp2到尾部时，temp1指向倒数第n个结点
		while (tmp2->next != NULL) {
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		tmp1->next = tmp1->next->next;
		return pre->next;
	}
};
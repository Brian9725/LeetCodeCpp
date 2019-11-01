#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL || m == n)
			return head;
		//pre可以当做第0个结点便于处理旋转后头结点变化的情况
		ListNode *pre = new ListNode(0);
		pre->next = head;
		//temp1将指向第m-1号结点，head将指向第m号结点，temp2将指向第m+1号结点，temp3将指向第n号结点
		ListNode *temp1 = pre, *temp2 = head->next, *temp3 = head;
		//将temp3后移n-m位，使head与temp3相差n-m位
		for (int i = 0; i < n - m; i++)
			temp3 = temp3->next;
		//将各指针移动到指定位置
		for (int i = 0; i < m - 1; i++) {
			temp1 = temp1->next;
			head = head->next;
			temp2 = temp2->next;
			temp3 = temp3->next;
		}
		temp1->next = temp3;
		while (head != temp3) {
			head->next = temp3->next;
			temp3->next = head;
			head = temp2;
			temp2 = head->next;
		}
		return pre->next;
	}
};
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
		//temp2和temp3指向当前需要交换位置的两个结点，temp4指向其后面一个结点，temp1用来保存已经完成交换的链表的最后一个结点
		ListNode *temp1 = NULL, *temp2 = NULL, *temp3 = NULL, *temp4 = NULL;
		temp2 = head; temp3 = temp2->next; temp4 = temp3->next;
		//先将前连个结点交换，为初始化操作
		head->next = temp4; temp3->next = head; head = temp3;
		while (temp4 != NULL && temp4->next != NULL) {
			//此时的temp2已经被交换到temp3的后面，temp2才是已经完成交换的链表的最后一个结点
			temp1 = temp2;
			//将两个结点交换
			temp2 = temp4; temp3 = temp2->next; temp4 = temp3->next;
			temp1->next = temp3; temp3->next = temp2; temp2->next = temp4;
		}
		return head;
	}

	/*将前两个结点交换，然后递归对后面的链进行交换
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
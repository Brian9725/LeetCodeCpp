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
		//将比x小的结点加到small链表中，大于等于x的加入large中，tempSmall指向small链表的最后，tempLarge指向large链表的最后
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
		//如果没有比x小的结点，则small为空
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
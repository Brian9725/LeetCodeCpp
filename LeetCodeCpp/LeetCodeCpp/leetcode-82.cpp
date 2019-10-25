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
		//pre->next为结果链表的头结点，head指向结果数组的最后一个元素
		ListNode *pre = new ListNode(0), *temp = head;
		pre->next = head;
		head = pre;
		//外层循环结束时最后一个结点并没有访问到，所以用flag标记链表最后一个元素是否是重复元素
		bool flag = true;
		while (temp->next) {
			//如果连续的两个结点元素值不等，则将前一个结点加入结果链表
			if (temp->next->val != temp->val) {
				head->next = temp;
				head = head->next;
				temp = temp->next;
			}
			else {
				//将temp移动到下一个和当前结点元素值不同的结点或者链表末尾
				while (temp->next && temp->val == temp->next->val) 
					temp = temp->next;
				//如果当前结点不是链表末尾，则说明当前元素和之前所有元素不重复
				if (temp->next) {
					temp = temp->next;
					flag = true;
				}
				else
					flag = false;
			}
		}
		//如果链表最后一个元素不是重复元素，则将其加入结果链表
		if (flag) {
			head->next = temp;
			head = head->next;
		}
		head->next = NULL;
		return pre->next;
	}
};
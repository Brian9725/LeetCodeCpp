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
		//temp1指向已经完成交换的链表的最后一个结点，temp2和temp3指向当前k个结点的前两个，temp4指向第k+1个结点
		ListNode *temp = NULL, *temp1 = new ListNode(0), *temp2 = NULL, *temp3 = NULL, *temp4 = head;
		temp1->next = head;
		//将head指向第k个元素，第k个元素就是全部交换后新的头结点
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
		//k个结点一组，循环交换至链尾
		while (true) {
			if (temp4 == NULL)
				break;
			bool flag = true;
			temp2 = temp1->next;
			temp3 = temp2->next;
			//将temp4指向第k+1个结点
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
			//将k个结点从第1个开始依次接到temp4的前面
			while (temp3->next != temp4) {
				temp2->next = temp;
				temp = temp2;
				temp2 = temp3;
				temp3 = temp2->next;
			}
			temp2->next = temp;
			temp3->next = temp2;
			temp1->next = temp3;
			//将temp1移动到第k个结点
			while (temp1->next != temp4)
				temp1 = temp1->next;
		}
		return head;
	}

	/*将前k个结点交换，然后递归对后面的链进行交换
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* pre = head;
		int count = 0;
		//将pre指向第k+1个结点
		while (pre != NULL && count < k) {
			pre = pre->next;
			count++;
		}
		if (count == k) {
			//对后面的链进行递归交换
			pre = reverseKGroup(pre, k);
			//将最前面的结点加到pre的前面，循坏k次，完成k个结点的翻转
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
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//����СԪ������
	struct cmp {
		bool operator()(ListNode* l1, ListNode* l2) {
			return l1->val > l2->val;
		}
	};

	//ʹ�����ȶ���
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = lists.size();
		if (len == 0) {
			return NULL;
		}
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
		ListNode *result = NULL, *temp = NULL;
		//��ÿ��������Ԫ�ص�ָ��������ȶ��У���ʼ�����ȶ���
		for (int i = 0; i < len; i++) {
			if (lists[i] != NULL) {
				pq.push(lists[i]);
			}
		}
		if (pq.empty()) {
			return NULL;
		}
		//��pq����СԪ������Ϊͷ���
		result = pq.top();
		temp = result;
		pq.pop();
		if (temp->next != NULL) {
			pq.push(temp->next);
		}
		//ÿ��pq��ĳ������Ľ��pop����Ҫ������������һ�����
		while (!pq.empty()) {
			temp->next = pq.top();
			pq.pop();
			if (temp->next->next != NULL) {
				pq.push(temp->next->next);
			}
			temp = temp->next;
		}
		return result;
	}

	/*���η�
	//�ϲ�l1��l2�������뱣֤l1��l2����Ϊ��
	ListNode* merge(ListNode *l1, ListNode *l2) {
		ListNode *result = NULL, *temp = NULL;
		if (l1->val < l2->val) {
			result = l1;
			l1 = l1->next;
		}
		else {
			result = l2;
			l2 = l2->next;
		}
		temp = result;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				temp->next = l1;
				l1 = l1->next;
			}
			else {
				temp->next = l2;
				l2 = l2->next;
			}
			temp = temp->next;
		}
		if (l1)
			temp->next = l1;
		if (l2)
			temp->next = l2;
		return result;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		//idx��ʾ��Ч�����һ��������lists�е��±�
		int idx = lists.size() - 1;
		if (idx < 0)
			return NULL;
		while (idx > 0) {
			for (int i = 0; i <= idx / 2; i++) {
				if (lists[i] == NULL)
					lists[i] = lists[idx - i];
				else if (lists[idx - i] == NULL || i == idx - i)
					continue;
				else
					lists[i] = merge(lists[i], lists[idx - i]);
			}
			idx /= 2;
		}
		return lists[0];
	}
	*/
};
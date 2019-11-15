#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	//�����߶�����ʹ�������ʾ�����������ڵ�Ϊtree[0]
	void buildTree(vector<int>& tree, int idx, vector<int>& heights, int start, int end) {
		if (start == end) {
			tree[idx] = start;
			return;
		}
		int mid = start + (end - start) / 2;
		buildTree(tree, 2 * idx + 1, heights, start, mid);
		buildTree(tree, 2 * idx + 2, heights, mid + 1, end);
		if (heights[tree[2 * idx + 1]] < heights[tree[2 * idx + 2]])
			tree[idx] = tree[2 * idx + 1];
		else
			tree[idx] = tree[2 * idx + 2];
	}

	//��ѯ������Сֵ���±�
	int searchMin(vector<int>& tree, vector<int>& heights, int idx, int treeStart, int treeEnd, int start, int end) {
		if (treeStart == start && treeEnd == end)
			return tree[idx];
		int mid = treeStart + (treeEnd - treeStart) / 2;
		if (end <= mid)
			return searchMin(tree, heights, 2 * idx + 1, treeStart, mid, start, end);
		if (start > mid)
			return searchMin(tree, heights, 2 * idx + 2, mid + 1, treeEnd, start, end);
		int leftIdx = searchMin(tree, heights, 2 * idx + 1, treeStart, mid, start, mid);
		int rightIdx = searchMin(tree, heights, 2 * idx + 2, mid + 1, treeEnd, mid + 1, end);
		if (heights[leftIdx] < heights[rightIdx])
			return leftIdx;
		else
			return rightIdx;
	}

	int dfs(vector<int>& tree, vector<int>& heights, int start, int end) {
		if (start == end)
			return heights[start];
		int minIdx = searchMin(tree, heights, 0, 0, heights.size() - 1, start, end);
		int leftMax = (minIdx == start) ? heights[start] : dfs(tree, heights, start, minIdx - 1);
		int rightMax = (minIdx == end) ? heights[end] : dfs(tree, heights, minIdx + 1, end);
		return max(max(leftMax, rightMax), heights[minIdx] * (end - start + 1));
	}

	int largestRectangleArea(vector<int>& heights) {
		int len = heights.size(), result = 0;
		if (len == 0)
			return result;
		vector<int> tree(4 * len, -1);
		buildTree(tree, 0, heights, 0, len - 1);
		result = dfs(tree, heights, 0, len - 1);
		return result;
	}

	/*ջ����
	int largestRectangleArea(vector<int>& heights) {
		int len = heights.size(), result = 0;
		if (len == 0)
			return result;
		//ջ���ŵ��Ǹ߶ȵ�����Ԫ���±�
		stack<int> st; st.push(-1);
		for (int i = 0; i < len; i++) {
			while (st.top() != -1 && heights[i] < heights[st.top()]) {
				//��heights[st[i]]Ϊ�߶ȵľ��γ���Ϊst[i-1]��i
				int top = st.top(); st.pop();
				result = max(result, heights[top] * (i - st.top() - 1));
			}
			st.push(i);
		}
		//������heights[len-1]Ϊ�ߵľ������
		while (st.top() != -1) {
			//��heights[st[i]]Ϊ�߶ȵľ��γ���Ϊst[i-1]��i
			int top = st.top(); st.pop();
			result = max(result, heights[top] * (len - st.top() - 1));
		}
		return result;
	}
	*/
};
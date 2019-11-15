#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int result = 0, len = height.size();
		stack<int> st;
		for (int i = 0; i < len; i++) {
			while (!st.empty() && height[i] > height[st.top()]) {
				int top = st.top(); st.pop();
				if (st.empty())
					break;
				int distance = i - st.top() - 1;
				int bounded_height = min(height[i], height[st.top()]) - height[top];
				result += distance * bounded_height;
			}
			st.push(i);
		}
		return result;
	}

	/*
	int trap(vector<int>& height) {
		int len = height.size(), result = 0;
		if (len < 3)
			return result;
		int left = 0, right = len - 1, leftMax = 0, rightMax = 0;
		while (left < right) {
			//���height[right]��height[0,left]���ߣ��ܽӶ���ˮ��ȫ��leftMax����
			if (height[left] < height[right]) {
				if (height[left] >= leftMax)
					leftMax = height[left];
				else
					result += leftMax - height[left];
				left++;
			}
			//���height[left]��height[right,len-1]���ߣ��ܽӶ���ˮ��ȫ��rightMax����
			else {
				if (height[right] >= rightMax)
					rightMax = height[right];
				else
					result += rightMax - height[right];
				right--;
			}
		}
		return result;
	}
	*/

	/*
	int trap(vector<int>& height) {
		int len = height.size(), result = 0;
		if (len < 3)
			return result;
		int leftIdx = 0, rightIdx = len - 1;
		for (int i = 1; i < len; i++) {
			if (height[i] >= height[leftIdx]) {
				leftIdx = i; continue;
			}
			result += height[leftIdx] - height[i];
		}
		result -= height[leftIdx] - height[len - 1];
		for (int i = len - 2; i > leftIdx; i--) {
			//�ڵ�1��ѭ���У�result��ӵĲ���Ҫ��ȥ
			result -= height[leftIdx] - height[i];
			if (height[i] >= height[rightIdx]) {
				rightIdx = i; continue;
			}
			result += height[rightIdx] - height[i];
		}
		return result;
	}
	*/

	/*
	int trap(vector<int>& height) {
		int len = height.size(), result = 0;
		if (len < 3)
			return result;
		//leftMax[i]��ʾheight[0,i-1]�����߶ȣ�rightMax[i]��ʾheight[i+1,len-1]�����߶�
		vector<int> leftMax(len, 0), rightMax(len, 0);
		for (int i = 1; i < len; i++) {
			leftMax[i] = max(leftMax[i - 1], height[i - 1]);
		}
		for (int i = len - 2; i >= 0; i--) {
			rightMax[i] = max(rightMax[i + 1], height[i + 1]);
		}
		for (int i = 0; i < len; i++) {
			result += max(0, min(leftMax[i], rightMax[i]) - height[i]);
		}
		return result;
	}
	*/
};
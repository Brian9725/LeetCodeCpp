#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	//栈方法，参见leetcode-84
	int largestRectangleArea(vector<int>& heights) {
		int len = heights.size(), result = 0;
		if (len == 0)
			return result;
		//栈里存放的是高度递增的元素下标
		stack<int> st; st.push(-1);
		for (int i = 0; i < len; i++) {
			while (st.top() != -1 && heights[i] < heights[st.top()]) {
				//以heights[st[i]]为高度的矩形长度为st[i-1]到i
				int top = st.top(); st.pop();
				result = max(result, heights[top] * (i - st.top() - 1));
			}
			st.push(i);
		}
		//考虑以heights[len-1]为高的矩形面积
		while (st.top() != -1) {
			//以heights[st[i]]为高度的矩形长度为st[i-1]到i
			int top = st.top(); st.pop();
			result = max(result, heights[top] * (len - st.top() - 1));
		}
		return result;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		int res = 0, row = matrix.size();
		if (row == 0 || matrix[0].size() == 0)
			return res;
		int col = matrix[0].size();
		vector<int> heights(col, 0);
		for (int i = 0; i < row; i++) {
			//以每一行为底，就算出柱状图
			for (int j = 0; j < col; j++) {
				heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
			}
			res = max(res, largestRectangleArea(heights));
		}
		return res;
	}

	/*
	int maximalRectangle(vector<vector<char>>& matrix) {
		int res = 0, row = matrix.size();
		if (row == 0 || matrix[0].size() == 0)
			return res;
		int col = matrix[0].size();
		vector<int> left(col, 0), right(col, col - 1), height(col, 0);
		int res = 0;
		for (int i = 0; i < row; i++) {
			int cur_left = 0, cur_right = col;
			// update height
			for (int j = 0; j < col; j++) {
				height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
			}
			// update left
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == '1') 
					//left[j]表示高度大于height[j]的左边界限
					left[j] = max(left[j], cur_left);
				else { 
					left[j] = 0; cur_left = j + 1; 
				}
			}
			// update right
			for (int j = col - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') 
					//rightft[j]表示高度大于height[j]的右边界限
					right[j] = min(right[j], cur_right);
				else { 
					right[j] = col; cur_right = j;
				}
			}
			// update area
			for (int j = 0; j < col; j++) {
				res = max(res, (right[j] - left[j]) * height[j]);
			}
		}
		return res;
	}
	*/
};

int main() {
	vector<vector<char>> v = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	};
	Solution().maximalRectangle(v);
	return 0;
}
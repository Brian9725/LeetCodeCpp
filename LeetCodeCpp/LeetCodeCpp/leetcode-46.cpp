#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//将result，tempResult和visit声明在函数外可略微加快运行速度
	void dfs(vector<vector<int>>& result, vector<int>& tempResult, vector<int>& nums, int *visit, int idx, int len) {
		//idx表示已经装入tempResult的元素个数
		if (idx == len) {
			result.push_back(tempResult);
			return;
		}
		for (int i = 0; i < len; i++) {
			if (visit[i] == 0) {
				tempResult.push_back(nums[i]);
				visit[i] = 1;
				dfs(result, tempResult, nums, visit, idx + 1, len);
				tempResult.pop_back();
				visit[i] = 0;
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		//visit记录第i个元素有没有被装入
		int len = nums.size(), *visit = new int[len];
		//初始化visit数组
		for (int i = 0; i < len; i++) {
			visit[i] = 0;
		}
		vector<vector<int>> result;
		vector<int> tempResult;
		dfs(result, tempResult, nums, visit, 0, len);
		return result;
	}
};
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>>& result, vector<int>& tempResult, vector<int>& candidates, int target, int sum, int begin, int len) {
		if (sum == target) {
			result.push_back(tempResult);
			return;
		}
		if (sum > target) 
			return;
		//begin保证每次加入tempResult的数字的下标在candidates中是递增的，保证结果不重复
		//每调用一次for循环，就是向tempResult的新的位置加入一个数
		for (int i = begin; i < len; i++) {
			//如果candidates[i]不是加入tempResult当前位置的第一个数并且和前一个数值相同，则表明tempResult当前位置为candidates[i]的情况已经在result中
			if (i > begin && candidates[i] == candidates[i - 1]) 
				continue;
			tempResult.push_back(candidates[i]);
			dfs(result, tempResult, candidates, target, sum + candidates[i], i + 1, len);
			tempResult.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		//将candidates排序，保证其中的数字递增
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> tempResult;
		int len = candidates.size();
		dfs(result, tempResult, candidates, target, 0, 0, len);
		return result;
	}
};
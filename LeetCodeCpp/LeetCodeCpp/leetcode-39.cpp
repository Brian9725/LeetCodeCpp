#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>>& result,vector<int>& tempResult, vector<int>& candidates, int target, int sum, int begin, int len) {
		if (sum == target) {
			result.push_back(tempResult);
			return;
		}
		if (sum > target) {
			return;
		}
		//begin保证每次加入tempResult的数字的下标在candidates中时非递减的，保证结果不重复
		for (int i = begin; i < len; i++) {
			tempResult.push_back(candidates[i]);
			dfs(result, tempResult, candidates, target, sum + candidates[i], i, len);
			tempResult.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> tempResult;
		int len = candidates.size();
		dfs(result, tempResult, candidates, target, 0, 0, len);
		return result;
	}
};
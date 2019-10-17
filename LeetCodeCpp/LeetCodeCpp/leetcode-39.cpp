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
		//begin��֤ÿ�μ���tempResult�����ֵ��±���candidates��ʱ�ǵݼ��ģ���֤������ظ�
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
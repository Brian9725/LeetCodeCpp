#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> candidates = { 1,2,3,4,5,6,7,8,9 };

	void dfs(vector<vector<int>>& result, vector<int>& tempResult, int target, int sum, int k, int num, int begin) {
		if (sum == target && num == k) {
			result.push_back(tempResult);
			return;
		}
		if (sum > target || num > k)
			return;
		//begin��֤ÿ�μ���tempResult�����ֵ��±���candidates���ǵ����ģ���֤������ظ�
		//ÿ����һ��forѭ����������tempResult���µ�λ�ü���һ����
		for (int i = begin; i < 9; i++) {
			tempResult.push_back(candidates[i]);
			dfs(result, tempResult, target, sum + candidates[i], k, num + 1, i + 1);
			tempResult.pop_back();
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> tempResult;
		dfs(result, tempResult, n, 0, k, 0, 0);
		return result;
	}
};
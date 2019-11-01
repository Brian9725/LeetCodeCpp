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
		//begin��֤ÿ�μ���tempResult�����ֵ��±���candidates���ǵ����ģ���֤������ظ�
		//ÿ����һ��forѭ����������tempResult���µ�λ�ü���һ����
		for (int i = begin; i < len; i++) {
			//���candidates[i]���Ǽ���tempResult��ǰλ�õĵ�һ�������Һ�ǰһ����ֵ��ͬ�������tempResult��ǰλ��Ϊcandidates[i]������Ѿ���result��
			if (i > begin && candidates[i] == candidates[i - 1]) 
				continue;
			tempResult.push_back(candidates[i]);
			dfs(result, tempResult, candidates, target, sum + candidates[i], i + 1, len);
			tempResult.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		//��candidates���򣬱�֤���е����ֵ���
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> tempResult;
		int len = candidates.size();
		dfs(result, tempResult, candidates, target, 0, 0, len);
		return result;
	}
};
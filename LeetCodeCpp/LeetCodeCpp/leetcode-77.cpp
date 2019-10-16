#include<vector>
using namespace std;

class Solution {
public:
	//从begin开始排列，保证后面的数字大于前面的
	void dfs(vector<vector<int>>& result, vector<int>& tempResult, int begin, int n, int k) {
		if (k == 0) {
			result.push_back(tempResult);
			return;
		}
		for (int i = begin; i <= n; i++) {
			tempResult.push_back(i);
			dfs(result, tempResult, i + 1, n, k - 1);
			tempResult.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> tempResult;
		dfs(result, tempResult, 1, n, k);
		return result;
	}
};
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//left表示未放入str的'('个数，right表示未放入str的')'个数
	void dfs(vector<string>& result, string str, int left, int right) {
		if (left == 0 && right == 0) {
			result.push_back(str);
			return;
		}
		//如果剩余的'('比')'多，则此时str已经不符合要求
		if (left > right) {
			return;
		}
		//向str中加入'('
		if (left > 0) {
			dfs(result, str + '(', left - 1, right);
		}
		//向str中加入')'
		if (right > 0) {
			dfs(result, str + ')', left, right - 1);
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n <= 0) {
			return result;
		}
		dfs(result, "", n, n);
		return result;
	}
};
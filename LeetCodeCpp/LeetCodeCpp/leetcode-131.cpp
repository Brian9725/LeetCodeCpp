#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> result;
	vector<string> tempRes;

	//从s中寻找第begin个元素开始的回文串
	void dfs(vector<vector<int>>& dp, string& s, int begin) {
		if (begin == (int)s.size()) {
			result.push_back(tempRes);
			return;
		}
		for (int end = begin; end < (int)s.size(); end++) {
			//如果s[begin,end]是一个回文串，继续寻找第end+1个元素开始的回文串
			if (dp[begin][end] == 1) {
				tempRes.push_back(s.substr(begin, end - begin + 1));
				dfs(dp, s, end + 1);
				tempRes.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		int len = s.size();
		//dp[i][j]保存s[i,j]是否为一个回文串
		vector<vector<int>> dp(len, vector<int>(len, 0));
		//初始化dp数组
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (i == j)
					dp[i][j] = 1;
			}
		}
		//这里i表示回文串的长度，j表示回文串第1个元素的下标
		for (int i = 2; i <= len; i++) {
			for (int j = 0; j <= len - i; j++) {
				//如果当前判断的回文串长度是2
				if (i == 2 && s[j] == s[j + 1]) {
					dp[j][j + 1] = 1; continue;
				}
				//如果当前判断的回文串长度不是2则需判断s[j]=s[j+i-1]和s[j+1,j+i-2]是否为回文串
				if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2] == 1)
					dp[j][j + i - 1] = 1;
			}
		}
		dfs(dp, s, 0);
		return result;
	}
};
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int minCut(string s) {
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
		//result[i]保存切割s[0,i]需要的最小次数
		vector<int> result(len, len - 1);
		for (int i = 0; i < len; i++) {
			if (dp[0][i] == 1) {
				result[i] = 0; continue;
			}
			for (int j = 0; j < i; j++) {
				if (dp[j + 1][i] == 1)
					result[i] = min(result[i], result[j] + 1);
			}
		}
		return result[len - 1];
	}
};
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> num;
		vector<char> op;
		//将input分成num和op
		int inputLen = input.size(), inputBegin = 0;
		for (int i = 0; i < inputLen; ++i) {
			if (input[i] < '0' || input[i] > '9') {
				num.push_back(stoi(input.substr(inputBegin, i - inputBegin)));
				op.push_back(input[i]);
				inputBegin = i + 1;
			}
		}
		num.push_back(stoi(input.substr(inputBegin)));
		int len = num.size();
		vector<vector<vector<int>>> dp(len, vector<vector<int>>(len));
		//初始化dp数组
		for (int i = 0; i < len; ++i) {
			dp[i][i].push_back(num[i]);
		}
		for (int length = 2; length <= len; ++length) {
			for (int begin = 0; begin <= len - length; ++begin) {
				for (int opIdx = begin; opIdx < begin + length - 1; ++opIdx) {
					//将dp[begin][opIdx]和dp[opIdx][begin+length-1]中的数依次运算
					for (int i = 0; i < (int)dp[begin][opIdx].size(); ++i) {
						for (int j = 0; j < (int)dp[opIdx + 1][begin + length - 1].size(); ++j) {
							if (op[opIdx] == '+')
								dp[begin][begin + length - 1].push_back(dp[begin][opIdx][i] + dp[opIdx + 1][begin + length - 1][j]);
							if (op[opIdx] == '-')
								dp[begin][begin + length - 1].push_back(dp[begin][opIdx][i] - dp[opIdx + 1][begin + length - 1][j]);
							if (op[opIdx] == '*')
								dp[begin][begin + length - 1].push_back(dp[begin][opIdx][i] * dp[opIdx + 1][begin + length - 1][j]);
						}
					}
				}
			}
		}
		return dp[0][len - 1];
	}
};
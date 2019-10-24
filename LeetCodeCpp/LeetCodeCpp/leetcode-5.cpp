#include<iostream>
#include<string>
using namespace std;

int dp[1005][1005];

class Solution {
public:
	//此为动态规划算法，时间复杂度O(n?)，还有一种Manacher算法，时间复杂度O(n)
	string longestPalindrome(string s) {
		int len = s.size(), head = 0, tail = 0;
		//初始化dp数组，dp[i][j]保存以s[i,j]是否为一个回文串
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (i == j) 
					dp[i][j] = 1;
				else 
					dp[i][j] = -1;
			}
		}
		//这里i表示回文串的长度，j表示回文串第1个元素的下标
		for (int i = 2; i <= len; i++) {
			for (int j = 0; j <= len - i; j++) {
				//如果当前判断的回文串长度是2
				if (i == 2) {
					if (s[j] == s[j + 1]) {
						dp[j][j + 1] = 1;
						head = j;
						tail = j + 1;
					}
					else 
						dp[j][j + 1] = 0;
				}
				//如果当前判断的回文串长度不是2则需判断s[j]=s[j+i-1]和s[j+1,j+i-2]是否为回文串
				else {
					if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2] == 1) {
						dp[j][j + i - 1] = 1;
						head = j;
						tail = j + i - 1;
					}
					else 
						dp[j][j + i - 1] = 0;
				}
			}
		}
		string result = "";
		for (int i = head; i <= tail; i++)
			result += s[i];
		return result;
	}
};
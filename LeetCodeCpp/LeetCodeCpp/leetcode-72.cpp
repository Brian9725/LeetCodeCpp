#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size(), len2 = word2.size();
		if (len1 == 0)
			return len2;
		if (len2 == 0)
			return len1;
		//dp[i][j]��ʾword1��ǰi���ַ����word2��ǰj���ַ���Ҫ����
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
		for (int i = 0; i <= len1; i++)
			dp[i][0] = i;
		for (int i = 0; i <= len2; i++)
			dp[0][i] = i;
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				//���word1�ĵ�i���ַ���word2�ĵ�j���ַ���ͬ����dp[i][j]=dp[i-1][j-1]
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				//���word1�ĵ�i���ַ���word2�ĵ�j���ַ���ͬ����dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
		return dp[len1][len2];
	}
};
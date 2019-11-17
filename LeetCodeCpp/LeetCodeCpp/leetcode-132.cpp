#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		//dp[i][j]����s[i,j]�Ƿ�Ϊһ�����Ĵ�
		vector<vector<int>> dp(len, vector<int>(len, 0));
		//��ʼ��dp����
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (i == j)
					dp[i][j] = 1;
			}
		}
		//����i��ʾ���Ĵ��ĳ��ȣ�j��ʾ���Ĵ���1��Ԫ�ص��±�
		for (int i = 2; i <= len; i++) {
			for (int j = 0; j <= len - i; j++) {
				//�����ǰ�жϵĻ��Ĵ�������2
				if (i == 2 && s[j] == s[j + 1]) {
					dp[j][j + 1] = 1; continue;
				}
				//�����ǰ�жϵĻ��Ĵ����Ȳ���2�����ж�s[j]=s[j+i-1]��s[j+1,j+i-2]�Ƿ�Ϊ���Ĵ�
				if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2] == 1)
					dp[j][j + i - 1] = 1;
			}
		}
		//result[i]�����и�s[0,i]��Ҫ����С����
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
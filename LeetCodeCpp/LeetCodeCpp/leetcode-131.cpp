#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> result;
	vector<string> tempRes;

	//��s��Ѱ�ҵ�begin��Ԫ�ؿ�ʼ�Ļ��Ĵ�
	void dfs(vector<vector<int>>& dp, string& s, int begin) {
		if (begin == (int)s.size()) {
			result.push_back(tempRes);
			return;
		}
		for (int end = begin; end < (int)s.size(); end++) {
			//���s[begin,end]��һ�����Ĵ�������Ѱ�ҵ�end+1��Ԫ�ؿ�ʼ�Ļ��Ĵ�
			if (dp[begin][end] == 1) {
				tempRes.push_back(s.substr(begin, end - begin + 1));
				dfs(dp, s, end + 1);
				tempRes.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
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
		dfs(dp, s, 0);
		return result;
	}
};
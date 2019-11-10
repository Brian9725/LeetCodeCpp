#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int lenS = s.size(), lenT = t.size();
		if (lenS == 0 && lenT == 0)
			return 1;
		if (lenS == 0 || lenT == 0 || lenS < lenT)
			return 0;
		//��Ȼ���Ľ�����ᳬ��int��Χ�������м����ᳬ��int��Χ
		//dp[i][j]��ʾt��ǰi���ַ���s��ǰj���ַ�ƥ��Ľ����
		vector<vector<long long>> dp(lenT + 1, vector<long long>(lenS + 1, 0));
		for (int i = 0; i <= lenT; i++) {
			for (int j = 0; j <= lenS; j++) {
				if (i == 0) {
					dp[i][j] = 1; continue;
				}
				if (j == 0) {
					dp[i][j] = 0; continue;
				}
				//���t�е�i���ַ���s�е�j���ַ����ȣ�dp[i][j]=dp[i][j-1]
				//�����ȣ�dp[i][j]=dp[i][j-1]+dp[i-1][j-1]
				dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
			}
		}
		return dp[lenT][lenS];
	}
};
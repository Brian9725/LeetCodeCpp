#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	//��leetcode-123�ƹ㲢�Ż��ռ临�Ӷ�
	int maxProfit(int k, vector<int>& prices) {
		int days = prices.size();
		if (days < 2 || k < 1)
			return 0;
		//���һ�ν�������Ҫ���죬���Ե�k����������һ��ʱ�����������ɽ����������
		if (k >= days / 2) {
			//�˲��ִ���Ϊleetcode-122
			int result = 0;
			for (int i = 1; i < days; i++) {
				if (prices[i] - prices[i - 1] > 0)
					result += prices[i] - prices[i - 1];
			}
			return result;
		}
		vector<vector<int>> dp(k + 1, vector<int>(2, 0));
		for (int i = 0; i <= k; i++) {
			dp[i][1] = INT_MIN;
		}
		for (int i = 1; i <= days; i++) {
			//����dp[i][k][1]ʱ��Ҫ�õ�dp[i-1][j-1][0]����dp�Ż��ɶ�ά��dp[i-1][j-1][0]�ᱻ���ǣ�������temp��¼����
			//dp�Ķ���μ�leetcode-123
			int temp = dp[0][0];
			for (int j = 1; j <= k; j++) {
				dp[j][0] = max(dp[j][0], dp[j][1] + prices[i - 1]);
				dp[j][1] = max(dp[j][1], temp - prices[i - 1]);
				temp = dp[j][0];
			}
		}
		return dp[k][0];
	}
};
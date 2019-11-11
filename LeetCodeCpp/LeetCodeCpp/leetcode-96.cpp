#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		//dp[i]��ʾ[1..i]��ɵĶ�������������
		vector<int> dp(n + 1, 0);
		dp[0] = 1; dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			//һ�ν�1��i��Ϊ���ڵ�(��Ϊj)����������������j-1��i-1-j����㣬����������Ҳ�Ƕ���������
			for (int j = 0; j < i; j++)
				dp[i] += dp[j] * dp[i - 1 - j];
		}
		return dp[n];
	}

	/*���Ϊ������������C(n,2n)/(n+1)���������õ��ƹ�ʽCn=Cn-1*(4n-2)/(n+1)
	int numTrees(int n) {
		long long result = 1;
		for (int i = 2; i <= n; i++) {
			result = result * (4 * i - 2) / (i + 1);
		}
		return (int)result;
	}
	*/
};
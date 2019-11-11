#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		//dp[i]表示[1..i]组成的二叉搜索树个数
		vector<int> dp(n + 1, 0);
		dp[0] = 1; dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			//一次将1到i作为根节点(设为j)，则左右子树各有j-1和i-1-j个结点，且左右子树也是二叉搜索树
			for (int j = 0; j < i; j++)
				dp[i] += dp[j] * dp[i - 1 - j];
		}
		return dp[n];
	}

	/*结果为卡特兰数，即C(n,2n)/(n+1)，可以利用递推公式Cn=Cn-1*(4n-2)/(n+1)
	int numTrees(int n) {
		long long result = 1;
		for (int i = 2; i <= n; i++) {
			result = result * (4 * i - 2) / (i + 1);
		}
		return (int)result;
	}
	*/
};
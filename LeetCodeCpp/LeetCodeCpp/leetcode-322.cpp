#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		//result[i]表示找零i元需要的硬币数量，初始化为-1
		int *result = new int[amount + 1], coinsLen = coins.size();
		memset(result, -1, sizeof(int)*(amount + 1));
		result[0] = 0;
		for (int i = 1; i <= amount; i++) {
			//如果有面值为i的硬币，找零i元只需一个硬币
			if (find(coins.begin(), coins.end(), i) != coins.end()) {
				result[i] = 1;
				continue;
			}
			//如果没有面值为i的硬币，则使用其他硬币找零
			for (int j = 0; j < coinsLen; j++) {
				//i需要大于第j个硬币的面值，并且i-coins[j]元能够被找零
				if (i > coins[j] && result[i - coins[j]] != -1)
					//采取更好的找零方式
					if (result[i] == -1 || result[i] > result[i - coins[j]] + 1)
						result[i] = result[i - coins[j]] + 1;
			}
		}
		return result[amount];
	}

	/*贪心法，每次都选用最大面额的硬币
	void dfs(vector<int>& coins, int start, int target, int cur, int& res) {
		if (start < 0) 
			return;
		//仅使用当前面额的硬币就可以找零，则直接返回，因为当前硬币已经是最大面额
		if (target % coins[start] == 0) {
			res = min(res, cur + target / coins[start]);
			return;
		}
		//尽可能多使用大面额硬币
		for (int i = target / coins[start]; i >= 0; i--) {
			//如果当前已经使用的硬币加上i个当前面额的硬币已经超过了某个解，则可以直接返回
			//因为target已经不可能整除coins[start]，所以只考虑cur+i < res-1的情况即可
			if (cur + i >= res - 1) 
				break;
			dfs(coins, start - 1, target - i * coins[start], cur + i, res);
		}
	}

	int coinChange(vector<int>& coins, int amount) {
		int res = INT_MAX, n = coins.size();
		//将硬币按面额大小递增排序
		sort(coins.begin(), coins.end());
		dfs(coins, n - 1, amount, 0, res);
		return (res == INT_MAX) ? -1 : res;
	}
	*/
};
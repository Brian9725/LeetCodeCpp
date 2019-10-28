#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		//result[i]��ʾ����iԪ��Ҫ��Ӳ����������ʼ��Ϊ-1
		int *result = new int[amount + 1], coinsLen = coins.size();
		memset(result, -1, sizeof(int)*(amount + 1));
		result[0] = 0;
		for (int i = 1; i <= amount; i++) {
			//�������ֵΪi��Ӳ�ң�����iԪֻ��һ��Ӳ��
			if (find(coins.begin(), coins.end(), i) != coins.end()) {
				result[i] = 1;
				continue;
			}
			//���û����ֵΪi��Ӳ�ң���ʹ������Ӳ������
			for (int j = 0; j < coinsLen; j++) {
				//i��Ҫ���ڵ�j��Ӳ�ҵ���ֵ������i-coins[j]Ԫ�ܹ�������
				if (i > coins[j] && result[i - coins[j]] != -1)
					//��ȡ���õ����㷽ʽ
					if (result[i] == -1 || result[i] > result[i - coins[j]] + 1)
						result[i] = result[i - coins[j]] + 1;
			}
		}
		return result[amount];
	}

	/*̰�ķ���ÿ�ζ�ѡ���������Ӳ��
	void dfs(vector<int>& coins, int start, int target, int cur, int& res) {
		if (start < 0) 
			return;
		//��ʹ�õ�ǰ����Ӳ�ҾͿ������㣬��ֱ�ӷ��أ���Ϊ��ǰӲ���Ѿ���������
		if (target % coins[start] == 0) {
			res = min(res, cur + target / coins[start]);
			return;
		}
		//�����ܶ�ʹ�ô����Ӳ��
		for (int i = target / coins[start]; i >= 0; i--) {
			//�����ǰ�Ѿ�ʹ�õ�Ӳ�Ҽ���i����ǰ����Ӳ���Ѿ�������ĳ���⣬�����ֱ�ӷ���
			//��Ϊtarget�Ѿ�����������coins[start]������ֻ����cur+i < res-1���������
			if (cur + i >= res - 1) 
				break;
			dfs(coins, start - 1, target - i * coins[start], cur + i, res);
		}
	}

	int coinChange(vector<int>& coins, int amount) {
		int res = INT_MAX, n = coins.size();
		//��Ӳ�Ұ�����С��������
		sort(coins.begin(), coins.end());
		dfs(coins, n - 1, amount, 0, res);
		return (res == INT_MAX) ? -1 : res;
	}
	*/
};
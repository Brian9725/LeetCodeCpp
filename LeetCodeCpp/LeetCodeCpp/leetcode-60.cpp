#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void dfs(vector<char>& tempResult, int *nums, int *visit, int idx, int n, int& cnt, int k) {
		//cnt�����Ѿ������ڼ�������
		if (cnt == k) {
			return;
		}
		//idxΪ�Ѿ�װ��tempResult���ַ�����
		if (idx == n) {
			cnt++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (visit[i] == 0) {
				tempResult.push_back(nums[i] + 48);
				visit[i] = 1;
				dfs(tempResult, nums, visit, idx + 1, n, cnt, k);
				//һ��������k�����У�Ҫ�������pop�����Ա���tempResult
				if (cnt == k) {
					return;
				}
				tempResult.pop_back();
				visit[i] = 0;
			}
		}
	}
	
	string getPermutation(int n, int k) {
		//nums��¼n��������visit��¼n�������Ƿ�װ��
		int *nums = new int[n], *visit = new int[n];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			nums[i] = i + 1;
			visit[i] = 0;
		}
		vector<char> tempResult;
		dfs(tempResult, nums, visit, 0, n, cnt, k);
		string str = "";
		for (int i = 0; i < n; i++) {
			str += tempResult[i];
		}
		return str;
	}

	//���õķ���
	/*
	����n = 5, k = 35,
	nΪ5��ȫ���о�����λΪ1 - 5���������е�����
	1_, , , 2, , , 3, , , 4, , , 5, , , ÿ������24�����У����12345��ȫ����
	����k = 35<48, Ҳ����˵��35���϶�����λΪ2��ȫ�������, ���Ե�һ��ȡ2��
	���������ǿ���ʣ��1345���ĸ�����ȫ�������ȡ��k = 35 - 24 = 11����
	1, , 3, , 4, , 5, , ÿ������6�����У����1345��ȫ���У�
	����k = 11<12, Ҳ����˵��11���϶�����λΪ3��ȫ������ߣ����Եڶ�����ȡ3
	���������ǿ���ʣ��145����������ȫ�������ȡ��k = 11 - 6 = 5����
	1, 4, 5, _ÿ������2�����У����145��ȫ����
	����k = 5<6, Ҳ����˵��5���϶�����λΪ5��ȫ������ߣ����Ե�������ȡ5
	���������ǿ���ʣ��14�����������������ȡ��k = 5 - 4 = 1��
	1_4_ÿ������1�����У����14�����У�
	����k = 1, ���Ե��ĸ���ȡ1
	������ʣ�µ����һ��4���������23514
	������
	*/
	/*
	string getPermutation(int n, int k) {
		string result;
		string num = "123456789";
		//f[i-1]�б�����i�Ľ׳�
		vector<int> f(n, 1);
		for (int i = 1; i < n; i++) {
			f[i] = f[i - 1] * i;
		}
		//��k��1��Ϊ����[0,i!-1]�����ж�Ӧ��num[i-1]
		k--;
		//i��ʾ�����м�����
		for (int i = n; i >= 1; i--) {
			int j = k / f[i - 1];
			k %= f[i - 1];
			result.push_back(num[j]);
			num.erase(j, 1);
		}
		return result;
	}
	*/
};

//int main() {
//	Solution().getPermutation(9, 3);
//	return 0;
//}
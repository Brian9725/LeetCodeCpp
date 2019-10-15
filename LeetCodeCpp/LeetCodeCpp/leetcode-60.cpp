#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void dfs(vector<char>& tempResult, int *nums, int *visit, int idx, int n, int& cnt, int k) {
		//cnt计数已经产生第几个排列
		if (cnt == k) {
			return;
		}
		//idx为已经装入tempResult的字符个数
		if (idx == n) {
			cnt++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (visit[i] == 0) {
				tempResult.push_back(nums[i] + 48);
				visit[i] = 1;
				dfs(tempResult, nums, visit, idx + 1, n, cnt, k);
				//一旦产生第k个排列，要避免进行pop操作以保存tempResult
				if (cnt == k) {
					return;
				}
				tempResult.pop_back();
				visit[i] = 0;
			}
		}
	}
	
	string getPermutation(int n, int k) {
		//nums记录n个整数，visit记录n个整数是否被装入
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

	//更好的方法
	/*
	假设n = 5, k = 35,
	n为5的全排列就是首位为1 - 5的如下排列的所有
	1_, , , 2, , , 3, , , 4, , , 5, , , 每个各有24个排列，组成12345的全排列
	由于k = 35<48, 也就是说第35个肯定在首位为2的全排列里边, 所以第一个取2。
	接下来就是考虑剩下1345这四个数的全排列里边取第k = 35 - 24 = 11个，
	1, , 3, , 4, , 5, , 每个各有6个排列，组成1345的全排列，
	由于k = 11<12, 也就是说第11个肯定在首位为3的全排列里边，所以第二个数取3
	接下来就是考虑剩下145这三个数的全排列里边取第k = 11 - 6 = 5个，
	1, 4, 5, _每个各有2个排列，组成145的全排列
	由于k = 5<6, 也就是说第5个肯定在首位为5的全排列里边，所以第三个数取5
	接下来就是考虑剩下14这两个数的排列里边取第k = 5 - 4 = 1个
	1_4_每个各有1个排列，组成14的排列，
	由于k = 1, 所以第四个数取1
	最后加上剩下的最后一个4，结果就是23514
	结束。
	*/
	/*
	string getPermutation(int n, int k) {
		string result;
		string num = "123456789";
		//f[i-1]中保存了i的阶乘
		vector<int> f(n, 1);
		for (int i = 1; i < n; i++) {
			f[i] = f[i - 1] * i;
		}
		//将k减1是为了让[0,i!-1]个排列对应到num[i-1]
		k--;
		//i表示现在有几个数
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
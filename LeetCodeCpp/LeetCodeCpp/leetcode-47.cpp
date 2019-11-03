#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//将result，tempResult和visit声明在函数外可略微加快运行速度
	void dfs(vector<vector<int>>& result, vector<int>& tempResult, vector<int>& nums, int *visit, int idx, int len) {
		//idx表示已经装入tempResult的元素个数
		if (idx == len) {
			result.push_back(tempResult);
			return;
		}
		for (int i = 0; i < len; i++) {
			if (visit[i] == 0) {
				//如果nums[i]和nums[i-1]相等并且nums[i-1]没有被装入（nums[i-1]在之前必然被装入过），则说明该位置数值等于nums[i]的情况已经全在result中
				if (i > 0 && nums[i] == nums[i - 1] && visit[i-1] == 0) 
					continue;
				tempResult.push_back(nums[i]);
				visit[i] = 1;
				dfs(result, tempResult, nums, visit, idx + 1, len);
				tempResult.pop_back();
				visit[i] = 0;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		//visit记录第i个元素有没有被装入
		int len = nums.size(), *visit = new int[len];
		//初始化visit数组
		for (int i = 0; i < len; i++) 
			visit[i] = 0;
		vector<vector<int>> result;
		vector<int> tempResult;
		dfs(result, tempResult, nums, visit, 0, len);
		return result;
	}
};
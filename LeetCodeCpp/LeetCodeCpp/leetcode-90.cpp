#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//dfs������nums[begin..nums.size()-1]���ҳ����г���Ϊnum���Ӽ�
	void dfs(vector<vector<int>>& result, vector<int>& tempRes, vector<int>& nums, int begin, int num) {
		if (num == 0) {
			result.push_back(tempRes);
			return;
		}
		for (int i = begin; i < nums.size(); i++) {
			//����Ӽ��ĵ�һ��Ԫ����ǰһ����ͬ����˵����һ��Ԫ�ص��ڸ�ֵ������Ѿ�ȫ���ҵ�
			if (i > begin && nums[i] == nums[i - 1])
				continue;
			tempRes.push_back(nums[i]);
			//��nums[i]ȷ��Ϊ�Ӽ��ĵ�һ��Ԫ�غ�ֻ����nums[i+1..nums.size()-1]���ҳ����г���Ϊnum-1���Ӽ�
			dfs(result, tempRes, nums, i + 1, num - 1);
			tempRes.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		int len = nums.size();
		if (len == 0)
			return result;
		//����nums����
		sort(nums.begin(), nums.end());
		vector<int> tempRes;
		for (int i = 0; i < len + 1; i++) {
			//�ҳ����г��ȵ�i���Ӽ�
			dfs(result, tempRes, nums, 0, i);
		}
		return result;
	}
};
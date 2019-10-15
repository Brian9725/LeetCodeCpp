#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//��result��tempResult��visit�����ں��������΢�ӿ������ٶ�
	void dfs(vector<vector<int>>& result, vector<int>& tempResult, vector<int>& nums, int *visit, int idx, int len) {
		//idx��ʾ�Ѿ�װ��tempResult��Ԫ�ظ���
		if (idx == len) {
			result.push_back(tempResult);
			return;
		}
		for (int i = 0; i < len; i++) {
			if (visit[i] == 0) {
				tempResult.push_back(nums[i]);
				visit[i] = 1;
				dfs(result, tempResult, nums, visit, idx + 1, len);
				tempResult.pop_back();
				visit[i] = 0;
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		//visit��¼��i��Ԫ����û�б�װ��
		int len = nums.size(), *visit = new int[len];
		//��ʼ��visit����
		for (int i = 0; i < len; i++) {
			visit[i] = 0;
		}
		vector<vector<int>> result;
		vector<int> tempResult;
		dfs(result, tempResult, nums, visit, 0, len);
		return result;
	}
};
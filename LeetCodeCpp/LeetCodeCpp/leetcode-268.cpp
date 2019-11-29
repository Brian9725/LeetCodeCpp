#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		//���n��0�Ƿ���nums��
		int idxN = -1, idx0 = -1;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == n)
				idxN = i;
			if (nums[i] == 0)
				idx0 = i;
		}
		if (idxN == -1) return n;
		if (idx0 == -1) return 0;
		//��nums�����������ʾ�����Ƿ����
		nums[idx0] = n;
		for (int i = 0; i < n; ++i) {
			int idx = abs(nums[i]);
			if (idx == n)
				continue;
			nums[idx] = 0 - abs(nums[idx]);
		}
		for (int i = 1; i < n; ++i) {
			if (nums[i] > 0)
				return i;
		}
		return 0;
	}
};
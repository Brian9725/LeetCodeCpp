#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		if (len == 1) {
			if (nums[0] == 1)
				return 2;
			else
				return 1;
		}
		//����Ƿ�������1
		bool hasOne = false;
		for (int i = 0; i < len; i++) {
			if (nums[i] == 1) {
				hasOne = true; break;
			}
		}
		if (!hasOne)
			return 1;
		//��С��1�ʹ���len������1����
		for (int i = 0; i < len; i++) {
			if (nums[i] < 1 || nums[i] > len)
				nums[i] = 1;
		}
		//nums[i]Ϊ������i+1������nums��
		for (int i = 0; i < len; i++) {
			nums[abs(nums[i]) - 1] = 0 - abs(nums[abs(nums[i]) - 1]);
		}
		for (int i = 0; i < len; i++) {
			if (nums[i] > 0)
				return i + 1;
		}
		return len + 1;
	}
};
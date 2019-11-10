#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//ones��ʾ����һ�εĶ�����λ��ɵ�����twos���ӳ������εĶ�����λ��ɵ���
		int ones = 0, twos = 0, len = nums.size();
		for (int i = 0; i < len; i++) {
			ones = (ones ^ nums[i]) & (~twos);
			twos = (twos ^ nums[i]) & (~ones);
		}
		return ones;
	}
};
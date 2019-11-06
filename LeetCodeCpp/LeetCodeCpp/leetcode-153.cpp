#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//��leetcode-33����
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return -1;
		//minIdxΪ��СԪ�ص��±�
		int low = 0, high = len - 1, minIdx = 0;
		while (low <= high) {
			//nums[0]�Ǵ���nums[len-1]�ģ�����������������ж�minIdx�Ĵ���λ��
			minIdx = (low + high) / 2;
			if (minIdx > 0 && nums[minIdx] < nums[minIdx - 1])
				break;
			//���nums[minIdx]��nums[len-1]��С�����������Сֵ��nums[len-1]֮��
			else if (nums[minIdx] < nums[len - 1])
				high = minIdx - 1;
			//���nums[minIdx]��nums[0]�����������nums[0]����Сֵ֮��
			else
				low = minIdx + 1;
		}
		return nums[minIdx];
	}
};
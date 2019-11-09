#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return -1;
		//minIdxΪ��СԪ�ص��±�
		int low = 0, high = len - 1, minIdx = 0;
		while (low <= high) {
			minIdx = (low + high) / 2;
			//nums[minIdx]<nums[high]ʱ��minIdx����СԪ�غ�nums[high]֮�䣬���ܵ�����СԪ��
			if (nums[minIdx] < nums[high])
				high = minIdx;
			//nums[minIdx]>nums[high]ʱ��minIdx��nums[low]����СԪ��֮�䣬�����ܵ�����СԪ��
			else if (nums[minIdx] > nums[high])
				low = minIdx + 1;
			//nums[minIdx]=nums[high]ʱ���޷��ж�minIdx�ľ���λ��
			//��ʱminIdx<=high�����minIdx<high����high-1���Ա�֤��СԪ������nums[low..high]�У����minIdx=high������low=high���Ѿ��ҵ����
			else
				high--;
		}
		return nums[minIdx];
	}
};
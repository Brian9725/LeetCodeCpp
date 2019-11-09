#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//��nums[low..high]�϶��ֲ���target
	int binSearch(vector<int>& nums, int low, int high, int target) {
		int result = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (target == nums[mid]) {
				result = mid; break;
			}
			else if (target >= nums[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
		return result;
	}

	//����leetcode-154
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0)
			return false;
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
			else {
				//�����nums[high]<nums[high-1]����high-1��Ȼ�����ҵ����±�minIdxҲ����СԪ�ص��±꣬��������ת����±�
				if (high > 0 && nums[high] >= nums[high - 1])
					high--;
				else {
					minIdx = high; break;
				}
			}
		}
		int result = -1, mid = 0;
		if (minIdx == 0)
			result = binSearch(nums, 0, len - 1, target);
		//��nums[0..minIdx-1]�϶��ֲ���target
		else if (target >= nums[0])
			result = binSearch(nums, 0, minIdx - 1, target);
		//��nums[minIdx..len-1]�϶��ֲ���target
		else if (target <= nums[len - 1])
			result = binSearch(nums, minIdx, len - 1, target);
		else
			result = -1;
		if (result == -1)
			return false;
		return true;
	}
};
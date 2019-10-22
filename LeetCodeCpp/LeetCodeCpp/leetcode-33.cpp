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
				result = mid;
				break;
			}
			else if (target >= nums[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
		return result;
	}

	//�ȶ��ֲ��������е���Сֵ������СֵΪ�����Խ�����ֳ���������������飬Ȼ���ٶ��ֲ���
	int search(vector<int>& nums, int target) {
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
		return result;
	}
};
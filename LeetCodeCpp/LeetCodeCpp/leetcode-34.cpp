#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		if (nums.size() == 0) {
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		//���ֲ��Ҹ�Ԫ���Ƿ����
		int low = 0, high = nums.size() - 1, mid = 0;
		bool exist = false;
		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target) {
				exist = true; break;
			}
			else if (nums[mid] > target) 
				high = mid - 1;
			else 
				low = mid + 1;
		}
		if (!exist) {
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		//��ǰ��β���Ԫ�ص�һ�γ��ֵ�λ��
		low = 0; high = mid;
		int tempMid = 0;
		while (low < high) {
			tempMid = (low + high) / 2;
			if (nums[tempMid] == target) 
				high = tempMid;
			else 
				low = tempMid + 1;
		}
		result.push_back(low);
		//�ں��β���Ԫ�����һ�γ��ֵ�λ��
		low = mid; high = nums.size() - 1;
		while (low < high) {
			tempMid = (low + high) / 2 + 1;
			if (nums[tempMid] == target) 
				low = tempMid;
			else 
				high = tempMid - 1;
		}
		result.push_back(high);
		return result;
	}
};
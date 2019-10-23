#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//idxΪ���һ��ʹ��nums[idx]<num[idx+]���±꣬idx֮�������ȫ�����ǵ�������
		int len = nums.size(), idx = 0, j = idx + 1, k = len - 1;
		for (int i = len - 1; i > 0; i--) {
			if (nums[i] > nums[i - 1]) {
				idx = i - 1;
				break;
			}
		}
		//��nums[idx]��������һ������������ֽ���λ��
		bool isChanged = false;
		for (int i = idx + 1; i < len; i++) {
			if (nums[i] <= nums[idx]) {
				swap(nums[idx], nums[i - 1]);
				isChanged = true;
				//���nums[idx]����������н���������Ҫ��nums[idx..len-1]���򣬷���nums[idx+1..len-1]����
				if (i == idx + 1)
					j = idx;
				else
					j = idx + 1;
				break;
			}
		}
		//���֮ǰһֱû�н�������nums[idx]��nums[len-1]����
		if (!isChanged) {
			swap(nums[idx], nums[len - 1]);
			j = idx + 1;
		}
		//���ǵ������е�nums[j..k]����ǵݼ�����
		while (j < k) {
			swap(nums[j], nums[k]);
			j++; k--;
		}
	}
};
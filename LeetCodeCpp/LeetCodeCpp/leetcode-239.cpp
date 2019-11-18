#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		vector<int> res, left(len), right(len);
		if (len == 0 || k == 0)
			return res;
		if (k == 1)
			return nums;
		//��nums��k��һ��ֿ飬���һ�����û��k��Ԫ�أ�begin��end�ֱ��ʾ��������յ�
		//left[i]��ʾ��ÿ����Ŀ�ʼ����i��Ԫ�ص����ֵ��right[i]��ʾ�ӿ�Ľ�������i��Ԫ�ص����ֵ
		int begin = 0, end = 0;
		while (begin < len) {
			//ȷ����ǰ��������յ�
			if (begin + k < len)
				end = begin + k - 1;
			else
				end = len - 1;
			left[begin] = nums[begin]; right[end] = nums[end];
			for (int i = begin + 1; i <= end; i++) {
				left[i] = max(left[i - 1], nums[i]);
				right[end - (i - begin)] = max(right[end - (i - begin) + 1], nums[end - (i - begin)]);
			}
			begin = end + 1;
		}
		for (int i = 0; i <= len - k; i++) {
			res.push_back(max(left[i + k - 1], right[i]));
		}
		return res;
	}
};
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	//�������ڷ�
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int res = INT_MAX, len = nums.size(), begin = 0, end = 0, sum = nums[begin];
		while (end < len) {
			//flag���end�Ƿ񵽴�ĩβ
			bool flag = false;
			while (sum < s) {
				if (end == len - 1) {
					flag = true; break;
				}
				sum += nums[++end];
			}
			if (flag) break;
			//��ʱnums[begin,end]�Ѿ���һ���ʹ���s���Ӵ������Խ�������
			while (sum - nums[begin] > s) {
				sum -= nums[begin++];
			}
			//����resֵ����begin����һλ��ʼ��һ�ֵĴ���
			res = min(res, end - begin + 1);
			sum -= nums[begin++];
		}
		if (res == INT_MAX) res = 0;
		return res;
	}
};
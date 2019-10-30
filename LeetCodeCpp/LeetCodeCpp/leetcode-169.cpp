#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//������Ԫ�أ����ִ����������֣���ͬ������һ������Ԫ��
	int majorityElement(vector<int>& nums) {
		int len = nums.size(), result = nums[0], cnt = 1;
		for (int i = 1; i < len; i++) {
			if (result == nums[i])
				cnt++;
			else {
				if (cnt == 0) {
					result = nums[i];
					cnt = 1;
				}
				cnt--;
			}
		}
		return result;
	}
};
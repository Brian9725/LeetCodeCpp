#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//与求主元素（出现次数最多的数字）相同，众数一定是主元素
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
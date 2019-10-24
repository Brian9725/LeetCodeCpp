#include<vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int numsSize = nums.size();
		if (numsSize == 0)
			return 0;
		int tail = numsSize - 1;
		for (int i = 0; i <= tail; i++) {
			if (nums[i] == val) {
				nums[i] = nums[tail];
				i--; tail--;
			}
		}
		return ++tail;
	}
};
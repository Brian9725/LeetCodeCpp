#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//resultNum表示已经不重复的子数组下标
		int resultNum = 0, tempNum = 1, numsSize = nums.size();
		if (numsSize == 0)
			return 0;
		while (tempNum < numsSize) {
			if (nums[tempNum] != nums[tempNum - 1])
				nums[++resultNum] = nums[tempNum];
			tempNum++;
		}
		return resultNum + 1;
	}
};
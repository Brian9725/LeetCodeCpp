#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//resultNum表示已经不重复的子数组下标
		int resultNum = 0, tempNum = 1, numsSize = nums.size();
		//isSecond表示当前数字是否已经遇到两次
		bool isSecond = false;
		if (numsSize == 0)
			return 0;
		while (tempNum < numsSize) {
			//如果当前数字和前一个相等，需继续判断是否已经遇到过两次
			if (nums[tempNum] == nums[tempNum - 1]) {
				if (!isSecond) {
					isSecond = true;
					nums[++resultNum] = nums[tempNum];
				}
			}
			else {
				isSecond = false;
				nums[++resultNum] = nums[tempNum];
			}
			tempNum++;
		}
		return resultNum + 1;
	}
};
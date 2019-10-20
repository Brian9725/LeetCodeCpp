#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		//p0指向已经排好的0后面一个位置，p1指向已经排好的2前面一个位置
		int len = nums.size(), p0 = 0, p1 = len - 1;
		for (int i = 0; i <= p1; ) {
			//如果nums[i]=0，将nums[i]和nums[p0]交换并更新p0，此外需保证i在p0和p1之间
			if (nums[i] == 0) {
				nums[i] = nums[p0];
				nums[p0] = 0;
				p0++;
				if (i < p0) {
					i = p0;
				}
			}
			else if (nums[i] == 1) {
				i++;
			}
			//如果nums[i]=2，将nums[i]和nums[p1]交换并更新p1
			else {
				nums[i] = nums[p1];
				nums[p1] = 2;
				p1--;
			}
		}
	}
};
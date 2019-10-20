#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		//nums按非递减排序
		sort(nums.begin(), nums.end());
		int len = nums.size();
		if (len < 3) {
			return result;
		}
		for (int i = 0; i < len - 2; i++) {
			//nums[i]为三个数中的最小数，如果其大于0，三数之和必然大于0
			if (nums[i] > 0) {
				break;
			}
			//nums[i]为三数中的第一个数，如果其之前已经出现过，则为了保证无重复性需跳过
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int j = i + 1, k = len - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					result.push_back(temp);
					//同nums[i]，为了保证结果无重复性需跳过
					while (j + 1 < len && nums[j + 1] == nums[j]) {
						j++;
					}
					j++;
					//同nums[i]，为了保证结果无重复性需跳过
					while (k - 1 > -1 && nums[k - 1] == nums[k]) {
						k--;
					}
					k--;
				}
				else if (nums[i] + nums[j] + nums[k] > 0) {
					k--;
				}
				else {
					j++;
				}
			}
		}
		return result;
	}
};
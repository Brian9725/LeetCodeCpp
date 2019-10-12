#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		int len = nums.size();
		for (int i = 0; i < len - 1; i++) {
			int temp = target - nums[i];
			for (int j = i + 1; j < len; j++) {
				if (temp == nums[j]) {
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
};

int main() {
	vector<int> temp;
	temp.push_back(2);
	temp.push_back(7);
	temp.push_back(11);
	temp.push_back(15);
	cout << Solution().twoSum(temp, 9)[0] << " " << Solution().twoSum(temp, 9)[1];
	return 0;
}
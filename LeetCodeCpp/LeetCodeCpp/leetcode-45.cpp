#include<vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size(), result = 1;
		if (len == 0 || len == 1) 
			return 0;
		for (int i = 0; i < len; ) {
			//distance为从第i个出发最远能跳到的位置
			int distance = i + nums[i];
			if (distance >= len - 1) 
				return result;
			//这次跳跃跳到使得下次跳跃能最远的位置上
			int maxDis = 0;
			for (int j = i + 1; j <= distance; j++) 
				if (j + nums[j] >= maxDis) {
					maxDis = j + nums[j];
					i = j;
				}
			result++;
		}
		return result;
	}
};
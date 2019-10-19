#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		//k��ʾ��ǰ�ܵ������Զλ��
		int k = 0, len = nums.size();
		for (int i = 0; i < len; i++) {
			if (i > k) {
				return false;
			}
			k = max(k, i + nums[i]);
		}
		return true;
	}
};
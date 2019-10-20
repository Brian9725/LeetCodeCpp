#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		//p0ָ���Ѿ��źõ�0����һ��λ�ã�p1ָ���Ѿ��źõ�2ǰ��һ��λ��
		int len = nums.size(), p0 = 0, p1 = len - 1;
		for (int i = 0; i <= p1; ) {
			//���nums[i]=0����nums[i]��nums[p0]����������p0�������豣֤i��p0��p1֮��
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
			//���nums[i]=2����nums[i]��nums[p1]����������p1
			else {
				nums[i] = nums[p1];
				nums[p1] = 2;
				p1--;
			}
		}
	}
};
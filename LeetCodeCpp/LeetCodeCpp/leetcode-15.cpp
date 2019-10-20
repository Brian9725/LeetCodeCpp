#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		//nums���ǵݼ�����
		sort(nums.begin(), nums.end());
		int len = nums.size();
		if (len < 3) {
			return result;
		}
		for (int i = 0; i < len - 2; i++) {
			//nums[i]Ϊ�������е���С������������0������֮�ͱ�Ȼ����0
			if (nums[i] > 0) {
				break;
			}
			//nums[i]Ϊ�����еĵ�һ�����������֮ǰ�Ѿ����ֹ�����Ϊ�˱�֤���ظ���������
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
					//ͬnums[i]��Ϊ�˱�֤������ظ���������
					while (j + 1 < len && nums[j + 1] == nums[j]) {
						j++;
					}
					j++;
					//ͬnums[i]��Ϊ�˱�֤������ظ���������
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
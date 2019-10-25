#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int len = nums.size(), sum = 0;
		vector<vector<int>> result;
		for (int i = 0; i < len - 3; i++) {
			//���nums[i]ǰ����ֹ���Ϊ�˱�֤�ⲻ�ظ���Ҫ�����Թ�����ͬ
			if (i > 0 && nums[i] == nums[i - 1]) 
				continue;
			for (int j = i + 1; j < len - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) 
					continue;
				for (int head = j + 1, tail = len - 1; head < tail;) {
					if (head > j + 1 && nums[head] == nums[head - 1]) {
						head++;
						continue;
					}
					if (tail < len - 1 && nums[tail] == nums[tail + 1]) {
						tail--;
						continue;
					}
					sum = nums[i] + nums[j] + nums[head] + nums[tail];
					if (sum > target) 
						tail--;
					else if (sum < target) 
						head++;
					else {
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]); 
						temp.push_back(nums[head]);
						temp.push_back(nums[tail]);
						result.push_back(temp);
						//����Ѿ��ҵ���������head++��tail--�����ܵõ��µĽ⣬��ʹ��Ҳ���ظ���
						head++;
						tail--;
					}
				}
			}
		}
		return result;
	}
};
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0 || k == 0 || k%nums.size() == 0) return;
		int len = nums.size(), n = len, idx = 0, cur = 0, temp = nums[idx];
		k %= n;
		while (n--) {
			int next = (cur + len - k) % len;
			if (next == idx) {
				nums[cur] = temp; 
				idx++; cur = idx; temp = nums[idx];
				continue;
			}
			nums[cur] = nums[(cur + len - k) % len];
			cur = (cur + len - k) % len;
		}
	}
};
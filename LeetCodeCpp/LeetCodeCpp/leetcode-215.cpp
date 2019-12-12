#include<iostream>
#include<functional>
#include<queue>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < (int)nums.size(); ++i) {
			pq.push(nums[i]);
			if ((int)pq.size() > k) pq.pop();
		}
		return pq.top();
	}
};
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int idx = m + n - 1;
		while (m > 0 || n > 0) {
			if (m == 0) 
				nums1[idx--] = nums2[--n];
			else if (n == 0) 
				nums1[idx--] = nums1[--m];
			else {
				if (nums1[m - 1] >= nums2[n - 1]) 
					nums1[idx--] = nums1[--m];
				else 
					nums1[idx--] = nums2[--n];
			}
		}
	}
};
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int len = citations.size(), low = 0, high = len - 1, result = 0;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (citations[mid] < len - mid)
				low = mid + 1;
			else {
				result = len - mid;
				if (citations[mid] > len - mid) 
					high = mid - 1;
				else
					break;
			}
		}
		return result;
	}
};
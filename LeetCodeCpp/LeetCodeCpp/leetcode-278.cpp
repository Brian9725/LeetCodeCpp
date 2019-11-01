#include<iostream>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int low = 1, high = n, mid = 1;
		while (low <= high) {
			//防止(low+high)/2溢出
			mid = low + (high - low) / 2;
			if (isBadVersion(mid))
				high = mid - 1;
			else
				low = mid + 1;
		}
		//有可能mid指向第一个错误版本的前一个
		if (!isBadVersion(mid))
			return mid + 1;
		return mid;
	}
};
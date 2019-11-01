#include<iostream>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int low = 1, high = n, mid = 1;
		while (low <= high) {
			//��ֹ(low+high)/2���
			mid = low + (high - low) / 2;
			if (isBadVersion(mid))
				high = mid - 1;
			else
				low = mid + 1;
		}
		//�п���midָ���һ������汾��ǰһ��
		if (!isBadVersion(mid))
			return mid + 1;
		return mid;
	}
};
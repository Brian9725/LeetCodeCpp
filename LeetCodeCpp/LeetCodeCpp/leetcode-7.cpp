#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int result = 0, tmpMax = INT_MAX / 10, tempMin = INT_MIN / 10;
		while (x) {
			if (result > tmpMax || result < tempMin ||
				(result == tmpMax && x % 10 > 7) || (result == tempMin && x % 10 > 8)) {
				return 0;
			}
			result = result * 10 + x % 10;
			x /= 10;
		}
		return result;
	}
};
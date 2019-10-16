#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int result = 0;
		while (x) {
			if (result > 214748364 || result < -214748364 || 
				(result == 214748364 && x % 10 > 7) || (result == -214748364 && x % 10 > 8)) {
				return 0;
			}
			result = result * 10 + x % 10;
			x /= 10;
		}
		return result;
	}
};
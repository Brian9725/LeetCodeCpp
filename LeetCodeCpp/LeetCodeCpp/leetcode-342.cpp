#include<iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0)
			return false;
		if (num == 1)
			return true;
		if (num % 4 != 0)
			return false;
		return isPowerOfFour(num / 4);
	}
};
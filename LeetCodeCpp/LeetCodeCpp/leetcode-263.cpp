#include<iostream>
using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0)
			return false;
		if (num == 5 || num == 3 || num == 2 || num == 1)
			return true;
		if (num % 5 == 0)
			return isUgly(num / 5);
		if (num % 3 == 0)
			return isUgly(num / 3);
		if (num % 2 == 0)
			return isUgly(num / 2);
		return false;
	}
};
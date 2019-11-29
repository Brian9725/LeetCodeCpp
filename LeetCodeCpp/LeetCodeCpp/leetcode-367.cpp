#include<iostream>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		int n = 1;
		while (num > 0) {
			num -= n;
			if (num == 0) return true;
			n += 2;
		}
		return false;
	}
};
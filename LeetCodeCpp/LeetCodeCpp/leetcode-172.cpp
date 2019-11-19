#include<iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int five = 0;
		while (n >= 5) {
			five += n / 5;
			n /= 5;
		}
		return five;
	}
};
#include<iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		for (int i = 1;; i++) {
			if (x / i < i) 
				return i - 1;
		}
	}
};
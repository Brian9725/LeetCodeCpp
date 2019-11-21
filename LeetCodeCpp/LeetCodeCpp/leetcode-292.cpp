#include<iostream>
using namespace std;

class Solution {
public:
	//ÕÒ¹æÂÉ
	bool canWinNim(int n) {
		if (n % 4 == 0)
			return false;
		return true;
	}
};
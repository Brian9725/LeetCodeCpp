#include<iostream>
using namespace std;

class Solution {
public:
	//�ҹ���
	bool canWinNim(int n) {
		if (n % 4 == 0)
			return false;
		return true;
	}
};
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		digits[len - 1] += 1;
		for (int i = len - 1; i > 0; i--) {
			if (digits[i] > 9) {
				digits[i] -= 10;
				digits[i - 1] += 1;
			}
			else {
				break;
			}
		}
		if (digits[0] < 10) 
			return digits;
		else {
			vector<int> result;
			result.push_back(1);
			result.push_back(0);
			for (int i = 1; i < len; i++)
				result.push_back(digits[i]);
			return result;
		}
	}
};
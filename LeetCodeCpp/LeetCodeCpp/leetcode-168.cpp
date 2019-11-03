#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string result = "", tempRes = "A";
		while (n > 0) {
			n -= 1;
			int temp = n % 26;
			n /= 26;
			tempRes = 'A' + temp;
			result = tempRes + result;
		}
		return result;
	}
};
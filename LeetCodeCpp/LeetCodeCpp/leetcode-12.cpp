#include<string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string result = "";
		int q = num / 1000;
		num %= 1000;
		if (q != 0) {
			for (int i = 0; i < q; i++)
				result += 'M';
		}
		int b = num / 100;
		num %= 100;
		if (b == 9) {
			result += 'C';
			result += 'M';
			b = 0;
		}
		else if (b >= 5) {
			result += 'D';
			b -= 5;
		}
		if (b == 4) {
			result += 'C';
			result += 'D';
		}
		else {
			for (int i = 0; i < b; i++)
				result += 'C';
		}
		int s = num / 10;
		num %= 10;
		if (s == 9) {
			result += 'X';
			result += 'C';
			s = 0;
		}
		else if (s >= 5) {
			result += 'L';
			s -= 5;
		}
		if (s == 4) {
			result += 'X';
			result += 'L';
		}
		else {
			for (int i = 0; i < s; i++)
				result += 'X';
		}
		if (num == 9) {
			result += 'I';
			result += 'X';
			num = 0;
		}
		else if (num >= 5) {
			result += 'V';
			num -= 5;
		}
		if (num == 4) {
			result += 'I';
			result += 'V';
		}
		else {
			for (int i = 0; i < num; i++)
				result += 'I';
		}
		return result;
	}
};
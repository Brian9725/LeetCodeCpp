#include<string>
using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string result = "";
		result += address[0];
		int len = address.size();
		for (int i = 1; i < len; i++) {
			if (address[i] == '.') {
				result += '[';
				result += '.';
				result += ']';
			}
			else
				result += address[i];
		}
		return result;
	}
};
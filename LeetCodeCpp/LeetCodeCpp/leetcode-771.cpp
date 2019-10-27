#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int result = 0, lenJ = J.size(), lenS = S.size();
		for (int i = 0; i < lenS; i++) {
			for (int j = 0; j < lenJ; j++) {
				if (S[i] == J[j]) {
					result++;
					break;
				}
			}
		}
		return result;
	}
};
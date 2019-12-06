#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int bulls = 0, cows = 0, len = secret.size();
		int sec[10] = { 0 }, gue[10] = { 0 };
		for (int i = 0; i < len; ++i) {
			if (secret[i] == guess[i]) bulls++;
			sec[secret[i] - '0']++;
			gue[guess[i] - '0']++;
		}
		for (int i = 0; i < 10; ++i) {
			cows += min(sec[i], gue[i]);
		}
		cows -= bulls;
		string res = to_string(bulls) + "A" + to_string(cows) + "B";
		return res;
	}
};
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int game(vector<int>& guess, vector<int>& answer) {
		int res = 0, len = guess.size();
		for (int i = 0; i < len; ++i) {
			if (guess[i] == answer[i]) res++;
		}
		return res;
	}
};
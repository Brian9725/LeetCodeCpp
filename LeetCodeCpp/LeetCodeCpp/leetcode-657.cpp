#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int v = 0, h = 0, len = moves.size();
		for (int i = 0; i < len; ++i) {
			if (moves[i] == 'U')
				v++;
			if (moves[i] == 'D')
				v--;
			if (moves[i] == 'L')
				h--;
			if (moves[i] == 'R')
				h++;
		}
		if (v == 0 && h == 0)
			return true;
		return false;
	}
};
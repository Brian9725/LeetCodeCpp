#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	//从后往前，从下往上dp求出到每个位置需要的最小血量
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int lenR = dungeon.size(), lenC = dungeon[0].size();
		for (int i = lenR - 1; i >= 0; i--) {
			for (int j = lenC - 1; j >= 0; j--) {
				if (j == lenC - 1) {
					if (i == lenR - 1)
						dungeon[i][j] = (1 - dungeon[i][j] <= 0) ? 1 : 1 - dungeon[i][j];
					else
						dungeon[i][j] = (dungeon[i + 1][j] - dungeon[i][j] <= 0) ? 1 : dungeon[i + 1][j] - dungeon[i][j];
				}
				else if (i == lenR - 1)
					dungeon[i][j] = (dungeon[i][j + 1] - dungeon[i][j] <= 0) ? 1 : dungeon[i][j + 1] - dungeon[i][j];
				else {
					dungeon[i][j] = min(dungeon[i][j + 1], dungeon[i + 1][j]) - dungeon[i][j];
					if (dungeon[i][j] <= 0) {
						dungeon[i][j] = 1;
					}
				}
			}
		}
		return dungeon[0][0];
	}
};
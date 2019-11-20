#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int lenA = C - A, widA = D - B;
		int lenB = G - E, widB = H - F;
		int sA = lenA*widA, sB = lenB*widB, sC = 0;
		int lenC = min(C, G) > max(A, E) ? (min(C, G) - max(A, E)) : 0;
		int widC = min(D, H) > max(B, F) ? (min(D, H) - max(B, F)) : 0;
		return sA - lenC*widC + sB;
	}
};
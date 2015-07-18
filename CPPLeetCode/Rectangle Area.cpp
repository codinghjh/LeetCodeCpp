#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	bool xU = false, yU = false;
	if (A <= E&&C >= E || E <= A&&G >= A)
		xU = true;
	if (F >= B&&F <= D || B >= F&&B <= H)
		yU = true;
	if (xU&&yU)
	{
		int xStart = max(A, E);
		int yStart = max(F, B);
		int xEnd = min(C, G);
		int yEnd = min(D, H);
		return (C - A)*(D - B) + (G - E)*(H - F) - (xEnd - xStart)*(yEnd - yStart);
	}
	else
		return (C - A)*(D - B) + (G - E)*(H - F);

}
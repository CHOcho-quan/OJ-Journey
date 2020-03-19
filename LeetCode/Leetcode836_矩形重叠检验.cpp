#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int ld_x = max(rec1[0], rec2[0]), ld_y = max(rec1[1], rec2[1]);
    int ru_x = min(rec1[2], rec2[2]), ru_y = min(rec1[3], rec2[3]);

    if (ru_x - ld_x > 0 && ru_y - ld_y > 0) return true;
    return false;
}

int main()
{
    // YES
}

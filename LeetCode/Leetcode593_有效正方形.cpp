class Solution {
public:
    int vectorMult(vector<int>& v1, vector<int>& v2) {
        return v1[0] * v2[0] + v1[1] * v2[1];
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int cnt = 0;
        vector<vector<int>> vs = { {p1[0] - p2[0], p1[1] - p2[1]}, {p1[0] - p3[0], p1[1] - p3[1]},
                                    {p1[0] - p4[0], p1[1] - p4[1]}, {p2[0] - p3[0], p2[1] - p3[1]},
                                    {p4[0] - p2[0], p4[1] - p2[1]}, {p4[0] - p3[0], p4[1] - p3[1]} };
        for (int i = 0; i < vs.size(); ++i) {
            if (vs[i][0] == 0 && vs[i][1] == 0) return false;
            for (int j = i + 1; j < vs.size(); ++j) {
                if (vectorMult(vs[i], vs[j]) == 0) ++cnt;
            }
        }
        cout << cnt;

        return cnt == 5;
    }
};
class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        
        queue<pair<int, int>> q;
        q.push(pair<int, int>(sr, sc));
        int she = image[sr][sc];
        visited[sr][sc] = true;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [r, c] = q.front();
                q.pop();
                if (image[r][c] == she) {
                    image[r][c] = newColor;
                } else continue;
                for (int i = 0; i < 4; ++i) {
                    int nsr = r + direction[i], nsc = c + direction[i + 1];
                    if (nsr < 0 || nsc < 0 || nsr >= image.size() || nsc >= image[0].size() || visited[nsr][nsc]) continue;
                    visited[nsr][nsc] = true;
                    q.push(pair<int, int>(nsr, nsc));
                }
            }
        }
        
        return image;
    }
};

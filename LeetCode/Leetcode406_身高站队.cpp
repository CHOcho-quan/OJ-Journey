class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.size() == 0) return people;
        vector<vector<int>> result;
        sort(people.begin(), people.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });
        if (people.size() == 1) return people;
        
        // for (auto& r : people) {
        //     std::cout << r[0] << ' ' << r[1] << " = ";
        // }
        // std::cout << '\n';
        
        int zeros = 0;
        for (; zeros < people.size(); ++zeros) {
            if (people[zeros][1]) break;
            result.insert(result.begin(), people[zeros]);
        }
        
        for (int i = zeros; i < people.size(); ++i) {
            int cnt = 0;
            bool inserted = false;
            for (int j = 0; j < result.size(); ++j) {
                if (result[j][0] >= people[i][0]) {
                    if (++cnt == people[i][1]) {
                        inserted = true;
                        result.insert(result.begin() + j + 1, people[i]);
                        break;
                    }
                }
            }
            if (!inserted) {
                result.push_back(people[i]);
            }
        }
        
        return result;
    }
};

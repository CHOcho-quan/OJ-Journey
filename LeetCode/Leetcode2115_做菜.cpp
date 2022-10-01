class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        auto supply_set = set<string>(supplies.begin(), supplies.end());
        auto recipe_set = set<string>(recipes.begin(), recipes.end());
        unordered_map<string, set<string>> needed_recipes;
        unordered_map<string, int> indegree;
        queue<string> q;
        for (int i = 0; i < ingredients.size(); ++i) {
            bool flag = true;
            for (int j = 0; j < ingredients[i].size(); ++j) {
                if (supply_set.find(ingredients[i][j]) == supply_set.end()) {
                    flag = false;
                    needed_recipes[recipes[i]].insert(ingredients[i][j]);
                    ++indegree[recipes[i]];
                }
            }
            if (flag) {
                supply_set.insert(recipes[i]);
                indegree[recipes[i]] = 0;
                q.push(recipes[i]);
                res.push_back(recipes[i]);
            } 
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto& iter : needed_recipes) {
                // founded
                if (iter.second.find(cur) != iter.second.end()) {
                    if (!(--indegree[iter.first])) {
                        q.push(iter.first);
                        res.push_back(iter.first);
                    }
                }                
            }
        }

        return res;
    }
};
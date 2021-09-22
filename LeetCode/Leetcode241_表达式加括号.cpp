class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        bool flag = false;
        int last = 0;
        for (int i = 0; i < input.length(); ++i) {
            auto n = input[i];
            if (n >='0' && n <= '9') continue;
            flag = true;
            auto l = diffWaysToCompute(input.substr(last, i - last));
            auto r = diffWaysToCompute(input.substr(i + 1, input.length()));
            for (auto li : l) {
                for (auto ri : r) {
                    switch (input[i]) {
                        case '+': {
                            result.push_back(li + ri);
                            break;
                        }
                        case '-': {
                            result.push_back(li - ri);
                            break;
                        }
                        case '*': {
                            result.push_back(li * ri);
                            break;
                        }
                    }
                }
            }
        }
        
        if (!flag) return {stoi(input)};
        
        return result;
    }
};

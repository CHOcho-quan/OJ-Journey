class Solution {
public:
    bool judgeCircle(string moves) {
        int ud = 0, lr = 0;
        for (auto& m : moves) {
            switch(m) {
                case 'L': {
                    --lr;
                    break;
                }
                case 'R': {
                    ++lr;
                    break;
                }
                case 'U': {
                    ++ud;
                    break;
                }
                case 'D': {
                    --ud;
                    break;
                }
            }
        }
        return ud == 0 && lr == 0;
    }
};

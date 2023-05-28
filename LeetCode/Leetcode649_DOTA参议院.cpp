class Solution {
public:
    string predictPartyVictory(string senate) {
        int d = 0, r = 0, nd = 0, nr = 0;
        int both = 3;
        string next = "";
        while (both == 3) {
            both = 0;
            next = "";
            for (auto& senator : senate) {
                if (senator == 'R') {
                    both |= 1;
                    if (nr != 0) --nr;
                    else {
                        next += senator;
                        ++nd;
                        ++r;
                    }
                } else {
                    both |= 2;
                    if (nd != 0) --nd;
                    else {
                        next += senator;
                        ++nr; // nr 0 r 4
                        ++d; // nd 0 d 4
                    }
                }
            }
            senate = next;
        }

        return both == 1 ? "Radiant" : "Dire";
        
    }
};
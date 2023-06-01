// class HitCounter {
// private:
//     vector<int> times;
//     vector<int> hits;
// public:
//     HitCounter() {
//         times = vector<int>(301, 0);
//         hits = vector<int>(301, 0);
//     }
    
//     void hit(int timestamp) {
//         int ind = timestamp % 300;
//         if (times[ind] != timestamp) {
//             times[ind] = timestamp;
//             hits[ind] = 1;
//         } else ++hits[ind];
//     }
    
//     int getHits(int timestamp) {
//         int total = 0;
//         for (int i = 0; i < 300; ++i) {
//             if (timestamp - times[i] < 300) total += hits[i];
//         }
//         return total;
//     }
// };

class HitCounter {
private:
    queue<int> times;
public:
    HitCounter() {}
    
    void hit(int timestamp) {
        times.push(timestamp);
        if (!times.empty() && timestamp - times.front() >= 300) times.pop();
    }
    
    int getHits(int timestamp) {
        if (times.empty()) return 0;
        while (timestamp - times.front() >= 300) {
            times.pop();
            if (times.empty()) break;
        }

        return times.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
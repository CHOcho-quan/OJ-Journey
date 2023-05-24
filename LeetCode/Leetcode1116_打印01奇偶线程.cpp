class ZeroEvenOdd {
private:
    int n;
    bool ze{true};
    bool finished{false};
    int cnt{1};
    mutex mut;
    condition_variable cond;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (cnt <= n) {
            unique_lock<mutex> l(mut);
            if (cnt > n) break;
            printNumber(0);
            // cout << 0 <<' ';
            ze = false;
            cond.notify_all();
            cond.wait(l, [this]() -> bool { return ze || finished; });
        }
        finished = true;
        cond.notify_all();
    }

    void even(function<void(int)> printNumber) {
        while (cnt <= n) {
            unique_lock<mutex> l(mut);
            cond.wait(l, [this]() -> bool { return (!ze && cnt % 2 == 0) || finished; });
            if (cnt > n) break;
            printNumber(cnt);
            // cout << cnt <<' ';
            ++cnt;
            ze = true;
            cond.notify_all();
        }
        finished = true;
        cond.notify_all();
    }

    void odd(function<void(int)> printNumber) {
        while (cnt <= n) {
            unique_lock<mutex> l(mut);
            cond.wait(l, [this]() -> bool { return (!ze && cnt % 2) || finished; });
            if (cnt > n) break;
            printNumber(cnt);
            // cout << cnt <<' ';
            ++cnt;
            ze = true;
            cond.notify_all();
        }
        finished = true;
        cond.notify_all();
    }
};
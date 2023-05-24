class FooBar {
private:
    int n;
    int cnt{0};
    mutex mut;
    condition_variable cond;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> l(mut);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ++cnt;
            cond.notify_all();
            cond.wait(l, [this]() -> bool { return cnt % 2 == 0; });
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> l(mut);
            cond.wait(l, [this]() -> bool { return cnt % 2; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ++cnt;
            cond.notify_all();
        }
    }
};
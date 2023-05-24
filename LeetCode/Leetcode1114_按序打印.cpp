class Foo {
private:
    atomic<int> cnt{0};
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++cnt;
    }

    void second(function<void()> printSecond) {
        while (cnt != 1) this_thread::yield();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++cnt;
    }

    void third(function<void()> printThird) {
        while (cnt != 2) this_thread::yield();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
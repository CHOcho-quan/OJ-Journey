template <typename T>
class SharedPtr {
  public:
    SharedPtr(T* ptr = nullptr) : _pPtr(ptr), _pRefCount(new int(1)) {}

    SharedPtr(const SharedPtr<T>& sp) {
        if (_pPtr != sp._pPtr) {
            Release();
            _pPtr = sp._pPtr;
            _pRefCount = sp._pRefCount;
            AddRefCount();
        }

        return *this;
    }

    T& operator*() {
        return *_pPtr;
    }
    T* operator->() {
        return _pPtr;
    }
    T* Get() { return _pPtr; }
    void AddRefCount() {
        ++(*_pRefCount);
    }

    ~SharedPtr() {
        Release();
    }

  private:
    void Release() {
        if (--(*_pRefCount) == 0) {
            delete _pRefCount;
            delete _pPtr;
        }
    }

    int *_pRefCount;
    T* _pPtr;
};
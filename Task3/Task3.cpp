#include <iostream>
#include <cstdlib>

template<typename T>
class unique_ptr {
private:
    T* __ptr{ nullptr };

public:
    unique_ptr(T* ptr) : __ptr(ptr) {}
    unique_ptr(const unique_ptr&) = delete;

    ~unique_ptr() {
        delete __ptr;
        __ptr = nullptr;
    }

    unique_ptr& operator=(const unique_ptr&) = delete;
    T& operator*() const { return *__ptr; }
    T* release() {
        T* OldUP{ __ptr };
        __ptr = nullptr;
        return OldUP;
    }
};

int main() {
    unique_ptr ptr1(new int(10));
    unique_ptr ptr2(new double(11.11));
    std::cout << *ptr1 << " " << *ptr2 << std::endl;

    return EXIT_SUCCESS;
}
//
//  object_traits.h
//  Allocators
//  credits: (code blacksmith) http://code-blacksmith.com/custom-allocator-with-statistics/
//

#ifndef allocator_h
#define allocator_h

#include <iostream>

using namespace std;

template<typename T>
class TrackingAllocator {
public:
    // define bunch of alias for later use
    // mandatory alias
    using value_type = T;
    
    // optional alias
    using ptr = T*;
    using const_ptr = const T*;
    using void_ptr = void *;
    using const_void_ptr = const void *;
    using size_type = size_t;
    using diff_type = std::ptrdiff_t;
    
    template<class U>
    struct rebind {
        using other = TrackingAllocator<U>;
    };
    
    
    TrackingAllocator() = default;
    
    template<class U>
    TrackingAllocator(const TrackingAllocator<U>&  other) {
        // copy here
    }
    
    ~TrackingAllocator() = default;
    
    // actual allocate and deallocate functions
    ptr allocate(size_type nobjs) {
        mAllocations += nobjs;
        cout << "allocating " << nobjs << endl;
        return static_cast<ptr>(operator new(sizeof(value_type)*nobjs));
    }
    
    // overload with locality hint
    ptr allocate(size_type nobjs, const_void_ptr hint) {
        mAllocations += nobjs;
        return allocate(nobjs);
    }
    
    void deallocate(ptr p, size_type nobjs) {
        cout << "deallocating " << nobjs << endl;
        operator delete(p);
    }
    
    size_type max_size() const {
        return std::numeric_limits<size_type>::max();
    }
    
    // construct the actual object here. doesn't necessarily have to be of type T.
    // Hence the type U.
    template<class U, class ...Args>
    void construct(U* p, Args&& ...args) {
        cout << "constructing obj"<< endl;
        new(p) U(std::forward<Args>(args)...);
    }
    
    // destroy the object
    template<class U>
    void destroy(U* p) {
        cout << "destructing obj"<< endl;
        p->~U();
    }
    
    size_type getAllocations() const noexcept(true) {
        return mAllocations;
    }

private:
    static size_type mAllocations;
};

template<class T>
typename TrackingAllocator<T>::size_type TrackingAllocator<T>::mAllocations = 0;


#endif /* allocator_h */

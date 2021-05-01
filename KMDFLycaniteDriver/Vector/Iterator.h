struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirection_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirection_iterator_tag {};

typedef int difference_type;
typedef bidirection_iterator_tag iterator_category;

template <typename T>
class iter {
    public:
        iter(T *ptr) : ptr_(ptr) { }
        iter operator++() { iter i = *this; ptr_++; return i; }
        iter operator++(int junk) { ptr_++; return *this; }
        T &operator*() { return *ptr_; }
        T *operator->() { return ptr_; }
        bool operator==(const iter& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const iter& rhs) { return ptr_ != rhs.ptr_; }
        T *get() { return ptr_; }
    protected:
        T *ptr_;
};

template <typename T>
class const_iter {
    public:
        const_iter(T *ptr) : ptr_(ptr) { }
        const_iter operator++() { const_iter i = *this; ptr_++; return i; }
        const_iter operator++(int junk) { ptr_++; return *this; }
        const T &operator*() { return *ptr_; }
        const T *operator->() { return ptr_; }
        bool operator==(const const_iter& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const const_iter& rhs) { return ptr_ != rhs.ptr_; }
        T *get() { return ptr_; }
    protected:
        T *ptr_;
};

template <typename T>
class reverse_iter: public iter<T> {
    public:
        reverse_iter(T *ptr) : iter<T>(ptr) { }
        reverse_iter operator++() { reverse_iter i = *this; this->ptr_--; return i; }
        reverse_iter operator++(int junk) { this->ptr_--; return *this; }
};

template <typename T>
class const_reverse_iter: public const_iter<T> {
    public:
        const_reverse_iter(T *ptr) : const_iter<T>(ptr) { }
        const_reverse_iter operator++() { const_reverse_iter i = *this; this->ptr_--; return i; }
        const_reverse_iter operator++(int junk) { this->ptr_--; return *this; }
};

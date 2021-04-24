
#include <cstring>
#include <iostream>

#include "Iterator.h"

template <typename type>
class Vector {
    typedef unsigned int size_type;

    public:

        class iterator: public iter<type> {
            public:
                iterator(type *ptr): iter<type>(ptr) {}
        };

        class const_iterator: public const_iter<type> {
            public:
                const_iterator(type *ptr): const_iter<type>(ptr) {}
        };

        class reverse_iterator: public reverse_iter<type> {
            public:
                reverse_iterator(type *ptr): reverse_iter<type>(ptr) {}
        };

        class const_reverse_iterator: public const_reverse_iter<type> {
            public:
                const_reverse_iterator(type *ptr): const_reverse_iter<type>(ptr) {}
        };

        Vector(const Vector<type> &vector):
            elems(vector.elems), memsize(vector.memsize), count(vector.count) {}

        Vector(const size_type count = 0) {
            memsize = 0;
            if (count >= 0) {
                size_type n;

                for (n = 0; (1 << n) < count * sizeof(type); n++);
                elems = new type[1 << n];
                memsize = 1 << n;
            }
        }

        ~Vector() {}

        void assign(const size_type _count, const type &value) {
            size_type n;

            for (n = 0; (1 << n) < _count * sizeof(type); n++);
            if (elems != nullptr) {
                delete elems;
            }
            elems = new type[1 << n];
            memsize = 1 << n;
            count = _count;
            for (size_type i = 0; i < _count; i++) {
                elems[i] = value;
            }
        }

        /***** Operators *****/

        Vector<type> &operator=(const Vector<type> &vector) {
            elems = vector.elems;
            memsize = vector.memsize;
            count = vector.count;
            return *this;
        }

        Vector<type> &operator=(Vector<type> &&vector) {
            elems = vector.elems;
            memsize = vector.memsize;
            count = vector.count;
            return *this;
        }

        type &operator[](const size_type pos) { return at(pos); }

        const type &operator[](const size_type pos) const { return at(pos); }

        /***** Element access *****/

        type &at(const size_type pos) { return elems[pos]; }

        const type &at(const size_type pos) const { return elems[pos]; }

        type &front() { return elems[0]; }

        const type &front() const { return elems[0]; }

        type &back() { return elems[count - 1]; }

        const type &back() const { return elems[count - 1]; }

        type *data() { return elems; }

        const type *data() const { return elems; }

        /***** Iterators *****/

        iterator begin() { return iterator(data()); }

        iterator end() { return iterator(data() + count); }

        const_iterator cbegin() const { return const_iterator(elems); }

        const_iterator cend() const { return const_iterator(elems + count); }

        reverse_iterator rbegin() { return reverse_iterator(data() + count - 1); }

        reverse_iterator rend() { return reverse_iterator(data() - 1); }

        const_reverse_iterator crbegin() { return const_reverse_iterator(elems + count - 1); }

        const_reverse_iterator crend() { return const_reverse_iterator(elems - 1); }

        /***** Capacity *****/

        bool empty() const { return count == 0; }

        size_type size() const { return count; }

        [[deprecated]]
        size_type max_size() const { return memsize; }

        void reserve(const size_type new_cap) {
            size_type n;
            type *new_ptr = nullptr;

            if (new_cap * sizeof(type) <= capacity()) { return; }
            for (n = 0; (1 << n) < new_cap * sizeof(type); n++);
            if (!empty() && elems != nullptr) {
                new_ptr = new type[1 << n];
                memsize = 1 << n;

                for (size_type i = 0; i < size(); i++) {
                    new_ptr[i] = elems[i];
                }
                delete elems;
                elems = new_ptr;
            }
        }

        size_type capacity() const { return memsize / sizeof(type); }

        void shrink_to_fit() {
            if (size() < capacity()) {
                type *new_ptr = nullptr;

                if (!empty() && elems != nullptr) {
                    new_ptr = new type[size() * sizeof(type)];
                    memsize = size() * sizeof(type);
                    for (size_type i = 0; i < size(); i++) {
                        new_ptr[i] = elems[i];
                    }
                    delete elems;
                    elems = new_ptr;
                }
            }
        }

        /***** Modifiers *****/

    private:

        type *elems = nullptr;
        size_type memsize;
        size_type count = 0;
};
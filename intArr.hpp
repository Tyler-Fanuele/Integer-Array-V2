#pragma once
#include <iostream>
#include <ostream>
#include <exception>

#define IS_BIG_ENDIAN (!*(unsigned char *)&(uint16_t){1})

template <typename T = int>
class bitArray {
    private: 
        T var;
    public: 
        // Constructors
        bitArray(T Init) : var(Init) {}

        // Indexing
        bool operator[] (unsigned index) {
            if (index >= (sizeof(var) * 8) || index < 0)
		    {
			    throw std::out_of_range("Bit index out of range!");
		    }
		    return 0 != (var & (1 << index));
        }

        // Getters
        unsigned size() { return sizeof(var) * 8; }

        // Plus operators
        friend bitArray<T> operator+(const bitArray<T>& left, const bitArray<T>& right) {
            return bitArray(left.var + right.var);
        }

        friend T& operator+(bitArray<T>& left, T& right) {
            return left.var + right;
        }

        // equals operators
        bitArray<T>& operator=(bitArray<T>& right) {
            if (this == &right) {
                return *this;
            }
            this->var = right.var;
            return *this;
        }

         bitArray& operator=(T& right) {
            if (this == &right) {
                return *this;
            }
            this->var = right;
            return *this;
        }

         bitArray<T>& operator=(bitArray<T>&& right) {
            if (this == &right) {
                return *this;
            }
            this->var = right.var;
            return *this;
        }

         bitArray& operator=(T&& right) {
            if (this == &right) {
                return *this;
            }
            this->var = right;
            return *this;
        }

        // input/output operators
        friend std::ostream& operator<<(std::ostream& out, bitArray& arr) {
            out << arr.var;
            return out;
        }
        
};

template <typename T = int>
static bool bit(T value, unsigned index) {
    if (index >= (sizeof(value) * 8) || index < 0) 
    {
        throw std::out_of_range("Bit index out of range!");
    }
    return 0 != (value & (1 << index));
}

template<typename T>
static bitArray<T> transfer(T value) {
    return bitArray(value);
}

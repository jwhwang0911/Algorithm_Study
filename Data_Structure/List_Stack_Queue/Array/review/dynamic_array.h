#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include<algorithm>
#include<iostream>
#include<string>
#include<sstream>

template <typename T>
class dynamic_array{
    private:
        T *data;
        size_t capacity;
    
    public:
        dynamic_array(size_t cap) : capacity(cap) {
            this->data = new T[cap];
        }

        dynamic_array(const dynamic_array<T>& other) {
            this->capacity = other.capacity;
            this->data = new T[other.capacity];

            for(int i = 0; i < other.capacity; i++) {
                this->data[i] = other.data[i];
            }
        }

        // Access
        T& operator[] (size_t i) {
            return this->data[i];
        }

        const T& operator[] (size_t i) const{
            return this->data[i];
        }

        T& at(int i);
        const T& at(int i) const;

        size_t size() const {
            return capacity;
        }

        T* begin();
        const T* begin() const;

        T* end();
        const T* end() const;

        friend dynamic_array<T> operator+ (const dynamic_array<T> &a, const dynamic_array<T> &b) {
            dynamic_array<T> result = dynamic_array(a.capacity + b.capacity);
            std::copy(a.begin(), a.end(), result.begin());
            std::copy(b.begin(), b.end(), result.begin() + a.size());

            return result;
        } 

        std::string to_string(const std::string& sep = ", ") {
            if(this->capacity == 0) return "";
            
            std::stringstream os;
            os << this->data[0];

            for(auto iter = this->begin(); iter != this->end(); iter++) {
                os << sep << *iter;
            }

            return os.str();
        };

        ~dynamic_array() {
            delete this->data;
        }
};      


template <typename T>
T& dynamic_array<T>::at(int i) {
    if(i < this->capacity) {
        return this->data[i];
    }
    throw std::length_error("index out of range");
}

template <typename T>
const T& dynamic_array<T>::at(int i) const{
    if(i < this->capacity) {
        return this->data[i];
    }
    throw std::length_error("index out of range");
}

template <typename T>
T* dynamic_array<T>::begin() {
    return data;
}

template <typename T>
const T* dynamic_array<T>::begin() const{
    return data;
}

template <typename T>
T* dynamic_array<T>::end() {
    return data + capacity;
}

template <typename T>
const T* dynamic_array<T>::end() const{
    return data + capacity;
}

#endif
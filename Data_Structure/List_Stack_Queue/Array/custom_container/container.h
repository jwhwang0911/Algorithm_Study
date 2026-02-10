#ifndef CONTAINER
#define CONTAINER

#include "node.h"
#include<algorithm>
#include<iostream>

class container {
    public:
        using elem = node;
        using node_ptr = node*;

        container() = default;

        container(const container& other) {
            this->header = nullptr;
            node_ptr curr;
            for(auto iter = other.begin(); iter != other.end(); iter++) {
                node_ptr n_node = new elem(*iter);
                if(iter == other.begin()) {
                    this->header = n_node;
                    curr = n_node;
                    continue;
                }

                curr->next = n_node;
                curr = n_node;
            }
        }

        container(const std::initializer_list<int> &ilist) : header(NULL) {
            for(auto it = std::rbegin(ilist); it != std::rend(ilist); it++) {
                push_front(*it);
            }
        }

        void push_front(int val) {
            node* n_node = new node(val);

            n_node->next = this->header;
            this->header = n_node;
        }

        void pop_front() {
            if(header) {
                node_ptr first = header;
                header = header->next;

                delete first;
            }
        }

        struct iterator {
            private:
                node_ptr ptr;
            
            public:
                iterator(node_ptr point) : ptr(point) {};

                int& operator*() {return ptr->data;}

                node_ptr get() const {
                    return ptr;
                }

                iterator& operator++() {
                    ptr = ptr->next;
                    return *this;
                }

                iterator operator++(int) {
                    iterator result = *this;
                    ++(*this);
                    return result;
                }

                friend bool operator==(const iterator& left, const iterator& right) {
                    return left.ptr == right.ptr;
                }

                friend bool operator!=(const iterator& left, const iterator& right) {
                    return left.ptr != right.ptr;
                }
        };

        iterator begin() {
            return iterator(this->header);
        }

        iterator begin() const {
            return iterator(this->header);
        }

        iterator end() {
            return iterator(nullptr);
        }

        iterator end() const {
            return iterator(nullptr);
        }

        friend std::ostream& operator<<(std::ostream &out, container const& data) {
            out << "[";
            for(auto iter = data.begin(); iter != data.end(); iter++) {
                out << *iter;

                if(iter.get()->next != data.end()) {
                    out << ", ";
                }
            }

            out << "]";

            return out;
        }

    private:
        node_ptr header;
};

#endif
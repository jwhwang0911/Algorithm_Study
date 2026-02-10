#ifndef NODE
#define NODE

struct node{
    int data;
    node* next;

    node(int value) : data(value), next(nullptr) {}
};

#endif
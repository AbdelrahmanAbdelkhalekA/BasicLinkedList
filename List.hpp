#ifndef LIST_H_
#define LIST_H_

#include <iostream>

#include <sstream>

#include <string>


/*
template < typename G >
Node<G>* get_next(void) {

}

void push_back(int data,Node* head){
    if(!head->next)
    {
        Node* newNode=new Node();
        newNode->data=data;
        newNode->next=NULL;
        head->next=newNode;
    }
    else
        push_back(data,head->next);
}
*/

/*
template < typename G >
Node<G>* get_next(void) {

}

void push_back(int data,Node* head){
    if(!head->next)
    {
        Node* newNode=new Node();
        newNode->data=data;
        newNode->next=NULL;
        head->next=newNode;
    }
    else
        push_back(data,head->next);
}
*/

namespace ECE275Lib {
    namespace containers {
        template<typename G>
        class Node {
        public:
            Node<G> *next = nullptr;
            G data;
            Node<G> *get_next () {
                return next;
            }
            // Node<G> * get_next(void);
        }; 

        template<typename T>
        class List {
        public:
            List() {
                (head) = NULL;
            }

            List(unsigned int N) {
                // We want to create N nodes but doesn't matter the contents
                head = new Node<T>();
                Node<T> *curNode = head;
                unsigned int i = 1;
                while (i != N) {
                    curNode->next = new Node<T>();
                    curNode = curNode->get_next();
                    ++i;
                }
            }

            unsigned int size() {
                unsigned int x = 0;
                for (Node<T> *ptr = head; ptr->get_next() != NULL; ptr = ptr->get_next()) {
                    std::cout << ptr->data << std::endl;
                    x++;
                }
                x++;
                return x;
            }

            void insert(unsigned int i, T h) {
                Node<T> *newNode = new Node<T>();
                Node<T> *before = att(i - 1);
                newNode->data = h;
                newNode->next = before->get_next();
                before->next = newNode;
            }

            T at(unsigned int v) {
                /*         T g;
                         Node < T > * newNode = head;
                         for (int i = 0; i < v; i++) {
                           newNode = newNode -> next;
                         }
                         return newNode -> data;
               */
                return att(v)->data;
            }

            Node<T> *att(unsigned int v) {
                //T g;
                Node<T> *newNode = head;
                for (unsigned int i = 0; i < v; i++) {
                    newNode = newNode->get_next();
                }
                return newNode;
            }

            Node<T> *front() {
                return head;
            }

            Node<T> *back() {
                return att(size() - 1);
            }

            void assign(unsigned int i, T d) {
                Node<T> *newNode = att(i);
                newNode->data = d;
            }

            void insert(unsigned int i, List<T> &other) {
                Node<T> *list2 = other.front();
                Node<T> *before = att(i - 1);
                Node<T> *newNode = list2;
                while (newNode->get_next() != NULL)
                    newNode = newNode->get_next();
                newNode->next = before->get_next();
                before->next = list2;
            }

            void remove(unsigned int x) {
                Node<T> *newNode = att(x);
                Node<T> *before = att(x - 1);
                before->next = newNode->get_next();
                free(newNode);
            }

            void remove(unsigned int x, unsigned int y) {
                Node<T> *first = att(x - 1);
                Node<T> *last = att(y);
                first->next = last->get_next();
            }

            void push_back(T h) {
                Node<T> *newNode = new Node<T>();
                Node<T> *temp = head;
                newNode->data = h;
                newNode->next = NULL;
                if (head == NULL) {
                    head = newNode;
                } else {
                    while (temp->get_next() != NULL)
                        temp = temp->get_next();
                    temp->next = newNode;
                }
            }

        private:
            Node<T> *head;
        };


    }
}

#endif

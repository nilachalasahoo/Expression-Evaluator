#include"Node.h"
template<class T>
Node<T>::Node(T data,Node *next){
   this->data=data;
   this->next=next;
}
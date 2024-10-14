#include<exception>
#include"Node.h"
template<class T>
class Stack{
   private:
      Node<T> *head;
      int size=0;
   public:
      void push(T element);
      T pop();
      T top();
      bool empty();
};


template<class T>
void Stack<T>::push(T element){
   if(size==0)
      head=new Node<T>(element,nullptr);
   else
      head=new Node<T>(element,head);
   size++;
}
template<class T>
T Stack<T>::pop(){
   if(empty())
      std::exception();
   T value=head->data;
   head=head->next;
   size--;
   return value;
}
template<class T>
T Stack<T>::top(){
   if(empty())
      std::exception();
   return head->data;
}
template<class T>
bool Stack<T>::empty(){
   return size==0;
}
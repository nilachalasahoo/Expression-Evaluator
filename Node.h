template<class T>
class Node{
   public:
      T data;
      Node *next;
      Node(T data,Node *next);
      ~Node();
};


template<class T>
Node<T>::Node(T data,Node *next){
   this->data=data;
   this->next=next;
}
template<class T>
Node<T>::~Node(){
   delete next;
}
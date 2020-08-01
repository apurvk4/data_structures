#pragma once
template<typename T>
class Node{
    public:
     T & get_data(){
       return this->data_;
     }
    protected:
      Node * head_=nullptr;
      Node * tail_=nullptr;
      void push_back(T &);
      void pop_back();
      Node(T &);
      Node();
     ~Node();
      T data_;
      Node *  next_=nullptr;
      Node * prev_=nullptr;
};
template<typename T>
void Node<T>::push_back(T & val){
  if(this->head_==nullptr){
    Node * temp=new Node(val);
    this->head_=temp;
    this->tail_=temp;
  }else{
    Node * temp=new Node(val);
    this->tail_->next_=temp;
    temp->prev_=this->tail_;
    this->tail_=temp;
  }
}
template<typename T>
void Node<T>::pop_back(){
  if(head_ !=nullptr){
    if(head_->next_ ==nullptr){
      delete head_;
      head_=nullptr;
      tail_=nullptr;
    }else{
      Node * temp=tail_->prev_;
      temp->next_=nullptr;
      delete tail_;
      tail_=temp;
    } 
  }
}
template<typename T>
Node<T>::Node():prev_{nullptr},next_{nullptr},head_{nullptr},tail_{next_}{  
}
template<typename T>
Node<T>::Node(T & val):data_{val},next_{nullptr},prev_{nullptr}{
}
template<typename T>
Node<T>::~Node(){
  if(head_ !=nullptr){
    if(head_==tail_){
        delete head_;
        head_=nullptr;
        tail_=nullptr;
    }else{
          Node *n1,*n2;
          n1=head_;
          while(n1 !=nullptr ){
            n2=n1;
            n1=n1->next_;
            delete n2;
          }
          head_=nullptr;
          tail_=nullptr;
    }
  }
}
template<typename T>
class Stack:public Node<T>{
  public:
   Stack()=default;
   ~Stack()=default;
   void push(T &);
   void push(T);
   void pop();
   T & top();
   bool empty();
   unsigned int size();
  private:
   unsigned int count=0;
};
template<typename T>
void Stack<T>::push(T & val){
  this->push_back(val);
  count++;
}
template<typename T>
void Stack<T>::push(T val){
  T v=val;
  this->push_back(v);
  count++;
}
template<typename T>
void Stack<T>::pop(){
  this->pop_back();
  count--;
}
template<typename T>
T & Stack<T>::top(){
  return this->tail_->get_data();
}
template<typename T>
unsigned int Stack<T>::size(){
  return count;
}
template<typename T>
bool Stack<T>::empty(){
  return count;
}




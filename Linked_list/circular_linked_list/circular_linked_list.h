#pragma once
template<typename T>
class circular_linked_list{
  public:
     ~ circular_linked_list();
     circular_linked_list()=default;
     circular_linked_list(T);
     void insert(T &);
     void clear();
     void remove(T &);
     class iterator{
         private:
           circular_linked_list<T> * ptr_;
         public:
           iterator(circular_linked_list<T> * ptr):ptr_{ptr}{
           }
           iterator operator++(int){
              ptr_=ptr_->next_;
              return *this;
           }
           iterator operator++(){
              ptr_=ptr_->next_;
              return *this;
           }
           const T & operator*(){
               return this->ptr_->value_;
           }
           bool operator==(const iterator & rhs){
               if(this->ptr_==rhs.ptr_){
                   return true;
               }else{
                   return false;
               }
           }
           bool operator !=(const iterator & rhs){
               if(this->ptr_!=rhs.ptr_){
                   return true;
               }else{
                   return false;
               }
           }
           circular_linked_list<T>* operator->(){
               return this->ptr_;
           }
     };
     iterator begin(){
        return iterator(head_);
     }
     iterator end(){
        return iterator(head_);
    }
    T & front();
    const T & cfront();
  private:
      T value_;
      circular_linked_list *head_=nullptr;
      circular_linked_list *next_=nullptr;
};
template<typename T>
circular_linked_list<T>::~circular_linked_list(){
    if(head_ !=nullptr){
        circular_linked_list * n=head_;
        if(n->next_ !=head_){
            n=n->next_;
            circular_linked_list *n1;
            while(n->next_ !=head_){
                n1=n;
                n=n->next_;
                delete n1;
            }
            delete n;
            delete head_;
        }else{
            delete head_;
        }
    }
}
template<typename T>
T & circular_linked_list<T>::front(){
    return head_->value_;
}
template<typename T>
const T & circular_linked_list<T>::cfront(){
    return head_->value_;
}
template<typename T>
circular_linked_list<T>::circular_linked_list(T val){
    circular_linked_list * n=new circular_linked_list();
    n->value_=val;
    head_=n;
    n->next_=head_;
}
template<typename T>
void circular_linked_list<T>::insert(T & val){
       circular_linked_list * n=head_;
       while(n->next_ !=head_){
           n=n->next_;
       }
       circular_linked_list *n1=new circular_linked_list<T>();
       n1->value_=val;
       n->next_=n1;
       n1->next_=head_;
}
template<typename T>
void circular_linked_list<T>::clear(){
    if(head_ !=nullptr){
        circular_linked_list * n=head_;
        if(n->next_ !=head_){
            n=n->next_;
            circular_linked_list *n1;
            while(n->next_ !=head_){
                n1=n;
                n=n->next_;
                delete n1;
            }
            delete n;
            delete head_;
        }else{
            delete head_;
        }
    }
}
template<typename T>
void circular_linked_list<T>::remove(T & val){
    circular_linked_list * n=head_;
    if(head_->next_==head_){
       if(head_->value_==val){
           delete head_;
           return;
       }
    }else if(head_->value_==val){
       circular_linked_list * n=head_;
       while(n->next_ !=head_){
           n=n->next_;
       }
       circular_linked_list * n1=head_;
       head_=head_->next_;
       n->next_=head_;
       n1->next_=nullptr;
       delete n1;
    }else{
        circular_linked_list * n=head_;
        circular_linked_list *n2,*n1;
       while(n->next_->value_ !=val){
           n=n->next_;
       }
       n2=n->next_->next_;
       n1=n->next_;
       n->next_=n2;
       n1->next_=nullptr;
       delete n1;
    }

}
#pragma once
#include<stdexcept>
template<typename T>
class doubly_linked_list{
    protected:
      T value;
      doubly_linked_list *next=nullptr;
      doubly_linked_list *prev=nullptr;
      doubly_linked_list* head=nullptr;
      doubly_linked_list * tail=nullptr;
    public:
      /**
    returns const reference to the value stored in head pointer.
    throws an instance of std::logic_error in case head pointer is null.
      */
      const T & cfront();
      /**
   returns read/write reference to the value stored in head pointer.
   throws an instance of std::logic_error in case head pointer is null.
    */
      T & front();
      const T & cback();
      /**
   returns read/write reference to the value stored in tail pointer.
   throws an instance of std::logic_error in case head pointer is null.
      */
      T & back();
      doubly_linked_list()=default;
      doubly_linked_list(T);
      void push_back(T);
      void push_front(T);
      void pop_front();
      void pop_back();
      bool empty();
      void clear();
      void insert_after(doubly_linked_list *,T);
      void insert_after(T,T);
      void insert_before(doubly_linked_list *,T);
      void insert_before(T,T);
      void erase(doubly_linked_list *);
      void erase(T);
      ~doubly_linked_list();
};

template<typename T>
T & doubly_linked_list<T>::front(){
   if(head==nullptr){throw std::logic_error("dereferencing a null pointer");}
    return head->value;
}
 
template<typename T>
const T & doubly_linked_list<T>::cfront(){
    if(head==nullptr){throw std::logic_error("dereferencing a null pointer");}
    const T & x= head->value;
    return x;
}

template<typename T>
T & doubly_linked_list<T>::back(){
    if(tail==nullptr){throw std::logic_error("dereferencing a null pointer");}
    return tail->value;
}
/*
    returns const reference to the value stored in tail pointer.
    throws an instance of std::logic_error in case head pointer is null.
*/
template<typename T>
const T & doubly_linked_list<T>::cback(){
    if(tail==nullptr){throw std::logic_error("dereferencing a null pointer");}
    const T & x=tail->value;
    return x;
}
/*
  one args constructor
*/
template<typename T>
doubly_linked_list<T>::doubly_linked_list(T val){
    doubly_linked_list *n= new doubly_linked_list<T>();
    n->value=val;
    if(head==nullptr && tail==nullptr){
        head=n;
        tail=head;
    }else{
        tail->next=n;
        n->prev=tail;
        tail=n;
    }
}
/*
 Add the element to the end of doubly linked-list.
 @param__val : value to be inserted.
*/
template<typename T>
void doubly_linked_list<T>::push_back(T val){
   if(head==nullptr && tail==nullptr){
       doubly_linked_list * n= new doubly_linked_list<T>();
       n->value=val;
       head=n;
       tail=n;
       head->next=nullptr;
       head->prev=nullptr;
   }else{
        doubly_linked_list * n= new doubly_linked_list<T>();
        n->value=val;
        tail->next=n;
        n->prev=tail;
        n->next=nullptr;
        tail=n;
   }
}
/*
removes element from end of doubly linked-list.
*/
template<typename T>
void doubly_linked_list<T>::pop_back(){
   if(head==tail){
      delete head;
      head=nullptr;
      tail=nullptr;
   }else{
       doubly_linked_list *ptr=tail->prev;
       tail->prev=nullptr;
       delete tail;
       ptr->next=nullptr;
       tail=ptr;
   }
}
/*
Adds element to the begining of doubly linked-list.
@param__val: value to be inserted.
*/
template<typename T>
void doubly_linked_list<T>::push_front(T val){
    if(head==nullptr && tail==nullptr){
        doubly_linked_list *ptr =new doubly_linked_list<T>();
        ptr->value=val;
        head=ptr;
        tail=ptr;
        head->next=nullptr;
        head->prev=nullptr;
    }else{
        doubly_linked_list *ptr =new doubly_linked_list<T>();
        ptr->value=val;
        ptr->next=head;
        ptr->prev=nullptr;
        head=ptr;
    }
}
/*
removes the element from begining of doubly linked-list.
*/
template<typename T>
void doubly_linked_list<T>::pop_front(){
     if(head==tail){
         delete head;
         tail=nullptr;
         head=nullptr;
     }else{
         doubly_linked_list * ptr=head->next;
         head->next=nullptr;
         ptr->prev=nullptr;
         delete head;
         head=ptr;
     }
}
/*
return true if list is empty else returns false.
*/
template<typename T>
bool doubly_linked_list<T>::empty(){
    if(head==nullptr && tail==nullptr){
        return true;
    }else{
        return false;
    }
}
/*
clears the list
*/
template<typename T>
void doubly_linked_list<T>::clear(){
    if(head !=nullptr && tail !=nullptr){
        if(head==tail){
            delete head;
            tail=nullptr;
            head=nullptr;
        }else{
            doubly_linked_list * ptr=head;
            doubly_linked_list * ptr1=ptr;
            while(ptr !=nullptr){
                ptr=ptr->next;
                delete ptr1;
                ptr1=ptr;
            }
            head=nullptr;
            tail=nullptr;
        }
    }
}
/*
  
*/
template<typename T>
void doubly_linked_list<T>::erase(doubly_linked_list<T> * ptr){
    if(ptr==nullptr){throw std::invalid_argument("Invalid node");}
    if(head==tail){
        if(head==ptr){
            delete ptr;
            head=nullptr;
            tail=nullptr;
        }else{
            throw std::logic_error("not found");
        }
    }else if(ptr==tail){
            tail=tail->prev;
            delete ptr;
            ptr=nullptr;
    }else if(ptr==head){
            head=head->next;
            delete ptr;
            ptr=nullptr;
    }else{
        doubly_linked_list * n=head;
        while(n != nullptr){
            if(n==ptr){
                break;
            }
            n=n->next;
        }
        if(n==ptr){
            n=ptr->prev;
            n->next=ptr->next;
            ptr->next->prev=n;
            delete ptr;
            ptr=nullptr;
        }else{
            throw std::logic_error("not found");
        }
    }
}
/*

*/
template<typename T>
void doubly_linked_list<T>::erase(T val){
 if(head !=nullptr && tail !=nullptr){
    if(head==tail){
        if(head->value==val){
            delete head;
            head=nullptr;
            tail=nullptr;
        }else{
            throw std::logic_error("not found");
        }
    }else if(head->value==val){
        doubly_linked_list* p=head;
        head=head->next;
        delete p;
        p=nullptr;
    }else if(tail->value==val){
        doubly_linked_list* p=tail;
        tail=tail->prev;
        delete p;
        p=nullptr;
    }else{
        doubly_linked_list * n=head;
        doubly_linked_list * ptr;
        while(n != nullptr){
            if(n->value==val){
                ptr=n;
                break;
            }
            n=n->next;
        }
        if(n==nullptr){
            throw std::logic_error("not found");
        }else{
            n=ptr->prev;
            n->next=ptr->next;
            ptr->next->prev=n;
            delete ptr;
        }
    }
 }else{
     std::logic_error("not found");
 }
}
/*

*/
template<typename T>
doubly_linked_list<T>::~doubly_linked_list(){
    if(head==tail){
        delete head;
        head=nullptr;
        tail=nullptr;
    }else{
        doubly_linked_list *n1,*n2;
        n1=head;
        while(n1 !=nullptr ){
            n2=n1;
            n1=n1->next;
            delete n2;
        }
    }
}
/*

*/
template<typename T>
void doubly_linked_list<T>::insert_after(doubly_linked_list<T> * ptr,T val){
    if(ptr==nullptr){throw std::invalid_argument("Invalid node");}
    if(head !=nullptr && tail !=nullptr){
          if(head==tail){
              doubly_linked_list * n=new doubly_linked_list<T>();
              n->value=val;
              head->next=n;
              n->prev=head;
              tail=n;
          }else if(tail==ptr){
               push_back(val);
          }else{
              doubly_linked_list * n=head;
              while(n != nullptr){
                  if(n==ptr){
                      break;
                    }
                   n=n->next;
                }
              if(n==ptr){
                  doubly_linked_list* n1=new doubly_linked_list<T>();
                  n1->value=val;
                  n1->next=ptr->next;
                  ptr->next->prev=n1;
                  ptr->next=n1;
                  n1->prev=ptr;
              }else{
                  throw std::logic_error("Provided Node not present");
              }
          }
    }else{
        push_back(val);
    }
}
/*

*/
template<typename T>
void doubly_linked_list<T>::insert_after(T p_val,T val){
        if(head !=nullptr && tail !=nullptr){
          if(head==tail){
              if(head->value==p_val){
                 doubly_linked_list * n=new doubly_linked_list<T>();
                 n->value=val;
                 head->next=n;
                 n->prev=head;
                 tail=n;
              }else{
                  throw std::logic_error("Provided value not present");
              }
          }else if(tail->value==p_val){          
              push_back(val);
          }else{
              doubly_linked_list * n=head;
              while(n != nullptr){
                  if(n->value==p_val){
                      break;
                    }
                   n=n->next;
                }
              if(n==nullptr){
                  throw std::logic_error("Provided value not present");
              }else{
                  doubly_linked_list* n1=new doubly_linked_list<T>();
                  n1->value=val;
                  n1->next=n->next;
                  n->next->prev=n1;
                  n->next=n1;
                  n1->prev=n;
              }
          }
    }else{
        push_back(val);
    }
}
/*

*/
template<typename T>
void doubly_linked_list<T>::insert_before(doubly_linked_list<T>* ptr,T val){
    if(ptr==nullptr){throw std::invalid_argument("Invalid node");}
     if(head !=nullptr && tail !=nullptr){
           if(head==tail){
               if(head==ptr){
                   push_front(val);
               }else{
                   throw std::logic_error("Provided Node not present");
               }
           }else if(head==ptr){
               push_front(val);           
           }else{
               doubly_linked_list * n=head;
              while(n != nullptr){
                  if(n==ptr){
                      break;
                    }
                   n=n->next;
                }
                if(n==ptr){
                  doubly_linked_list* n1=new doubly_linked_list<T>();
                  n1->value=val;
                  n1->prev=tail->prev;
                  tail->prev->next=n1;
                  n1->next=tail;
                  tail->prev=n1;
                }else{
                    throw std::logic_error("Provided Node not present");
                }   
           }
     }else{
         push_front(val);
     }       
}
/*

*/
template<typename T>
void doubly_linked_list<T>::insert_before(T P_val,T val){
   if(head !=nullptr && tail !=nullptr){
           if(head==tail){
               if(head->value==P_val){
                   push_front(val);
               }else{
                   throw std::logic_error("Provided value not present");
               }
           }else if(head->value==P_val){
               push_front(val);           
           }else{
               doubly_linked_list * n=head;
              while(n != nullptr){
                  if(n->value==P_val){
                      break;
                    }
                   n=n->next;
                }
                if(n==nullptr){
                    throw std::logic_error("Provided value not present");
                }else{
                  doubly_linked_list* n1=new doubly_linked_list<T>();
                  n1->value=val;
                  n1->prev=tail->prev;
                  tail->prev->next=n1;
                  n1->next=tail;
                  tail->prev=n1;
                }   
           }
     }else{
         push_front(val);
     }
}


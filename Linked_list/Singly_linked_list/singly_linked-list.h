#pragma once
// #ifdef FORWARD_LIST_EXPORTS
// #define FORWARD_LIST_API __declspec(dllexport)
// #else
// #define FORWARD_LIST_API __declspec(dllimport)
// #endif
template<typename T>
 class linked_list
{
protected:
    T value=0;
    linked_list* next=nullptr;
    linked_list* head=nullptr;
    linked_list* tail=nullptr;
public:
    virtual void push_back(T);
    virtual void pop_back();
    virtual void push_front(T);
    virtual bool empty();
    virtual void pop_front();
    linked_list(T);
    virtual void clear();
    // void remove(T);
    linked_list()=default;
    virtual ~linked_list();
};
template<typename T>
linked_list<T>::~linked_list(){
    if(head==tail){
        delete head;
        head=nullptr;
        tail=nullptr;
    }else{
        linked_list *n1,*n2;
        n1=head;
        while(n1 !=nullptr ){
            n2=n1;
            n1=n1->next;
            delete n2;
        }
    }
}
template<typename T>
bool linked_list<T>::empty(){
    if(head==nullptr){
        return true;
    }else{
        return false;
    }
}
template<typename T>
void linked_list<T>::clear(){
  if(head !=nullptr && tail !=nullptr){
    if(head==tail){
        delete head;
        head=nullptr;
        tail=nullptr;
    }else{
        linked_list *n1,*n2;
        n1=head;
        while(n1 !=nullptr ){
            n2=n1;
            n1=n1->next;
            delete n2;
        }
    }
  }
}
// template<typename T>
// void linked_list<T>::remove(T val){
//     if(head !=nullptr && tail !=nullptr){
//         if(head==tail){
//             if(head->value==val){
//                 delete head;
//                 head=nullptr;
//                 tail=nullptr;
//             }
//         }else if(head->value==val){
//              linked_list * n=head;
//              head=head->next;
//              delete n;
//         }else{
//             linked_list * n=head;
//             linked_list * n1=n;
//             while(n != nullptr){
//                   if(n->value==val){
//                      break;
//                    }
//                  n1=n;
//                  n=n->next;
//                }
//                if(n !=nullptr){
//                    n1->next=n->next;
//                }
//         }
//     }
// }
template<typename T>
linked_list<T>::linked_list(T val)
{
  linked_list* n=new linked_list();
  n->value=val;
  if(head==nullptr && tail==nullptr){
     head=n;
     head->next=nullptr;
     tail=head;
  }
}
template<typename T>
void linked_list<T>::push_back(T val){
    if(head==nullptr){ // no elements in linked_list
       linked_list(val);
    }else{
        linked_list *n=new linked_list(val);
        tail->next=n;
        tail=n;
        tail->next=nullptr;
    }
}
template<typename T>
void linked_list<T>::pop_back(){
    if(head==tail){
        delete head;
        head=nullptr;
        tail=nullptr;
    }else{
        linked_list * temp;
        temp=head;
        while(temp->next !=tail){
            temp=temp->next;
        }
        delete tail;
        temp->next=nullptr;
        tail=temp;
    }

}
template<typename T>
void linked_list<T>::push_front(T val){
    if(head==nullptr){
       linked_list(val);
    }else{
        linked_list *n=new linked_list(val);
        n->next=head;
        head=n;
    }
}
template<typename T>
void linked_list<T>::pop_front(){
    if(head==tail){
        delete head;
        head=nullptr;
        tail=nullptr;
    }else{
        linked_list * n=head;
        head=head->next;
        delete n;
    }
}




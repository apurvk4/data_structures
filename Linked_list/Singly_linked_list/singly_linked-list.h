#pragma once
template<typename T>
 class linked_list
{
protected:
    T value=0;
    linked_list* next=nullptr;
    linked_list* head=nullptr;
    linked_list* tail=nullptr;
public:
    virtual T &  front();
    virtual const T & cfront();
    virtual T & back();
    virtual const T & cback(); 
    virtual void push_back(T);
    virtual void pop_back();
    virtual void push_front(T);
    virtual bool empty();
    virtual void pop_front();
    linked_list(T);
    virtual void clear();
    void remove(T);
    linked_list()=default;
    virtual ~linked_list();
};
template<typename T>
T & linked_list<T>::front(){
    return head->value;
}
template<typename T>
const T & linked_list<T>::cfront(){
    return head->value;
}
template<typename T>
T & linked_list<T>::back(){
    return tail->value;
}
template<typename T>
const T & linked_list<T>::cback(){
    return tail->value;
}
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
template<typename T>
void linked_list<T>::remove(T val){
    if(head !=nullptr && tail !=nullptr){
        if(head==tail){
            if(head->value==val){
                delete head;
                head=nullptr;
                tail=nullptr;
            }
        }else if(head->value==val){
             linked_list * n=head;
             head=head->next;
             delete n;
        }else{
            linked_list * temp;
            temp=head;
            while(temp->next->value!=val && temp->next !=tail){
              temp=temp->next;
            }
            if(temp->next->value==val ){
                if(temp->next==tail){
                    tail=temp;
                    temp=temp->next;
                    delete temp;
                    tail->next=nullptr;
                }else{
                    linked_list *n2=temp->next->next;
                    linked_list *n1=temp->next;
                     temp->next=n2;
                     n1->next=nullptr;
                     delete n1;
                }
            }
        }
    }
}
template<typename T>
linked_list<T>::linked_list(T val)
{
  linked_list* n=new linked_list();
  n->value=val;
     head=n;
     head->next=nullptr;
     tail=head;
}
template<typename T>
void linked_list<T>::push_back(T val){
    if(head !=nullptr && tail !=nullptr){
               linked_list *n=new linked_list();
               n->value=val;
               n->next=nullptr;
               tail=n;
    }else{
        linked_list * n=new linked_list();
        n->value=val;
        head=n;
        head->next=nullptr;
        tail= head;
    }
}
template<typename T>
void linked_list<T>::pop_back(){
    if(head !=nullptr && tail !=nullptr){
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
}
template<typename T>
void linked_list<T>::push_front(T val){
    if(head==nullptr){
       linked_list *n=new linked_list();
       n->value=val;
       n->next=nullptr;
       head=n;
       tail=n;
    }else{
        linked_list *n=new linked_list(val);
        n->next=head;
        head=n;
    }
}
template<typename T>
void linked_list<T>::pop_front(){
    if(head !=nullptr && tail !=nullptr){
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
}




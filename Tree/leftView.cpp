#include<iostream>
#include "binaryTree.hpp"
#include "../queue/queue.h"
void leftView(binaryTree<int> * node){
    if(node==nullptr){
        return;
    }
    queue<binaryTree<int> *> q;
    q.push(node);
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            auto curr=q.front();
            q.pop();
            if(i==0){
                std::cout<<curr->data_<<" ";
            }
            if(curr->left_ !=nullptr){
                q.push(curr->left_);
            }
            if(curr->right_ !=nullptr){
                q.push(curr->right_);
            }
        }
    }
}
int main(){
     auto head=new binaryTree<int>(12);
     head->insert_left(34);
     head->insert_right(90);
     head->left_->insert_left(345);
     head->left_->insert_right(9);
     head->right_->insert_left(56);
     head->right_->insert_right(45);
     head->right_->left_->insert_left(17);
     head->right_->left_->insert_right(3456);
     head->left_->left_->insert_left(11);
     head->left_->left_->insert_right(33);
     head->left_->right_->insert_right(55);
    // head->insert_left(20);
    // head->insert_right(30);
    // head->left_->insert_left(40);
    // head->left_->insert_right(50);
    // head->insert_right(30);
    // head->right_->insert_right(70);
    // head->right_->right_->insert_right(80);
    leftView(head);
    std::cout<<"\n";
    return 0;
}
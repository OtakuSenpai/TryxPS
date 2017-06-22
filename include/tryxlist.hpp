///////////////////////////////////////////////////////////////////////////////////
// Tryx Plugin System made by Avra Neel Chakraborty                              //
//                                                                               //
// Copyright (c) 2017 Avra Neel Chakraborty                                      // 
//                                                                               //
// Permission is hereby granted, free of charge, to any person obtaining a copy  //
// of this software and associated documentation files (the "Software"), to deal //
// in the Software without restriction, including without limitation the rights  //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell     //
// copies of the Software, and to permit persons to whom the Software is         //
// furnished to do so, subject to the following conditions:                      //
//                                                                               //
// The above copyright notice and this permission notice shall be included in    // 
// all copies or substantial portions of the Software.                           // 
///////////////////////////////////////////////////////////////////////////////////

#ifndef TRYX_LINKEDLIST_HPP
#define TRYX_LINKEDLIST_HPP

#include <stdexcept>

namespace Tryx {

  template<typename T,typename U>
  class TryxList {
    public:
      TryxList() {
        root = nullptr;
      }

      ~TryxList() { deleteList(); }
      
      void create(T param1,U param2) {
        if(root == nullptr) {
          Node* nn = new Node(param1,param2);
          root = nn; 
        }
        else throw std::runtime_error("tryxlist.hpp : line 18,list already exists.\n");
      }
      
      int size() const {
        Node* temp = root;
        int count = 0;
        while(temp != nullptr) {
          count++; temp = temp->next;
        }
        return count;
      }
      
      int search(T searchItem) {
        if(root != nullptr) {
          Node* current = root;
          int pos = 0;
          while(current != nullptr) {
            if(current->_name == searchItem) 
              return pos;
            ++pos;
            current = current->next;
          }
        }
        else throw std::runtime_error("tryxlist.hpp : line 44, searching on an empty list.\n");
      }
      
      void reverse() {
        Node* prev   = nullptr;
        Node* current = root;
        Node* next;
        while(current != nullptr)
        {
          next = current->next;  
          current->next = prev;   
          prev = current;
          current = next;
        }
        root = prev;
      } 
       
      void uniqueIt() {
        Node *ptr1, *ptr2, *dup;
        ptr1 = root;
 
        while (ptr1 != nullptr && ptr1->next != nullptr)
        {
          ptr2 = ptr1;
 
          while (ptr2->next != nullptr)
          {
            if (ptr1->_data == ptr2->next->_data)
            {
              dup = ptr2->next;
              ptr2->next = ptr2->next->next;
              delete dup;
            }
            else ptr2 = ptr2->next;
          }
          ptr1 = ptr1->next;
        }
      } 
       
      void push_back(T param1,U param2) {
        if(root != nullptr) {
          Node* nn = new Node(param1,param2);
          Node* temp = root;
          while(temp->next != nullptr) temp = temp->next;
          temp->next = nn; nn->next = nullptr;
        }
        else create(param1,param2);
      }
      
      void pop_back() {
        if(root != nullptr) {
          Node* current = root;
          Node* prev;
          while(1) {
            if(current->next == nullptr)
            break;
            prev = current;
            current = current->next;
          }
          std::cout<<"Prev: "<<prev->_data<<std::endl;
          prev->next = nullptr;
          delete current;
        }
        else throw std::runtime_error("tryxlist.hpp : line 104,list has not been created.\n");
      }
      
      void pop(T param1) {
        Node *old, *current;
        current = root;
        if(root != nullptr) {
          while(current != nullptr) {
            if(current->_name == param1) {
              if(current == root)
                root = current->next;
              else old->next = current->next;
              delete current; current = nullptr;
              return;
            }
            else {
              old = current;
              current = current->next;
            }
          }
        }
        else throw std::runtime_error("tryxlist.hpp : line 121,parameter to be deleted not found.");
      }
      
      void deleteList() {
        Node* current = root;
        Node* next;
        while (current != nullptr) {
         next = current->next;
         delete current;
         current = next;
        }
        root = nullptr;
      } 
        
    private:
      
      void display() {
        Node* temp = root;
        while(temp != nullptr) {  
          std::cout<<"Parameter one is: "<<temp->_name<<std::endl
                   <<"Parameter two is: "<<temp->_data<<std::endl;
          temp = temp->next;         
        }
      }
      
      struct Node {
        T _name;
        U _data;
        Node* next;
        
        Node() {}    
        Node(T t,U u) : _name(t), _data(u) {}
        Node(const Node* other) {
          try {
            _name = other._name;
            _data = other._data;
            next = other.next;
          }
          catch(std::exception& e){ std::cerr<<"tryxlist.hpp : line 162,caught exception: "<<e.what(); }           
        }
        Node* operator=(const Node* other) {
          try {
            free();
            Node* temp = new Node(other);
            return temp;
          }
          catch(std::exception& e){ std::cerr<<"tryxlist.hpp : line 170,caught exception: "<<e.what(); }
        }
        void free() {
        delete next; 
        }
        ~Node() {}
      };  
    
      Node* root;
  };

};

#endif

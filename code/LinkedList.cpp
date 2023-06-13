#include "LinkedList.h"

// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList(){
}


//deconstructor,
LinkedList::~LinkedList(){
}


shared_ptr<node> LinkedList::InitNode(int data){
  //allocate memory for new node
  shared_ptr<node> ret(new node);
  //fill in struct info
  ret->data = data;
  ret->next = nullptr;
  return ret;
}

string LinkedList::Report(){
  string ret = "";

  //create current node pointer and start at head
  shared_ptr<node> curr = top_ptr_;
  //traverse through entire list to the tail
  while(curr != nullptr) {
    //record data from each node into string
    ret = ret + to_string(curr->data) + " ";
    curr = curr->next;
  }

  return ret;
}

void LinkedList::AppendData(int data){
  //create new node
  shared_ptr<node> new_node = InitNode(data);
  //call Append function
  Append(new_node); 
}

void LinkedList::Append(shared_ptr<node> new_node){
  //check if list is empty
  if (top_ptr_ == nullptr){
    top_ptr_ = new_node;
  }
  //traverse through list to find the end
  else {
    //create current node pointer and start at head
    shared_ptr<node> curr = top_ptr_;
    while(curr->next !=nullptr) {
      curr = curr->next;
    }
    //add new_node to linked list at the end
    curr->next = new_node;

  }
}

void LinkedList::InsertData(int offset, int data){
  //create new node
  shared_ptr<node> new_node = InitNode(data);
  //check that offset is valid
  if (offset < 0) {
    return;
  }
  //check if offset is zero. If yes, make new_node head of list
  else if (offset == 0) {
    new_node->next = top_ptr_;
    top_ptr_ = new_node;
    return;
  }
  //traverse list to find offset position
  else {
  shared_ptr<node> curr = top_ptr_;
    //stop traversal if end of list reached before offset position reached
    int pos_count = 0;
    while(curr != nullptr && pos_count < offset - 1){
        curr = curr->next;
        pos_count++;
      }
    
    //add new_node at offset position
    new_node->next = curr->next;
    curr->next = new_node;
    
  }
}

void LinkedList::Insert(int offset, shared_ptr<node> new_node){
  InsertData(offset, new_node->data);
}

void LinkedList::Remove(int offset){
   //check that offset is valid
  if (offset < 0) {
    return;
  }
  //check if offset is zero. 
  else if (offset == 0) {
    if(top_ptr_->next != nullptr){
      //remove top pointer by setting next pointer as new top
      SetTop(top_ptr_->next);
    }
    return;
  }
  //traverse list to find offset position
  else {
  shared_ptr<node> curr = top_ptr_;
    //stop traversal if end of list reached before offset position reached
    int pos_count = 0;
    while(pos_count < offset - 1){
        curr = curr->next;
        pos_count++;
      }
    
    if (curr != nullptr){
      shared_ptr<node> temp = curr->next;
      curr->next = curr->next->next;
      
    }
  }
}

int LinkedList::Size(){
  int ret = 0;
  shared_ptr<node> curr = top_ptr_;
    while(curr != nullptr) {
      //count each node traversed
      curr = curr->next;
      ret++;
    }
  return ret;
}

bool LinkedList::Contains(int data){
  bool ret;
  shared_ptr<node> curr = top_ptr_;
    while(curr != nullptr) {
      if(curr->data == data) {
        ret = true;
      }
      curr = curr->next;
    }
  return ret;
}

// This function is implemented for you
// It returns the top pointer
shared_ptr<node> LinkedList::GetTop(){
  return top_ptr_;
}

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::SetTop(shared_ptr<node> top_ptr){
  top_ptr_ = top_ptr;
}

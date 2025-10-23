#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //empty case 
  if (head == nullptr ){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node* curr = head;
  head = head->next;
  curr->next = nullptr;

  llpivot(head, smaller, larger, pivot);// recurive call 

  if (pivot >=  curr->val){ // checks if the values in head is less than or equal to teh pivot and stores in the smaller list 
    curr->next = smaller;
    smaller=curr;
  }
  else {// else stores in larger list
    curr->next =larger;
    larger=curr;
  }

}



#include <iostream>
class LinkedListNode
{
public:
  int val;
  LinkedListNode *next;
};
// 2 4 6 7
// 8 2 4 6 7
// Implement pushToFrontOfList and popFromFrontOfList below
LinkedListNode *pushToFrontOfList(LinkedListNode *whatYouWantToBeNext, int newVal)
{
  LinkedListNode *newHead = new LinkedListNode();
  newHead->val = newVal;
  // Same as (*newHead).val = 8;
  // You now want to set the next pointer of newHead to be "next"
  newHead -> next = whatYouWantToBeNext;
  //[3, 4, 5, 6] 
  // 8, [3]
  // 3, [4]
  // 4, [5]
  // 5, [6]
  // 6, [] next == nullptr


  return newHead; // should return the new head of the list with next as its next LinkedListNode and newVal as its value.
}

LinkedListNode *popFromFrontOfList(LinkedListNode *root)
{
  LinkedListNode *newHead = root -> next;
  delete root;
  return newHead; // should pop and delete the current root node and return the next node as the new head of the list.
}

int main()
{
  LinkedListNode *root = new LinkedListNode();
  root -> val = 10;
  for (int i = 0; i < 10; i++)
  {
    root = pushToFrontOfList(root, i); // 2 1 0
    std::cout << "value pushed: " << root->val << std::endl;
  }
  for (int i = 0; i < 10; i++)
  {
    std::cout << "value popped: " << root->val << std::endl;
    root = popFromFrontOfList(root);
  }
}
// Given the head of a singly linked list, reverse the list, 
// and return the reversed list.
//
// Reverse a linked list
#include <iostream>
#include <string>

using namespace std;

struct ListNode 
{
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* reverseList(ListNode* head) 
{
  if(head == nullptr) return head;

  ListNode* curr = head;
  ListNode* next;
  ListNode* prev = nullptr; 

  while(true)
  {
    // save the old "next"
    next = curr->next;

    // set current as previous
    curr->next = prev;

    // the current becomes the next previous
    prev = curr;

    // set current as the next
    if(next == nullptr)
    {
      head = curr;
      break;
    }
    curr = next;
  }

  return head;
}

void build_list(ListNode* head, int* items, int length)
{
  if(head == nullptr) return;

  ListNode* temp = head;
  for(int i = 0; i < length; i++)
  {
    int data = items[i];
    if(temp->val==0)
    {
        temp->val = data;
    }

    if(i < (length-1))
    {
      ListNode* new_node = new ListNode();
      temp->next = new_node;
      temp = new_node;
    }
  }
}

void print_list(ListNode* head)
{
  ListNode* temp = head;
  while(temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}

void print_array(int* a, int length)
{
  for(int i = 0; i < length; i++)
  {
    cout << " " << a[i];
  }
  cout << endl;
}

int main()
{
    int a[8] = {1,2,4,5,6,7,8,9};
    //print_array(a, 8);
    ListNode* head = new ListNode();
    build_list(head, a, 8);
    print_list(head);
    head = reverseList(head);
    print_list(head);
    return 0;
}
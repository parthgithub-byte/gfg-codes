/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // code here
        if (!head->next){
            return head;
        }
        
        head->next = compute(head->next);
        
        if (head->data < head->next->data){
            return head->next;
        }
        return head;
    }
};
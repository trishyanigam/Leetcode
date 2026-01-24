/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertLL(Node* head)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
    }
    void copyRandom(Node* head)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            {
                temp->next->random = temp->random->next;
            }
            else
            {
                temp->next->random = NULL;
            }
            temp = temp->next->next;
        }
    }
    Node* deepCopy(Node* head)
    {
        Node* dummy = new Node(0);
        Node* curr = dummy;
        Node* temp = head;
        while(temp!=NULL)
        {
            curr->next = temp->next;
            temp->next = temp->next->next;
            curr = curr->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insertLL(head);
        copyRandom(head);
        return deepCopy(head);
    }
};
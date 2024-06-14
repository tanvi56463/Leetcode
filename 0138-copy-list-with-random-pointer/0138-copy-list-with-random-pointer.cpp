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
    Node* copyRandomList(Node* head) {
        if(!head) return 0;
        
        //step1 ->clone A->A'
        Node* it = head;
        while(it){
            Node* clonedNode = new Node(it->val);
            clonedNode-> next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }
        it =head;
        while(it){
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
            
        }
        it=head;
        Node* clonedHead = it->next;
        while(it){
            Node* cloneNde = it->next;
            it->next = it->next->next;
            if(cloneNde->next){
                cloneNde->next = cloneNde->next->next;
                
            }
            it=it->next;
        }
        return clonedHead;
    }
};
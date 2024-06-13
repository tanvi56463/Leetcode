/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
    
    while(a->next && b->next){
        if(a==b){//same length
            return a;
        }
        a=a->next;
        b=b->next;
    }
    if(a->next==0 && b->next==0 && a!=b){
        return 0; // no intersection in LL
    }   
    if(a->next==0){
        // B LL is bigger
        // find how big B is
        int blen = 0;
        while(b->next){
            blen++;
            b=b->next;
        }
        
        //diff of the lengths of a and b is stored in blen
        //so we will initialize head of b from blen
        while(blen--){
            headB = headB->next;
        }
    }
        
        else{
        // A LL is bigger
        // find how big A is
        int alen = 0;
        while(a->next){
            alen++;
            a=a->next;
        }
        
        //diff of the lengths of a and b is stored in alen
        //so we will initialize head of a from alen
        while(alen--){
            headA = headA->next;
        }
    }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headB; //here headA and headB are same
    }    
};
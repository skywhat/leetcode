#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    typedef RandomListNode ln;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return nullptr;
        ln *iter=head,*next;
        //make a copy of each node
        while(iter){
            next=iter->next;
            ln *copy=new ln(iter->label);
            copy->next=next;
            iter->next=copy;
            iter=next;
        }
        //assign the random pointers for the copy list
        iter=head;
        while(iter){
            if(iter->random){
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        //restore the original list
        //extract the copy list
        ln preHead(-1);
        preHead.next=head;
        ln *prev=&preHead;
        iter=head;
        while(iter){
            next=iter->next->next;
            prev->next=iter->next;
            prev=prev->next;
            
            iter->next=next;
            iter=next;
        }
        return preHead.next;
        
        
    }
};



#include <stdio.h>
#include <malloc.h>

/*
1. nth to last
2. max stack, push, pop, max in O(1)
3. divide into 2 halves
4. check if list a plindrome
5. reverse a linked list
6. convert BT to DLL
7. unsorted list - remove all duplicates
8. clone a linked list
9. list cycles in a list
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode     Node;

Node *getNode(int x)
{
    Node *node = NULL;    
    node = (Node *)malloc(sizeof(Node));
    if (node != NULL) {
        node->val = x;
        node->next = NULL;        
    }
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (!l1 && !l2) return NULL;
    
    if (l1 == NULL && l2 != NULL) return l2;
    
    if (l2 == NULL && l1 != NULL) return l1;        
    
    int sz1=0, sz2=0, carry=0, num=0;
    
    Node *hd1 = l1;
    Node *hd2 = l2;
    
    while(hd1) {
        sz1 += 1;
        hd1 = hd1->next;    
    }
    
    while(hd2) {
        sz2 += 1;
        hd2 = hd2->next;
    }
    
    Node *hd3 = NULL;
    Node *hold = NULL;
    
    if (sz1 > sz2) 
    {
        carry = 0;
        sz1 -= sz2;
    
        while(sz2 > 0) 
        {
            num = hd1->val + hd2->val + carry;
            if (num >= 10) {
                carry = num/10;
                num = num%10;
            }
            
            if (hd3 == NULL)
                hd3 = getNode(num);
            else {
                hold = hd3;
                hd3 = getNode(num);
                hd3->next = hold;
            }
            
            hd1 = hd1->next;
            hd2 = hd2->next;
            
            sz2 -= 1;            
        }             
        
        while(sz1 > 0)
        {
            hold = hd3;
            hd3 = getNode(hd1->val +carry);
            hd3->next = hold;
            
            hd1 = hd1->val;
            sz1 -= 1;
            carry = 0;
        }        
    }
    else if (sz2 > sz1)
    {
        carry = 0;
        sz2 -= sz1;
    
        while(sz1 > 0) 
        {
            num = hd1->val + hd2->val + carry;
            if (num >= 10) {
                carry = num/10;
                num = num%10;
            }
            
            if (hd3 == NULL)
                hd3 = getNode(num);
            else {
                hold = hd3;
                hd3 = getNode(num);
                hd3->next = hold;
            }
            
            hd1 = hd1->next;
            hd2 = hd2->next;
            
            sz1 -= 1;            
        }             
        
        while(sz2 > 0)
        {
            hold = hd3;
            hd3 = getNode(hd1->val + carry);
            hd3->next = hold;
            
            hd2 = hd2->val;
            sz2 -= 1;
            carry = 0;
        }
    }
    else if (sz1 == sz2)
    {
        while(sz2 > 0)
        {
           //num = ((hd1 != NULL)?hd1->val:0) + ((hd2 != NULL)?hd2->val:0) + carry; 
           num = hd1->val + hd2->val + carry;
           if (num >= 10) {
               carry = num/10;
               num = num%10;
           }
            
           if (hd3 == NULL)
               hd3 = getNode(num);
           else {
               hold = hd3;
               hd3 = getNode(num);
               hd3->next = hold;
           }
           
      
           if (hd1)
               hd1 = hd1->next;
           if (hd2)
               hd2 = hd2->next;                  
                       
            sz2 -= 1;            
        }
    }
    
    return hd3;
}

void singly_linked_list()
{

}


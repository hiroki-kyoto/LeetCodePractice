/*******************
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
**********************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode t_node;
 t_node * createNode() {
     return (t_node*) malloc( sizeof(t_node) );
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    t_node * s, *e, *l;
    int is_adv = 0;
    t_node *p, *q;
    p = l1;
    q = l2;
    s = createNode();
    s->next = 0;
    l = 0; // last node
    while( p && q ) {
        if ( l == 0 ) { // first node
            e = s;
        } else { // middle list node
            e = createNode();
            e->next = 0;
            l->next = e;
        }
        l = e;
        e->val = p->val + q->val + is_adv;
        if ( e->val >= 10 ) {
            is_adv = 1;
            e->val -= 10;
        } else {
            is_adv = 0;
        }
        p = p->next;
        q = q->next;
    }
    if ( p==0 ) {
        if ( q==0 ) { // p and q are both 0
            if ( is_adv == 1 ) { // advanced figure
                e = createNode();
                e->next = 0;
                e->val = 1;
                l->next = e;
            }
        } else { // p is 0 and q not 0
            while ( q ) {
                e = createNode();
                e->next = 0;
                l->next = e;
                l = e;
                e->val = q->val + is_adv;
                if ( e->val >= 10 ) {
                    e->val -= 10;
                    is_adv = 1;
                } else {
                    is_adv = 0;
                }
                q = q->next;
            }
            if ( is_adv == 1 ) { // advanced figure
                e = createNode();
                e->next = 0;
                e->val = 1;
                l->next = e;
            }
        }
    } else { // p not 0, then q must be 0
        while ( p ) {
            e = createNode();
            e->next = 0;
            l->next = e;
            l = e;
            e->val = p->val + is_adv;
            if ( e->val >= 10 ) {
                e->val -= 10;
                is_adv = 1;
            } else {
                is_adv = 0;
            }
            p = p->next;
        }
        if ( is_adv == 1 ) { // advanced figure
            e = createNode();
            e->next = 0;
            e->val = 1;
            l->next = e;
        }
    }
    return s;
}

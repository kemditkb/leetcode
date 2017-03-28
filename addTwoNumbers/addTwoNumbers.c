#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *result = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    struct ListNode *p = result;
    struct ListNode *last = NULL;

    int sum = 0;
    int carry = 0;
    while(1)
    {
        if(p1 && p2)
        {
            sum += p1->val + p2->val;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1 && (p2 == NULL))
        {
            sum += p1->val;
            p1 = p1->next;  
        }
        else if(p2 && (p1 == NULL))
        {
            sum += p2->val;
            p2 = p2->next;
        }
        else
        {
            break;
        }

        p->val = (sum % 10);
        sum /= 10;

        p->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        last = p;
        p = p->next;
    }

    if(sum != 0)
    {
        last->next->val = sum;
    }
    else
    {
        free(last->next);
        last->next = NULL;
    }

    return result;
}

int main(int argc, char **argv)
{
    struct ListNode *l1 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
    struct ListNode *p1 = l1;

    p1->val = 2;
    p1->next = p1 + 1;
    p1++;

    p1->val = 4;
    p1->next = p1 + 1;
    p1++;

    p1->val = 3;
    p1->next = NULL;

    struct ListNode *l2 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
    struct ListNode *p2 = l2;

    p2->val = 5;
    p2->next = p2 + 1;
    p2++;

    p2->val = 6;
    p2->next = p2 + 1;
    p2++;

    p2->val = 4;
    p2->next = NULL;

    struct ListNode *p = addTwoNumbers(l1, l2);

    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}

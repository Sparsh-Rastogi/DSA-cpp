/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
                return 0;
            }
            ListNode *i = head->next;
            ListNode* j = head->next->next;
            while(i->next && j->next && j->next->next){
                if(i==j){
                    return 1;
                }
                i = i->next;
                j = j->next->next;
            }
            return 0;
            
        }
    };
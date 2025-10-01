/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    unordered_set<ListNode*> visited_nodes;
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;

        while (curr != nullptr){
            if(visited_nodes.count(curr))
                return true;

            visited_nodes.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};
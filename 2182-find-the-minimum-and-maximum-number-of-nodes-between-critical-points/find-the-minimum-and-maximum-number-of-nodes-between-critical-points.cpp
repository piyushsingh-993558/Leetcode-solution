/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
                vector<int> ans;
                        vector<int> intermediate;

                                // Your dummy node logic with your variable names
                                        ListNode* temp = head;
                                                ListNode* Newnode = new ListNode(0);
                                                        ListNode* tempc = Newnode;
                                                                tempc->next = temp;  // Link dummy node to head
                                                                        temp = tempc->next;  // Start from actual head

                                                                                int idx = 1;  // Start indexing from the second node for critical check
                                                                                        while (temp != NULL && temp->next != NULL && temp->next->next != NULL) {
                                                                                                    if ((temp->next->val > temp->val && temp->next->val > temp->next->next->val) || 
                                                                                                                    (temp->next->val < temp->val && temp->next->val < temp->next->next->val)) {
                                                                                                                                    intermediate.push_back(idx);
                                                                                                                                                }
                                                                                                                                                            temp = temp->next;
                                                                                                                                                                        idx++;
                                                                                                                                                                                }

                                                                                                                                                                                        if (intermediate.size() < 2) {
                                                                                                                                                                                                    ans.push_back(-1);
                                                                                                                                                                                                                ans.push_back(-1);
                                                                                                                                                                                                                            return ans;
                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                            int mindist = INT_MAX;
                                                                                                                                                                                                                                                    for (int i = 1; i < intermediate.size(); i++) {
                                                                                                                                                                                                                                                                mindist = min(mindist, intermediate[i] - intermediate[i - 1]);
                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                int maxdist = intermediate.back() - intermediate.front();

                                                                                                                                                                                                                                                                                        ans.push_back(mindist);
                                                                                                                                                                                                                                                                                                ans.push_back(maxdist);
                                                                                                                                                                                                                                                                                                        return ans;
    }
};
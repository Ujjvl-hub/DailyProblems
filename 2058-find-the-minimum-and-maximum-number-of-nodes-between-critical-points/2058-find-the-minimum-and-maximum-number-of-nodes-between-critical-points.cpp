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
        if(head==NULL || head->next==NULL) return {-1,-1};
        ListNode* prev = head;
        ListNode* curr = prev->next;

        int firstPoint = 0;
        int secondPoint = 0;
        int i=1;  //currPosition
       
        bool found = false;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        while(curr->next!=NULL){
            if(prev->val> curr->val && curr->val < curr->next->val){
                if(!found){
                    found = true;
                    firstPoint = i;
                    secondPoint = i;
                }else{
                    maxi = max(maxi, i-firstPoint);
                    mini = min(mini,i-secondPoint);
                    secondPoint = i;
                }
            }
            else if(prev->val < curr->val && curr->val > curr->next->val){
                if(!found){
                    found = true;
                    firstPoint = i;
                    secondPoint = i;
                }else{
                    maxi = max(maxi, i-firstPoint);
                    mini = min(mini,i-secondPoint);
                    secondPoint = i;
                }
            }
            i++;
            prev = prev->next;
            curr = curr->next;
        } 

        int minAns = (mini==INT_MAX)?-1:mini;
        int maxAns = (maxi==INT_MIN)?-1:maxi;

        return {minAns,maxAns};
        
    }
};
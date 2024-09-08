
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

       vector<ListNode*>ans;

        ListNode* temp1 = head;
        ListNode* curr = head;
        int count = 0;

        while(temp1 != NULL)
        {
            count++;
            temp1 = temp1->next;
        }

        int i = count % k;
        int j = count / k;


        ListNode* temp = head;

        if(k <= count)
        {
            while(temp != NULL)
            {
                 ans.push_back(curr);
                 int l = 1;

                while(l<j && temp != NULL)
                {
                  
                    l++;
                    temp = temp->next;          
                }

                if(i>0)
                {
                    i--;
                    temp = temp->next;
                }
             
                if(temp == NULL){
                    break;
                }
                curr = temp->next;
                temp->next = NULL;
                temp = curr;
            }
        }
        else{
            while(temp != NULL){
                ans.push_back(curr);
                curr = temp->next;
                temp->next = NULL;
                temp = curr;
                k--;
            }
            while(k--)
            {
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};
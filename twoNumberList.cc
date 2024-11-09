#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper function to create a linked list from an array
ListNode* createList(const int arr[], int size) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < size; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode *node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head;
        ListNode *curNode;
        ListNode *prec;
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        bool overTen;
        int sum = 0;
        int rem = 0;
        //first Node i do it before the iteration, it is the better way
        head = new ListNode();
        sum = cur1->val + cur2->val;
        overTen = sum < 10;
        head->val = overTen ? sum : (sum-10);
        rem = overTen ? 0 : 1;
        cur1 = cur1->next;
        cur2 = cur2->next;
        //sum = 0;
        prec = head;
        cout << "Head: " << head->val << endl;
        cout << "Sum: " << sum << endl;
        //i have to traverse the list!!!
        while (cur1 != nullptr || cur2 != nullptr) {
            curNode = new ListNode(); 
            if (cur1 != nullptr && cur2 != nullptr) {
                sum = cur1->val + cur2->val + rem;
                overTen = sum < 10;
                curNode->val = overTen ? sum : (sum-10); 
                rem = overTen ? 0 : 1;
                cur1 = cur1->next;
                cur2 = cur2->next;
                cout << "sum: " << sum << endl;
                
            }
            else if (cur1 == nullptr) {
                sum = cur2->val + rem;
                overTen = sum < 10;
                curNode->val = overTen ? sum : (sum-10);
                rem = overTen ? 0 : 1;
                cur2 = cur2->next;
            }
            else {
                sum = cur1->val + rem;
                overTen = sum < 10;
                curNode->val = overTen ? sum : (sum-10);
                rem = overTen ? 0 : 1;
                cur1 = cur1->next;
            }
            //sum = 0;
            cout << "CurNode: " << curNode->val << endl;
            prec->next = curNode;
            prec = curNode;
        }
        if (rem != 0) {
            curNode = new ListNode();
            curNode -> val = rem;
            prec->next = curNode;
        }



        return head;
    }
};
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode();
            ListNode* current = dummy;
            int carry = 0;
            while (l1 || l2 || carry)
            {
                int sum = carry;
                current->next = new ListNode();
                if (l1)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2)
                {
                    sum += l2->val;
                    l2 = l2->next;
                }
                carry = sum / 10;
                sum = sum - carry * 10;
                current->next->val = sum;
                
                
                current = current->next;
            }
            
            return dummy->next;
        }
};
*/
int main() {
    // Define the input lists
    int arr1[] = {9,9,9,9,9,9,9};
    int arr2[] = {9,9,9,9};
    ListNode *l1 = createList(arr1, 7);
    ListNode *l2 = createList(arr2, 4);
    printList(l1);
    printList(l2);
    // Create solution object
    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);

    // Print the resulting list
    cout << "Result: ";
    printList(result);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        int valSx, valDx, height;
        queue<TreeNode *> q;
        stack<TreeNode *> s;
        q.push(root);
        s.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            printStack(s);
            printQueue(q);
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentQueue = q.front();
                q.pop();

                if (currentQueue->left != NULL && currentQueue->right != NULL)
                {
                    q.push(currentQueue->left);
                    q.push(currentQueue->right);

                    if ((((height % 2) == 0) && (i < levelSize/2)) || (levelSize == 1))
                    {
                        TreeNode *currentStack = s.top();

                        valSx = currentQueue->left->val;
                        valDx = currentQueue->right->val;

                        currentQueue->left->val = currentStack->right->val;
                        currentQueue->right->val = currentStack->left->val;

                        currentStack->right->val = valSx;
                        currentStack->left->val = valDx;

                        cout << "currentStack.val: " << currentStack -> val << endl;
                        s.pop();
                    }
                    else if ((i >= (levelSize/2)) && ((height % 2) == 0))
                    {
                        s.pop();
                    }
                    else if ((height % 2) != 0)
                    {
                        s.push(currentQueue->left);
                        s.push(currentQueue->right);
                    }
                }
            }
            ++height;
        }
        return root;
    }

    void printStack(stack<TreeNode *> s)
    {
        cout << "Stack: ";
        while (!s.empty())
        {
            TreeNode *node = s.top();
            cout << node->val << " "; // Stampa il valore del nodo
            s.pop();
        }
        cout << endl;
    }

    void printQueue(queue<TreeNode *> q)
    {
        cout << "Queue: ";
        while (!q.empty())
        {
            TreeNode *node = q.front();
            cout << node->val << " "; // Stampa il valore del nodo
            q.pop();
        }
        cout << endl;
    }
};

void printTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }
}

int main()
{
    // Creazione manuale dell'albero rappresentato nell'immagine
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);

    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(1);

    root->right->left->left = new TreeNode(2);
    root->right->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(2);
    root->right->right->right = new TreeNode(2);

    // Stampa iniziale dell'albero
    cout << "Albero iniziale:" << endl;
    printTree(root);

    // Applicazione della funzione
    Solution sol;
    root = sol.reverseOddLevels(root);

    // Stampa dell'albero dopo l'inversione
    cout << "Albero dopo reverseOddLevels:" << endl;
    printTree(root);

    // Pulizia della memoria (deallocazione dell'albero)
    return 0;
}


/*

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        int level = 0;
        vector<TreeNode*> cur_level;
        while (q.size()) {
            int q_len = q.size();
            for (int i = 0; i < q_len; i++) {
                auto* cur_node = q.front();
                q.pop();
                if (level % 2) {
                    cur_level.push_back(cur_node);
                }
                if (cur_node->left) q.push(cur_node->left);
                if (cur_node->right) q.push(cur_node->right);
            }
            if (level%2) {
                for (int i = 0; i < cur_level.size() / 2 ; i++) {
                    swap(cur_level[i]->val, cur_level[cur_level.size()-i-1]->val);
                }
            }
            cur_level.clear();
            level++;
        }
        return root;
    }
};

*/
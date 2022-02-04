#ifndef MY_TREE_H
#define MY_TREE_H

#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class MyTree {

private:
    struct Node {
        int data;
        Node *left;
        Node *right;
    };
    Node *root;

public:
    MyTree() {
        root = NULL;
    }

    MyTree(vector<T> elements) {
        root = NULL;
        sort(elements.begin(),elements.end());
        root = insertForVector(elements,0,elements.size()-1);

    }
    Node* insertForVector(vector<T> v, int start, int end){
        if (start > end){
            return NULL;
        }
        int mid = (start+end)/2;
        Node* temp = createNode(v[mid]);
        temp->left = insertForVector(v, start, mid-1);
        temp->right = insertForVector(v, mid+1, end);
        return temp;
    }

    bool search(T key) {
        Node *temp = root;

        while (temp != NULL) {

            if (key > temp->data)
                temp = temp->right;

            else if (key < temp->data)
                temp = temp->left;
            else
                return true;
        }
        return false;
    }

    void insert(T key) {

        Node *newMember = createNode(key);

        Node *x = root;

        Node *y = NULL;

        while (x != NULL) {
            y = x;
            if (key < x->data)
                x = x->left;
            else
                x = x->right;
        }


        if (root == NULL) {
            root = newMember;
        } else if (key < y->data)
            y->left = newMember;


        else
            y->right = newMember;
    }

    void inorder_rec() { inorderRecImp(root); }

    void preorder_rec() { printPreorderRecImp(root); }

    void postorder_rec() { printPostorderRecImp(root); }

    void inorder_it() {
        stack<Node *> storedElements;
        Node *currentNode = root;

        while (currentNode != NULL || storedElements.empty() == false) {
            while (currentNode != NULL) {
                storedElements.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = storedElements.top();
            storedElements.pop();

            cout << currentNode->data << " ";
            currentNode = currentNode->right;

        }
    }

    void preorder_it() {
        if (root == NULL)
            return;

        stack<Node *> nodeStack;
        nodeStack.push(root);


        while (nodeStack.empty() == false) {

            struct Node *node = nodeStack.top();
            printf("%d ", node->data);
            nodeStack.pop();

            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
    }

    void postorder_it() {
        if (root == NULL)
            return;

        stack<Node *> stack1, stack2;

        stack1.push(root);
        Node *node;

        while (!stack1.empty()) {

            node = stack1.top();
            stack1.pop();
            stack2.push(node);


            if (node->left)
                stack1.push(node->left);
            if (node->right)
                stack1.push(node->right);
        }

        while (!stack2.empty()) {
            node = stack2.top();
            stack2.pop();
            cout << node->data << " ";
        }
    }

    void breadth_traversal() {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printCurrentLevel(root, i);
    }

    int size() { return size(root);}


    Node *createNode(T data) {
        Node *temp = new Node;

        temp->data = data;

        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    void inorderRecImp(Node *temp) {
        if (temp == NULL)
            return;

        inorderRecImp(temp->left);

        cout << temp->data << " ";
        inorderRecImp(temp->right);
    }

    int height(Node *node) {
        if (node == NULL)
            return 0;
        else {

            int leftHeight = height(node->left);
            int rightHeight = height(node->right);

            if (leftHeight > rightHeight) {
                return (leftHeight + 1);
            } else {
                return (rightHeight + 1);
            }
        }
    }


    void printCurrentLevel(Node *temp, int level) {
        if (temp == NULL)
            return;
        if (level == 1)
            cout << temp->data << " ";
        else if (level > 1) {
            printCurrentLevel(temp->left, level - 1);
            printCurrentLevel(temp->right, level - 1);
        }
    }

    void printPreorderRecImp(struct Node *node) {
        if (node == NULL)
            return;

        cout << node->data << " ";

        printPreorderRecImp(node->left);

        printPreorderRecImp(node->right);
    }

    void printPostorderRecImp(struct Node *node) {
        if (node == NULL)
            return;

        printPostorderRecImp(node->left);

        printPostorderRecImp(node->right);

        cout << node->data << " ";
    }

    int size(Node* temp)
    {

        if (temp == NULL)
            return 0;
        else
            return(size(temp->left) + 1 + size(temp->right));
    }

};



#endif
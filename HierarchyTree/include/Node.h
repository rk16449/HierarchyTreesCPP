#ifndef NODE_H
#define NODE_H
#include "Member.h"

class Node
{
    public:
        Node();


        Node* GetNewNode(int data){
            // Create new node
            Node* newNode = new Node();
            // Set values of data and left/right child
            newNode->data = data;
            newNode->left = newNode->right = 0;
        }

        Node* Insert(Node* root, int data){
            if(root == 0){ // Empty Tree
                root = GetNewNode(data);

            }
            else if(data <= root->data){
                root->left = Insert(root->left, data);
            }
            else{
                root->right = Insert(root->right, data);
            }
            return root;
        }

        bool Search(Node* root, int data){
            if(root == 0) return false;
            else if(root->data == data) return true;
            else if(data <= root->data) return Search(root->left, data);
            else return Search(root->right, data);
        }

        // Getters and setters
        int getData() { return data; }
        void setData(int val) { data = val; }

    protected:

    private:
        int data;
        Node* left;
        Node* right;
};

#endif // NODE_H

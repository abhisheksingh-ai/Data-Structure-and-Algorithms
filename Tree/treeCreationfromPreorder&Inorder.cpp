#include <iostream>
#include <queue>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to create a Node
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function for level order traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL) return; // handle the case if the root is NULL
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data<< " ";

            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

// Function to search an element in the inorder array
int searchingInInorder(int inOrder[], int element, int size) {
    for (int i = 0; i < size; i++) {
        if (inOrder[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to create a tree from preorder and inorder arrays
Node* treeCreationFromPreorderAndInorder(int preOrder[], int inOrder[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int size) {
    // Base case
    if (preOrderIndex >= size || inOrderStart > inOrderEnd) {
        return NULL;
    }

    // Current element from preorder traversal
    int element = preOrder[preOrderIndex];
    preOrderIndex++;
    Node* root = new Node(element);

    // Find position of the current element in inorder traversal
    int position = searchingInInorder(inOrder, element, size);
    root->left = treeCreationFromPreorderAndInorder(preOrder, inOrder, preOrderIndex, inOrderStart, position - 1, size);
    root->right = treeCreationFromPreorderAndInorder(preOrder, inOrder, preOrderIndex, position + 1, inOrderEnd, size);

    return root;
}

int main() {
    int preOrder[] = {10, 8, 6, 2, 4, 12};
    int inOrder[] = {2, 8, 10, 6, 4, 12};
    int size = 6;
    int preOrderIndex = 0; // The index in the preorder array
    int inOrderStart = 0;
    int inOrderEnd = size - 1; // Correct end index

    Node* root = treeCreationFromPreorderAndInorder(preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing the tree" << endl;

    levelOrderTraversal(root);

    return 0;
}

#include<iostream>
#include<queue>
using namespace std;

class Node{
public:

    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        // ab do case honge ya to front NULL hai 
        //case1 -> NULL hai
        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";

            if(front->left!=NULL){
                q.push(front->left);
            }

            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }

}

Node* insertToBST(Node* root, int data){
    if(root == NULL){
        //phle ek Node to bana
        root = new Node(data);
        return root;
    }
    // ab recursion kaam karega 
    if(data > root->data){
        root->right = insertToBST(root->right, data);
    }
    else{
        root->left = insertToBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root){
    //byrefernce pass kiya hai actual root me changes honge
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
   
    while(data != -1){
        root = insertToBST(root, data);
        cout<<"Enter the data: "<<endl;
        cin>>data;
    }
}

int main(){
    // 50 30 40 20 60 55 70 80 25 -1
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    return 0;
}
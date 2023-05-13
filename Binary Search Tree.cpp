#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        cout << "Unable to allocate memory\n";
        exit(0);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *SearchKey(Node *root, int key)
{
    Node *current = root, *parent = root;

    while(current != NULL){
        parent = current;
        if(current->data == key){
            return NULL;
        }
        else if(current->data> key){
            current = current->left;
        }
        else if(current->data < key){
            current = current->right;
        }
    }
    return parent;
}

void insertNode(Node *root, int data)
{
    Node *parent = SearchKey(root, data), *newNode = createNode(data);

    if(parent == NULL){
        cout << "Duplicate Element not allowed in BST\n";
    }
    else if(parent->data > data){
        parent->left = newNode;
    }
    else if(parent->data < data){
        parent->right = newNode;
    }
}

void PreOrder(Node *root){
    cout << root->data << "\t";
    if(root->left != NULL){
        PreOrder(root->left);
    }
    if(root->right != NULL){
        PreOrder(root->right);
    }
}

void PostOrder(Node *root){
    
    if(root->left != NULL){
        PostOrder(root->left);
    }
    if(root->right != NULL){
        PostOrder(root->right);
    }
    cout << root->data << "\t";
}

void InOrder(Node *root){
    
    if(root->left != NULL){
        InOrder(root->left);
    }
    cout << root->data << "\t";
    if(root->right != NULL){
        InOrder(root->right);
    }
}

int InternalPathLength(Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    queue<Node*> q;
    q.push(root);
    int pathLen = 0;
    int level = 0;
    
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* node = q.front();
            q.pop();
            pathLen += level;
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        level += 1;;
    }
    
    return pathLen;
}

int ExternalPathLength(Node *root)
{
    int pathLength = 0;
    int level = 0;
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        while(n--){
            Node *node = q.front();
            q.pop();
            if(node->left == NULL && node->right == NULL){
                pathLength += level;
            }
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
        }
        level += 1;
    }
    return pathLength;
}

int main()
{
    string data;
    cout << "Enter root Node : ";
    cin >> data;
    Node *root = createNode(stoi(data));
    cout << "Enter more nodes:(Enter any english alphabet to exit)\n";
    while(true){
        cin >> data;
        if((data[0] >= 'A' && data[0] <= 'Z') || (data[0] >= 'a' && data[0] <= 'z')){
            break;
        }
        
        insertNode(root ,stoi(data));
    }
    cout << "PreOrder Traverse: ";
    PreOrder(root);
    cout << "\n";

    cout << "PostOrder Traverse: ";
    PostOrder(root);
    cout << "\n";

    cout << "InOrder Traverse: ";
    InOrder(root);
    cout << "\n";
    
    cout << "Internal Path Length: " << InternalPathLength(root) << endl;
    cout << "External Path Length: " << ExternalPathLength(root)<< endl;

    if(SearchKey(root, 3)){
        cout << "Item Dose not exist\n" << endl;
    }
    else{
        cout << "Item Exist\n";
    }
    return 0;
}
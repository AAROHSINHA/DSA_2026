#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// declaring a binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// 1. recursive preorder
void RPreorderTraversal(Node* head){
    if(!head) return;
    cout << head->data << " ";
    RPreorderTraversal(head->left);
    RPreorderTraversal(head->right);
}

// 2. recursive postorder
void RPostorderTraversal(Node* head){
    if(!head) return;
    RPostorderTraversal(head->left);
    RPostorderTraversal(head->right);
cout << head->data << " ";
}

// 3. recursive inorder
void RInorderTraversal(Node* head){
    if(!head) return;
    RInorderTraversal(head->left);
    cout << head->data << " ";
    RInorderTraversal(head->right);
}

// 4. Iterative Level Order Traversal
void IterativeLevelOrderTraversal(Node* head){
    vector<vector<Node*>> vec;
    queue<Node*> q;
    q.push(head);
    while(!q.empty()){
        vector<Node*> vecs;
        while(!q.empty()){
            vecs.push_back(q.front());
            q.pop();
        }
        for(Node* node : vecs){
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right); 
        }

        vec.push_back(vecs);
    }

    // print
    for(vector<Node*> heads: vec){
        for(Node* head : heads){
            cout << head->data << " ";
        }
    }
    cout << "\n";
}

// 5. Iterative preorder
void IterativePreorder(Node* head){
    stack<Node*> st;
    st.push(head);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
    cout << "\n";
}

// 6. Iterative Postorder
void IterativePostorder(Node* head){
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(head);
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        if(temp->left) st1.push(temp->left);
        if(temp->right) st1.push(temp->right);
        st2.push(temp);
    }

    while(!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop();
    }
    cout << "\n";
}
void IterativePostorder2(Node* head){
    vector<int> nums;
    stack<Node*> st1;
    st1.push(head);
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        if(temp->left) st1.push(temp->left);
        if(temp->right) st1.push(temp->right);
        nums.push_back(temp->data);
    }

    for(int i = nums.size() - 1; i >= 0; i-=1){
        cout << nums[i] << " ";
    }
    cout << "\n";
}

// iterative inorder
void iterativeInorder(Node* head){
    stack<Node*> st;
    vector<Node*> inorder;
    Node* tempPtr = head;
    while(true){
        if(tempPtr){
            st.push(tempPtr);
            tempPtr = tempPtr->left;
        }else{
            if(st.empty()) break;
            tempPtr = st.top();
            st.pop();
            cout << tempPtr->data << " ";
            tempPtr = tempPtr->right;
        }
    }
    cout << "\n";
}

// MORRIS INORDER TRAVERSAL
void MorrisInorderTraversal(Node* head){
    Node* currPtr = head;
    while(currPtr){
        if(currPtr->left == nullptr){
            cout << currPtr->data << " ";
            currPtr = currPtr->right;
        }else{
            // find inorder predecessor
            Node* predPtr = currPtr->left;
            while(predPtr->right && predPtr->right!=currPtr){
                predPtr = predPtr->right;
            }

            // thread doesnt exist
            if(predPtr->right == NULL){
                predPtr->right = currPtr;
                currPtr = currPtr->left;
            }else{
                predPtr->right = NULL;
                cout << currPtr->data << " ";
                currPtr = currPtr->right;
            }
        }
    }
}

int main(){
    Node* head = new Node(1);
    head->left = new Node(2);

    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    iterativeInorder(head);
    MorrisInorderTraversal(head);
    return 0;
}
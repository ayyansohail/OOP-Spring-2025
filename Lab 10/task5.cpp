#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class BinaryTree {

    private:
    struct Node{
        T data;
        Node* left;
        Node* right;

        Node(T value): data(value), left(nullptr), right(nullptr) {}
    };
    Node* root;
    Node* insertHelper(Node* node, T value){
        if(node == nullptr){
            return new Node(value);
        }

        if(value<node->data){
            node->left = insertHelper(node->left, value);
        }
        if(value>node->data){
            node->right = insertHelper(node->right, value);
        } return node;
    }
    void inOrderHelper(Node* node, vector<T>& output){
        if(node == nullptr){
            return;
        }

        inOrderHelper(node->left, output);
        output.push_back(node->data);
        inOrderHelper(node->right, output);
    }
    void clearHelper(Node* node){
        if(node == nullptr) return;
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }

    public:
    BinaryTree(): root(nullptr) {}
    void insert(T value){
        root = insertHelper(root, value);
    }
    void inOrder(vector<T>& output){
        inOrderHelper(root, output);
    }
    void operator()(vector<T>& vec){
        for(T value: vec){
            insert(value);
        }
        vector<T> sorted;
        inOrder(sorted);
        vec = sorted;
    }
    void clear(){
        clearHelper(root);
        root = nullptr;
    }
};

int main(){
    BinaryTree<int> binT;
    vector<int> output;
    binT.insert(10);
    binT.insert(15);
    binT.insert(5);
    binT.inOrder(output);
    for(int n: output){
        cout<<n<<" ";
    }cout<<endl;

    vector<int> nums = {4,1,5,2,3};
    BinaryTree<int> tree;
    tree(nums); // sorts the vector using bst logic
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
    binT.clear();
    return 0;
}
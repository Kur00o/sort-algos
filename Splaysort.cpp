#include <iostream>
#include <vector>
using namespace std;

// Node structure for Splay Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Splay Tree implementation
class SplayTree {
private:
    Node* root;
    
    // Right rotation
    Node* rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }
    
    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }
    
    // Splay operation brings the target key to the root
    Node* splay(Node* root, int key) {
        // Base cases: root is NULL or key is at root
        if (root == nullptr || root->key == key)
            return root;
            
        // Key is in left subtree
        if (root->key > key) {
            // Key not in tree
            if (root->left == nullptr)
                return root;
                
            // Zig-Zig (Left Left)
            if (root->left->key > key) {
                // First recursively bring the key as root of left-left
                root->left->left = splay(root->left->left, key);
                // Do first rotation for root, second rotation is done after else
                root = rightRotate(root);
            }
            // Zig-Zag (Left Right)
            else if (root->left->key < key) {
                // First recursively bring the key as root of left-right
                root->left->right = splay(root->left->right, key);
                // Do first rotation for root->left
                if (root->left->right != nullptr)
                    root->left = leftRotate(root->left);
            }
            
            // Do second rotation for root
            return (root->left == nullptr) ? root : rightRotate(root);
        }
        // Key is in right subtree
        else {
            // Key not in tree
            if (root->right == nullptr)
                return root;
                
            // Zag-Zig (Right Left)
            if (root->right->key > key) {
                // First recursively bring the key as root of right-left
                root->right->left = splay(root->right->left, key);
                // Do first rotation for root->right
                if (root->right->left != nullptr)
                    root->right = rightRotate(root->right);
            }
            // Zag-Zag (Right Right)
            else if (root->right->key < key) {
                // First recursively bring the key as root of right-right
                root->right->right = splay(root->right->right, key);
                // Do first rotation for root
                root = leftRotate(root);
            }
            
            // Do second rotation for root
            return (root->right == nullptr) ? root : leftRotate(root);
        }
    }
    
    // Insert a key into the tree
    Node* insert(Node* root, int key) {
        // If tree is empty
        if (root == nullptr)
            return new Node(key);
            
        // Splay the key (or the nearest key)
        root = splay(root, key);
        
        // If key already exists, return
        if (root->key == key)
            return root;
            
        // Create a new node
        Node* newNode = new Node(key);
        
        // If root's key is greater, make root as right child of newNode
        // and copy the left child of root to newNode
        if (root->key > key) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        }
        // If root's key is smaller, make root as left child of newNode
        // and copy the right child of root to newNode
        else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }
        
        return newNode;
    }
    
    // Inorder traversal to fill the sorted array
    void inorder(Node* root, vector<int>& result) {
        if (root == nullptr)
            return;
            
        inorder(root->left, result);
        result.push_back(root->key);
        inorder(root->right, result);
    }
    
    // Free memory
    void freeTree(Node* root) {
        if (root == nullptr)
            return;
            
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
    
public:
    SplayTree() : root(nullptr) {}
    
    ~SplayTree() {
        freeTree(root);
    }
    
    // Public method to insert a key
    void insert(int key) {
        root = insert(root, key);
    }
    
    // Public method to get sorted array
    vector<int> getSortedArray() {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

// Splay Sort function
vector<int> splaySort(const vector<int>& arr) {
    SplayTree tree;
    
    // Insert all elements into the splay tree
    for (int num : arr) {
        tree.insert(num);
    }
    
    // Get sorted array from the tree
    return tree.getSortedArray();
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> sorted_arr = splaySort(arr);
    
    cout << "Sorted array: ";
    for (int num : sorted_arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
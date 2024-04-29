#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
//
struct Node {
    int key;
    char value[10];
    Node* left;
    Node* right;
};
//prototypes
Node* CreateNode(int key, char* value);
Node* Insert_Element(Node*& root, int key, char* value);
void print_tree(Node* node, int indent);
Node* search(Node* root, int key);
Node* DelNode(Node* root, int key);
void FreeTree(Node* root);
int count_right_nodes(Node* node);

void main()
{
    Node* root = nullptr;
    int indent = 0;
    Node* search_result;
    char choise;

    do {
        cout << "1-Add element" << endl;
        cout << "2-Find by key" << endl;
        cout << "3-Print the tree" << endl;
        cout << "4-Delete a specific element" << endl;
        cout << "5-Clear the whole tree" << endl;
        cout << "6-Count nodes in the right branch" << endl;
        cout << "7-Exit" << endl;
        cin >> choise;
        while (!(choise >= '1' && choise <= '7')) {
            cout << "Wrong variant! Try again: ";
            cin >> choise;
        }
        int choise_sw = choise - '0';//convert char to int
        switch (choise_sw) {
        case 1:int amm_of_elements;
            cout << "Enter the amount of elements: ";
            cin >> amm_of_elements;
            for (int i = 0; i < amm_of_elements; i++) {//cycle to insert all the required elements
                int key_temp;
                cout << "Enter the key: ";
                cin >> key_temp;
                char value_temp[10];
                cout << "Enrer the value: ";
                cin >> value_temp;
                root = Insert_Element(root, key_temp, value_temp);
            }
            break;
        case 2:int search_key;
            cout << "Enter the key of an element you would like to find: ";
            cin >> search_key;
            search_result = search(root, search_key);//create a node for a result only
            if (search_result != nullptr) {
                cout << "Element found! It's " << search_result->key << " " << search_result->value << endl;
            }
            else {
                cout << "There's no such an element" << endl;
            }
            break;
        case 3:
            print_tree(root, indent); break;
        case 4:int del_key;
            cout << "Enter the key of an element to be deleted:";
            cin >> del_key;
            DelNode(root, del_key); break;
        case 5:FreeTree(root); cout << "The tree is deleted" << endl;
            break;
        case 6:cout << "The amount of nodes in the right branch is: " << count_right_nodes(root) << endl;
            break;
        }


    } while (choise != '7');
}

Node* CreateNode(int key, char* value)//function that creates a node 
{
    Node* NewNode = new Node();//get memory for a new node
    if (!NewNode) {//if there is a memoy failure
        cout << "Memory Error!" << endl;
        return nullptr;
    }
    NewNode->key = key;
    for (int i = 0; i < 10; i++) {//cycle to insert an array of chars in a new node
        *((NewNode->value) + i) = *(value + i);
    }
    NewNode->left = NewNode->right = nullptr;//set all the branches to null
    return NewNode;
}
Node* Insert_Element(Node*& root, int key, char* value)//function to insert previousl created element in the tree
{
    if (root == nullptr) {//if the tree is empty
        root = CreateNode(key, value);
    }
    else {
        if (key < root->key) {//sort values in two branches of BST based on the key value
            Insert_Element(root->left, key, value);
        }
        else {
            Insert_Element(root->right, key, value);
        }
    }
    return root;
}

void print_tree(Node* node, int indent)//function to print the whole BST
{
    if (node != nullptr) {//if there is something to print
        print_tree(node->right, indent + 4);
        cout << setw(indent) << node->key << " " << node->value << endl;
        print_tree(node->left, indent + 4);
    }
}
Node* search(Node* root, int key)//function to find a specific element by key
{
    if (root == nullptr || root->key == key) {//if the root is null or the required element is the root
        return root;
    }
    if (root->key < key) {//if the required key is greater than the root key
        return search(root->right, key);
    }
    else {
        return search(root->left, key);//if not
    }
}

Node* DelNode(Node* root, int key)//function to delete a specific node from a BST
{
    if (root == nullptr) {//if the tree is empty
        return root;
    }
    if (key < root->key) {//if the required key is smaller than the root one. It means that it's located in the left subtree
        root->left = DelNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = DelNode(root->right, key);
    }
    //if the node is same as the root one
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        Node* temp = root;
        temp->key = 100;
        char temp_val[10] = "deleted";
        *(temp->value) = *temp_val;
        root->key = temp->key;
        *(root->value) = *(temp->value);
        root->right = DelNode(root->right, temp->key);
    }
    return root;
}

void FreeTree(Node* root)//function to delete the whole BST
{
    if (root == nullptr) {//if the tree is already empty
        return;
    }
    FreeTree(root->left);//recursively implement the function
    FreeTree(root->right);
    delete root;//delete the node
}

int count_right_nodes(Node* node)//function to count nodes in the right branch
{
    if (node == nullptr) {//if the tree is empty
        return 0;
    }
    int count = (node->right != nullptr) ? 1 : 0;//count the node if it's in the right branch
    return count + count_right_nodes(node->right);//recursively use this function
}

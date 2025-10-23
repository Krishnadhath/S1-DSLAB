#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* create(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Insert a node
struct Node* insert(struct Node* root, int data) {
    if (!root) return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Search a node
struct Node* search(struct Node* root, int key) {
    if (!root || root->data == key) return root;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Delete a node
struct Node* delete(struct Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        // Node with one or no child
        if (!root->left) { struct Node* r = root->right; free(root); return r; }
        if (!root->right) { struct Node* l = root->left; free(root); return l; }
        // Node with two children
        struct Node* t = findMin(root->right);
        root->data = t->data;
        root->right = delete(root->right, t->data);
    }
    return root;
}

// Inorder traversal (sorted order)
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    root = delete(root, 30);
    printf("After deleting 30: ");
    inorder(root);
    printf("\n");

    printf("Search 60: %s\n", search(root, 60) ? "Found" : "Not Found");
    return 0;
}

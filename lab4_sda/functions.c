#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

Node* insertNode(Node* root, int key, const char* name, const char* data, int value) {
    if (!root) return createNode(key, name, data, value);
    if (key < root->key)
        root->left = insertNode(root->left, key, name, data, value);
    else
        root->right = insertNode(root->right, key, name, data, value);
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d %s %s %d\n", root->key, root->name, root->data, root->value);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        printf("%d %s %s %d\n", root->key, root->name, root->data, root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d %s %s %d\n", root->key, root->name, root->data, root->value);
    }
}

Node* searchNode(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

Node* mirrorTree(Node* root) {
    if (!root) return NULL;
    Node* left = mirrorTree(root->left);
    Node* right = mirrorTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

void clearTree(Node* root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

void bfs(Node* root) {
    if (!root) return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d %s %s %d\n", current->key, current->name, current->data, current->value);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Node {
    int key;
    char name[50];
    char data[50];
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key, const char* name, const char* data, int value);
Node* insertNode(Node* root, int key, const char* name, const char* data, int value);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
Node* searchNode(Node* root, int key);
Node* mirrorTree(Node* root);
void clearTree(Node* root);
void bfs(Node* root);

#endif

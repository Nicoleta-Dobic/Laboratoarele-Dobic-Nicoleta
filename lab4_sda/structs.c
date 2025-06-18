#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

Node* createNode(int key, const char* name, const char* data, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->name, name);
    strcpy(newNode->data, data);
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

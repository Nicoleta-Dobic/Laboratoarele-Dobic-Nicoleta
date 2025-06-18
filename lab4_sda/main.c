#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Node* root = NULL;
    int opt, key, value;
    char name[50], data[50];

    do {
        printf("\nMeniu:\n");
        printf("1. Adauga nod\n2. Cauta nod\n3. Afiseaza inordine\n4. Preordine\n5. Postordine\n");
        printf("6. BFS\n7. Oglindire arbore\n8. Curata arbore\n0. Iesire\n");
        printf("Optiune: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Key: "); scanf("%d", &key);
            printf("Name: "); scanf("%s", name);
            printf("Data: "); scanf("%s", data);
            printf("Value: "); scanf("%d", &value);
            root = insertNode(root, key, name, data, value);
            break;
            case 2:
                printf("Key cautat: "); scanf("%d", &key);
            Node* found = searchNode(root, key);
            if (found)
                printf("Gasit: %d %s %s %d\n", found->key, found->name, found->data, found->value);
            else
                printf("Nu a fost gasit.\n");
            break;
            case 3: inorder(root); break;
            case 4: preorder(root); break;
            case 5: postorder(root); break;
            case 6: bfs(root); break;
            case 7: root = mirrorTree(root); break;
            case 8: clearTree(root); root = NULL; break;
        }
    } while (opt != 0);

    clearTree(root);
    return 0;
}

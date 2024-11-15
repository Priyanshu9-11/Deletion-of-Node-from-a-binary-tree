#include <stdio.h>
#include <stdlib.h>

struct bintree {
    int info;
    struct bintree *left, *right;
};
typedef struct bintree node;

node *insert(node *, int);
int search(node *, int, node **, node **);
int del(node **, int);

node *insert(node *s, int n) {
    node *nn;
    nn = (node *)malloc(sizeof(node));
    nn->info = n;
    nn->left = NULL;
    nn->right = NULL;
    if (s == NULL) {
        return nn;
    } else {
        node *S = s;
        while (1) {
            if (n < S->info) {
                if (S->left == NULL) {
                    S->left = nn;
                    break;
                } else {
                    S = S->left;
                }
            } else {
                if (S->right == NULL) {
                    S->right = nn;
                    break;
                } else {
                    S = S->right;
                }
            }
        }
    }
    return s;
}


int search(node *s, int n, node **p, node **x) {
    *p = NULL; // Parent starts as NULL
    *x = s;    // Start at the root

    while (*x != NULL) {
        if ((*x)->info == n) {
            return 1;
        }
        *p = *x; // Update the parent before moving
        if (n < (*x)->info) {
            *x = (*x)->left;
        } else {
            *x = (*x)->right;
        }
    }
    return 0;
}

int del(node **root, int n) {
    node *x, *p, *xs, *xp;
    int r;
    if (*root == NULL) {
        return 0;
    }
    r = search(*root, n, &p, &x);
    if (r == 0) {
        return 0;
    }

    // Node with two children
    if (x->left != NULL && x->right != NULL) {
        xp = x;
        xs = x->right;
        while (xs->left != NULL) {
            xp = xs;
            xs = xs->left;
        }
        x->info = xs->info;  // Copy the inorder successor's value to x
        x = xs;              // Now we need to delete xs
        p = xp;
    }

    // Node with at most one child
    node *child = (x->left != NULL) ? x->left : x->right;

    // Deleting the root node
    if (p == NULL) {
        *root = child;
    } else if (p->left == x) {
        p->left = child;
    } else {
        p->right = child;
    }

    free(x);
    return 1;
}

int main() {
    node *root = NULL;
    int choice, num, result;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                root = insert(root, num);
                printf("%d inserted.\n", num);
                break;
            case 2:
                printf("Enter the number to search: ");
                scanf("%d", &num);
                node *p, *x;
                result = search(root, num, &p, &x);
                if (result == 1) {
                    printf("%d found.\n", num);
                } else {
                    printf("%d not found.\n", num);
                }
                break;
            case 3:
                printf("Enter the number to delete: ");
                scanf("%d", &num);
                result = del(&root, num);
                if (result == 1) {
                    printf("%d deleted.\n", num);
                } else {
                    printf("Error: %d not found or cannot be deleted.\n", num);
                }
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

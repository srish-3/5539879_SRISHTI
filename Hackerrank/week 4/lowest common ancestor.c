#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

struct node *lca( struct node *root, int v1, int v2 ) {
if (root == NULL) {
        return NULL;
    }

    
    if (v1 < root->data && v2 < root->data) {
        return lca(root->left, v1, v2);
    }

        if (v1 > root->data && v2 > root->data) {
        return lca(root->right, v1, v2);
    }

    
    return root;
}
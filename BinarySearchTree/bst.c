//
//  bst.c
//  BinarySearchTree
//
//  Created by Donald Usry on 3/7/16.
//  Copyright © 2016 Donald Usry. All rights reserved.
//

#include "bst.h"

int main(void)
{
    BstNode* root = NULL;
    
    root = parse_and_build();
    
    search(root);
    
    return 0;
}

BstNode* parse_and_build()
{
    FILE* file = NULL;
    BstNode* root = NULL;
    int ch;
    
    file = fopen("/Users/donald/git/BinarySearchTree/BinarySearchTree/data", "r");
    
    if(file == NULL)
    {
        fprintf(stderr, "Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    
    if(fscanf(file, "%d", &ch) == EOF)
    {
        fprintf(stderr, "File is empty.\n");
        exit(EXIT_FAILURE);
    }
    
    root = create_node(ch);
    
    while(fscanf(file, "%d", &ch) != EOF)
    {
        if(!find_element(ch, root))
            place_element(ch, root);
    }
    
    return root;
}

BstNode* create_node(int value)
{
    BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void place_element(int value, BstNode* root)
{
    if(value <= root->data)
    {
        if(root->left == NULL)
        {
            root->left = create_node(value);
        }
        else
        {
            place_element(value, root->left);
        }
    }
    else if(value > root->data)
    {
        if(root->right == NULL)
        {
            root->right = create_node(value);
        }
        else
        {
            place_element(value, root->right);
        }
    }
}

int find_element(int value, BstNode* root)
{
    if(root->data == value)
    {
        return 1;
    }
    else if(value <= root->data)
    {
        if(root->left != NULL)
        {
            return find_element(value, root->left);
        }
    }
    else if(value > root->data)
    {
        if(root->right != NULL)
        {
            return find_element(value, root->right);
        }
    }
    return 0;
}

void search(BstNode* root)
{
    int value;
    
    do
    {
        value = 0;
        printf("Enter a number to search for: ");
        scanf("%d", &value);
    
        if(find_element(value, root))
        {
            printf("%d was found in the BST.\n", value);
        }
        else
        {
            printf("%d was not found in the BST.\n", value);
        }
    }
    while(value >= 0);
}


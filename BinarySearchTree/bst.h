//
//  bst.h
//  BinarySearchTree
//
//  Created by Donald Usry on 3/7/16.
//  Copyright © 2016 Donald Usry. All rights reserved.
//

#ifndef bst_h
#define bst_h

#include <stdio.h>
#include <stdlib.h>

#endif /* bst_h */

typedef struct BstNode
{
    int data;
    struct BstNode* left;
    struct BstNode* right;
} BstNode;

int main(void);

BstNode* parse_and_build();

BstNode* create_node(int);

void place_element(int, BstNode*);

int find_element(int, BstNode*);

void search(BstNode*);
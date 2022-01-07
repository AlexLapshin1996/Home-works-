#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int key;
    struct Node*left;
    struct Node*right;
}TreeNode;

TreeNode * treeInsert(TreeNode*t,int data)
{
    TreeNode  *newNode;
    newNode=(TreeNode*) malloc(sizeof(TreeNode));
    newNode->key=data;
    newNode->left=NULL;
    newNode->right=NULL;
    TreeNode * current = t;
    TreeNode *parent = t;
    if (t==NULL)
    {
        t = newNode;
    }
    else
    {
        while(current->key!=data)
        {
            parent=current;
            if(current->key>data)
            {
                current=current->left;
                if(current==NULL)
                {
                    parent->left=newNode;
                    return t;
                }
            }
            else
            {
                current=current->right;
                if(current==NULL)
                {
                    parent->right=newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode*root)
{
    if(root)
    {
        printf("%d",root->key);
        if(root->left || root->right)
        {
            printf("(");
            if(root->left)
            printTree(root->left);

            else
                printf("NULL");
                printf(",");

            if(root->right)
               printTree(root->right);

            else
                printf("NULL");
                printf(")");

        }
    }
}


int main()
{

   TreeNode *tree = treeInsert(tree,10);
    treeInsert(tree,8);
    treeInsert(tree,19);
    treeInsert(tree,5);
    treeInsert(tree,9);
    treeInsert(tree,16);
    treeInsert(tree,21);
    printTree(tree);


    return 0;
}

#include "geek.h"
#include "stdbool.h"

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
        if(root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);

            else
                printf("NULL");
            printf(",");

            if (root->right)
                printTree(root->right);

            else
                printf("NULL");
                printf(")");

        }
    }
}

TreeNode * find(TreeNode* res,int data)
{
    if(res==NULL)
    {
        return NULL;
    }
    if (res->key==data)
    {
        return res;
    }
    if(data<=res->key)
    {
        if(res->left!=NULL)
            return find(res->left,data);

        else
        {
            return NULL;
        }
    }
    else
    {
        if(res->right)
        {
            return find(res->right,data);
        }
        else
        {
            return NULL;
        }
    }

}

int max(int a,int b)
{
    return (a>=b) ? a : b;
}

int height(struct Node*node)
{
    if(node==NULL)
        return 0;

    return 1+ max(height(node->left),height(node->right));
}

bool isBalanced(struct Node* root)
{
    int Lh;
    int Rh;
    int height_balanced;

    if (root==NULL)
        return 1;

    Lh = height(root->left);
    Rh= height(root->right);
    height_balanced= abs(Lh-Rh);

    if(height_balanced>1)
        return 0;

    return isBalanced(root->left) && isBalanced(root->right);
}

void kill_tree(TreeNode*root)
{
    if(root==NULL)
        return;
    if (root->left!=NULL)
    {
        kill_tree(root->left);
    }
    if(root->right!=NULL)
    {
        kill_tree(root->right);
    }
    free(root);
}


int main()
{
    srand(time(NULL));

  const int Numbers_Trees = 50;
  const int Numbers_nodes = 10000;

  TreeNode * tree[Numbers_Trees];
  int trees_in_balanced = 0;

    for (int i = 0; i < Numbers_Trees; i++)
    {
     tree[i]=NULL;
     tree[i]= treeInsert(tree[i],rand());
        for (int j = 0; j < Numbers_nodes; j++)
        {
            treeInsert(tree[i],rand());
        }
        trees_in_balanced+= isBalanced(tree[i]);
        kill_tree(tree[i]);
    }

    printTree(tree);

    //вроде как получилось сделать по заданию деревья,и забить их случайными числами,
    //также ввел счетчик для подсчета сбалансированных деревьев,но как вывести % этих деревьев не понял.


    if (isBalanced(tree))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");

    printf("\n");

    TreeNode * search_tree = NULL;

    search_tree=treeInsert(search_tree,8);
    search_tree=treeInsert(search_tree,12);
    search_tree=treeInsert(search_tree,17);
    search_tree=treeInsert(search_tree,21);
    search_tree=treeInsert(search_tree,25);
    search_tree=treeInsert(search_tree,30);
    search_tree=treeInsert(search_tree,40);
    search_tree=treeInsert(search_tree,80);
    search_tree=treeInsert(search_tree,99);
    search_tree=treeInsert(search_tree,6);

    const int search[6]={8,21,25,80,16,10};
    for (int i = 0; i < 6; i++)
    {
     TreeNode*found_done= find(search_tree,search[i]);
     if (found_done!=NULL)
     {
         printf("\tFound %d!\n",found_done->key);
     }
     else
     {
         printf("\tNot found %d!\n",search[i]);
     }

    }

    return 0;
}

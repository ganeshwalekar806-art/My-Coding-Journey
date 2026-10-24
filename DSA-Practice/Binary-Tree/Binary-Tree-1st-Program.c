#include<stdio.h>
#include<stdlib.h>

struct treenode
{
    struct treenode *lchild;
    int ele;
    struct treenode *rchild;

};

struct treenode *root;

void place_node(struct treenode *p,struct treenode *nnode)
{
    if( p->ele > nnode->ele)
    {
        // place in left child 

        if( p->lchild == NULL)
        {
            p->lchild = nnode;
        }
        else
        {
            place_node(p->lchild,nnode);
        }
    }
    else
    {
        //place in right child

        if(p->rchild == NULL)
        {
            p->rchild = nnode;
        }
        else
        {
            place_node(p->rchild,nnode);
        }
    }    

} 

void create_node(int val)
{
    struct treenode *nn;

    nn = (struct treenode *)malloc(sizeof(struct treenode));
    nn->ele = val;
    nn->lchild = NULL;
    nn->rchild = NULL;

    if( root == NULL)
    {
        root = nn;
    }
    else
    {
        place_node(root,nn);
    }


}



void inorder(struct treenode *p)
{
    if( p != NULL)
    {
        inorder(p->lchild);
        printf("%d\t",p->ele);
        inorder(p->rchild);
    }

}

void preorder(struct treenode *p)
{
    if( p != NULL)
    {
        printf("%d\t",p->ele);
        preorder(p->lchild);
        preorder(p->rchild);
    }

}

void postorder(struct treenode *p)
{
    if( p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d\t",p->ele);
    }

}

void print_left_node(struct treenode *p)
{
    if( p != NULL)
    {
        print_left_node(p->lchild);
        if( p->lchild != NULL && p->rchild == NULL)
        {
            printf("%d\t",p->ele);
        }
        print_left_node(p->rchild);
    }
}

void print_leaf_node(struct treenode *p)
{
    print_leaf_node(p->lchild);
    if(p->lchild == NULL && p->rchild == NULL)
    {
        printf("%d\t",p->ele);
    }
    print_leaf_node(p->rchild);
}

int main()
{
    root = NULL;
    int a[100],sz,i;

    // INPUT IN ARRAY FOR CREATE BINARY TREE

    printf("\nENTER TOTAL NODES OF BUNARY TREE: ");
    scanf("%d",&sz);

    printf("\n=  =  = ENTER ELEMENT OF BINARY TREE =  =  = \n\n");
    for(i = 0;i<sz;i++)
    {
         scanf("%d",&a[i]);
    }

    // CREATE  BINARY TREE AND CREATE NODE 

    for(i=0;i<sz;i++)
    {
        create_node(a[i]);
    }

    printf("\n\n- - - BINARY TREE WAS CREATED - - -\n\n");

    // TRAVERSAL OF BUNARY TREE 
    
    printf("\nINORDER : ");
    inorder(root);

    printf("\n PREORDER : ");
    preorder(root);

    printf("\nPOSTORDER : ");
    postorder(root);

    printf("\nLEFT NODE WAS : ");
    print_left_node(root);

    printf("\nLEAF NODE WAS : ");
    print_leaf_node(root);

    return 0;

}

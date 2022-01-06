//BINARY SEARCH TREE
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
}*root;
typedef struct node *NODE;

void insert(int item){
    NODE temp,cur,prev;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL){
        root=temp;
        return;
    }
    prev=NULL;
    cur=root;
    while(cur!=NULL){
        prev=cur;//to obtain the position of the parent whenever the cur becomes the null and then insert 
        if(item==cur->info){
            printf("ERROR DUPLICATION");
            free(temp);
            return;
        }
        if(item<cur->info)  
            cur=cur->llink;//visiting the left subtree
        else
            cur=cur->rlink;//visiting the right subtree
    }
    if(item<prev->info)//this if else gets executed till the cur will become NuLL
        prev->llink=temp;//insert the item on the left when item is less than prev of info
    else
        prev->rlink=temp;//insert the item on the Right when item is greater than prev of info
}
void inorder(NODE root){
    if(root!=NULL){
        inorder(root->llink);
        printf("%d\t",root->info);
        inorder(root->rlink);
    }
}
void preorder(NODE root){
    if(root!=NULL){
        printf("%d\t",root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(NODE root){
    if(root!=NULL){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t",root->info);
    }
}
int search(NODE root,int key)
{
    NODE temp;
    temp=root;
    if(root==NULL){
        printf("TREE DOESN'T EXISTS");
        return -1;
    }
    while(temp!=NULL){
        if(key==temp->info)
            return 1;
        if(key<temp->info)
            temp=temp->llink;
        else
            temp=temp->rlink;
    }
    return -1;
}
void main(){
    int ch,item,key,res;
    printf("BINARY SEARCH TREE\n");
    printf("1.CREATE\n2.INORDER\n3.PREORDER\n4.POSTORDER\n5.SEARCH\n6.EXIT\n");
    while(1){
        printf("ENTER THE CHOICE: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the item : ");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: inorder(root);break;
            case 3: preorder(root);break;
            case 4: postorder(root);break;
            case 5: printf("Enter the key : ");
                    scanf("%d",&key);
                    res=search(root,key);
                    if(res==1)
                        printf("SUCCESS");
                    else
                        printf("FAILURE");
            case 6: exit(0);
        }
    }
}

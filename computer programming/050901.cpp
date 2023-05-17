//050901
#include<bits/stdc++.h>
using namespace std;
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree treenode;
typedef treenode *btree;

btree insert_node(btree root, int value){
    btree newnode, current, back;
    newnode = (btree)malloc(sizeof(treenode));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
        return newnode;
    else{
        current = root;
        while(current != NULL){
            back = current;
            if(current->data < value)
                current = current->right;
            else
                current = current->left;
        }
        if(back->data < value)
            back->right = newnode;
        else
            back->left = newnode;
    }
    return root;
}

btree create_btree(int *data, int len){
    btree root = NULL;
    for(int i = 0; i < len; i++)
        root = insert_node(root, data[i]);
    return root;
}

btree delete_node(btree root, int value){
    btree current, back = NULL;
    current = root;
    while(current != NULL && current->data != value){//找value
        back = current;
        if(current->data < value)
            current = current->right;
        else
            current = current->left;
    }
    if(current != NULL){//有找到value
        btree ptr = current;
        if(ptr->right == NULL){
            if(ptr->left == NULL){
                if(back == NULL){//root = value, tree only root
                    free(current);
                    btree newnode = NULL;
                    return newnode;
                }
                else{//leave = value
                    if(back->left == current)
                        back->left = NULL;
                    else
                        back->right = NULL;
                    free(current);
                    return root;
                }
            }
            else{
                ptr = ptr->left;
                if(ptr->right == NULL){//current的左邊沒有右邊&current沒右邊
                    if(back == NULL){//root = value
                        free(current);
                        return ptr;
                    }
                    else{
                        if(back->left == current)
                            back->left = ptr;
                        else
                            back->right = ptr;
                        free(current);
                        return root;
                    }
                }
                else{//找current左邊的最右
                    while(ptr->right != NULL){
                        back = ptr;
                        ptr = ptr->right;
                    }
                    current->data = ptr->data;
                    back->right = ptr->left;
                    free(ptr);
                    return root;
                }
            }
        }
        else{
            ptr = ptr->right;
            if(ptr->left == NULL){//current右邊沒左邊
                ptr->left = current->left;
                if(back == NULL){//root = value
                    free(current);
                    return ptr;
                }
                else{
                    if(back->left == current)
                        back->left = ptr;
                    else
                        back->right = ptr;
                    free(current);
                    return root;
                }
            }
            else{//找current右邊的最左
                while(ptr->left != NULL){
                    back = ptr;
                    ptr = ptr->left;
                }
                current->data = ptr->data;
                back->left = ptr->right;
                free(ptr);
                return root;
            }
        } 
    }
    else{
        cout<<"no element\n";
        return root;
    }
}

void print_btree(btree root){
    btree ptr;
    ptr = root;
    cout<<"列印左子樹:\n";
    while(ptr != NULL){
        printf("[%2d]\n", ptr->data);
        ptr = ptr->left;
    }
    ptr = root;
    cout<<"列印右子樹:\n";
    while(ptr != NULL){
        printf("[%2d]\n", ptr->data);
        ptr = ptr->right;
    }
}

int main(){
    btree root = NULL;
    int data[7] = {25, 20, 50, 10, 22, 40, 60};
    root = create_btree(data, 7);
    print_btree(root);
    root = delete_node(root, 25);
    print_btree(root);
    return 0;
}
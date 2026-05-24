#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left,*right;
    
};
class bst
{
public:
    node* root;

    bst()
    {
        root = NULL;
    }

    void inserting()
    {
        node* p;
        int val, c = 0;

        while (c < 5)
        {
            if (root==NULL)
            {
                root = new node;
                cout << "enter value of root node\n";
                cin >> root->data;
                root->right = NULL;
                root->left = NULL;
                c++;
            }
            else
            {
                p=root;
                cout<<"enter value of node\n";
                cin >>val;

                while (true)
                {
                    if (val < p->data)
                    { // inserting value at left of tre root
                        if (p->left == NULL)
                        {
                            p->left = new node;
                            p = p->left;
                            p->data = val;
                            p->left = NULL;
                            p->right = NULL;
                            cout << "value entered in left\n";
                            break;
                        }
                        else
                        {
                            p = p->left;
                        }
                    }
                    else if (val >= p->data) // inserting value at right of tree root
                    {
                        if (p->right == NULL)
                        {
                            p->right = new node;
                            p = p->right;
                            p->data = val;
                            p->left = NULL;
                            p->right = NULL;
                            cout << "value entered in right\n";
                            break;
                        }
                        else
                        {
                            p = p->right;
                        }
                    }
                }
                c++;
            }
        }
    }
    void inorder(node* p){
        if (p != NULL){
            inorder(p->left);
            cout << p->data << "\n";
            inorder(p->right);
        }
    }
    node* searchmin(node* curr){
        while (curr != NULL && curr->left != NULL)
        {
            curr = curr->left;
        }

        return curr;
    }
    node* searchmax(node* curr){
        while (curr != NULL && curr->right != NULL)
        {
            curr = curr->right;
        }
        return curr;
    }
};
int main(){
    bst T;
    T.inserting();
    cout << "\ninorderly traversal:\n";
    T.inorder(T.root);
    node* min=T.searchmin(T.root);
    node* max =T.searchmax(T.root);
    if (min!=NULL)
        cout<<"sab to minimum valu hegi: "<< min->data<< "\n";
    if (max != NULL)
        cout << "sab to waddi valu hegi:" << max->data << "\n";
    
    return 0;

}
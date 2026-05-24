#include<iostream>
using namespace std;
class node{
public:
    node*left,*right;
    int data;
};
class bst{
public:
    node*root;
    bst()
    {
        root =NULL;
    }
    void insert(){ // inserting avlues in data of nodes
        node*p;
        int value,c=0;
        while (c<3){
            if (root== NULL){
                root = new node;
                cout << "enter value of root node\n";
                cin >> root->data; //data ki insertion 
                root->right = NULL;
                root->left = NULL;
                c++;
            }
            else{
                p=root;
                cout <<"enter value of node\n";
                cin >> value; // here are values inseritons
                while (true){
                    if (value <p->data){
                        if (p->left == NULL){
                            p->left = new node;
                            p = p->left;
                            p->data = value;
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
                    else if (value >=p->data){
                        if (p->right == NULL){
                            p->right = new node;
                            p = p->right;
                            p->data = value;
                            p->left = NULL;
                            p->right = NULL;
                            cout << "value entered in right\n";
                            break;
                        }
                        else
                        {
                            p =p->right;
                        }
                    }
                }   
                c++;
            }
        }
    }
    void inorder(node* p)
    {
        if (p!=NULL)
        {
            inorder(p->left);
            cout << p->data<<endl; // wese he puranay tasks ki terh inorder traversing kerwayi ha yaha meine

            inorder(p->right);
        }
    }
    node*search(node*curr,int val)
    {
        if (curr ==NULL)
        {
            return NULL;
        }

        if (curr->data ==val)
        {
            return curr;
        }
        else if (val< curr->data)
        {
            return search(curr->left,val);
        }
        else
        {
            return search(curr->right,val);
        }
    }

    node* getparent(node*curr,node* prev, int val) //recursion funciton of getting parent node of children nodes
    {
        if (curr == NULL)
            return NULL;
        if (curr->data== val)
            return prev;
        else if (val<curr->data)
        {
            return getparent(curr->left, curr, val);
        }
        else
        {
            return getparent(curr->right,curr, val);
        }
    }
    node* searchmin(node*curr) // finding the mininmum
    {
        while (curr !=NULL &&curr->left!= NULL)
            curr = curr->left;
        return curr;
    }
    void deletingnode(int val){
        node* temp = search(root, val);
        if (temp==NULL)
            return;
        node* parent= getparent(root,NULL,val);
        if (temp->left ==NULL && temp->right ==NULL)
        { // leaf node
            if (parent== NULL)
            {
                root =NULL;
            }
            else if (parent->left ==temp)
            {
                parent->left =NULL;
            }
            else
            {
                parent->right= NULL;
            }

            delete temp;
            cout <<"leaf node deleted successfully\n";
        }
        else if(temp->left==NULL&&temp->right!=NULL){
            // agar right wala bacha ha node ka
            if (parent ==NULL)
            {
                root= temp->right;
            }
            else if (parent->left=temp)
            {
                parent->left=temp->right;
            }
            else
            {
                parent->right=temp->right;
            }

            delete temp;
            cout << "node with only right child deleted successfully\n";
        }
        else if (temp->left != NULL && temp->right == NULL)
        {// agar node k paas ek he bacha ha
            if (parent == NULL)
            {
                root=temp->left;
            }
            else if (parent->left==temp)
            {
                parent->left=temp->left;
            }
            else
            {
                parent->right=temp->left;
            }
            delete temp;
        }
        else// agar node k 2 bachay ha
        {
            node* minnode=searchmin(temp->right);
            int minvalue=minnode->data;
            deletingnode(minvalue);
            temp->data =minvalue;
        }
    }
};
int main()
{
    bst T;
    T.insert();
    cout << "\ninorder traversal:\n";
    T.inorder(T.root);
    int deletingval;
    cout << "\nenter value you want to delete: ";
    cin >> deletingval;
    T.deletingnode(deletingval);
    cout << "\nbst after deletion in inorder traversal\n";
    T.inorder(T.root);
    return 0;

}
#include <iostream>
using namespace std;
class node {
public:
    int data;
    node*left,*right;
    node(int val) {
        data = val;
        left=right = NULL;
    }
};

class bst {
public:
    node* root;
    bst()
    {
        root = NULL;
    }

    node*insert(node*root,int val)
        // values insert ki hain yaha par
    {
        if (root==NULL)
        {
            return new node(val);
        }
        
        if (val<root->data)
        {
            root->left=insert(root->left,val); // less than root ka data, value left pe ghusaadi
        } else
        if (val>root->data)
        {
            root->right = insert(root->right, val);//greater than root ki data,value right pe ghusaadi simple, ohoi ascending oder ch kitta
        }
        return root;
    }
    // recursion use kia insert k function mein
    void inorder(node* root) {
        if (root==NULL)
            return;

        inorder(root->left);
        cout <<root->data <<" "; // inorder traversing ki gyi yaha par bilkul pichla task ki terh
        inorder(root->right);
    }

    bool searching(node* root, int val){ // yaha par searching kerrege, bool ka fucniton create kia
        
        if (root== NULL)
            return false;

        if (root->data==val)
        {
            return true;
        }
        if (root->data>val)
        {
            return searching(root->left, val);
        }
        else if (val>root->data)
        {
            return searching(root->right, val);
        }
    }

};
int main(){
    bst T;
    int n,val, searchval;
    cout<<"enter how many nodes:\t";
    cin >> n; // kinnay nodes enter kerne..

    for (int i=1;i<=n; i++)
    {
        cout<<"\nvalue enter kerien: ";
        cin >>val;
        T.root=T.insert(T.root,val);

    }

    cout<<"\ntraversing inorderly:\n";//ascending order mein hoga qk task 2 ka he hissa ha yeh wala task
    T.inorder(T.root);// function call kita
    cout <<endl<<"enter value to search:";
    cin>>searchval;
    if (T.searching(T.root, searchval))
    {
        cout<<"\nvalue found :D\n";
    }
    else
    {
        cout<<"koi value ni hegi ):\n";
    }
    
    return 0;
}
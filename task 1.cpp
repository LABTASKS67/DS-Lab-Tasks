#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* ltree;
    node* rtree;

    node(int value)
    {
        data=value;
        ltree=NULL;
        rtree=NULL;
    }
};
class bst
{
public:
    node* root;
    bst()
    {
        root=NULL;
    }
    node *insert(node* curr,int value)
    {
        if(curr==NULL)
            return new node(value);
        if(value<curr->data)
            curr->ltree=insert(curr->ltree,value);
        else if(value>curr->data)
            curr->rtree=insert(curr->rtree,value);
        else
            cout<<"duplicate value not allowed\n";
        return curr;
    }
    void inorder(node* curr)
    {
        if(curr!=NULL)
        {
            inorder(curr->ltree);
            cout<<curr->data<<" ";
            inorder(curr->rtree);
        }
    }
    void preorder(node* curr)
    {
        if(curr!=NULL)
        {
            cout<<curr->data<<" ";
            preorder(curr->ltree);
            preorder(curr->rtree);
        }
    }
    void postorder(node* curr)
    {
        if(curr!=NULL)
        {
            postorder(curr->ltree);
            postorder(curr->rtree);
            cout<<curr->data<<" ";
        }
    }
    bool search(node* curr,int key)
    {
        if(curr==NULL)
            return false;

        if(curr->data==key)
            return true;

        if(key<curr->data)
            return search(curr->ltree,key);
        else
            return search(curr->rtree,key);
    }
};
int main()
{
    bst obj;
    int n, value, key;

    cout << "how many numbers do you want to insert? ";
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cout<<"enter value: ";
        cin>>value;

        obj.root=obj.insert(obj.root,value);
    }

    cout<<"\ninorder traversal:"<<endl;
    obj.inorder(obj.root);

    cout<<"\n\npreorder traversal:"<<endl;
    obj.preorder(obj.root);

    cout<<"\n\npostorder traversal:"<<endl;
    obj.postorder(obj.root);
    cout<<"\n\nenter key to search: ";
    cin>>key;
    if(obj.search(obj.root,key))
    {
        cout<<"key found in bst";
    }
    else
    {
        cout<<"key not found in bst";
    }
    return 0;
}
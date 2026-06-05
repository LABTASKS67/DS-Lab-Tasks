#include<iostream>
#include<string>
using namespace std;
class node
{
public:
    int data;
    string title;
    node* left;
    node* right;
};
class listnode
{
public:
    int isbn;
    string title;
    listnode* next;
};
class bst
{
public:
    node* root;

    bst()
    {
        root = NULL;
    }
    void addnode(int n)
    {
        node* p;
        int val;
        string t;
        while (n > 0)
        {
            if (root == NULL)
            {
                root = new node;
                cout << "Enter isbn data: ";
                cin >> root->data;
                cout << "Enter title: ";
                cin >> root->title;

                root->left = NULL;
                root->right = NULL;
                n--;
            }
            else
            {
                p = root;

                cout << "Enter isbn data: ";
                cin >> val;
                cout << "Enter title:";
                cin >> t;

                while (true)
                {
                    if (val < p->data)
                    {
                        if (p->left == NULL)
                        {
                            p->left = new node;
                            p = p->left;
                            p->data = val;
                            p->title = t;
                            p->left = NULL;
                            p->right = NULL;
                            break;
                        }
                        else
                        {
                            p = p->left;
                        }
                    }
                    else
                    {
                        if (p->right == NULL)
                        {
                            p->right = new node;
                            p = p->right;
                            p->data = val;
                            p->title = t;
                            p->left = NULL;
                            p->right = NULL;
                            break;
                        }
                        else
                        {
                            p = p->right;
                        }
                    }
                }
                n--;
            }
        }
    }
    void inorder(node* root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " - " << root->title << endl;
            inorder(root->right);
        }
    }
    void convertToList(node* root, listnode*& head, listnode*& tail)
    {
        if (root == NULL)
        {
            return;
        }
        convertToList(root->left, head, tail);
        listnode* newnode = new listnode;
        newnode->isbn = root->data;
        newnode->title = root->title;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        convertToList(root->right, head, tail);
    }

    void printList(listnode* head)
    {
        listnode* temp = head;

        while (temp != NULL)
        {
            cout << temp->isbn << " " << temp->title << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    bst b;

    int n;
    cout << "Enter number of books: ";
    cin >> n;
    b.addnode(n);
    cout << "\nbst inorder sorted:\n";
    b.inorder(b.root);
    listnode* head = NULL;
    listnode* tail = NULL;
    b.convertToList(b.root, head, tail);
    cout << "\nsorted linked list catalog:\n";
    b.printList(head);
}
#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* ltree;
	node* rtree;
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
		while (n>0)
		{
			if (root==NULL)
			{
				root = new node;
				cout << "Enter value of root: ";
				cin >> root->data;
				root->ltree = NULL;
				root->rtree = NULL;
				cout << "Root "<<root->data<<" added!" << endl;
				n--;
			}
			else
			{
				p=root;
				cout<<"Enter next node: ";
				cin>>val;

				while (true)
				{
					if (val<p->data)
					{
						if (p->ltree == NULL)
						{
							p->ltree = new node;
							p = p->ltree;
							p->data = val;
							p->ltree = NULL;
							p->rtree = NULL;
							cout << "Value entered at left tree" << endl;
							break;
						}
						else
							p=p->ltree;
					}
					else if (val >= p->data)
					{
						if (p->rtree == NULL)
						{
							p->rtree = new node;
							p = p->rtree;
							p->data = val;
							p->ltree = NULL;
							p->rtree = NULL;
							cout << "Value entered at right tree" << endl;
							break;
						}
						else
						{
							p = p->rtree;
						}
					}
					else
					{
						cout<<"error\n";
					}
				}
				n--;
			}
		}
	}
	void inorder(node * root)
	{
		if (root != NULL)
		{
			inorder(root->ltree);
			cout << root->data << " ";
			inorder(root->rtree);
		}
	}
	void preorder(node * root)
	{
		if (root != NULL)
		{
			cout << root->data << " ";
			preorder(root->ltree);
			preorder(root->rtree);
		}
	}
	void postorder(node * root)
	{
		if (root != NULL)
		{
			postorder(root->ltree);
			postorder(root->rtree);
			cout << root->data << " ";
		}
	}
	bool identical(node* root1, node* root2)
	{
		if (root1 == NULL && root2 == NULL)
		{
			return true;
		}

		if (root1 == NULL || root2 == NULL)
		{
			return false;
		}

		if (root1->data == root2->data)
		{
			return identical(root1->ltree, root2->ltree) &&
				identical(root1->rtree, root2->rtree);
		}
		return false;
	}
};
int main()
{
	bst b1, b2;
	int n;
	cout << "Enter number of nodes for tree 1: ";
	cin >> n;
	b1.addnode(n);

	cout << "\nEnter number of nodes for tree 2: ";
	cin >> n;
	b2.addnode(n);

	cout << "\ninorder traversal of tree 1:\n";
	b1.inorder(b1.root);

	cout << "\ninorder traversal of tree 2:\n";
	b2.inorder(b2.root);

	if (b1.identical(b1.root, b2.root))
		cout << "\nidentical";
	else
		cout << "\nnot identical";
}

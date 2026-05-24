#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* left,*right;
	node(int val){
		data = val;
		left = NULL;
		right= NULL;}
};
class bst {public: // bst binary search tree
	node* root;
	bst()
	{
		root = NULL;
	}
	node* insertasc(node*root, int val) //function of inserting nodes in ascending order
	{
		if (root==NULL)
			return new node(val);	// if root is null, this returns new node containing the valeu
		
		if (val<root->data)	// left node of root if value is less than root's value
		{
			root->left=insertasc(root->left,val);// recursion of insertascending function to insert value at left node of root
		}
		else if (val>root->data)	// assigning valueto right node of root becuz of greater value than root
		{
			root->right=insertasc(root->right, val);
		}

		return  root;}
	void inorder(node*root){ // funciton of inorder traversal of binarytree
		if (root==NULL)
			return;

		inorder(root->left);// this recursion for the left nodes of tree
		cout <<root->data<<" "; // after left nodes, displaying the data of nodes inorderly
		inorder(root->right);// recurison for right nodes of tree, 
			//then displaying the right noeds of tree after all left nodes insreted in ascending order
		}
};
int main(){
	bst T;
	int n, userval;
	cout<<"how many nodes u wanna enter: ";
	cin>>n;
	if (n< 0)
	{
		cout << "\nwrong input value hegi saaaaar\nmain function return kerta\n";
		cout <<"aeythay v program mukgya" <<endl;
		return 0;
	}
	if (n==0)
	{
		cout<< "\ndata ha he nai :(\n";
		cout <<"aho aeythay v program mukgya"<< endl; return 0;
	}
	for (int i=1; i <=n;i++)
	{
		cout<< "\nenter value in nodes: ";
		cin>> userval;
		T.root =T.insertasc(T.root, userval); // this funciton calling will insert all the values in ascending order
	}
	cout <<endl<<"nodes data in ascending order inorderly:\n";
	T.inorder(T.root);
	cout<< "\n\nprogram mukgya\n" <<endl;
	return 0;
}
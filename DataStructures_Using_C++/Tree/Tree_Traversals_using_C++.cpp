#include<iostream>
#include<queue>
using namespace std;


	//structure of any node 
typedef struct node {
	int data;
	struct node *left ,*right;
	//constructor for assigning 
	//values in allocated memory 
	node(int data)
	{
		this->data=data;
		left=right=NULL;

	}
	
}NODE;


void printpreorder(NODE *root)
{
	if (root==NULL)
		return ;
	cout<<root->data<<"  ";
	printpreorder(root->left);
	printpreorder(root->right);
}

void printinorder(NODE *root)
{
	if (root==NULL)
		return ;
	printinorder(root->left);
	cout<<root->data<<"  ";
	printinorder(root->right);
}

void printpostorder(NODE *root)
{
	if (root==NULL)
		return ;
	printpostorder(root->left);
	printpostorder(root->right);
	cout<<root->data<<"  ";
	
}

void printlevelorder(NODE *root)
{
	queue<NODE*>q;
	if(!root)
	{
		return;
	}
	for(q.push(root);!q.empty();q.pop())
	{
		NODE* const temp_node=q.front();
		cout<<temp_node->data<<"\n";

		if(temp_node->left)
		{
			q.push(temp_node->left);
		}
		if(temp_node->right)
		{
			q.push(temp_node->right);
		}
	}
}
int main()
{     
	//INSERTION
	/*       100
	     200       300
    400
         500

     */
	NODE *root =new node(100);
	root->left =new node(200);
	root->right= new node(300);
	root->left->left=new node(400);
	root->left->left->right= new node(500);


	//TRAVERSALS

	cout<<"\nPREORDER TRAVERSAL OF BINARY TREE \n";
	printpreorder(root);

	cout<<"\nINORDER TRAVERSAL OF BINARY TREE \n";
	printinorder(root);

	cout<<"\nPOSTORDER TRAVERSAL OF BINARY TREE \n";
	printpostorder(root);

	cout<<"\nLEVELORDER TRAVERSAL OF BINARY TREE \n";
	printlevelorder(root);
	return 0;


} 
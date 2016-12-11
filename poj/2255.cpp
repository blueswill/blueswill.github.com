#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct node_
{
	char d;
	node_ *left,*right;
};

string pre_order;
string in_order;

void build_tree(int in_bg,int in_ed,int &pre_bg,int pre_ed,node_ *&root)
{
	if(in_bg>in_ed||pre_bg>pre_ed)
	{
		--pre_bg;
		root=NULL;
		return;
	}
	root=new node_;
	root->d=pre_order[pre_bg];
	int i;
	for(i=in_bg;i<=in_ed;++i)
		if(in_order[i]==root->d)
			break;
	build_tree(in_bg,i-1,++pre_bg,pre_ed,root->left);
	build_tree(i+1,in_ed,++pre_bg,pre_ed,root->right);
	return;
}

const string &print(node_ *n)
{
	static string res;
	if(n==NULL)
		res="";
	if(n!=NULL)
	{
		if(n->left!=NULL)
			print(n->left);
		if(n->right!=NULL)
			print(n->right);
		res.push_back(n->d);
	}
	return res;
}

void clear(node_ *n)
{
	if(n!=NULL)
	{
		if(n->left!=NULL)
			clear(n->left);
		if(n->right!=NULL)
			clear(n->right);
		delete n;
	}
}

int main(void)
{
	while(cin>>pre_order>>in_order)
	{
		node_ *root=NULL;
		int i,j,k,m;
		i=0,j=in_order.size()-1,k=0,m=pre_order.size()-1;
		build_tree(i,j,k,m,root);
		cout<<print(root)<<endl;
		print(NULL);
		clear(root);
	}
	return 0;
}

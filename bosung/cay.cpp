#include <iostream>
#define COUNT  10
using namespace std;

struct node 
{
    int data;
    node* left;
    node* right;
    int height;
};

node* CreateNode(int x){
    node* p = new node();
   p->data = x;
   p->left = p->right = nullptr;
   p->height = 1;
    return p;
}

int getHeight(node* root){
    if(root == nullptr)return 0;
    return root->height;
}

node* RightRotate(node* &root){
    node* x = root->left;
    root->left = x->right;
    x->right = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

node* LeftRotate(node* &root){
    node* y = root->right;
    root->right = y->left;
    y->left  = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}



node* InsertNode(node* root, int x){
    if( root != nullptr){
        if(root->data == x)return root;
        else if(root->data < x) root->right = InsertNode(root->right, x);
        else root->left = InsertNode(root->left, x);
    }
    else root = CreateNode(x);

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    //kiem tra chieu cao
    int height = getHeight(root->left) - getHeight(root->right);

    //kiem tra truong hop
    if(height > 1 && root->left->data < x){
        root->left = LeftRotate(root->left);
        return root = RightRotate(root);
    }
    else if(height > 1 && root->left->data > x){
        return root = RightRotate(root);
    }
    else if(height < -1 && root->right->data < x){
        return root = LeftRotate(root);
    }
    else if(height < -1 && root->right->data > x){
        root->right = RightRotate(root->right);
        return root = LeftRotate(root);
    }
    return root;
}





// In - Print 2D ra console
void print2DUtil(node* root, int space){
	if (root == NULL)
		return;
	space += COUNT;

	print2DUtil(root->right, space);
	cout << endl;

	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data << " (" << root->height << ") " << "\n";

	print2DUtil(root->left, space);
}

void print2D(node* root){
	print2DUtil(root, 0);
}

void IN(node* root){
    if(root != nullptr){
        IN(root->left);
        IN(root->right);
        cout << root->data << " ";
    }
}

int main() {
	node* tree = NULL;
	tree = InsertNode(tree, -2);
	tree = InsertNode(tree, 3);
	tree = InsertNode(tree, 1);
	tree = InsertNode(tree, 0);
	tree = InsertNode(tree, -1);
	tree = InsertNode(tree, 5);
    tree = InsertNode(tree, 4);
	tree = InsertNode(tree, 6);
	tree = InsertNode(tree, 2);
	tree = InsertNode(tree, -3);
	print2D(tree);
    IN(tree);
}
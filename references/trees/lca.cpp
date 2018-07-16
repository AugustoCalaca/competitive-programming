#include <iostream>
#include <vector>

#define pb push_back
using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
};

Node* push(int key) {
  Node* temp = new Node;
  temp->key = key;
  temp->left = temp->right = NULL;

  return temp;
}

Node* lca(Node* root, int n1, int n2) {
  if(root == NULL) return NULL;
  if(root->key == n1 || root->key == n2) return root;

  Node* lef = lca(root->left, n1, n2);
  Node* rig = lca(root->right, n1, n2);

  if(lef != NULL && rig != NULL) return root;
  if(lef == NULL && rig == NULL) return NULL;

  return lef == NULL ? rig : lef;
}

int height(Node* root, int key, int d = 0) {
  if(root == NULL) return -1;
  if(root->key == key) return d;

  int lef = height(root->left, key, d + 1);
  if(lef == -1)
    return height(root->right, key, d + 1);
  return lef;
}

int distance(Node* root, int n1, int n2) {
  Node* ancestor = lca(root, n1, n2);

  int d1 = height(ancestor, n1);
  int d2 = height(ancestor, n2);

  return d1 + d2;
}

int main() {
  Node* root = push(1);
  root->left = push(2);
  root->right = push(3);
  root->left->left = push(4);
  root->left->right = push(5);
  root->right->left = push(6);
  root->right->right = push(7);
  root->right->left->right = push(8);

  cout << distance(root, 5, 8) << "\n";
  cout << lca(root, 5, 8)->key << "\n";


  return 0;
}
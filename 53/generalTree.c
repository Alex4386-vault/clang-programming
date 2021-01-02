#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int data;

  struct TreeChildNode* childNodes;
  int childNodeCount;
} TreeNode;

typedef struct TreeChildNode {
  struct TreeNode *node;
  struct TreeChildNode *nextNode;
} TreeChildNode;

int createNode();
TreeChildNode *createChildNode();
int preorder(TreeNode *root);
int deleteNodeViaPostOrder(TreeNode *root);

int main() {
  TreeNode *root1;
  TreeNode *root2;

  // tree 1
  printf("1. ");

  createNode(&root1, 100);
  createChildNode(&root1, 200);
  TreeNode *root1_75 = createChildNode(&root1, 75)->node;
  createChildNode(&root1, 300);
  createChildNode(&root1_75, 25);
  createChildNode(&root1_75, 50);
  TreeNode *root1_35 = createChildNode(&root1_75, 30)->node;
  createChildNode(&root1_75, 150);
  createChildNode(&root1_35, 120);
  createChildNode(&root1_35, 55);

  preorder(root1);

  // clean tree 1
  //deleteNodeViaPostOrder(root1);

  printf("\n");

  // tree 2
  printf("2. ");

  createNode(&root2, 100);
  createChildNode(&root2, 200);
  TreeNode *root2_75 = createChildNode(&root2, 75)->node;
  createChildNode(&root2, 300);

  TreeNode *root2_95 = createChildNode(&root2, 95)->node;
  createChildNode(&root2_95, 150);

  createChildNode(&root2_75, 25);
  createChildNode(&root2_75, 50);
  TreeNode *root2_30 = createChildNode(&root2_75, 30)->node;

  createChildNode(&root2_30, 120);

  preorder(root2);
  printf("\n");

  // clean tree 2
  //deleteNodeViaPostOrder(root2);
  root2 = NULL;
}

int createNode(TreeNode** root, int data) {
  TreeNode *node;

  node = (TreeNode *)malloc(sizeof(TreeNode));
  
  if (node == NULL) {
    return 0;
  }

  node->data = data;
  node->childNodeCount = 0;

  *root = node;

  return 1;
}

TreeChildNode *createChildNode(TreeNode** nodePtr, int data) {
  TreeNode *node = *nodePtr;
  if (node->childNodeCount == 0) {
    node->childNodes = (TreeChildNode *)malloc(sizeof(TreeChildNode));

    if (node->childNodes == NULL) {
      return 0;
    }

    if (createNode(&(node->childNodes->node), data)) {
      node->childNodeCount++;
      return node->childNodes;
    } else {
      return 0;
    }
  }

  TreeChildNode *head = node->childNodes;
  
  while (head->nextNode != NULL) {
    head = head->nextNode;
  }

  head->nextNode = (TreeChildNode *)malloc(sizeof(TreeChildNode));
  head->nextNode->nextNode = NULL;

  if (createNode(&(head->nextNode->node), data)) {
    node->childNodeCount++;
    return head->nextNode;
  } else {
    return NULL;
  }
}

int preorder(TreeNode* root) {
  if (root) {
    printf("%d ", root->data);

    if (root->childNodeCount > 0) {
      TreeChildNode *head = root->childNodes;
      do {
        preorder(head->node);  
        head = head->nextNode;
      } while(head != NULL);
    }
  }
  return 0;
}

int deleteNodeViaPostOrder(TreeNode *root) {
  if (root) {
    if (root->childNodeCount > 0) {
      TreeChildNode *head = root->childNodes;
      do {
        deleteNodeViaPostOrder(head->node);
        root->childNodeCount--;
        TreeChildNode* next = head->nextNode;
        head->nextNode = NULL;
        free(head);
        head = next;
      } while(head != NULL);
    }

    root->data = 0;
    root->childNodes = NULL;
    root->childNodeCount = 0;
    free(root);
  }

  return 0;
}

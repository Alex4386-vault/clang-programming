#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomSeedReady = 0;
int randomGenerator(int min, int max);

typedef struct TreeNode {
  int key;
  struct TreeNode *lPtr, *rPtr;
  int height;
} TreeNode;

typedef enum RotationDirection {
  left = 0,
  rr = 0,
  right = 1,
  ll = 1,
  rl = 2,
  lr = 3
} RotationDirection;

TreeNode *insert(TreeNode *node, int key);
TreeNode *delete(TreeNode *node, int key);
int height(TreeNode *node);
int BF(TreeNode *node);
TreeNode *rotate(RotationDirection direction, TreeNode *node);
int treeSize(TreeNode *node);
TreeNode *search(TreeNode *node, int key);
int inorder(TreeNode *node);
int getMin(TreeNode *node);
int getMax(TreeNode *node);
int inorderMinMax(TreeNode *node, int min, int max);

int main() {
  TreeNode *root = NULL;

  int randomInt[200] = {0,};

  for (int i = 2; i < 200; i++) {
    randomInt[i] = randomGenerator(1, 100);
  }

  randomInt[0] = 15;
  randomInt[1] = 50;

  for (int i = 0; i < 100; i++) {
    root = insert(root, randomInt[i]);
  }

  printf("Inserted tree items: %d\n", treeSize(root));


  
  printf("Max Value: %d\n", getMax(root));

  printf("All keys < 15: ");
  inorderMinMax(root, getMin(root) - 1, 15);
  printf("\n");

  printf("All keys > 50: ");
  inorderMinMax(root, 50, getMax(root) + 1);
  printf("\n");

  printf("15 < All keys < 50: ");
  inorderMinMax(root, 15, 50);
  printf("\n");

  return 0;

}

/* =========== */

int randomGenerator(int min, int max) {
  if (!randomSeedReady) {
    srand(time(NULL));
    randomSeedReady = 1;
  }

  return ((int) rand() % (max - min + 1) + min);
}

TreeNode *insert(TreeNode *node, int key) {
  if (node == NULL) {
    node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL) {
      printf("[Error] Unable to allocate memory properly. Terminating...\n");
      exit(1);
    }
    node->key = key;
    node->lPtr = NULL;
    node->rPtr = NULL;
  } else {
    if (key > node->key) {
      node->rPtr= insert(node->rPtr, key);
      if (BF(node) <= -2) {
        node = rotate(
          (key > (node->rPtr->key)) ? rr : rl,
          node
        );
      }
    } else if (key < node->key) {
      node->lPtr= insert(node->lPtr, key);
      if (BF(node) >= 2) {
        node = rotate(
          (key < (node->lPtr->key)) ? ll : lr,
          node
        );
      }
    } else {
      // key == node->key. ignore input.
      return node;
    }
  }

  node->height = height(node);

  return node;
}


TreeNode *delete(TreeNode *node, int key) {
  if (node == NULL) {
    return NULL;
  } else {
    if (key > node->key) {
      node->rPtr= delete(node->rPtr, key);
      if (BF(node) >= 2) {
        node = rotate(
          BF(node->lPtr) >= 0 ? ll : lr,
          node
        );
      }
    } else if (key < node->key) {
      node->lPtr= delete(node->lPtr, key);
      if (BF(node) <= -2) {
        node = rotate(
          BF(node->rPtr) <= 0 ? rr : rl,
          node
        );
      }
    } else {
      if (node->rPtr != NULL) {
        //get right->left most one.
        TreeNode *p = node->rPtr;

        while (p->lPtr != NULL) {
          p = p->lPtr;
        }

        node->key = p->key;
        node->rPtr = delete(node->rPtr, p->key);

        if (BF(node) >= 2) {
          node = rotate(
            BF(node->lPtr) >= 0 ? ll : lr,
            node
          );
        }

      } else {
        return node->lPtr;
      }
    }
  }

  node->height = height(node);
  return node;
}

int height(TreeNode *node) {
  int leftHeight = ((node->lPtr == NULL) ? 0 : 1+node->lPtr->height);
  int rightHeight = ((node->rPtr == NULL) ? 0 : 1+node->rPtr->height);
  return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

int BF(TreeNode *node) {
  int leftHeight = ((node->lPtr == NULL) ? 0 : 1+height(node->lPtr));
  int rightHeight = ((node->rPtr == NULL) ? 0 : 1+height(node->rPtr));
  return (leftHeight - rightHeight);
}

TreeNode *rotate(RotationDirection direction, TreeNode *node) {
  TreeNode *tmp;

  if (direction == left) {
    tmp = node->rPtr;
    node->rPtr = tmp->lPtr;
    tmp->lPtr = node;
    node->height = height(node);
    tmp->height = height(tmp);
  } else if (direction == right) {
    tmp = node->lPtr;
    node->lPtr = tmp->rPtr;
    tmp->rPtr= node;
    node->height = height(node);
    tmp->height = height(tmp);
  } else if (direction == lr) {
    tmp = node;
    tmp->lPtr = rotate(left, tmp->lPtr);
    tmp = rotate(right, tmp);
  } else if (direction == rl) {
    tmp = node;
    tmp->rPtr = rotate(right, tmp->rPtr);
    tmp = rotate(left, tmp);
  }

  return tmp;
}

int treeSize(TreeNode *node) {
  if (node == NULL) return 0;

  int size = 0;
  if (node->lPtr != NULL) size += treeSize(node->lPtr);
  if (node->rPtr != NULL) size += treeSize(node->rPtr);

  size += 1;

  return size;
}

int inorder(TreeNode *node) {
  if (node == NULL) return 0;

  if (node->lPtr != NULL) inorder(node->lPtr);
  printf("%d ", node->key);
  if (node->rPtr != NULL) inorder(node->rPtr);

  return 0;
}

int inorderMinMax(TreeNode *node, int min, int max) {
  if (node == NULL) return 0;

  if (node->lPtr != NULL) {
    if (min < getMax(node->lPtr))
      inorderMinMax(node->lPtr, min, max);
  }
  if (min < node->key && node->key < max) printf("%d ", node->key);
  if (node->rPtr != NULL) {
    if (max > getMin(node->rPtr))
      inorderMinMax(node->rPtr, min, max);
  }

  return 0;
}

int getMin(TreeNode *node) {
  if (node->lPtr == NULL) return node->key;
  else return getMin(node->lPtr);
}

int getMax(TreeNode *node) {
  if (node->rPtr == NULL) return node->key;
  else return getMax(node->rPtr);
}

TreeNode *search(TreeNode *node, int key) {
  //printf("search %d, %d\n", node->key, key);
  if (node == NULL) return NULL;

  if (node->key == key) {
    return node;
  } else {
    if (node->lPtr != NULL) {
      if (node->lPtr->key < key) {
        return node->lPtr;
      } else {
        return search(node->lPtr, key);
      }
    } else if (node->rPtr != NULL) {
      if (node->rPtr->key > key) {
        return node->rPtr;
      } else {
        return search(node->rPtr, key);
      }
    }

    return node;
  }
}
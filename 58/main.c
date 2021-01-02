#include <stdio.h>
#include <stdlib.h>

#define MAX_DIMENSION 3

typedef struct KDTreeNode {
  int x[MAX_DIMENSION];

  struct KDTreeNode *left;
  struct KDTreeNode *right;
} TreeNode;

typedef struct LinkedListKDTreeNode {
  struct KDTreeNode *node;
  struct LinkedListKDTreeNode *next;
} LinkedTreeNode;

void swap(TreeNode *node1, TreeNode *node2);
TreeNode *build_tree(TreeNode t[], int len, int i, int dim);
TreeNode *find_median(TreeNode *start, TreeNode *end, int currentDimension);
void show_treenodes(LinkedTreeNode *nodes, int maxDimensions);
void nearest_neighbor_search(TreeNode *root, int *target, int currentDimension, int maxDimension, int *bestDist, TreeNode** returnNode);
LinkedTreeNode *range_search(TreeNode *root, int min[], int max[], int currentDimension, int maxDimension);
TreeNode *point_search(TreeNode *root, int x[], int currentDimension, int maxDimension);

int main() {
  TreeNode nodes[] = {
    {{2,3}, NULL, NULL},
    {{5,4}, NULL, NULL},
    {{3,4}, NULL, NULL},
    {{9,6}, NULL, NULL},
    {{4,7}, NULL, NULL},
    {{8,1}, NULL, NULL},
    {{7,2}, NULL, NULL}
  };
  TreeNode* root = build_tree(nodes, 7, 0, 2);

  int searchQuery[] = {5, 4};
  TreeNode* search = point_search(root, searchQuery, 0, 2);
  if (search != NULL) {
    printf("%d, %d\n", search->x[0], search->x[1]);
  } else {
    printf("Non-existent node\n");
  }

  searchQuery[0] = 4;
  searchQuery[1] = 7;
  search = point_search(root, searchQuery, 0, 2);
  if (search != NULL) {
    printf("%d, %d\n", search->x[0], search->x[1]);
  } else {
    printf("Non-existent node\n");
  }

  searchQuery[0] = 10;
  searchQuery[1] = 5;
  search = point_search(root, searchQuery, 0, 2);
  if (search != NULL) {
    printf("%d, %d\n", search->x[0], search->x[1]);
  } else {
    printf("Non-existent node\n");
  }

  int min[] = {6,3};
  int max[] = {9,7};
  LinkedTreeNode *rangeSearch = range_search(root, min, max, 0, 2);

  show_treenodes(rangeSearch, 2);

  TreeNode *result = (TreeNode *)malloc(sizeof(TreeNode));
  int arg[] = {5,4};
  int best = 0;
  nearest_neighbor_search(root, arg, 0, 2, &best, &result);
  if (result != NULL) {
    printf("%d, %d\n", result->x[0], result->x[1]);
  } else {
    printf("Non-existent node\n");
  }

  arg[0] = 4;
  arg[1] = 7;
  nearest_neighbor_search(root, arg, 0, 2, &best, &result);
  if (result != NULL) {
    printf("%d, %d\n", result->x[0], result->x[1]);
  } else {
    printf("Non-existent node\n");
  }


  return 0;
}


TreeNode *point_search(TreeNode *root, int x[], int currentDimension, int maxDimension) {
  if (root == NULL) {return NULL;}
  
  currentDimension %= maxDimension;
  
  if (x[currentDimension] < root->x[currentDimension]) {
    return point_search(root->left, x, ++currentDimension, maxDimension);
  } else if (x[currentDimension] > root->x[currentDimension]) {
    return point_search(root->right, x, ++currentDimension, maxDimension);
  } else {
    return root;
  }
}

LinkedTreeNode *range_search(TreeNode *root, int min[], int max[], int currentDimension, int maxDimension) {
  if (root == NULL) {return NULL;}

  LinkedTreeNode *basePtr = NULL;

  currentDimension %= maxDimension;
  
  if (min[currentDimension] < root->x[currentDimension]) {
    LinkedTreeNode* tmp = range_search(root->left, min, max, ++currentDimension, maxDimension);
    basePtr = tmp;
  }
  
  if (min[currentDimension] < root->x[currentDimension] && root->x[currentDimension] < max[currentDimension]) {
    LinkedTreeNode *ptr = basePtr;
    if (ptr) {
      while (ptr->next != NULL) {
        ptr = ptr->next;
      }
    } else {
      ptr = (LinkedTreeNode *)malloc(sizeof(LinkedTreeNode));
      ptr->next = NULL;
      ptr->node = root;
      basePtr = ptr;
    }
  }
  
  if (root->x[currentDimension] < max[currentDimension]) {
    LinkedTreeNode *tmp = range_search(root->right, min, max, ++currentDimension, maxDimension);
    LinkedTreeNode *ptr = basePtr;

    if (ptr) {
      while (ptr->next != NULL) {
        ptr = ptr->next;
      }
      ptr->next = tmp;
    } else {
      basePtr = tmp;
    }
  }

  return basePtr;
}

void nearest_neighbor_search(TreeNode *root, int *target, int currentDimension, int maxDimension, int *bestDist, TreeNode** returnNode) {
  if (root == NULL) return;
  int dist = 0, distOfCurrentDimension = 0, distOfCurrentDimensionSquared = 0;

  currentDimension = currentDimension % maxDimension;

  for (int i = 0; i < maxDimension; i++) {
    int value = root->x[i] - target[i];
    dist += (value * value);
  }
  distOfCurrentDimension = root->x[currentDimension] - target[currentDimension];
  distOfCurrentDimensionSquared = distOfCurrentDimension * distOfCurrentDimension;

  if (bestDist != NULL || dist < *bestDist ) {
    *returnNode = root;
    *bestDist = dist;
  }

  nearest_neighbor_search((distOfCurrentDimension > 0) ? root->left : root->right, target, ++currentDimension, maxDimension, bestDist, returnNode);
  if (distOfCurrentDimensionSquared >= *bestDist) return;
  nearest_neighbor_search((distOfCurrentDimension > 0) ? root->right : root->left, target, ++currentDimension, maxDimension, bestDist, returnNode);
}

void show_treenodes(LinkedTreeNode *nodes, int maxDimensions) {
  LinkedTreeNode* ptr = nodes;
  while (ptr != NULL) {
    for (int i = 0; i < maxDimensions; i++) {
      if (i != 0) {
        printf(", %d", ptr->node->x[i]);
      } else {
        printf("%d", ptr->node->x[i]);
      }
    }
    printf("\n");
    ptr = ptr->next;
  }
}

void swap(TreeNode *node1, TreeNode *node2) {
  int tmp[MAX_DIMENSION];
  for (int i = 0; i < MAX_DIMENSION; i++) {
    tmp[i] = node1->x[i];
  }
  for (int i = 0; i < MAX_DIMENSION; i++) {
    node1->x[i] = node2->x[i];
  }
  for (int i = 0; i < MAX_DIMENSION; i++) {
    node2->x[i] = tmp[i];
  }
}

TreeNode *find_median(TreeNode *start, TreeNode *end, int currentDimension) {

    // check validity
    if (end <= start) return NULL;
    if (end == start + 1) return start;

    TreeNode *tmp, *store, *md = start + (end - start) / 2;
    double pivot;
    while (1) {
        pivot = md->x[currentDimension];
 
        swap(md, end - 1);
        for (store = tmp = start; tmp < end; tmp++) {
            if (tmp->x[currentDimension] < pivot) {
                if (tmp != store)
                    swap(tmp, store);
                store++;
            }
        }
        swap(store, end - 1);
 
        // if both is same
        if (store->x[currentDimension] == md->x[currentDimension]) return md;
 
        if (store > md) end = store;
        else start = store;
    }
}

TreeNode *build_tree(TreeNode t[], int len, int i, int dim)
{
    TreeNode *n;
 
    if (!len) return 0;
 
    if ((n = find_median(t, t + len, i))) {
        i = (i + 1) % dim;
        n->left  = build_tree(t, n - t, i, dim);
        n->right = build_tree(n + 1, t + len - (n + 1), i, dim);
    }
    return n;
}

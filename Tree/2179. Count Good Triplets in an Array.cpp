/*
Platform :- Leetcode
Contest :- Bi weekly contest 72
Approach :- For each of values in array nums1 , we will create array of index in array 2 , now we want to know for (i=1 , to n-2 ), no of values that are smaller than current value
            in that array and no of values greater than that value to the right in that array , the product of those is added to the answer .
            For finding no of values greater than curret value to the right we will use self balancing BST and using that info we can also find no of values smaller than it to let
            check more about this :- https://www.geeksforgeeks.org/count-smaller-elements-on-right-side/
*/
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
     
    // size of the tree rooted
    // with this node
    int size;
};
 
// A utility function to get
// maximum of two integers
int max(int a, int b);
 
// A utility function to get
// height of the tree rooted with N
int height(struct node *N)
{
    if (N == NULL)
        return 0;
         
    return N->height;
}
 
// A utility function to size
// of the tree of rooted with N
int size(struct node *N)
{
    if (N == NULL)
        return 0;
         
    return N->size;
}
 
// A utility function to
// get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
// Helper function that allocates a
// new node with the given key and
// NULL left and right pointers.
struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
     
    // New node is initially added at leaf
    node->height = 1; 
    node->size = 1;
    return(node);
}
 
// A utility function to right rotate
// subtree rooted with y
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Update sizes
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate
// subtree rooted with x
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Update sizes
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
         
    return height(N->left) - height(N->right);
}
 
// Inserts a new key to the tree rotted with
// node. Also, updates *count to contain count
// of smaller elements for the new key
struct node* insert(struct node* node, int key,
                    int *count)
{
    // 1. Perform the normal BST rotation
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key, count);
    else
    {
        node->right = insert(node->right, key, count);
 
        // UPDATE COUNT OF SMALLER ELEMENTS FOR KEY
        *count = *count + size(node->left) + 1;
    }
 
 
    // 2.Update height and size of this ancestor node
    node->height = max(height(node->left),
                       height(node->right)) + 1;
    node->size   = size(node->left) +
                   size(node->right) + 1;
 
    // 3. Get the balance factor of this
    // ancestor node to check whether this
    // node became unbalanced
    int balance = getBalance(node);
 
    // If this node becomes unbalanced,
    // then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    // Return the (unchanged) node pointer
    return node;
}
 
// The following function updates the
// countSmaller array to contain count of
// smaller elements on right side.
void constructLowerArray(int arr[], int countSmaller[],
                         int n)
{
    int i, j;
    struct node *root = NULL;
     
    // Initialize all the counts in
    // countSmaller array as 0
    for(i = 0; i < n; i++)
        countSmaller[i] = 0;
     
    // Starting from rightmost element,
    // insert all elements one by one in
    // an AVL tree and get the count of
    // smaller elements
    for(i = n - 1; i >= 0; i--)
    {
        root = insert(root, arr[i], &countSmaller[i]);
    }
}
 


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        
        int n = nums1.size();
        vector<int>z(n);
        
        for(int i = 0;i<n;++i){
            z[nums2[i]] = i;
        }
        int temp[n];
        for(int i = 0;i<n;++i){
            temp[i]=z[nums1[i]];
        }
        
        int *low = (int *)malloc(sizeof(int)*n);
     
        constructLowerArray(temp, low, n);
        
        for(int i=1 ;i<n-1;++i){
            //so low will tell no of values smaller than it to the right
            long long small_right = low[i];
            long long big_right = ((n-(i+1))-small_right);
            long long  left_small = temp[i] - small_right;
           /// cout<<temp[i]<<" "<<left_small<<" "<<big_right<<"\n";
            ans+=(big_right*left_small);
        }
    
        return ans;
    }
};

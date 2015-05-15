#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

vector<vector<int>> combine(int n, int k);
vector<vector<int>> subCombine(int *p,int k,int start,int end);
vector<vector<int> > subsets(vector<int> &S);
bool exist(vector<vector<char> > &board, string word);
bool isExist(vector<vector<char>> &board,string word,int i,int j,int pos,vector<vector<bool>> isContains);
int removeDuplicates(int A[], int n);
bool search(int A[], int n, int target);
ListNode *deleteDuplicates(ListNode *head);
int largestRectangleArea(vector<int>& height);
int maximalRectangle(vector<vector<char> > &matrix);
int largestRectangle(vector<int>& height);
ListNode* partition(ListNode* head, int x);
bool isScramble(string s1, string s2);
vector<int> grayCode(int n);
vector<vector<int>> subsetsWithDup(vector<int>& nums);
int numDecodings(string s);
ListNode* reverseBetween(ListNode* head, int m, int n);
vector<string> restoreIpAddresses(string s);
vector<string> address(string s, int n);
vector<int> inorderTraversal(TreeNode* root);
vector<TreeNode*> generateTrees(int n);
vector<TreeNode*>  searchTrees(int start, int end);
int numTrees(int n);
bool isInterleave(string s1, string s2, string s3);
bool isValidBST(TreeNode* root);
void recoverTree(TreeNode* root);
vector<vector<int>> zigzagLevelOrder(TreeNode* root);
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder);
TreeNode* sortedArrayToBST(vector<int>& nums);
void flatten(TreeNode* root);
int numDistinct(string s, string t);
void connect(TreeLinkNode *root);
void connect1(TreeLinkNode *root);
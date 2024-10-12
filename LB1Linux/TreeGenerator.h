#pragma once 

typedef struct TreeNode {
    char* label;
    int type;
    int countChildren;
    struct TreeNode** children;
}TreeNode;

typedef struct ErrorInfo {
    char* message;
    int line;
    int position;
} ErrorInfo;

typedef struct OutStruct {
    struct TreeNode* root;
    struct ErrorInfo** er;
    int* erCount;
} OutStruct;

void freeMemori(TreeNode* root);

void addElement(int* size, ErrorInfo* newValue);

void freeEr();

void allFree(TreeNode* root);


OutStruct* treeGeneration(char* inputFile);


#pragma once
#include "TreeGenerator.h"


typedef struct Programm {
	struct Subprogramme** subPr;
	int subPrSize;
} Programm;

typedef struct Subprogramme {
	char* name;
	char* signature;
	char* fileName;
	struct CFGNode* root;
	struct CFGNode* last_node;
	struct LoopStack* stack;
}Subprogramme;

typedef struct CFGNode {
	int id;
	int visited;
	char* label;
	struct CFGNode* conditional;
	struct CFGNode* notcond;
	struct OperTree* root;
}CFGNode;

typedef struct OperTree {
	char* label;
	struct OperTree** children;
}OperTree;

typedef struct LoopStack {
	struct CFGNode* node;
	struct LoopStack* next;
} LoopStack;

Programm* cfgGenerator(TreeNode* root);

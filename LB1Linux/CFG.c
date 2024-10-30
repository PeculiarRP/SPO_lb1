#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CFG.h"

void createSubSign(TreeNode* root, Subprogramme* node, int backType){
	if (root->type == 27)
	{
		if (backType == 23) {
			node->name = root->label;
		}
		else {
			char* tmp = (char*)malloc(sizeof(node->signature) + sizeof(root->label) + 3);
			strcpy_s(tmp, sizeof(tmp), node->signature);
			strcat_s(tmp, sizeof(tmp), root->label);
			strcat_s(tmp, sizeof(tmp), " ");
			if (node->signature != "") {
				free(node->signature);
			}
			node->signature = tmp;
		}
	}
	else if ((root->type == 71) || (root->type == 13) || (root->type == 64) || (root->type == 6) || (root->type == 17)) {
		size_t sig = strlen(node->signature);
		size_t label = strlen(root->label);
		size_t final_size = sig + label + 2;

		char* tmp = (char*)malloc(final_size);
		strcpy_s(tmp, final_size, node->signature);
		strcat_s(tmp, final_size, root->label);
		strcat_s(tmp, final_size, " ");
		free(node->signature);
		node->signature = tmp;
	}
	for (int i = 0; i < root->countChildren; i++) {
		int type = root->type;
		if (type == 26) type = backType;
		createSubSign(root->children[i], node, type);
	}
}

void push_loopstack(LoopStack** head, CFGNode* node) {
	LoopStack* tmp = malloc(sizeof(LoopStack));
	tmp->node = node;
	tmp->next = *head;
	*head = tmp;
}

CFGNode* pop_loopstack(LoopStack** head) {
	LoopStack* out;
	CFGNode* value;
	out = *head;
	*head = (*head)->next;
	value = out->node;
	free(out);
	return value;
}

int stack_size(const LoopStack* head) {
	int size = 0;
	while (head) {
		size++;
		head = head->next;
	}
	return size;
}

CFGNode* createCFGNode(int childId, char* label) {
	CFGNode* node = (CFGNode*)malloc(sizeof(CFGNode));
	node->id = childId;
	node->visited = 0;
	node->label = label;
	node->conditional = NULL;
	node->notcond = NULL;
	node->root = NULL;
	return node;
}

CFGNode* createSubStat(Subprogramme* sub_pr, TreeNode* root, CFGNode* node, int id) {
	if (node == NULL) {
		node = createCFGNode(id, root->label);
	}
	else if (node->label == "") {
		node->label = root->label;
		sub_pr->last_node = NULL;
	}

	if (root->type == 30) { 
		push_loopstack(&(sub_pr->stack), node); 
	}
	if ((root->type == 11) && (stack_size(sub_pr->stack) != 0)) {
		node->notcond = pop_loopstack(&(sub_pr->stack));
		sub_pr->last_node = node;
		return node;
	}

	for (int i = 0; i < root->countChildren; i++) {
		int childId = id * 10 + i;
		switch (root->children[i]->type)
		{
		case 30:
			node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
			break;
		case 40:
			if ((root->type == 28) || (root->type == 8)) {
				if (node->conditional == NULL) node->conditional = createSubStat(sub_pr, root->children[i], node->conditional, childId);
				else node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
			}
			else if (root->type == 9) {
				if (node->notcond == NULL) node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
				else if ((sub_pr->last_node != NULL) && (sub_pr->last_node->label == "")) sub_pr->last_node->notcond = createSubStat(sub_pr, root->children[i], sub_pr->last_node->notcond, childId);
			}
			else if (root->type = 30) {
				if (node->conditional == NULL) {
					node->conditional = createSubStat(sub_pr, root->children[i], node->conditional, childId);
					if (sub_pr->last_node->label != root->label) {
						sub_pr->last_node->notcond = node;
					}
					sub_pr->last_node = NULL;
				}
				else if (sub_pr->last_node != NULL) sub_pr->last_node->notcond = createSubStat(sub_pr, root->children[i], sub_pr->last_node->notcond, childId);
			}
			break;
		case 8:
			node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
			break;
		case 9:
			node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
			break;
		case 27:
			node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
			break;
		case 20:
			node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
			break;
		case 28:
			node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
			break;
		case 69:
			if ((root->type == 30) && (stack_size(sub_pr->stack) != 0)) pop_loopstack(&(sub_pr->stack));
			else {}
			break;
		case 11:
			node->notcond = createSubStat(sub_pr, root->children[i], node->notcond, childId);
			break;
		default:
			break;
		}
	}

	if (node->notcond == NULL) {
		if (sub_pr->last_node == NULL){
			sub_pr->last_node = createCFGNode(id * 10 + root->countChildren + 1, "");
		}
		node->notcond = sub_pr->last_node;
	}

	return node;
}

void createSubNode(TreeNode* root, Subprogramme* node){
	CFGNode* start = (CFGNode*)malloc(sizeof(CFGNode));
	start = createCFGNode(1, "Start");
	node->root = start;
	node->last_node = NULL;
	node->signature = "";
	for (int i = 0; i < root->countChildren; i++) {
		if (root->children[i]->type == 23) createSubSign(root->children[i], node, 0);
		else if (root->children[i]->type == 40) {
			if (start->notcond == NULL) start->notcond = createSubStat(node, root->children[i], start->notcond, start->id * 10 + i);
			else node->last_node = createSubStat(node, root->children[i], node->last_node, node->last_node->id);
		}
	}
	node->last_node->label = "End";
}

void addSubPr(Programm* out, Subprogramme* sub) {
	out->subPr = realloc(out->subPr, (out->subPrSize + 1) * sizeof(Subprogramme*));
	out->subPr[out->subPrSize] = malloc(sizeof(Subprogramme));
	out->subPr[out->subPrSize] = sub;
	out->subPrSize++;
}

void createSt(Programm* out, TreeNode* root) {
	if (root->type == 38) {
		for (int i = 0; i < root->countChildren; i++) {
			TreeNode* child = root->children[i];
			if (child->type == 22) {
				Subprogramme* node = (Subprogramme*)malloc(sizeof(Subprogramme));
				node->stack = NULL;
				createSubNode(child, node);
				addSubPr(out, node);
			}	
		}
		return;
	}
	for (int i = 0; i < root->countChildren; i++) {
		createSt(out, root->children[i]);
	}
}

Programm* cfgGenerator(TreeNode* root){
	Programm* out = malloc(sizeof(Programm));
	out->subPr = NULL;
	out->subPrSize = 0;
	createSt(out, root);
	return out;
}
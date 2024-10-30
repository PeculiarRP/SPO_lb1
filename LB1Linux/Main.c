#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TreeGenerator.h"
#include "CFG.h"

void printCFG(FILE* out, CFGNode* graph, int type, char** links) {
    char buffer[256];
    size_t fin_size = 0;
    char* tmp_str = NULL;
    if (type == 0) fprintf(out, "<Node Id=\"%d\" Label=\"%s\"/>\n", graph->id, graph->label);
    graph->visited = 1;
    if (graph->conditional != NULL) {
        snprintf(buffer, sizeof(buffer), "<Link Source=\"%d\" Target=\"%d\"/>\n", graph->id, graph->conditional->id);
        fin_size = strlen(*links) + strlen(buffer) + 1;
        tmp_str = (char*)malloc(fin_size);
        strcpy_s(tmp_str, fin_size, *links);
        strcat_s(tmp_str, fin_size, buffer);
        *links = tmp_str;
        if (graph->conditional->visited != 1) printCFG(out, graph->conditional, type, links);
    }
    if (graph->notcond != NULL) {
        snprintf(buffer, sizeof(buffer), "<Link Source=\"%d\" Target=\"%d\"/>\n", graph->id, graph->notcond->id);
        fin_size = strlen(*links) + strlen(buffer) + 1;
        tmp_str = (char*)malloc(fin_size);
        strcpy_s(tmp_str, fin_size, *links);
        strcat_s(tmp_str, fin_size, buffer);
        *links = tmp_str;
        if (graph->notcond->visited != 1) printCFG(out, graph->notcond, type, links);
    }
};

void generateTreeTextBlock(TreeNode* node, FILE* outFile, int id, int operType) {
    if (operType == 0) fprintf(outFile, "<Node Id=\"%d\" Label=\"%d: %s\"/>\n", id, node->type, node->label);
    for (int i = 0; i < node->countChildren; i++) {
        int childId = id * 10 + i; // Простая схема генерации уникальных ID
        generateTreeTextBlock(node->children[i], outFile, childId, operType);
        if (operType == 1) fprintf(outFile, "<Link Source=\"%d\" Target=\"%d\"/>\n", id, childId);
    }
};

void generateDGML(TreeNode* root, CFGNode* pr, FILE* outFile) {
    char* links = "";
    fprintf(outFile, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    fprintf(outFile, "<DirectedGraph xmlns=\"http://schemas.microsoft.com/vs/2009/dgml\">\n");
    fprintf(outFile, "<Nodes>\n");
    if (root != NULL) generateTreeTextBlock(root, outFile, 1, 0);
    else printCFG(outFile, pr, 0, &links);
    fprintf(outFile, "</Nodes>\n");
    fprintf(outFile, "<Links>\n");
    if (root != NULL) generateTreeTextBlock(root, outFile, 1, 1);
    else fprintf(outFile, "%s", links);
    fprintf(outFile, "</Links>\n");
    fprintf(outFile, "</DirectedGraph>");
};


int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error: not all files are specified!");
        return;
    }
    Programm* outPr = NULL;
    OutStruct* out = treeGeneration(argv[1]);
    FILE* outFile = fopen(argv[2], "w");
    FILE* tmpFile = fopen("tmp.dgml", "w");
    if (out != NULL) {
         outPr = cfgGenerator(out->root);
    }
    if (outPr != NULL) {
        generateDGML(NULL, outPr->subPr[0]->root, tmpFile);
    }
    if (out != NULL) {
        generateDGML(out->root, NULL, outFile);
        freeMemori(out->root);
    }
    int errorCount = out->erCount;
    if (errorCount != 0) {
        for (int i = 0; i < errorCount; i++) {
            printf("%s line %d in %d\n", out->er[i]->message, out->er[i]->line, out->er[i]->position);
        }
    }
    else printf("No errors found!");
    fclose(tmpFile);
    fclose(outFile);
};
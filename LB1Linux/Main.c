#include <stdio.h>
#include <stdlib.h>

#include "TreeGenerator.h"


void generateTreeTextBlock(TreeNode* node, FILE* outFile, int id, int operType) {
    if (operType == 0) fprintf(outFile, "<Node Id=\"%d\" Label=\"%d: %s\"/>\n", id, node->type, node->label);
    for (int i = 0; i < node->countChildren; i++) {
        int childId = id * 10 + i; // Простая схема генерации уникальных ID
        generateTreeTextBlock(node->children[i], outFile, childId, operType);
        if (operType == 1) fprintf(outFile, "<Link Source=\"%d\" Target=\"%d\"/>\n", id, childId);
    }
};

void generateDGML(TreeNode* root, FILE* outFile) {
    fprintf(outFile, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    fprintf(outFile, "<DirectedGraph xmlns=\"http://schemas.microsoft.com/vs/2009/dgml\">\n");
    fprintf(outFile, "<Nodes>\n");
    generateTreeTextBlock(root, outFile, 1, 0);
    fprintf(outFile, "</Nodes>\n");
    fprintf(outFile, "<Links>\n");
    generateTreeTextBlock(root, outFile, 1, 1);
    fprintf(outFile, "</Links>\n");
    fprintf(outFile, "</DirectedGraph>");
};


int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error: not all files are specified!");
        return;
    }
    OutStruct* out = treeGeneration(argv[1]);
    FILE* outFile = fopen(argv[2], "w");
    if (out != NULL) {
        generateDGML(out->root, outFile);
        freeMemori(out->root);
    }
    int errorCount = out->erCount;
    if (errorCount != 0) {
        for (int i = 0; i < errorCount; i++) {
            printf("%s line %d in %d\n", out->er[i]->message, out->er[i]->line, out->er[i]->position);
        }
    }
    else printf("No errors found!");
    fclose(outFile);
};
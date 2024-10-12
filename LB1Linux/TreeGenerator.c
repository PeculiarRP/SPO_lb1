#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "antlr3.h"           // ANTLR библиотека
#include "ANTLR/MyGramLexer.h" // Заголовочный файл лексера
#include "ANTLR/MyGramParser.h" // Заголовочный файл парсера

#include "TreeGenerator.h"

ErrorInfo** errors = NULL;
int erCount = 0;

TreeNode* createTreeNode(TreeNode* node, char* value, int type, int count) {
    if (value[0] == '<') {
        value[0] = ' ';
        value[strlen(value) - 1] = ' ';
    }
    node->label = strdup(value);
    node->type = type;
    node->children = NULL;
    if (count != 0) {
        node->children = (TreeNode**)malloc(count * sizeof(TreeNode*));
        //node->children = NULL;
        for (int i = 0; i < count; i++) {
            node->children[i] = malloc(count * sizeof(TreeNode));
        }
    }
    node->countChildren = count;
    return node;
}

TreeNode* createTree(pANTLR3_BASE_TREE root, TreeNode* node) {
    if (node == NULL) {
        node = (TreeNode*)malloc(sizeof(TreeNode));
    }
    
    node = createTreeNode(node, root->getText(root)->chars, root->getType(root), root->getChildCount(root));
    int count = root->getChildCount(root);
    for (int i = 0; i < count; i++) {
        pANTLR3_BASE_TREE child = root->getChild(root, i);
        node->children[i] = createTree(child, node->children[i]);
    }
    return node;
};

void freeMemori(TreeNode* root) {
    if (root->countChildren != 0) {
        for (int i = 0; i < root->countChildren; i++) {
            freeMemori(root->children[i]);
        }
    }
    free(root);
    return;
};

void addElement(int* size, ErrorInfo* newValue) {
    errors = realloc(errors, (*size + 1) * sizeof(ErrorInfo*));
    errors[*size] = malloc(sizeof(ErrorInfo));
    errors[*size] = newValue;
    (*size)++;
};

void myReportError(ANTLR3_BASE_RECOGNIZER* recognizer) {
    ErrorInfo* error = malloc(sizeof(ErrorInfo));
    error->message = recognizer->state->exception->message;
    error->line = recognizer->state->exception->line;
    error->position = recognizer->state->exception->charPositionInLine;
    addElement(&erCount, error);
};

void freeEr() {
    for (int i = 0; i < erCount; i++) {
        free(errors[i]);
    }
    free(errors);
};

void allFree(TreeNode* root) {
    freeMemori(root);
    freeEr();
};


OutStruct* treeGeneration(char* inputFile) {
    pANTLR3_INPUT_STREAM input;         
    pMyGramLexer lexer;             
    pANTLR3_COMMON_TOKEN_STREAM tokens; 
    pMyGramParser parser;
    OutStruct* out = malloc(sizeof(OutStruct));

    FILE* inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        printf("Error: Unable to open input file \n");
        return out;
    }

    input = antlr3FileStreamNew((pANTLR3_UINT8)inputFile, ANTLR3_ENC_8BIT);
    if (input == NULL) {
        printf("Error: Could not open input stream.\n");
        fclose(inFile);
        return out;
    }

    lexer = MyGramLexerNew(input);
    if (lexer == NULL) {
        printf("Error: Could not create lexer.\n");
        input->close(input);
        fclose(inFile);
        return out;
    }

    tokens =
        antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));
    if (tokens == NULL) {
        fprintf(stderr, "Error: Could not create token stream.\n");
        lexer->free(lexer);
        input->close(input);
        fclose(inFile);
        return out;
    }

    parser = MyGramParserNew(tokens);
    if (parser == NULL) {
        fprintf(stderr, "Error: Could not create parser.\n");
        tokens->free(tokens);
        lexer->free(lexer);
        input->close(input);
        fclose(inFile);
        return out;
    }

    parser->pParser->rec->reportError = myReportError;

    MyGramParser_source_return progReturn = parser->source(parser);

    /*if (parser->pParser->rec->state->errorCount > 0) {
        
        for (int i = 0; i < parser->pParser->rec->state->errorCount; i++) {
            char* name = parser->pParser->rec->state->exception->name;

        }

        fprintf(stderr, "Parsing finished with errors.\n");
    }*/
    //else {
    pANTLR3_BASE_TREE tree = progReturn.tree;
    out->root = createTree(tree, NULL);
    out->er = errors;
    out->erCount = erCount;
    //}

    parser->free(parser);
    tokens->free(tokens);
    lexer->free(lexer);
    input->close(input);
    fclose(inFile);

    return out;
};

#ifndef ASSEMBLE_H
#define ASSEMBLE_H

#endif // ASSEMBLE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NORTYPE 5
#define NOITPYE 8            //**************  ?????? ***************// 8? 6?
#define NOJTYPE 2
#define RTYPE 0
#define ITYPE 1
#define jTYPE 2

struct symbolTable{
    int value;
    char *symbol;

};

struct instruction{
    size_t instType; // 0 => r , 1 => i , 2 => j
    size_t intInst;
    char *nnemonic;
    char inst[9];
    int rs;
    int rt;
    int rd;
    int imm;
    int pc;
};

int findSymTablen(FILE *);
int fillSymTab(struct symbolTable *,FILE *);
void formInst(struct instruction *,FILE *);
int hex2int(char *);
void int2hex16(char *,int);


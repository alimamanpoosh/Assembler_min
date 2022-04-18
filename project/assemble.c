#include<assemble.h>
//argv not indtefing
//getline not indtefing
int main(int argc,char **agrv)
{
    FILE *assp, *machp, *fopen();
    struct symbolTable *pSymTab;
    int symTabLen;
    int i,j,found,noInsts;
    struct instruction *currInst;
    size_t lineSize;
    char *line;
    char *token;
    char *instruction[] = {"add" , "sub" , "slt", "or" , "nand" , "addi" , "slti" , "ori" , "lui" , "lw" , "sw" , "beq" , "jalr" , "j" , "halt"};
    int instCnt = 0 ;
    char hexTable[16] = {'0' , '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char lower[5];
    i =0;
    j =0;
    line = (char *)malloc(72);
    currInst =(struct instruction *)malloc(sizeof (struct instruction));
    if(argc < 3)
    {
        printf("****** Please run this program as follows :\n");
        //printf("****** %s assprog.as machprog.m \n ", argv[0]);    // ******************  ??????????? ***************//
        printf("****** where assprog.as in your assembly program \n");
        printf("****** and machprog.m will be your machine code \n");
    }

//    if((assp=fopen(argv[1],"r")) == NULL)
//    {
//        printf("%s cannot be opened \n" , argv[1]);
//        exit(1);
//    }


//    if((machp = fopen(argv[2],"w+")) == NULL)
//    {
//        printf("%s cannot be opened \n",argv[1]);
//        exit(1);
//    }


    //here you can place your code for the assembler

    symTabLen = findSymTablen(assp);
    pSymTab = (struct symbolTable *)malloc(symTabLen *sizeof (struct symbolTable));
    for(i =0 ;i < symTabLen ; i++) printf("%s %d \n", pSymTab[i].symbol , pSymTab[i].value);
    while (getline(&line , &lineSize , assp) != -1) {
        currInst->pc = instCnt;
        instCnt++;
        found =0;
        token = strtok(line,"\t, \n");
        for(i = 0 ; i < symTabLen ; i++)
        {
            if(strcmp(pSymTab[i].symbol,token) == 0)
            {
                token = strtok(NULL,"\t, \n");
            }
        }
        strcpy(currInst ->nnemonic ,token);
        currInst->instType = -1;
        if(strcmp(currInst->nnemonic,".fill") == 0)
        {
            token = strtok(NULL,"\t, \n");
            currInst ->intInst = atoi(token);
            //!!!!!!!!!!!!!!!!!!!!!  ME !!!!!!!!!!!!!!!!!!!!!!!
        }

    }





    return 0;
}



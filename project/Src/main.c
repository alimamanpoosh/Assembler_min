#include <stdio.h>
#include<string.h>
#include <ctype.h>
char Symbol[8];

int numOfLine =0;


char* int2hex(int a)
{
    char* lower =(char*) malloc(10);

    sprintf(lower, "%X",a);
    if(a < 0x10){
        lower[4] = '\0';
        lower[3] = lower[0];
        lower[2] = '\0';
        lower[1] = '\0';
        lower[0] = '\0';

    }

    else if (a < 0x100) {
        lower[4] = '\0';
        lower[3] = lower[1];
        lower[2] = lower[0];
        lower[1] = '\0';
        lower[0] = '\0';

    }
    else if (a < 0x1000) {
        lower[4] = '\0';
        lower[3] = lower[2];
        lower[2] = lower[1];
        lower[1] = lower[0];
        lower[0] = '\0';

    }
    return lower;

}
int hex2int(char* hex)
{
    int result = 0;
    while ((*hex) != '\0')
    {
        if(('0' <= (*hex))&&((*hex) <= '9'))
            result = result * 16 + (*hex) - '0';
        else if (('a' <= (*hex))&&((*hex) <= 'f'))
            result = result * 16 + (*hex) - 'a'+10;
        else if(('A' <= (*hex)) && ((*hex) <= 'f'))
            result = result *16 + (*hex) - 'A' +10;
        hex++;
    }
    return(result);
}
void lw_op(char * line)
{    
    //op = 9 // rt,rs,offset // I Type // make label operation

    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*offset;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rs = pch;
            }
            else if (Specified == 2) {
                rt = pch;

            }
            else if (Specified == 3) {
                offset = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            else if (Specified == 4) {
                offset = pch;

            }

            Specified++;
        }
    }


    Symbol[0] = 0;
    Symbol[1] = 9;
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = int2hex((int)offset)[0];
    Symbol[5] = int2hex((int)offset)[1];
    Symbol[6] = int2hex((int)offset)[2];
    Symbol[7] = int2hex((int)offset)[3];

}
void slt_op(char * line)
{
    //op = 2 // rd,rs,rt // R Type
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*rd;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rd = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rd = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }
            else if (Specified == 4) {
                rt = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;  // zero
    Symbol[1] = 2;  //op code
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = (int)rd;
    Symbol[5] = 0;
    Symbol[6] = 0;
    Symbol[7] = 0;
}
void sub_op(char * line)
{
    //op = 1 // rd,rs,rt // R Type    
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*rd;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rd = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rd = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }
            else if (Specified == 4) {
                rt = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;  // zero
    Symbol[1] = 1;  //op code
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = (int)rd;
    Symbol[5] = 0;
    Symbol[6] = 0;
    Symbol[7] = 0;

}
void add_op(char * line)
{
    //op = 0 // rd,rs,rt // R Type    
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*rd;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rd = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rd = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }
            else if (Specified == 4) {
                rt = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;  // zero
    Symbol[1] = 0;  //op code
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = (int)rd;
    Symbol[5] = 0;
    Symbol[6] = 0;
    Symbol[7] = 0;
}
void nand_op(char * line)
{
    //op = 4 // rd,rs,rt // R Type
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*rd;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rd = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rd = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }
            else if (Specified == 4) {
                rt = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;  // zero
    Symbol[1] = 4;  //op code
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = (int)rd;
    Symbol[5] = 0;
    Symbol[6] = 0;
    Symbol[7] = 0;

}
void or_op(char * line)
{
    //op = 3 // rd,rs,rt // R Type
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*rd;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rd = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rd = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }
            else if (Specified == 4) {
                rt = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;  // zero
    Symbol[1] = 3;  //op code
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = (int)rd;
    Symbol[5] = 0;
    Symbol[6] = 0;
    Symbol[7] = 0;

}
void slti_op(char * line)
{
    //op = 6 // rt,rs,imm // I Type    
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*imm;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                imm = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                imm = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }
            else if (Specified == 4) {
                rt = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;  // zero
    Symbol[1] = 6;  //op code
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = int2hex((int)imm)[0];
    Symbol[5] = int2hex((int)imm)[1];
    Symbol[6] = int2hex((int)imm)[2];
    Symbol[7] = int2hex((int)imm)[3];

}
void addi_op(char * line)
{
    //op = 5 // rt,rs,imm // I Type
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*imm;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                imm = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                imm = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }
            else if (Specified == 4) {
                rt = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;  // zero
    Symbol[1] = 5;  //op code
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = int2hex((int)imm)[0];
    Symbol[5] = int2hex((int)imm)[1];
    Symbol[6] = int2hex((int)imm)[2];
    Symbol[7] = int2hex((int)imm)[3];
}
void ori_op(char * line)
{
    //op = 7 // rt,rs,imm //I Type
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*imm;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                imm = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                imm = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }
            else if (Specified == 4) {
                rt = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;  // zero
    Symbol[1] = 7;  //op code
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = int2hex((int)imm)[0];
    Symbol[5] = int2hex((int)imm)[1];
    Symbol[6] = int2hex((int)imm)[2];
    Symbol[7] = int2hex((int)imm)[3];
}
void beq_op(char *line)
{
    //op = 11 // rt,rs,offset // I Type // make label operation
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*offset;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rs = pch;
            }
            else if (Specified == 2) {
                rt = pch;

            }
            else if (Specified == 3) {
                offset = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            else if (Specified == 4) {
                offset = pch;

            }

            Specified++;
        }
    }
    if(isdigit(offset[0]))
    {
        Symbol[0] = 0;
        Symbol[1] = 'B';
        Symbol[2] = (int)rs;
        Symbol[3] = (int)rt;
        Symbol[4] = int2hex((int)offset)[0];
        Symbol[5] = int2hex((int)offset)[1];
        Symbol[6] = int2hex((int)offset)[2];
        Symbol[7] = int2hex((int)offset)[3];

    }
    else if (isalpha(offset[0])) {
        //sherch in file and for \n num of line ++
    }

}
void sw_op(char * line)
{
    //op = 10 // rt,rs,offset // I Type // make label operation
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rs,*rt,*offset;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 4)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rs = pch;
            }
            else if (Specified == 2) {
                rt = pch;

            }
            else if (Specified == 3) {
                offset = pch;
            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            else if (Specified == 3) {
                rt = pch;
            }
            else if (Specified == 4) {
                offset = pch;

            }

            Specified++;
        }
    }
    Symbol[0] = 0;
    Symbol[1] = 'A';
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = int2hex((int)offset)[0];
    Symbol[5] = int2hex((int)offset)[1];
    Symbol[6] = int2hex((int)offset)[2];
    Symbol[7] = int2hex((int)offset)[3];

}
void lui_op(char * line)
{
    //op = 8 // rt,imm // I Type
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rt,*imm;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 3)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rt = pch;
            }
            else if (Specified == 2) {
                imm = pch;

            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rt = pch;

            }
            else if (Specified == 3) {
                imm = pch;
            }

            Specified++;
        }
    }
    //imperfect
    Symbol[0] = 0;
    Symbol[1] = 8;
    Symbol[2] = 0;
    Symbol[3] = (int)rt;
    Symbol[4] = int2hex((int)imm)[0];
    Symbol[5] = int2hex((int)imm)[1];
    Symbol[6] = int2hex((int)imm)[2];
    Symbol[7] = int2hex((int)imm)[3];
}
void jalr_op(char * line)
{
    //op = 12 // rt,rs //  I Type
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*rt,*rs;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 3)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                rt = pch;
            }
            else if (Specified == 2) {
                rs = pch;

            }
            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                rt = pch;

            }
            else if (Specified == 3) {
                rs = pch;
            }

            Specified++;
        }
    }
    //imperfect
    Symbol[0] = 0;
    Symbol[1] = 'C';
    Symbol[2] = (int)rs;
    Symbol[3] = (int)rt;
    Symbol[4] = 0;
    Symbol[5] = 0;
    Symbol[6] = 0;
    Symbol[7] = 0;
}
void j_op(char * line)
{
    //op = 13 // offset // j Type
    char * pch;
    int count = 0;
    int Specified = 0;
    char *label,* operation,*offset;
    pch = strtok(line,"\t,");
    while (pch != NULL) {
        count++;
    }
    if(count  == 2)
    {
        while (pch != NULL) {
            if(Specified == 0)
                operation = pch;
            else if (Specified == 1) {
                offset = pch;
            }

            Specified++;


        }
    }
    else {
        while (pch != NULL) {
            if(Specified == 0)
                label= pch;
            else if (Specified == 1) {
                operation = pch;
            }
            else if (Specified == 2) {
                offset = pch;

            }


            Specified++;
        }
    }
    Symbol[0] = 0;
    Symbol[1] = 'D';
    Symbol[2] = 0;
    Symbol[3] = 0;
    Symbol[4] = int2hex((int)offset)[0];
    Symbol[5] = int2hex((int)offset)[1];
    Symbol[6] = int2hex((int)offset)[2];
    Symbol[7] = int2hex((int)offset)[3];
}
void halt_op()
{

        //End program
        Symbol[0] = 0;
        Symbol[1] = 'E';
        Symbol[2] = 0;
        Symbol[3] = 0;
        Symbol[4] = 0;
        Symbol[5] = 0;
        Symbol[6] = 0;
        Symbol[7] = 0;
}

int com(char * str)
{
    for(int i = 0 ; i < (int)strlen(str) ; ++i)
    {
        if(str[i] == 'l' || str[i+1] == 'w')
        {
            beq_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'a' || str[i+1] == 'd' || str[i+2] == 'd') {
            // add function
            add_op(str);
            return (hex2int(Symbol));

        }
        else if (str[i] == 's' || str[i+1] == 'u' || str[i+2] == 'b') {
            // sub function
            sub_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 's' || str[i+1] == 'l' || str[i+2] == 't') {
            // slt function
            slt_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'n' || str[i+1] == 'a' || str[i+2] == 'n' || str[i+3] == 'd' ) {
            // nand function
            nand_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'o' || str[i+1] == 'r') {
            // or function
            or_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 's' || str[i+1] == 'l' || str[i+2] == 't' || str[i+3] == 'i' ) {
            // slti function
            slti_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'a' || str[i+1] == 'd' || str[i+2] == 'd' || str[i+3] == 'i' ) {
            // addi function
            addi_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'o' || str[i+1] == 'r' || str[i+2] == 'i') {
            // ori function
            ori_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'b' || str[i+1] == 'e' || str[i+2] == 'q') {
            // beq function
            beq_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 's' || str[i+1] == 'w') {
            // sw function
            sw_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'l' || str[i+1] == 'u' || str[i+2] == 'i') {
            // lui function
            lui_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'j' || str[i+1] == 'a' || str[i+2] == 'l' || str[i+3] == 'r' ) {
            // jalr function
            jalr_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'j' ) {
            // j function
            j_op(str);
            return (hex2int(Symbol));
        }
        else if (str[i] == 'h' || str[i+1] == 'a' || str[i+2] == 'l' || str[i+3] == 't' ) {
            // halt function
            halt_op();
            return (hex2int(Symbol));
        }


    }

}



int main()
{
    FILE *inputFile;
    char *line = "";
    line = (char*) malloc(72);
    inputFile = fopen("F:\\isfahan_ univercity\\new\\test_assembler\\File\\test.as","r");
//    char *str;
    while (fgets(line,72,inputFile)) {
        com(line);

        numOfLine++;
    }
    fclose(inputFile);








    return 0;
}

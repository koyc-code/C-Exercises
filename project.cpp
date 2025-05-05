#include <stdio.h.>
#include <stdlib.h>
#include <string.h>
#define scanrange 0.05

/*
next:the badcode detect
fix:the form to code might need to be check
bug:not found
*/

//normal routine
int fileread();
char *formtocode();
int findstartstop();
char *codetranslate();
char codetochar();
int findcandk(char *check, char cork);
void candkcheck();
//accident handle
void reverse();

int main()
{
    char filepath[] = {"C:/Users/rebecca/Desktop/vs_c_project/finalproject/finaltest.txt"};

    int *sourse = malloc(sizeof(int) * 200); //contain the data from scan
    int usingtimes = 0, casecount = 0;       //tatai scantime

    while (1)
    {
        int scantimes = fileread(filepath, sourse, usingtimes);

        if (scantimes == 0)
        {
            printf("-----FINISH-----");
            break;
        }
        printf("-----------case %d------------\n", ++casecount);

        usingtimes += scantimes + 1;                //count total scantimes
        char *code = formtocode(sourse, scantimes); //trnalate data to 1 0 code

        int startpoint = findstartstop(code); //set the star and stop point
        int stoppoint = findstartstop(startpoint + code + 1) + startpoint + 2;
        //printf("codes start and stop: %d %d\n", (startpoint), stoppoint); //---------------------

        if ((startpoint == -1 || stoppoint == -1) || (stoppoint - startpoint - 1) % 6 != 0) //start and stop detect
        {
            //printf("try to reverse\n\n");
            reverse(code, scantimes); //try to reverse

            startpoint = findstartstop(code);
            stoppoint = findstartstop(startpoint + code + 1) + startpoint + 2;
            //printf("codes start and stop: %d %d\n", (startpoint), stoppoint);                   //-----------------------------
            if ((startpoint == -1 || stoppoint == -1) || (stoppoint - startpoint - 1) % 6 != 0) //if still error... continue
            {
                printf("\nBad code: missing or invalid start/stop codes\n");
                continue;
            }
        }

        char *output = codetranslate(code, startpoint, stoppoint); //translate code to output+c k check
        free(code);                                                //code is useless hahaha cy@

        //printf("%s\tccheck:%d kcheck:%d\n", output,findcandk(output, 'c'), findcandk(output, 'k'));----------------------------------
        candkcheck(output, findcandk(output, 'c'), findcandk(output, 'k'));
    }
}

int fileread(char path[], int *output, int usingtimes)
{
    FILE *filecontent = NULL;
    fopen_s(&filecontent, path, "r");

    if (filecontent == NULL) //the filenot found
    {
        printf("the file not founded");
        return 0;
    }

    int scantimes;

    for (int i = 0; i < usingtimes; i++) //scape the former scan
    {
        fscanf(filecontent, "%d", (output));
    }

    fscanf(filecontent, "%d", &scantimes); //scan the scnatimes

    for (int i = 0; i < scantimes; i++) //scan
    {
        fscanf(filecontent, "%d", (output + i));
    }

    fclose(filecontent);
    return scantimes;
}

char *formtocode(int form[], int formlength)
{
    int makeaswitch = 0; //detect wether transform 2to1 1to0
    static char *code;   //the code will return
    code = malloc(sizeof(char) * formlength);
    code[0] = '1';                       //set first code is 0 and standard
    for (int i = 0; i < formlength; i++) //translate
    {
        if (form[i] >= form[0] * (2 - 2 * scanrange))
        {
            *(code + i) = '2';
            makeaswitch = 1;
        }
        else if ((2 - 2 * scanrange) * form[i] <= form[0])
        {
            *(code + i) = '0';
        }
        else if (form[i] <= form[0] * (2 - 2 * scanrange) && (2 - 2 * scanrange) * form[i] >= form[0])
        {
            *(code + i) = '1';
        }
        else
        {
            printf("\nBad code: bar widths outside the allowable range\n");
        }
    }
    if (makeaswitch == 1) //transform
    {
        for (int i = 0; i < formlength; i++)
        {
            if (*(code + i) == '1')
            {
                *(code + i) = '0';
            }
        }
        for (int i = 0; i < formlength; i++)
        {
            if (*(code + i) == '2')
            {
                *(code + i) = '1';
            }
        }
    }

    return code;
}

char *codetranslate(char *code, int startpoint, int stoppoint)
{
    int outputlength = (stoppoint - startpoint - 1) / 6 - 1; //set the meaningful part
    char *output = malloc(sizeof(char) * outputlength);      //output will return
    for (int i = 0; i < outputlength; i++)
    {
        char *tempstr = malloc(sizeof(char) * 6);                 //six digit a part
        strncpy(tempstr, code + (startpoint + 1) * 6 + i * 6, 5); //drpart
        *(tempstr + 5) = '\0';                                    //set the partend
        //printf("%s ", tempstr);----------------------------------------------------[for debug]
        *(output + i) = codetochar(tempstr); //translate to meaning
    }
    output[outputlength] = '\0'; //the ending charctor of output
    return output;
}
char codetochar(char *fivedigit)
{
    if (strcmp("00001", fivedigit) == 0)
    {
        return '0';
    }
    else if (strcmp("10001", fivedigit) == 0)
    {
        return '1';
    }
    else if (strcmp("01001", fivedigit) == 0)
    {
        return '2';
    }
    else if (strcmp("11000", fivedigit) == 0)
    {
        return '3';
    }
    else if (strcmp("00101", fivedigit) == 0)
    {
        return '4';
    }
    else if (strcmp("10100", fivedigit) == 0)
    {
        return '5';
    }
    else if (strcmp("01100", fivedigit) == 0)
    {
        return '6';
    }
    else if (strcmp("00011", fivedigit) == 0)
    {
        return '7';
    }
    else if (strcmp("10010", fivedigit) == 0)
    {
        return '8';
    }
    else if (strcmp("10000", fivedigit) == 0)
    {
        return '9';
    }
    else if (strcmp("00100", fivedigit) == 0)
    {
        return '-';
    }
    else
    {
        printf("translate error %s not match\n", fivedigit); //if error return X as a signal
        return 'X';
    }
}

void reverse(char *arr, int l)
{
    //ya just reverse
    char temp[l];
    for (int i = 0; i <= l; i++)
    {
        temp[i] = *(arr + i);
    }
    for (int i = 1; i <= l; i++)
    {
        *(arr + i - 1) = temp[l - i];
    }
}

int findcandk(char *check, char cork)
{
    int checklength = strlen(check) - 2;
    int ccheck = 0;
    int kcheck = 0;
    for (int i = 0; i < checklength; i++)
    {
        ccheck += ((*(check + i) == '-') ? 10 : *(check + i) - '0') * ((checklength - i - 1) % 10 + 1);
    }
    ccheck %= 11;
    for (int i = 0; i < checklength + 1; i++)
    {
        kcheck += ((*(check + i) == '-') ? 10 : *(check + i) - '0') * ((checklength - i) % 9 + 1);
    }
    kcheck %= 11;
    return (cork == 'c') ? ccheck : kcheck;
}

int findstartstop(char *code)
{
    return (strstr(code, "00110") != NULL) ? strstr(code, "00110") - code : -1;
}

void candkcheck(char *output, int ccheck, int kcheck)
{
    if (ccheck + '0' != *(output + (int)strlen(output) - 2))
    {
        printf("\nBad C\n");
        return;
    }
    if (kcheck + '0' != *(output + (int)strlen(output) - 1))
    {
        printf("\nBad K\n");
        return;
    }
    *(output + strlen(output) - 2) = '\0';
    printf("\noutput: %s\n", output);
}

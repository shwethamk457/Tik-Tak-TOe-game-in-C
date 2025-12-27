#include<stdio.h>
#include<string.h>
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW "\033[33m"
#define RESET   "\033[0m"
#define BOLD_RED    "\033[1;31m"
#define BOLD_GREEN  "\033[1;32m"
#define BOLD_BLUE   "\033[1;34m"
#define BOLD_PURPLE "\033[1;35m"
#define BOLD_CYAN   "\033[1;36m"
#define BOLD    "\033[1m"

int win_game(int r,int c,int (*arr)[3])
{
    int count1=0,count2=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
            {
                if(arr[i][j]==10)
                count1++;
                else if(arr[i][j]==20)
                count2++;
            }
        }
    }
    if(count1==3)
    return 10;
    else if(count2==3)
    return 20;
    
    count1=0,count2=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i+j==3-1)
            {
                if(arr[i][j]==10)
                count1++;
                else if(arr[i][j]==20)
                count2++;
            }
        }
    }
    if(count1==3)
    return 10;
    else if(count2==3)
    return 20;

    //row
    for(int i=0;i<3;i++)
    {
        if((arr[i][0]==arr[i][1])&&(arr[i][0]==arr[i][2]))
        return arr[i][0];
    }

    //for  column
    for(int j=0;j<3;j++)
    {
        if((arr[0][j]==arr[1][j])&&(arr[0][j]==arr[2][j]))
        return arr[0][j];
    }
    return 0;
}

int valid_option(int i,int j,int (*arr)[3])
{
    if(!((i>=0 && i<3)&&(j>=0 && j<3)))
    {
        printf(BOLD_RED"i and j value should be <=2 and >=0\n"RESET);
        return 0;
    }
    if(arr[i][j]!=0)
    {
        printf(BOLD_RED"already it is filled\n"RESET);
        return 0;
    }
    return 1;
}
void print_array(int r,int c,int (*arr)[3])
{
    printf(YELLOW"+-----+-----+-----+\n"RESET);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==0)
            {
                printf(YELLOW"|     "RESET);
            }
            else if(arr[i][j]==10)
            {
                printf(YELLOW"|"RESET);
                printf(" ❌  ");
            }
            else if(arr[i][j]==20)
            {
                printf(YELLOW"|"RESET);
                printf(" ⭕  ");
            }
        }
        printf(YELLOW"|\n"RESET);
        printf(YELLOW"+-----+-----+-----+\n"RESET);
    }
}
int main()
{
    char str1[10];
    char str2[10];
    printf("::::::::::WELCOME TO GAME::::::::::\n");
    printf("Please Enter the 1st person name: ");
    scanf("%s",str1);
    printf("Please Enter the 2nd person name: ");
    scanf("%s",str2);
    int arr[3][3]={0};
    print_array(3,3,arr);
    int k=1;
    char name[10];
    strcpy(name,str1);
    int i,j,attempt=0;
    while(k)
    {
        label:
        printf(BOLD_BLUE"%s "RESET"please enter the rows and columns:ex(1 1):",name);
        scanf("%d %d",&i,&j);
        int valid=valid_option(i,j,arr);
        if(valid==1)
        {
            if((strcmp(name,str1))==0)
                arr[i][j]=10;
            else
                arr[i][j]=20;
        }
        else if(valid==0)
        {
            printf(BOLD_RED"Inavlid option\n"RESET);
            goto label;
        }
        //printing 
        print_array(3,3,arr);

        //checking for winning conditions
        int win=win_game(3,3,arr);
            if(win==10)
            {
                printf(BOLD_GREEN"Congratulations\n"RESET);
                printf(BOLD_GREEN"%s you won the game🥳🥳🥳🥳\n"RESET,str1);
                return 0;
            }
            else if(win==20)
            {
                printf(BOLD_GREEN"Congratulations\n"RESET);
                printf(BOLD_GREEN"%s you won the game🥳🥳🥳🥳\n"RESET,str2);
                return 0;
            }
        
        if((strcmp(name,str1))==0)
            strcpy(name,str2);
        else
            strcpy(name,str1);
        attempt++;
        if(attempt==9)
        {
            printf(BOLD_GREEN"Game draw🙆🏻‍♀️🙆🏻‍♀️🙆🏻‍♀️🙆🏻‍♀️\n"RESET);
            k=0;
        }
    }
}
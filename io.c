#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    FILE *fs,*ft;
    fs=fopen("n.txt","w");
    ft=fopen("n.txt","r+");
    struct em{
        char name[20];char sur[20];int age;
    };
    struct em e;
    char ch='Y';
    while(ch=='Y')
    {
        printf("enter name,surname,age:");
        scanf("%s%s%d",e.name,e.sur,&e.age);
        fprintf(fs,"%s %s %d\n",e.name,e.sur,e.age);
        fflush(stdin);
        printf("For More Press Y:");
        ch=fgetchar();
    }
    fclose(fs);
    system("cls");
    printf("Entered Data:\n");
    char q;
    while((q=fgetc(ft))!=EOF)
    {
        printf("%c",q);
    }
    
    int g;
    printf("----------------------\n");
    printf("Press 1 for change data and 2 for exit:");
    scanf("%d",&g);
    switch(g)
    {
        case 1:
        printf("Change Data:----\n");
        int rec;
        rec=sizeof(struct em);
        char na[20];
        char s[100];
        printf("Enter name to modify:");
        scanf("%s",na);
        rewind(ft);
        while((fgets(s,sizeof(s),ft))!=NULL)
        {
            if(strcmp(e.name,na)==0)
            {
                printf("Enter new name,surname,age:");
                scanf("%s%s%d",e.name,e.sur,&e.age);
                fseek(ft,-rec,SEEK_CUR);
                fwrite(&e,sizeof(e),1,fs);
            }
        }
        fclose(ft);
        break;
        case 2:
        printf("Thanks for using");
        exit(1);
    }
}
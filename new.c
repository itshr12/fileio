#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    FILE *fs,*fa;
    fs=fopen("n1.dat","wb");
    fa=fopen("n1.dat","rb+");
    struct em{
        char name[20];char sur[20];int age;
    };
    struct em e;
    char ch='Y';
    while(ch=='Y')
    {
        printf("enter name,surname,age:");
        scanf("%s%s%d",e.name,e.sur,&e.age);
        fwrite(&e,sizeof(e),1,fs);
        fflush(stdin);
        printf("For More Press Y:");
        ch=fgetchar();
    }
    fclose(fs);
    while(fread(&e,sizeof(e),1,fa)==1)
    {
        printf("%s%s%d\n",e.name,e.sur,e.age);
    }
    printf("Entered Data:\n");
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
        rewind(fa);
        while((fread(&e,rec,1,fa))==1)
        {
            if(strcmp(e.name,na)==0)
            {
                printf("Enter new name,surname,age:");
                scanf("%s%s%d",e.name,e.sur,&e.age);
                fseek(fa,-rec,SEEK_CUR);
                fwrite(&e,sizeof(e),1,fa);
                break;
            }
        }

        fclose(fa);
        break;
        case 2:
        printf("Thanks for using");
        exit(1);
    }
    FILE *ffl;
    ffl=fopen("n1.dat","rb");

    while(fread(&e,sizeof(e),1,ffl)==1)
    {
        printf("%s%s%d\n",e.name,e.sur,e.age);
    }
    fclose(ffl);
}
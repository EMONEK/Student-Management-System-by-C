#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <windows.h>
typedef struct student
{
    int rno;
    char name[20];
    struct subject
    {
        int marks;

    } sub[3];
    int total;
    float per;


} student;

void EndMessage()
{   printf("\n\n");
    printf("\n\t\t\t  =-=-=-=-=-=-=-=-=-=-=-=-=\t\t\t");
    printf("\n\t\t\t  =                       =\t\t\t");
    printf("\n\t\t\t  =          THANK        =\t\t\t");
    printf("\n\t\t\t  =           YOU         =\t\t\t");
    printf("\n\t\t\t  =                       =\t\t\t");
    printf("\n\t\t\t  =-=-=-=-=-=-=-=-=-=-=-=-=\t\t\t");
    printf("\n\n");
}

void headMessage()
{
    printf("\t\t\t#####################################################################");
    printf("\n\t\t\t############                                             ############");
    printf("\n\t\t\t############   Student Management System Project in C    ############");
    printf("\n\t\t\t############                                             ############");
    printf("\n\t\t\t#####################################################################");
    printf("\n\t\t\t-------------------------------------------------------------------\n");
    printf("\n\t\t\t---------------------PROJECT MADE BY EMON KHAN---------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------");
}
///Display message
void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                    WELCOME                =");
    printf("\n\t\t\t        =                      TO                   =");
    printf("\n\t\t\t        =               STUDENT  MANAGEMENT         =");
    printf("\n\t\t\t        =                    SYSTEM                 =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
void create()
{

    student *s;
    FILE *fp;
    int n;
    int i,j;
    printf("Enter How Many Student You Want?: ");
    scanf("%d",&n);
    s = (student*)calloc(n,sizeof(student));
    fp = fopen("Mystudents.txt","w");
    for (i=0; i<n; i++)
    {
        s[i].total=0;
        s[i].per=0;
        printf("Enter RollNo: ");
        scanf("%d",&s[i].rno);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%[^\n]s",s[i].name);
        for (j=0; j<3; j++)
        {
            printf("Enter Marks Of Student %d : ",j+1);
            scanf("%d",&s[i].sub[j].marks);
            s[i].total+=s[i].sub[j].marks;

        }

        s[i].per = s[i].total/3.0;
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}
void display()
{
    student s1;
    FILE *fp;
    int j;
    fp = fopen("Mystudents.txt","r");
    while(fread(&s1,sizeof(student),1,fp))
    {

        printf("\n%-5d%-20s",s1.rno,s1.name);
        for (j=0; j<3; j++)
        {
            printf("%4d",s1.sub[j].marks);


        }
        printf("%5d %7.2f",s1.total,s1.per);
    }

    fclose(fp);
}


void append()
{


    student *s;
    FILE *fp;
    int n;
    int i,j;
    printf("Enter How Many Student You Want?: ");
    scanf("%d",&n);
    s = (student*)calloc(n,sizeof(student));
    fp = fopen("Mystudents.txt","a");
    for (i=0; i<n; i++)
    {
        s[i].total=0;
        s[i].per=0;
        printf("Enter RollNo: ");
        scanf("%d",&s[i].rno);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%[^\n]s",s[i].name);
        for (j=0; j<3; j++)
        {
            printf("Enter Marks Of Student %d : ",j+1);
            scanf("%d",&s[i].sub[j].marks);
            s[i].total+=s[i].sub[j].marks;

        }

        s[i].per = s[i].total/3.0;
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);

}

void no_of_records()
{

    student s1;
    FILE *fp;
    fp = fopen("Mystudents.txt","r");
    fseek(fp,0,SEEK_END);
    int n= ftell(fp)/sizeof(student);
    printf("\n\n Number Of Records Is : %d",n);

}

void search()
{

    student s1;
    FILE *fp;
    int j;
    int rno1;
    int found=0;
    fp = fopen("Mystudents.txt","r");
    printf("Enter RollNo For Search: ");
    scanf("%d",&rno1);

    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.rno==rno1)
        {
            found=1;
            printf("\n%-5d%-20s",s1.rno,s1.name);
            for (j=0; j<3; j++)
            {
                printf("%4d",s1.sub[j].marks);


            }
            printf("%5d %7.2f",s1.total,s1.per);
        }
    }

    if(!found)
    {
        printf("\nRecord Not Found !\n");
    }
    fclose(fp);
}

void update()
{

    student s1;
    FILE *fp,*fp1;
    int j;
    int rno1;
    int found=0;
    fp = fopen("Mystudents.txt","r");
    fp1 = fopen("Temp.txt","w");
    printf("Enter RollNo For Update: ");
    scanf("%d",&rno1);

    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.rno==rno1)
        {
            found=1;
            s1.total=0;
            s1.per=0;

            fflush(stdin);
            printf("Enter New Name : ");
            scanf("%[^\n]s",s1.name);
            for (j=0; j<3; j++)
            {
                printf("Enter New Marks Of Student %d : ",j+1);
                scanf("%d",&s1.sub[j].marks);
                s1.total+=s1.sub[j].marks;

            }

            s1.per = s1.total/3.0;
        }
        fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found)
    {
        fp1 = fopen("Temp.txt","r");
        fp = fopen("Mystudents.txt","w");

        while(fread(&s1,sizeof(student),1,fp1))
        {
            fwrite(&s1,sizeof(student),1,fp);
        }

        fclose(fp);
        fclose(fp1);

    }

    else
    {
        printf("\nRecord Not Found !\n");
    }

}

void deleterec()
{

    student s1;
    FILE *fp,*fp1;
    int j;
    int rno1;
    int found=0;
    fp = fopen("Mystudents.txt","r");
    fp1 = fopen("Temp.txt","w");
    printf("Enter RollNo For Delete: ");
    scanf("%d",&rno1);

    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.rno==rno1)
        {
            found=1;
        }
        else
            fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found)
    {
        fp1 = fopen("Temp.txt","r");
        fp = fopen("Mystudents.txt","w");

        while(fread(&s1,sizeof(student),1,fp1))
        {
            fwrite(&s1,sizeof(student),1,fp);
        }

        fclose(fp);
        fclose(fp1);

    }

    else
    {
        printf("\nRecord Not Found !\n");
    }

}


int main()
{
    int ch;
    SetConsoleTitle("Student Management System | UIU");
    headMessage();
    welcomeMessage();
    printf("\n");
    char array[100]="uiu",array1[100]="";
    char pass[100]="1234", pass1[100]="";
    printf("\n\t\t\tEnter User name : ");
    gets(array1);

    if(strcmp(array,array1)==0)
    {
        printf("\n\t\t\tEnter Password : ");
        gets(pass1);
        if (strcmp(pass,pass1)==0)
        {
            printf("\n\t\t\tLog In Successful\n");


            do
            {
                printf("\n\t1.CREATE");
                printf("\n\t2.DISPLAY");
                printf("\n\t3.APPEND");
                printf("\n\t4.NO OF RECORDS");
                printf("\n\t5.SEARCH");
                printf("\n\t6.UPDATE");
                printf("\n\t7.DELETE");
                printf("\n\t0.Exit\n");

                printf("\n\n   Enter Your Choice :.....");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1:
                    create();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    append();
                    break;
                case 4:
                    no_of_records();
                    break;
                case 5:
                    search();
                    break;
                case 6:
                    update();
                    break;
                case 7:
                    deleterec();
                    break;

                }
            }
            while(ch!=0);

        }
        else
            printf("\n\t\t\tWrong Password!\n");


    }
    else
        printf("\n\t\t\tWrong User Name\n");
        EndMessage();
    return 0;

}






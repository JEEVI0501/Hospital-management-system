
#include<stdio.h>
#include<windows.h>
char e=0;
int t;
int b,valid=0;
void Welcomescreen(void);//Welcome page function
void Title(void);//Hospital title declaration
void MainMenu(void);//MainMenu function
void LoginScreen(void);
void Add_Rec(void);
void gen_bill(void);
void pat_det(void);
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);
void gotoxy(short x,short y)
{
    COORD pos={x,y};//declaring co ordinates in (x,y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

struct patient
{
    char Firstname[20],Lastname[20],Contact_No[15],Gender;
    char Address[70],Email[30],Doctor[20],Report[200];
    int age;
};
struct patient p1,temp;


void main()
{
    WelcomeScreen();
    Title();
    LoginScreen();
}
void WelcomeScreen(void)
{
    printf("\n\n\n\n\n\n\n\t\t\t\t***************************");
    printf("\n\t\t\t\t\tWELCOME TO");
    printf("\n\t\t\t    + SUN HOSPITAL MANAGEMENT SYSTEM +\n");
    printf("\t\t\t\t***************************");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress any key to continue....\n");
    getch();
    system("cls");
}
void Title(void)
{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
    printf("\n\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\t\t\t\t  SUN HOSPITAL    ");
    printf("\n\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}
void MainMenu(void)
{

    system("cls");

    int ch;
    Title();
    printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Generate Bill\n");
	printf("\n\t\t\t\t7. ex_it\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 7:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: Add_Rec();break;
        case 2: pat_det();break;
        case 3: Search_rec();break;
        case 4: Edit_rec();break;
        case 5: Dlt_rec();break;
        case 6: gen_bill();break;
        case 7: ex_it();break;
        default:
              printf("\t\t\tInvalid entry. Please enter right option :)");
              getch();
    }
}
void ex_it(void)
{
      system("cls");
      Title();
      printf("\n\n\n\n\n\t\t\t\t THANK YOU FOR USING THIS SYSTEM :)");
      getch();
}
void LoginScreen(void)
{
    int b=0;
    char Username[20];
    char Password[20];
    char o_Username[20]="Jeevickha";
    char o_Password[20]="Mathi";
    do
    {
        printf("\n\n\n\t\t\tEnter your Username and Password :)");
        printf("\n\n\n\t\t\t\tUSERNAME:");
        scanf("%s",Username);
        printf("\n\n\n\t\t\t\tPASSWORD:");
        scanf("%s",Password);
        if(strcmp(Username,o_Username)==0 && strcmp(Password,o_Password)==0)
        {
            printf("\n\n\n\t\t\t\t\t...Login successful....");
             getch();
             MainMenu();
             break;
        }
        else
        {
            printf("\n\t\t\tIncorrect password...");
            e++;
            getch();
        }
    }
    while(e<=2);

        if(e>2)
    {
        printf("You cannot login now.");
        getch();
        ex_it();
    }
    system("cls");
}
void Add_Rec(void)
{
    system("cls");
    Title();
    FILE *fp;
    fp=fopen("Record.dat","a");
    printf("\n\n\t\t\t***********ADD PATIENTS RECORD*********\n");
    A:printf("\n\t\t\tFirst Name: ");
    scanf("%s",p1.Firstname);
    p1.Firstname[0]=toupper(p1.Firstname[0]);
    if(strlen(p1.Firstname)>20 || strlen(p1.Firstname)<2)
    {
        printf("\n\t Invalid input...");
        goto A;
    }
    else
    {
        for(b=0;b<strlen(p1.Firstname);b++)
        {
            if(isalpha(p1.Firstname[b]))
            {
                valid =1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t\t\t\tInvalid name\n");
            goto A;
        }
    }
    B:printf("\n\t\t\tLast Name: ");
    scanf("%s",p1.Lastname);
    p1.Lastname[0]=toupper(p1.Lastname[0]);
    if(strlen(p1.Lastname)>20 || strlen(p1.Lastname)==0)
    {
        printf("\n\t \t\t\tInvalid input...");
        goto B;
    }
    else
    {
        for(b=0;b<strlen(p1.Lastname);b++)
        {
            if(isalpha(p1.Lastname[b]))
            {
                valid =1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t\t\t\tInvalid Last name\n");
            goto B;
        }
    }
    do
    {
        printf("\n\t\t\tGender[F/M]:");
             scanf(" %c",&p1.Gender);
             if(toupper(p1.Gender)=='M'|| toupper(p1.Gender)=='F')
                   {
                       t=1;
             }
             else
                {t=0;}
             if(!t)
             {
            printf("\n\t\t\t\t\t\t  Invalid Character..\n");
             }
    }while(!t);
     printf("\n\t\t\tAge:");
     scanf("%d",&p1.age);
     do
     {
         C:printf("\n\t\t\tAddress: ");
         scanf(" %s",p1.Address);
         p1.Address[0]=toupper(p1.Address[0]);
         if(strlen(p1.Address)>70 || strlen(p1.Address)<4)
         {
             printf("\n\t \t\t\tInvalid Address....");
             goto C;
         }
     }while(!valid);
     do
     {
         D:printf("\n\t\t\tContact no: ");
         fflush(stdin);
         scanf("%s",p1.Contact_No);
         if(strlen(p1.Contact_No)>10 || strlen(p1.Contact_No)!=10)
         {
             printf("\n\t \t\t\tInvalid Contact number...");
             goto D;
         }
         else
         {
             for(b=0;b<strlen(p1.Contact_No);b++)
             {
                 if(!isalpha(p1.Contact_No[b]))
                     valid=1;
                 else
                  {
                     valid=0;
                      break;
             }
             }
             if(!valid)
             {
                 printf("\n\t\t \t\tInvalid contact number..\n");
                goto D;
             }
             }
         }while(!valid);
        do
         {
             printf("\n\t\t\tEmail: ");
             scanf("%s",p1.Email);
              if (strlen(p1.Email)>30||strlen(p1.Email)<8)
       printf("\n\t\t\t\t\t Invalid Email..\n");
         }
        while(strlen(p1.Email)>30||strlen(p1.Email)<8);
        E:printf("\n\t\t\tReport: ");
           fflush(stdin);
          scanf(" %s",p1.Report);
          p1.Report[0]=toupper(p1.Report[0]);
    if(strlen(p1.Report)>200||strlen(p1.Report)<3)
	{
		printf("\n\t \t\t\tInvalid Report");
		goto E;

	}

    F:printf("\n\t\t\tPrescribed Doctor:");
    fflush(stdin);
    scanf("%s",p1.Doctor);
    p1.Doctor[0]=toupper(p1.Doctor[0]);
    if(strlen(p1.Doctor)>30||strlen(p1.Doctor)<3)
	{
		printf("\n\t Invalid name....\n");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(p1.Doctor);b++)
		{
			if (isalpha(p1.Doctor[b]))
				valid=1;
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Doctor name contain Invalid character :(  Enter again :)");
			goto F;
		}
	}
	fprintf(fp," %s %s %c %i %s %s %s %s %s\n", p1.Firstname, p1.Lastname, p1.Gender, p1.age, p1.Address, p1.Contact_No, p1.Email, p1.Report, p1.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(fp);//fp file is closed
    getch();
    MainMenu();
    }
void pat_det()
{
    int row;
	system("cls");
	Title();
	FILE *fp;
	fp=fopen("Record.dat","r");
	printf("\n\n\t\t\t*********** List Patients Record ****************\n");
	gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(32,15);
		printf("Age");
		gotoxy(37,15);
		printf("Address");
		gotoxy(49,15);
		printf("Contact No.");
		gotoxy(64,15);
		printf("Email");
		gotoxy(88,15);
		printf("Report");
		gotoxy(98,15);
		printf("Prescribed Doctor\n");
		printf("=================================================================================================================");
		row=17;
		while(fscanf(fp,"%s %s %c %d %s %s %s %s %s\n", p1.Firstname, p1.Lastname,&p1.Gender, &p1.age, p1.Address, p1.Contact_No, p1.Email, p1.Report, p1.Doctor)!=EOF)

		{
			gotoxy(1,row);
			printf("%s %s",p1.Firstname, p1.Lastname);
			gotoxy(20,row);
			printf("%c",p1.Gender);
			gotoxy(32,row);
			printf("%d",p1.age);
			gotoxy(37,row);
			printf("%s",p1.Address);
			gotoxy(49,row);
			printf("%s",p1.Contact_No);
			gotoxy(64,row);
			printf("%s",p1.Email);
			gotoxy(88,row);
			printf("%s",p1.Report);
			gotoxy(98,row);
			printf("%s",p1.Doctor);
			row++;
		}
		fclose(fp);
		getch();
		MainMenu();
}
void Search_rec(void)
{
   char name[20];
	system("cls");
	Title();// call Title function
	FILE *fp;
	fp=fopen("Record.dat","r");
	printf("\n\n\t\t\t******** Search Patients Record **************\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(fp,"%s %s %c %i %s %s %s %s %s\n", p1.Firstname, p1.Lastname, &p1.Gender, &p1.age, p1.Address, p1.Contact_No, p1.Email, p1.Report, p1.Doctor)!=EOF)
	{
		if(strcmp(p1.Firstname,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Contact No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(80,15);
			printf("Report");
			gotoxy(95,15);
			printf("Prescribed Doctor\n");
			printf("=================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",p1.Firstname, p1.Lastname);
			gotoxy(25,18);
			printf("%c",p1.Gender);
			gotoxy(32,18);
			printf("%d",p1.age);
			gotoxy(37,18);
			printf("%s",p1.Address);
			gotoxy(52,18);
			printf("%s",p1.Contact_No);
			gotoxy(64,18);
			printf("%s",p1.Email);
			gotoxy(80,18);
			printf("%s",p1.Report);
			gotoxy(95,18);
			printf("%s",p1.Doctor);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(p1.Firstname,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(fp);
	getch();
	MainMenu();

}
void Edit_rec(void)
{
	FILE *fp, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.dat","w+");
	   fp=fopen("Record.dat","r");
	   if(fp==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		MainMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Patient : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);

		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			MainMenu();
		}
		while(fscanf(fp,"%s %s %c %d %s %s %s %s %s\n", p1.Firstname, p1.Lastname, &p1.Gender, &p1.age, p1.Address, p1.Contact_No, p1.Email, p1.Report, p1.Doctor)!=EOF)
		{
			if(strcmp(p1.Firstname, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%d \t%s \t%s \t%s \t%s \t%s\n",p1.Firstname,p1.Lastname,p1.Gender, p1.age,p1.Address,p1.Contact_No,p1.Email,p1.Report,p1.Doctor);
				gotoxy(12,22);
				printf("Enter New First Name: ");
				scanf("%s",p1.Firstname);
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",p1.Lastname);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&p1.Gender);
				p1.Gender=toupper(p1.Gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %d",&p1.age);
				gotoxy(12,30);
				printf("Enter Address: ");
				scanf("%s",p1.Address);
				p1.Address[0]=toupper(p1.Address[0]);
				gotoxy(12,32);
				printf("Enter Contact no: ");
				scanf("%s",p1.Contact_No);
				gotoxy(12,34);
				printf("Enter New email: ");
				scanf("%s",p1.Email);
			    gotoxy(12,36);
				printf("Enter Report: ");
				scanf("%s",p1.Report);
				p1.Report[0]=toupper(p1.Report[0]);
			    gotoxy(12,38);
				printf("Enter Doctor: ");
			    scanf("%s",p1.Doctor);
			    p1.Doctor[0]=toupper(p1.Doctor[0]);
			    printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %d %s %s %s %s %s\n",p1.Firstname,p1.Lastname,p1.Gender, p1.age,p1.Address,p1.Contact_No,p1.Email,p1.Report,p1.Doctor);
				printf("\n\n\t\t\tPatient record updated successfully...");
				}
			}
			else
			{
			fprintf(ft,"%s %s %c %d %s %s %s %s %s\n",p1.Firstname,p1.Lastname,p1.Gender, p1.age,p1.Address,p1.Contact_No,p1.Email,p1.Report,p1.Doctor);
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(fp);
	   remove("Record.dat");
   	   rename("temp2.dat","Record.dat");
		getch();
		MainMenu();
}
void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *fp, *ft;
	ft=fopen("temp_file2.dat","w+");
	fp=fopen("Record.dat","r");
	printf("\n\n\t\t\t************ Delete Patients Record ***************\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);

	while (fscanf(fp,"%s %s %c %d %s %s %s %s %s", p1.Firstname, p1.Lastname, &p1.Gender,
			 &p1.age, p1.Address, p1.Contact_No, p1.Email, p1.Report, p1.Doctor)!=EOF)
	{
		if (strcmp(p1.Firstname,name)!=0)
		fprintf(ft,"%s %s %c %d %s %s %s %s %s\n", p1.Firstname, p1.Lastname, p1.Gender, p1.age, p1.Address, p1.Contact_No, p1.Email, p1.Report, p1.Doctor);
		else
		{
			printf("%s %s %c %i %s %s %s %s %s\n", p1.Firstname, p1.Lastname, p1.Gender, p1.age, p1.Address, p1.Contact_No, p1.Email, p1.Report, p1.Doctor);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		MainMenu();
	}
	else
	{
		fclose(fp);
		fclose(ft);
		remove("Record.dat");
		rename("temp_file2.dat","Record.dat");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		MainMenu();
	}
}
void gen_bill(void)
{
int nm,len,n,i,addmit;
    float amt,tp;
    char Firstname[20],Gender,Address[100],Email[20];
    system("cls");
    struct bill
    {
        int age;
        char m[200],ContactNo[10];
        float p,q;
    }p1,c[100];
    printf("Enter the type of addmission:\n (1 If in general ward\n 2 If in special ward\n 3 If in ICU\n 0 If a regular check up):\n ");
    scanf("%d",&addmit);
    printf("Number of days stayed:");
    scanf("%d",&n);
    switch(addmit)
    {
        case 1: amt=3000;
                break;
        case 2:amt=5000;
                break;
        case 3:amt=10000;
                break;
        default : amt=500;
    }

    printf("\n\t\t SUN HOSPITALS\n\n");

    printf("\nEnter the Patient`s name :");
    scanf("%s",Firstname);
    fflush(stdin);
    a:printf("Enter Gender:");
    scanf(" %c",&Gender);
    if(Gender!='f'&&Gender!='F'&&Gender!='m'&&Gender!='M'&&Gender!='T'&&Gender!='t')
    {
        printf("Invalid Gender!!");
        goto a;
    }
    printf("Enter age: ");
    scanf("%d",&p1.age);
    printf("Enter Address: ");
    scanf(" %s",Address);
    a1:printf("Enter Contact no: ");
    scanf(" %s",p1.ContactNo);
        len=strlen(p1.ContactNo);
        if(len!=10||len<10)
        {
                printf("Invalid contact number!!");
                 goto a1;
        }
    printf("Enter email id: ");
    scanf("%s",Email);
    printf("Enter the no of medicines used:");
    scanf("%d",&nm);
    for(i=1;i<=nm;i++)
    {
        printf("Enter the medicine:");
        scanf("%s",c[i].m);
        printf("Enter the quantity and price:");
        scanf("%f%f",&c[i].q,&c[i].p);
   }
     system("cls");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t|*|SUN HOSPITALS|*|\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("NAME :%s\t\t\tGENDER :%c\nAGE :%d\t\t\t\tE-MAIL ID :%s\nADDRESS :%s\t\tCONTACT NO :%s",Firstname,Gender,p1.age,Email,Address,p1.ContactNo);
    printf("\n----------------------------------------------------------------------------------------------\n");
    printf("Medicine\t\tPrice\t\tQuantity\tTotal price\n");
    for(i=1;i<=nm;i++)
    {
        printf("%s\t\t\t%.2f\t\t%.2f\t\t%.2f\n",c[i].m,c[i].p,c[i].q,c[i].p*c[i].q);
        tp+=c[i].p*c[i].q;
    }
    printf("=================================================================================================================\n");
    printf("Total medicine bill = Rs. %.2f\n",tp);
    printf("=================================================================================================================\n");
    if(n!=0)
    {
        printf("=================================================================================================================\n");
        printf("Total medical bill = Rs. %.2f\n",n*(tp+amt));
        printf("=================================================================================================================\n");
    }
   else
   {
   }
printf("\t\t\t\tThank you\n");
getch();
}




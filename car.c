#include<stdio.h>
#include<string.h>
#include"conio2.h"
#include"car.h"
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
void addAdmin()
{
    FILE *fp;
    fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
fp=fopen("admin.bin","wb");
        User u[2]={{"admin 1","test","Ravi"},{"admin 2","demo","Anil"}};
         fwrite(u,sizeof(u),1,fp);

}

        fclose(fp);

}
User* getInput()
{
    int i;
    clrscr();
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    for(i=0;i<80;i++)
    {
        printf("%c",247);
    }
    gotoxy(32,5);
    printf("* LOGIN PANEL *");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=0;i<80;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,14);
    for(i=0;i<80;i++)
    {
        printf("%c",247);
    }
    gotoxy(61,8);
    textcolor(WHITE);
    printf("press 0 to exit");
    gotoxy(26,10);
    textcolor(LIGHTCYAN);
    printf("Enter Userid:");
    fflush(stdin);
    textcolor(WHITE);
    static User u;
      fgets(u.userId,20,stdin);
      char* pos;
     pos= strchr(u.userId,'\n');
     if(pos!=NULL)
     {
         *pos='\0';
         }
       if (strcmp(u.userId,"0")==0)
       {
           gotoxy(32,17);
           textcolor(LIGHTRED);
           printf("Login Cancelled");
           getch();
        textcolor(YELLOW);
         return NULL;
       }
         gotoxy(26,11);
       textcolor(LIGHTCYAN);
       printf("Enter password:");
       fflush(stdin);
       i=0;
       textcolor(WHITE);
       for(;;)
       {
           u.pwd[i]=getch();
       if(u.pwd[i]==13)
       {
           break;
       }
       else if(u.pwd[i]==8&&i==0)
        continue;
       else if(u.pwd[i]==8)
        {
        printf("\b \b");
        i--;
        continue;
       }
       else
        printf("*");
        i++;
        continue;
    }
       u.pwd[i]='\0';
         if (strcmp(u.pwd,"0")==0)
       {
           gotoxy(32,17);
           textcolor(LIGHTRED);
           printf("Login cancelled");
           gotoxy(32,17);
           printf("\t\t\t\t");
         return NULL;
       }
       else
        return &u;

}


int checkUserExist(User u,char *p)
{
    User x;
    FILE *fp;
    if(strlen(u.userId)==0 || strlen(u.pwd)==0)
    {
        gotoxy(29,18);
        textcolor(LIGHTRED);
        printf("Both Fields Are Mandatory");
        getch();
        gotoxy(29,18);
        printf("\t\t\t\t");
        return 0;
    }
    if(strcmp("admin",p)==0)
        fp=fopen("admin.bin","rb");
    else
        fp=fopen("emp.bin","rb");
    if(fp==NULL)
    {
        gotoxy(29,18);
        textcolor(LIGHTRED);
        printf("Sorry! can not open the file");
        gotoxy(29,18);
        getch();
        printf("\t\t\t\t");
        return -1;
    }
    while(fread(&x,sizeof(x),1,fp)==1)
    {

        if(strcmp(u.userId,x.userId)==0 && strcmp(u.pwd,x.pwd)==0)
        {
            gotoxy(29,19);
            textcolor(GREEN);
            printf("Login Successful!");
            delay(1500);
            gotoxy(29,19);
            printf("\t\t\t\t");
            return 1;
        }
     }
    gotoxy(29,19);
    textcolor(LIGHTRED);
    printf("Invalid Userid or Password");
    getch();
    gotoxy(29,19);
    printf("\t\t\t\t");
    fclose(fp);
    return 0;
}



int adminMenu()
{

int i,choice;
    clrscr();
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,3);
    textcolor(LIGHTCYAN);
   for(i=0;i<80;i++)
        printf("~");
    gotoxy(35,5);
    textcolor(GREEN);
    printf("ADMIN MENU");
    gotoxy(1,7);
    for(i=0;i<80;i++)
        printf("*");
    gotoxy(32,9);
    textcolor(YELLOW);
    printf("1.Add Empolyee");
    gotoxy(32,10);
    printf("2.Add Car Details");
    gotoxy(32,11);
    printf("3.Show Empolyee");
    gotoxy(32,12);
    printf("4.Show Car Details");
    gotoxy(32,13);
    printf("5.Delete Empolyee");
    gotoxy(32,14);
    printf("6.Delete Car Model");
    gotoxy(32,15);
    printf("7.Exit");
    gotoxy(32,17);
    printf("Enter Choice:");
    scanf("%d",&choice);
    return choice;
}
void addEmployee()
{
char temp[10];
char choice;
User u;
char *pos;
FILE *fp=fopen("emp.bin","ab+");
fseek(fp,0,SEEK_END);
long total_rec=ftell(fp)/sizeof(User);
if(total_rec!=0)
{
fseek(fp,-60,SEEK_END);
fread(temp,sizeof(temp),1,fp);
textcolor(LIGHTCYAN);
printf("last emp id is :%s",temp);
pos=strchr(temp,'-');
total_rec=atoi(pos+1);
printf("\ntotal rec is %ld",total_rec);
getch();
}
total_rec++;
sprintf(u.userId,"EMP-%ld",total_rec);
fseek(fp,0,SEEK_END);
do
{
clrscr();
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL APP");
    textcolor(LIGHTGREEN);
    int i;
    gotoxy(1,3);
    for(i=0;i<80;i++)
        printf("~");

        gotoxy(25,5);
        textcolor(WHITE);
        printf("*****Add Employee Details*****");
            gotoxy(1,10);
        textcolor(YELLOW);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        char*pos;
        pos=strchr(u.name,'\n');
        if(pos!=NULL);

        {
            *pos='\0';
        }
        gotoxy(1,12);
        textcolor(YELLOW);
        printf("Enter Employee Passward:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        if(pos!=NULL);
        {
            *pos='\0';
        }
        fwrite(&u,sizeof(u),1,fp);
        textcolor(LIGHTGREEN);
        gotoxy(30,15);
        printf("EMPLOYEE ADDED SUCESSFULLY(%s)",u.name);
        printf("\nEMPLOYEE ID IS %s",u.userId);
        gotoxy(30,20);
        textcolor(LIGHTRED);
        printf("DO YOU WANT TO ADD MORE EMPLOYEE(Y/N):");
    textcolor(WHITE);
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='N'||choice=='n')
    break;
    total_rec++;
    sprintf(u.userId,"EMP-%ld",total_rec);
}while(choice=='Y'||choice=='y');
fclose(fp);
}

void viewEmployee()
    {
        FILE*fp=fopen("emp.bin","rb");
        User ur;
        int i;
        textcolor(YELLOW);
        gotoxy(32,1);
        printf("CAR RENTAL SYSTEM\n");
        for(i=1;i<=80;i++)
            printf("%c",247);
        gotoxy(31,5);
        textcolor(YELLOW);
        printf("EMPLOYEE DETAILS");
        gotoxy(1,7);
        textcolor(LIGHTGREEN);
        for(i=1;i<=80;i++)
            printf("%c",247);
        if(fp==NULL)
        {
            gotoxy(31,9);
            textcolor(LIGHTRED);
            printf("SORRY NO EMPLOYEE ADDED YET!");
            getch();
            return;
        }
        gotoxy(1,8);
        printf("EMPLOYEE ID\t\t\tNAME\t\t\tPASSWORD");
        gotoxy(1,9);
        textcolor(LIGHTGREEN);
        for(i=1;i<=80;i++)
            printf("%c",247);
        int row=10;
        textcolor(YELLOW);
        while(fread(&ur,sizeof(ur),1,fp)==1)
        {
            gotoxy(2,row);
            printf("%s",ur.userId);
            gotoxy(33,row);
            printf("%s",ur.name);
            gotoxy(57,row);
            printf("%s",ur.pwd);
            row++;

        }
        fclose(fp);
        getch();
    }


int deleteEmp()
{
FILE *fp1 =fopen("emp.bin","rb");
char empid[10];
int i,result;
gotoxy(32,1);
textcolor(YELLOW);
printf("CAR RENTAL SYSTEM\n");
for(i=1;i<=80;i++)
{
printf("%c",247);
}
gotoxy(29,5);
printf("* DELETE EMPLOYEE RECORD*");
textcolor(LIGHTGREEN);
gotoxy(1,7);
for(i=1;i<=80;i++)
{
printf("%c",247);
}
gotoxy(1,12);
for(i=1;i<=80;i++)
{
printf("%c",247);
}
if(fp1==NULL)
{
textcolor(LIGHTRED);
gotoxy(32,10);
printf("NO employee added yet");
return -1;
}
FILE *fp2 =fopen("temp.bin","wb");
if(fp2==NULL)
{
textcolor(LIGHTRED);
gotoxy(32,10);
printf("sorry cannot create temp file");
return -1;
}
gotoxy(10,9);
textcolor(YELLOW);
printf("Enter  employee id  to delete the record:");
textcolor(WHITE);
scanf("%s",empid);
User u;
int found =0;
while(fread(&u,sizeof(u),1,fp1)==1)
{
if(strcmp(u.userId,empid)!=0)

    fwrite(&u,sizeof(u),1,fp2);
else
found =1;
}
fclose(fp1);
fclose(fp2);
if(found==0)
{
remove("temp.bin");
gotoxy(10,13);
textcolor(LIGHTRED);
printf(" sorry!employee id not found ");
}
else
{
result = remove("emp.bin");
if(result!=0)
return 2;
result = rename("temp.bin","emp.bin");
if(result!= 0)
return 2;
}
return found;
}


void addCarDetails()
{
    int temp;
Car c;
int i;
char choice,*pos;
FILE *fp=fopen("car.bin","ab+");
fseek(fp,0,SEEK_END);
long total_rec =ftell(fp)/sizeof(Car);
if(total_rec!=0)
{
fseek(fp,-sizeof(c),SEEK_END);
fread(&temp,sizeof(temp),1,fp);
printf("\nlast car id is %d",temp);
getch();

printf("\ntotal car is %ld",total_rec);
total_rec=temp;
getch();
}
total_rec++;
c.car_id=total_rec;
fseek(fp,0,SEEK_END);
do
{
    clrscr();
 gotoxy(32,2);
textcolor(LIGHTRED);
printf("CAR RENTAL APP\n");
textcolor(LIGHTGREEN);
for(i=0;i<80;i++)
{   printf("~");   }
gotoxy(25,6);
textcolor(WHITE);
printf("*****ADD CAR DETAILS*****");
gotoxy(1,9);
textcolor(YELLOW);
printf("Enter Car Model:");
fflush(stdin);
textcolor(WHITE);
fgets(c.car_model,20,stdin);
pos=strchr(c.car_model,'\n');
if(pos!=NULL)
*pos='\0';
gotoxy(1,10);
textcolor(YELLOW);
printf("Enter Car Capacity:");
fflush(stdin);
textcolor(WHITE);
scanf("%d",&c.capacity);
gotoxy(1,11);
textcolor(YELLOW);
printf("Enter Car Count:");
fflush(stdin);
textcolor(WHITE);
scanf("%d",&c.car_count);
gotoxy(1,12);
textcolor(YELLOW);
printf("Enter Car Price/Day");
fflush(stdin);
textcolor(WHITE);
scanf("%d",&c.price);
fwrite(&c,sizeof(c),1,fp);
gotoxy(32,15);
textcolor(LIGHTGREEN);
printf("CAR ADDED SUCESSFULLY\n");
printf("CAR ID IS: %d",c.car_id);
gotoxy(1,18);
textcolor(LIGHTRED);
printf("DO YOU WANT TO ADD MORE CAR(Y/N)?:");
fflush(stdin);
scanf("%c",&choice);
if(choice=='n'||choice=='N')
break;
total_rec++;
c.car_id=total_rec;

}while(choice=='Y'||choice=='y');
fclose(fp);

}



 int deleteCarModel()
  {

FILE *fp1= fopen("car.bin","rb");
int carid;
int result,i;

gotoxy(32,1);
textcolor(YELLOW);
printf("CAR RENTAL SYSTEM\n");
for(i=0;i<80;i++)
printf("%c",247);

gotoxy(31,5);
printf("*DELETE CAR RECORD*");
gotoxy(1,7);
textcolor(LIGHTGREEN);
for(i=0;i<80;i++)
printf("%c",247);
gotoxy(1,12);
for(i=0;i<80;i++)
printf("%c",247);
if(fp1==NULL)
 {
    gotoxy(35,11) ;
    textcolor(LIGHTRED);
    printf("SORRY! NOT CAR PRESENT YET");
    getch();
    return -1;

 }
FILE *fp2=fopen("temp.bin","wb+");

if(fp2==NULL)
    {
    gotoxy(35,11) ;
    textcolor(LIGHTRED);
    printf("SORRY!CANNOT CREAT TEMP FILE");
    getch();
    return -1;
    }
       gotoxy(6,10);
    textcolor(YELLOW);
    printf("Ente Car Model Id to delete the  record:");
    fflush(stdin);
    textcolor(WHITE);
    scanf("%d",&carid);

    Car c;
    int found=0;

    while(fread(&c,sizeof(c),1,fp1)==1)
{

if(c.car_id==carid)
  found=1;
else
fwrite(&c,sizeof(c),1,fp2);

    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("temp.bin");

    }
    else
    {
    result=remove("car.bin");
    if(result!=0)
    return 2;
    result=rename("temp.bin","car.bin");
    if(result!=0)
            return 2;  }
return found;

  }


  void showCarDetails()
{
Car c;
int i;
FILE *fp=fopen("car.bin","rb");

clrscr();
gotoxy(32,1);
textcolor(YELLOW);
printf("CAR RENTAL APP\n");
for(i=0;i<80;i++)
printf("%c",247);
gotoxy(32,5);
printf("*ALL CAR DETAILS*");
gotoxy(1,7);
textcolor(LIGHTGREEN);
for(i=0;i<80;i++)
printf("%c",247);
gotoxy(1,9);
for(i=0;i<80;i++)
printf("%c",247);
gotoxy(2,8);
    if(fp==NULL)
    {
    gotoxy(20,8);
    textcolor(LIGHTRED);
    printf("SORRY! NO CAR PRESENT YET");
    getch();
    return;
    }
printf("CAR ID\t\tMODEL\t\tCAPACITY\tCOUNT\t\tPRICE");
int r=10;
while(fread(&c,sizeof(c),1,fp)==1)
{
gotoxy(2,r);
textcolor(YELLOW);
printf("%d",c.car_id);
gotoxy(17,r);
textcolor(YELLOW);
printf("%s",c.car_model);
gotoxy(35,r);
textcolor(YELLOW);
printf("%d",c.capacity);
gotoxy(50,r);
textcolor(YELLOW);
printf("%d",c.car_count);
gotoxy(65,r);
textcolor(YELLOW);
printf("%d",c.price);
r++;

}
fclose(fp);
getch();
 }

int empMenu()
{   int i;
int choice;
clrscr();
gotoxy(32,2);
textcolor(LIGHTRED);
printf("CAR RENTAL SYSTEM");
gotoxy(35,6);
textcolor(LIGHTGREEN);
printf("EMPLOYEE MENU\n");
for(i=0;i<=80;i++)
            printf("*");
            textcolor(YELLOW);
            gotoxy(32,10);
            printf("1. Rent A Car");
            gotoxy(32,11);
            printf("2. Booking Details");
            gotoxy(32,12);
            printf("3. Available Car Details");
            gotoxy(32,13);
            printf("4. Show All Car Details");
            gotoxy(32,14);
            printf("5. RETURN CAR");
             gotoxy(32,15);
            printf("6. EXIT");
            gotoxy(32,17);
            printf("Ente Choice:");
            scanf("%d",&choice);
            return choice;
            getch();
    }


    int selectCarModel()
{
    int flag;
    int carcount=0;
    FILE *fp=fopen("car.bin","rb");
    Car C;
    int choice,row=9;

    gotoxy(34,row);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            printf("%d . %s",C.car_id,C.car_model);
            gotoxy(34,++row);
            carcount++;
        }
    }
    if(carcount==0)
    {
        fclose(fp);
       return -2;
    }

    gotoxy(34,row+2);
    printf("Enter your choice(0 to exit:)");
    while(1)
    {
        flag=0;
        scanf("%d",&choice);
        if(choice==0)
        {
            fclose(fp);
            return 0;
        }
        rewind(fp);
        while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(C.car_id==choice && C.car_count>0)
            {
                flag=1;
                break;

            }
        }
        if(flag==1)
        {
            fclose(fp);
            return choice;
        }
        else
        {
            gotoxy(37,row+4);
            textcolor(LIGHTRED);
            printf("Wrong Input");
            _getch();
            gotoxy(35,row+4);
            printf("\t\t");
            gotoxy(52,row+2);
            printf("\t");
            gotoxy(52,row+2);
            textcolor(WHITE);

        }
    }

}

int isValidDate(struct tm dt)
{

    if(dt.tm_year>=2021&&dt.tm_year<=2022)
    {
        if(dt.tm_mon>=1&&dt.tm_mon<=12)
        {
            if((dt.tm_mday>=1&&dt.tm_mday<=31)&&(dt.tm_mon==1||dt.tm_mon==3||dt.tm_mon==5||dt.tm_mon==7||dt.tm_mon==8||dt.tm_mon==10||dt.tm_mon==12))
        return 1;

        else if((dt.tm_mday>=1&&dt.tm_mday<=30)&&(dt.tm_mon==4||dt.tm_mon==6||dt.tm_mon==9||dt.tm_mon==11))
            return 1;
        else if((dt.tm_mday>=1&&dt.tm_mday<=28)&&(dt.tm_mon==2))
            return 1;
        else if((dt.tm_mday>=1&&dt.tm_mday<=29)&&dt.tm_mon==2&&(dt.tm_year%400==0||(dt.tm_year%4==0&&dt.tm_year%100!=0)))
        return 1;
        }
        }

   else{
    return 0;
   }


       }

void updateCarCount(int carid)
{
    int x;
    FILE*fp=fopen("car.bin","rb+");
    Car c;
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(c.car_id==carid)
        {
            x=c.car_count;
            --x;
            fseek(fp,-8,SEEK_CUR);
            fwrite(&x,sizeof(int),1,fp);
        break;
        }
    }
    fclose(fp);

    }

    void bookedCarDetails()
    {
        clrscr();
    FILE *fp=fopen("customer.bin","rb");
    Customar_Car_Details CC;
     int i;
     textcolor(YELLOW);
     gotoxy(32,1);
     printf("CAR RENTAL SYSTEM\n");
     for(i=0;i<80;i++)
     {
         printf("%c",247);
     }
     gotoxy(31,5);
     textcolor(YELLOW);
     printf("*BOOKED CAR DETAILS*");

    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf("Model\t   Cust Name\t   Pick Up\t   Drop\t\t  S_Date\tE_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=0;i<80;i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);
       while(fread(&CC,sizeof(Customar_Car_Details),1,fp)==1)
    {
        gotoxy(1,x);
        printf("%s",getCarName(CC.car_id));

        gotoxy(14,x);
        printf("%s",CC.cust_name);

        gotoxy(28,x);
        printf("%s",CC.pick);

         gotoxy(45,x);
        printf("%s",CC.drop);

         gotoxy(59,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(71,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;
    }
    fclose(fp);
    getch();
    }


   char* getCarName(int car_id)
    {
        FILE *fp=fopen("car.bin","rb");
        static Car C;
        while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(C.car_id==car_id)
            {
                break;
            }
        }
        fclose(fp);
        return C.car_model;
    }



    int rentCar()
    {
         Customar_Car_Details CC;
        int c,i;
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR ENTAL SYSTEM");
        textcolor(LIGHTGREEN);
        gotoxy(35,6);
        printf("EMPLOYEE MENU\n");
        for(i=0;i<80;i++)
        {
            printf("*");
        }
        gotoxy(1,17);
        for(i=0;i<80;i++)
        {
            printf("*");
        }
        textcolor(YELLOW);
        gotoxy(32,8);
         c = selectCarModel();

        CC.car_id=c;
        printf("%d",CC.car_id);
        getch();
        if(c==0||c==-2)
            return c;
        clrscr();
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR ENTAL SYSTEM");
        textcolor(LIGHTGREEN);
        gotoxy(35,6);
        printf("EMPLOYEE MENU\n");
        for(i=0;i<80;i++)
        {
            printf("*");
        }
        gotoxy(1,17);
        for(i=0;i<80;i++)
        {
            printf("*");
        }

        textcolor(YELLOW);
        gotoxy(27,9);
        printf("Enter Customer Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(CC.cust_name,30,stdin);
        char*pos;
        pos=strchr(CC.cust_name,'\n');
        *pos='\0';
        gotoxy(27,10);
        textcolor(YELLOW);
        printf("Enter Pick Up Point:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(CC.pick,30,stdin);
        pos=strchr(CC.pick,'\n');
        *pos='\0';
        gotoxy(27,11);
        textcolor(YELLOW);
        printf("Enter Drop Point:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(CC.drop,30,stdin);
        pos=strchr(CC.drop,'\n');
        *pos='\0';
        gotoxy(27,12);
        textcolor(YELLOW);

        printf("Enter start date(dd/mm/yyyy):");
        textcolor(WHITE);
        do
        {
            scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);

          int datevalid2 = isvaliddate2(CC.sd);
          if(datevalid2==1)
                break;
            else

                gotoxy(27,18);
                textcolor(LIGHTRED);
                printf("Wrong Date");
                getch();
                gotoxy(27,18);
                printf("\t\t");
                gotoxy(56,12);
                printf("\t\t\t");
                gotoxy(56,12);
                textcolor(WHITE);

                }while(1);
         gotoxy(27,13);
        textcolor(YELLOW);
        printf("Enter end date(dd/m/yyyy):");
        textcolor(WHITE);
        do
        {
            scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);

            int datevalid3 = isvaliddate3(CC.sd,CC.ed);
          if(datevalid3==1)
            break;
                gotoxy(27,18);
                textcolor(LIGHTRED);
                printf("Wrong Date");
                getch();
                gotoxy(27,18);
                printf("\t\t");
                gotoxy(53,13);
                printf("\t\t");
                gotoxy(53,13);
                textcolor(WHITE);


                }while(1);


                        FILE *fp;
        fp=fopen("Customer.bin","ab");
        if(fp==NULL)
        {
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("sorry!File cannot  be opened");
            getch();
            gotoxy(27,18);
            printf("\t\t");
            return -1;
            }
            fwrite(&CC,sizeof(Customar_Car_Details),1,fp);
            printf("BOOKING DONE:\n For carid: %d",CC.car_id);
            printf("\nPress any key to continue...");
            getch();
            fclose(fp);
            updateCarCount(c);
            bookedCarDetails();
            return 1;

    }

void availCarDetails()
{
    Car c;
int i;
FILE *fp=fopen("car.bin","rb");

clrscr();
gotoxy(32,1);
textcolor(YELLOW);
printf("CAR RENTAL APP\n");
for(i=0;i<80;i++)
printf("%c",247);
gotoxy(32,5);
printf("*AVAILABLE CAR DETAILS*");
gotoxy(1,7);
textcolor(LIGHTGREEN);
for(i=0;i<80;i++)
printf("%c",247);
gotoxy(1,9);
for(i=0;i<80;i++)
printf("%c",247);
gotoxy(2,8);
    if(fp==NULL)
    {
    gotoxy(20,8);
    textcolor(LIGHTRED);
    printf("SORRY! NO CAR PRESENT YET");
    getch();
    return;
    }
printf("CAR ID\t\tMODEL\t\tCAPACITY\tCOUNT\t\tPRICE");
int r=10;
while(fread(&c,sizeof(c),1,fp)==1)
{
    if(c.car_count>0)
{
    gotoxy(2,r);
textcolor(YELLOW);
printf("%d",c.car_id);
gotoxy(17,r);
textcolor(YELLOW);
printf("%s",c.car_model);
gotoxy(35,r);
textcolor(YELLOW);
printf("%d",c.capacity);
gotoxy(50,r);
textcolor(YELLOW);
printf("%d",c.car_count);
gotoxy(65,r);
textcolor(YELLOW);
printf("%d",c.price);
r++;
}

}
fclose(fp);
getch();
 }





 void showAllCarDetails()
 {

     clrscr();
     showCarDetails();
 }


 int isvaliddate2(struct tm dt)
        {

    SYSTEMTIME  stime;
GetSystemTime(&stime);

if(dt.tm_mday>=stime.wDay&&dt.tm_mon>=stime.wMonth&&dt.tm_year>=stime.wYear)
    return 1;
    else if((dt.tm_mday<=stime.wDay&&dt.tm_mon>stime.wMonth&&dt.tm_year>=stime.wYear))
    return 1;
else
    return 0;
                   }




int isvaliddate3(struct tm dt,struct tm dtt)
{
    SYSTEMTIME  stime;
GetSystemTime(&stime);

    if(dtt.tm_mday>=dt.tm_mday&&dtt.tm_mon>=dtt.tm_mon&&dtt.tm_year>=dtt.tm_year)
    return 1;
     else if(dtt.tm_mday<dt.tm_mday&&dtt.tm_mon>dt.tm_mon&&dtt.tm_year>=dt.tm_year)
        return 1;
    else
    return 0;

}

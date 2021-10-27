#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include"car.h"
#include<ctype.h>

int main()
{ int i,n,k;
int result;
int choice;
User* usr;
gotoxy(25,10);
textcolor(YELLOW);
printf("WELCOME TO CAR RENTAL APP");
gotoxy(20,13);
textcolor(GREEN);
printf("* RENT A CAR AND GO WHEREEVER YOU NEED *");
getch();
addAdmin();
while(1)
{
clrscr();
    gotoxy(31,2);
    textcolor(RED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,8);
    textcolor(YELLOW);
for(i=0;i<80;i++)
    printf("*");
gotoxy(1,18);
for(i=0;i<80;i++)
     printf("*");
     gotoxy(32,10);
     textcolor(YELLOW);
     printf("1.ADMIN");
     gotoxy(32,12);
     textcolor(YELLOW);
     printf("2.EMPLOYE");
     gotoxy(32,14);
     textcolor(YELLOW);
     printf("3.QUIT");
     gotoxy(29,16);
     textcolor(WHITE);
     printf("Select Your Role:");
     do
     {
     scanf("%d",&n);
     if(n==1)
     {
         do
         {
     usr = getInput();
     if(usr==NULL)
     break;
     else
     {
         k=checkUserExist(*usr,"admin");
     }

}while(k==0);
         if(k==-1||usr==NULL)
        {
            break;}
         if(k==1)
    {  gotoxy(1,20);
    textcolor(WHITE);
    printf("press any key to continue");
    _getch();
    while(1)
    {

        clrscr();
        choice=adminMenu();
       if(choice==7)
       break;
        switch(choice)
        {
    case 1:
        clrscr();
        addEmployee();
        break;
        case 2:
        clrscr();
        addCarDetails();
        break;
        case 3:
        clrscr();
        viewEmployee();
        break;
        case 4:
        clrscr();
        showCarDetails();
        break;
        case 5:
        clrscr();
        result=deleteEmp();
        gotoxy(15,14);
        if(result==1)
            printf("Record delete sucessfully");
        else if(result==0)
            {
                textcolor(LIGHTRED);
                printf("Record not found in company");  }
        else if(result==2)
        {
        textcolor(LIGHTRED);
        printf("error in deletion");
        }
        gotoxy(6,16);
        textcolor(WHITE);
        printf("press any key to back menu");
        getch();
        break;
        case 6:
        clrscr();
        result=deleteCarModel();
             gotoxy(40,15);
             if(result==0)
             {
                 textcolor(LIGHTRED);
                 printf("Sorry!No Car found for given car id.");
             }
             else if(result==1)
             {
                 textcolor(LIGHTGREEN);
                 printf("Record deleted successfully!");
             }
             else if(result==2)
             {
                 textcolor(LIGHTRED);
                 printf("Sorry!Error in deletion.Try again.");
             }
             textcolor(WHITE);
             printf(       "\n\n\n\n\nPress any key to go back to the main screen:");
             getch();
             break;
        default:
        textcolor(LIGHTRED);
        printf("invalid choice");
        break;
        }


    }   if(choice==7)
        break;


         }
     }


     else if(n==2)
           {
         do
         {
     usr = getInput();
     if(usr==NULL)
     {
    break;
     }
     else
     {
         k=checkUserExist(*usr,"emp");
         printf("%d",k);
     }

     }while(k==0);
     if(k==-1)
        break;
          if(k==1)
    {  gotoxy(1,20);
    textcolor(WHITE);
    printf("press any key to continue");
    _getch();
    while(1)
    {

        clrscr();
        choice=empMenu();
        if(choice==5)
        break;
        switch(choice)
        {
        case 1:
            clrscr();
            int rentresp;
          rentresp = rentCar();

          if(rentresp ==-2)
          {
              gotoxy(35,9);
              textcolor(LIGHTRED);
              printf("Sorry!All Car Booked,Try Later");
              getch();

          }
          else if(rentresp==0)
          {
              gotoxy(29,22);
              textcolor(LIGHTRED);
              printf("YOU DID NOT CHOOSE ANY CAR");
              getch();

           }

          break;

        case 2:
            bookedCarDetails();

            break;
        case 3:
            availCarDetails();
            break;
        case 4:
            showAllCarDetails();
            break;

        default:
            gotoxy(36,18);
             textcolor(LIGHTRED);
        printf("invalid choice");
        getch();
            break;
            //
}
    } if(choice==5)
        break;

           }
           }



     else if(n==3)
     {
         clrscr();
         gotoxy(30,12);
         textcolor(GREEN);
         printf("THANK YOU FOR USING THE APP");
         getch();
         exit(0);
     }
     else
     {
    gotoxy(32,18);
        textcolor(RED);
        printf("invalid choice");
        getch();
        gotoxy(32,18);
        printf("\t\t\t");
        gotoxy(46,15);
        printf("\t\t\t");
        textcolor(WHITE);
        gotoxy(46,15);
        }

}while(1);


}

return 0;

}

#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
struct User
{
    char userId[20];
    char pwd[20];
    char name[20];
};
struct Car
{
    int car_id;
    char car_model[50];
    int capacity;
    int car_count;
    int price;

};
struct Customar_Car_Details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
   struct tm sd;
   struct tm ed;
};
struct return_Car_Details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
   struct tm rd;
   struct tm sd;
   struct tm ed;

};
typedef struct User User;
typedef struct Car Car;
typedef struct Customar_Car_Details Customar_Car_Details;
typedef struct return_Car_Details return_Car_Details;
void addAdmin();
User* getInput();
int checkUserExist(User,char*);
int adminMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
int empMenu();
int selectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void  bookedCarDetails();
int rentCar();
char* getCarName(int);
void availCarDetails();
void showAllCarDetails();
int isvaliddate2();


#endif // CAR_H_INCLUDED

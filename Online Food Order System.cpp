#include <stdio.h>
#include <string.h>
#include <conio.h>
//#include <stdlib.h>
#include <windows.h>

#include<time.h>
#define max 50

int total = 0,count,food_choice, n;
int hotel_choice, search_choice, confirm;
int ch, food, hotel_id;

char name[max];

/*-----------structure for Clients registration-------------*/
typedef struct
{
	char username[max];
	char login_user[max];
	char pass[max];
	char login_pass[max];
	char gmail[max];
	char gen[max];
	char country[max];
}student_registration;
student_registration reg[100];
int reg_count=0;

/*-----------structure for Clients Hotel and Food-------------*/
struct hotels
{
    char hotel[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    int first, second, third, fourth;
};
struct hotels m[100];


COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int ,int);
void Registration_drawRectangle(void);
void Registration_clearWindow(void);
void drawRectangle(void);
void clearWindow(void);
void System_Time(void);
void window(void);
void print_heading(const char st[]);
void Loading(int count);
void Registration_Login(student_registration[],int *);
void get_password(char*);
void login_get_password(char*);
void Menu_List(int);
void Logout(void);
void hotel_initialize(void);
void search_by_hotels(void);
void hotels(int hotel_choice);
void Hotel_1_ForFood(int);
void Hotel_2_ForFood(int);
void Hotel_3_ForFood(int);
void search_by_food();
void food_order(int);
void FoodList();

void cart();
void booking(void);
void Special();

int main()
{



    window();
    Menu_List(count);


}

void gotoxy(int x, int y)
{
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN+FOREGROUND_BLUE);
}

void Loading(int count)
{
	gotoxy(45,17);printf("Loading......");
	gotoxy(45,18);
	for(count=0;count<=35;count++)
	{
		printf("%c",177);
		Sleep(23);
	}
}
void System_Time()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE*FOREGROUND_RED*FOREGROUND_INTENSITY);
	time_t T=time(NULL);
	struct tm tm=*localtime(&T);
	gotoxy(82,2);printf("Date: %02d/%02d/%04d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
	gotoxy(82,3);printf("Time: %02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);

}
void Registration_drawRectangle()
{

    int i, j;
    gotoxy(1,0);
    printf("%c",201);
    for(i = 2; i < 100; i++)
	{
        gotoxy(i, 0);
        printf("%c",205);
        Sleep(10);
    }
    gotoxy(100,0);
    printf("%c",187);
    for(i = 1; i <  28; i++)
	{
        gotoxy(100, i);
        if(i == 6)
		{
            printf("%c",185);
            Sleep(10);
        }
		else
		{
            printf("%c",186);
            Sleep(10);
        }
    }
    gotoxy(100, 28);
    printf("%c",188);
    for(i = 99; i > 0; i--)
	{
        gotoxy(i,28);
        if(i == 35)
		{
            printf("%c",202);
            Sleep(10);
        }
		else
		{
            printf("%c",205);
            Sleep(10);
        }
    }
    gotoxy(1,28);
    printf("%c",200);
    for(i = 27; i > 0; i--)
	{
        gotoxy(1,i);
        if(i == 6)
		{
            printf("%c",204);
            Sleep(10);
        }
		else
		{
            printf("%c",186);
            Sleep(10);
        }
    }

    for(i = 2; i < 100; i++)
	{
    	gotoxy(i,6);
        if(i == 35)
		{
            printf("%c",203);
            Sleep(10);
        }
		else
		{
            printf("%c",205);
            Sleep(10);
        }
    }

    for(i = 7; i < 28; i++)
	{
        gotoxy(35,i);
        printf("%c",186);
        Sleep(10);
    }

}

void Registration_clearWindow()
{
    int i,j;
    for(i = 37; i < 100; i++)
	{
        for(j = 7; j < 28; j++)
		{
            gotoxy(i,j);printf(" ");
        }Sleep(2);
    }
    return;
}
/*-------------------------------Table Rectangle-----------------------------------*/

void drawRectangle()
{
    int c, d;
    gotoxy(1,0);
    printf("%c",201);
    for(c = 2; c < 100; c++)
	{
        gotoxy(c, 0);
        printf("%c",205);
       Sleep(10);
    }
    gotoxy(100,0);
    printf("%c",187);
    for(c = 1; c <  28; c++)
	{
        gotoxy(100, c);
        if(c == 6)
		{
			printf("%c",185);
        }
		else
		{
            printf("%c",186);

        }
        Sleep(10);
    }
    gotoxy(100, 28);
    printf("%c",188);
    for(c = 99; c > 0; c--)
	{
        gotoxy(c,28);
        if(c == 35)
		{
            printf("%c",202);

        }else
		{
            printf("%c",205);
        }
        Sleep(10);
    }
    gotoxy(1,28);
    printf("%c",200);
    for(c = 27; c > 0; c--)
	{
        gotoxy(1,c);
        if(c == 6)
		{
			printf("%c",204);

        }
		else
		{
			printf("%c",186);

        }
        Sleep(10);
    }

    for(c= 2; c < 100; c++)
	{
    	gotoxy(c,6);
        if(c == 35)
		{
            printf("%c",203);

        }
		else
		{
            printf("%c",205);

        }
        Sleep(10);
    }

    for(c = 7; c < 28; c++)
	{
        gotoxy(35,c);
        printf("%c",186);
        Sleep(10);
    }

}
void clearWindow()
{
    int c,d;
    for(c = 37; c < 100; c++)
	{
        for(d = 7; d < 28; d++)
		{
            gotoxy(c,d);printf(" ");
        }Sleep(1);
    }
    return;
}
void window()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED*FOREGROUND_INTENSITY);
	Registration_drawRectangle();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED-FOREGROUND_INTENSITY);
	gotoxy(28,2);
    printf("   ONLINE FOOD ORDER SYSTEM");
    System_Time();
    gotoxy(20,3);
    printf("Daffodil International University, Dhanmondi 32,Dhaka");
    gotoxy(31,4);
    printf("Mahbuba Akhtar,201-35-3049");
    gotoxy(25,24);
    Registration_Login(reg,&reg_count);
	Registration_clearWindow();
	system("cls");
    drawRectangle();
	gotoxy(28,2);
    printf("   ONLINE FOOD ORDER SYSTEM");
    System_Time();
    gotoxy(20,3);
    printf("Daffodil International University, Dhanmondi 32,Dhaka");
    gotoxy(31,4);
    printf("Mahbuba Akhtar,201-35-3049");
    gotoxy(25,24);

}
void print_heading(const char heading[])
{
    gotoxy(45,8);printf("\t\tTITLE : %s",heading);
}
void Registration_Login(student_registration reg[],int *reg_count)
{
    FILE *fp;
    fp = fopen("D:\\record.txt","w");
    if(fp == NULL)
	{
        MessageBoxA(0,"Error in Opening file\nMake sure your file is not write protected","Warning",MB_OK);

    }
	else
	{
		int print = 37;
		int x=7,reg_log_select;
		do
		{
			again:
			gotoxy(x,14);printf("1.Registration");
			gotoxy(x,15);printf("2.Login");
			gotoxy(x,17);printf("Enter your choose-->> ");
			scanf("%d",&reg_log_select);
			Loading(count);
			Registration_clearWindow();
			print_heading("REGISTRATION & LOGIN SYSTEM");
			switch(reg_log_select)
			{
				case 1:
					{
						fflush(stdin);
						gotoxy(print,12);printf("1.Username          :  ");
						gets(reg[*reg_count].username);
						//fputs(reg[*reg_count].username,fp);
						gotoxy(print,13);printf("2.New Password      :  ");
						//gets(reg->pass);
						get_password(reg[*reg_count].pass);
						gotoxy(print,14);printf("3.Confirm Password  :  ");
						//gets(reg->pass);
						get_password(reg[*reg_count].pass);
						gotoxy(print,15);printf("4.E-mail            :  ");
						gets(reg[*reg_count].gmail);
						gotoxy(print,16);printf("5.Gender            :  ");
						gets(reg[*reg_count].gen);
						gotoxy(print,17);printf("6.Nationality       :  ");
						gets(reg[*reg_count].country);
						char design[]={"Thank You! Your Registration Complete."};
						gotoxy(42,19);
						for(count=0;design[count]!='\0';count++)
						{
							printf("%c",design[count]);
							Sleep(50);
						}
						Registration_clearWindow();
						break;
					}
				case 2:
					login_again:
						fflush(stdin);
						gotoxy(print,16);printf("Username   : ");
						gets(reg[*reg_count].login_user);
						gotoxy(print,18);printf("Password   : ");
						login_get_password(reg[*reg_count].login_pass);
						//gets(reg->login_pass);
						if(strcmp(reg[*reg_count].username,reg[*reg_count].login_user)==0 && strcmp(reg[*reg_count].pass,reg[*reg_count].login_pass)==0)
						{
							gotoxy(43,20);printf("Congratulations! Login in Succesful.\n\n");
							gotoxy(45,23);
							char welcome[]={"THANK YOU SO MUCH DEAR STUDENTS.WELCOME TO OUR SYSTEM"};
							for(count=0;welcome[count]!='\0';count++)
							{
								printf("%c",welcome[count]);
								Sleep(50);
							}
						}
						else
						{
							MessageBox(0,"Sorry! Username or Password Error!","Warning",0);
							Beep(384,500);
							Beep(382,500);
							Beep(384,500);
							Beep(382,500);
							Registration_clearWindow();
							goto login_again;
						}
						break;
				default :
							gotoxy(40,15);
							MessageBox(0,"Sorry! Wrong number.Please again input(1 or 2)","Warning",0);

							Beep(384,500);
							Beep(382,500);
							Beep(384,500);
							Beep(382,500);goto again;
			}
		}while(reg_log_select!=2);
	}
    	fclose(fp);
    	return;
}

void get_password(char* pass)
{
    char temp_passP[25];
    int i=0;
    while(1)
    {
        temp_passP[i]=getch();
        if(temp_passP[i]==13)
		{
			break;
		}
        else if(temp_passP[i]==8)
        {
            if(i!=0)
			{

        		i--;
            }
			else
			{
				printf("\a");
			}
        }
        else
        {
            printf("*");
            *(pass+i) = temp_passP[i];
            i++;
        }
        *(pass+i)='\0';
     }
}

void login_get_password(char *login_pass)
{
	char temp_passP[25];
    int i=0;
    while(1)
    {
        temp_passP[i]=getch();
        if(temp_passP[i]==13)
		{
			break;
		}
        else if(temp_passP[i]==8)
        {
            if(i!=0)
			{

        		i--;
            }
			else
			{
				printf("\a");
			}
        }
        else
        {
            printf("*");
            *(login_pass+i) = temp_passP[i];
            i++;
        }
        *(login_pass+i)='\0';
     }
}




void Menu_List(int count)
{
	int x=7;
	again:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN+FOREGROUND_BLUE);
	gotoxy(x,7);
	printf("\t       MENU");
	gotoxy(2,8);
	for(count=0;count<33;count++)
	{
		printf("%c",254);
	}
	gotoxy(2,15);
	char design[]={"  1. Search By Hotels"};
	for(count=0;design[count]!='\0';count++)
	{
		printf("%c",design[count]);
		Sleep(20);
	}
    gotoxy(4,16);
    char desig[]={"  2. Search by Foods"};
	for(count=0;desig[count]!='\0';count++)
	{
		printf("%c",desig[count]);
		Sleep(20);
	}
	gotoxy(6,17);
	char desi[]={"  3. If you want booking"};
	for(count=0;desi[count]!='\0';count++)
	{
		printf("%c",desi[count]);
		Sleep(10);
	}
	gotoxy(6,18);
	char de[]={"   4. Special Foods"};
	for(count=0;de[count]!='\0';count++)
	{
		printf("%c",de[count]);
		Sleep(10);
	}
    gotoxy(8,19);
    char des[]={"   5. Exit"};
	for(count=0;des[count]!='\0';count++)
	{
		printf("%c",des[count]);
		Sleep(10);
	}
	gotoxy(4,22);
	printf("Please enter your choice :  ");
	scanf("%d",&search_choice);
	int dr;
                switch (search_choice)
                {
                	case 1:
                	{
                    	search_by_hotels();
                    	break;
                	}
                	case 2:
                		{
                			search_by_food();
                			break;
						}
					case 3:
                		{

                			booking();
                			break;
						}

					case 4:
                		{
                			Special();
                			break;
						}
					case 5:
                		{
                			MessageBox(0,"Thank you so much.\nCome to again.","Message",0);
                			system("cls");
							exit(0);
						}
                	default:
                		{
                			MessageBox(0,"Sorry! incorrect your choose number\nPlease try again correct number","Warning",0);
                			goto again;

						}


            }

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
}





void hotel_initialize()
{
	gotoxy(42,13);
    strcpy(m[1].hotel, "Deck");
    gotoxy(42,14);
    strcpy(m[1].first_food, "Sandwich");
    gotoxy(42,15);
    strcpy(m[1].second_food, "Pizza");
    gotoxy(42,16);
    strcpy(m[1].third_food, "Fried_Rice");
    m[1].first = 70;
    m[1].second = 100;
    m[1].third = 95;



    strcpy(m[2].hotel, "Sultan's dine");
    strcpy(m[2].first_food, "chicken_Shorma");
    strcpy(m[2].second_food, "Noodles");
    strcpy(m[2].third_food, "Chicken_Rice");
    m[2].first = 120;
    m[2].second = 75;
    m[2].third = 80;


    strcpy(m[3].hotel, "Chillox");
    strcpy(m[3].first_food, "Chicken_Biriyani");
    strcpy(m[3].second_food, "Prawn");
    strcpy(m[3].third_food, "Pasta");
    m[3].first = 90;
    m[3].second =120;
    m[3].third = 100;

}

// Function to implement the search
// by hotels
void search_by_hotels()
{
    hotel_initialize();
    Loading(count);
	clearWindow();
	again:
    print_heading("Search By Hotel Section");
    gotoxy(52,9);
    for(count=0;count<39;count++)
	{
		printf("%c",254);
	}
    fflush( stdin );


    gotoxy(52,13);
    printf("%c\t\t     Hotels \t\t  %c",219,219);

    gotoxy(52,14);
    printf("%c",219);
    for(int i =0;i<=36;i++)
	{
		printf("%c",196);
	}
	gotoxy(90,14);
    printf("%c",219);

    gotoxy(52,11);
	for(int i =0;i<=38;i++)
	{
		printf("%c",177);
	}

	gotoxy(52,12);
    printf("%c",219);
    gotoxy(90,12);
    printf("%c",219);

    gotoxy(52,15);
    printf("%c\t\t1->  %s\t\t  %c",219,m[1].hotel,219);
	gotoxy(52,16);
    printf("%c\t\t2->  %s\t  %c",219,m[2].hotel,219);
    gotoxy(52,17);
    printf("%c\t\t3->  %s\t\t  %c",219, m[3].hotel,219);

	gotoxy(52,18);
    printf("%c\t\t4-> Exit\t\t  %c",219,219);
    gotoxy(52,19);
    printf("%c",219);
    gotoxy(90,19);
    printf("%c",219);

    gotoxy(52,21);
    printf("%c",219);
    gotoxy(90,21);
    printf("%c",219);

    gotoxy(52,22);
	for(int i =0;i<=38;i++)
	{
		printf("%c",177);
	}
	gotoxy(90,20);
    printf("%c",219);
    gotoxy(52,20);
    printf("%c  Please select the hotel number : ",219);
    scanf("%d",&hotel_choice);


    if (hotel_choice > 4)
    {
    	MessageBox(0,"Sorry! incorrect your choose number\n\nPlease try again correct number","Warning",MB_OK);
    	goto again;
    }

    else if (hotel_choice==4)
    {
    	clearWindow();
    	Menu_List(count);
	}
    else
    {
    	clearWindow();
    	hotels(hotel_choice);
	}


}

void hotels(int hotel_choice)
{
    total = 0;
    int food_choice;
    while (1)
    {
		again:
		gotoxy(52,10);
        printf("Foods available in %s",m[hotel_choice].hotel);
        gotoxy(50,11);
        for(count=0;count<36;count++)
		{
			printf("%c",254);
		}

		gotoxy(50,14);
        for(count=0;count<36;count++)
		{
			printf("%c",177);
		}
		gotoxy(50,15);
    	printf("%c",219);
    	gotoxy(85,15);
    	printf("%c",219);

		if(hotel_choice==1)
		{
			gotoxy(50,16);
			printf("%c\t 1-> %s\tRs: %d\t     %c",219,
            m[hotel_choice].first_food,
            m[hotel_choice].first,219);

			gotoxy(50,17);
        	printf("%c\t 2-> %s\tRs: %d\t     %c",219,
            m[hotel_choice].second_food,
            m[hotel_choice].second,219
            );

        	gotoxy(50,18);
       		printf("%c\t 3-> %s\tRs: %d\t     %c",219,m[hotel_choice].third_food,
            m[hotel_choice].third,219);

            gotoxy(50,19);
    		printf("%c",219);
    		gotoxy(85,19);
    		printf("%c",219);

    		gotoxy(50,21);
    		printf("%c",219);
    		gotoxy(50,22);
    		for(count=0;count<36;count++)
			{
				printf("%c",177);
			}
    		gotoxy(85,21);
    		printf("%c",219);

            gotoxy(85,20);
        	printf("%c",219);
            gotoxy(50,20);
        	printf("%c    Please choose the number : ",219);
        	scanf("%d", &food_choice);

            Hotel_1_ForFood(food_choice);

		}
		else if(hotel_choice==2)
		{
			gotoxy(50,16);
			printf("%c\t1-> %s   Rs: %d %c",219,
            m[hotel_choice].first_food,
            m[hotel_choice].first,219);

			gotoxy(50,17);
        	printf("%c\t2-> %s          Rs: %d  %c",219,
            m[hotel_choice].second_food,
            m[hotel_choice].second,219
            );

        	gotoxy(50,18);
       		printf("%c\t3-> %s     Rs: %d  %c",219,m[hotel_choice].third_food,
            m[hotel_choice].third,219);

            gotoxy(50,19);
    		printf("%c",219);
    		gotoxy(85,19);
    		printf("%c",219);

    		gotoxy(50,21);
    		printf("%c",219);
    		gotoxy(50,22);
    		for(count=0;count<36;count++)
			{
				printf("%c",177);
			}
    		gotoxy(85,21);
    		printf("%c",219);

            gotoxy(85,20);
        	printf("%c",219);
            gotoxy(50,20);
        	printf("%c     Please choose the number : ",219);
        	scanf("%d", &food_choice);

            Hotel_2_ForFood(food_choice);
		}
		else if(hotel_choice==3)
		{
			gotoxy(50,16);
			printf("%c   1-> %s   Rs: %d  %c",219,
            m[hotel_choice].first_food,
            m[hotel_choice].first,219);

			gotoxy(50,17);
        	printf("%c   2-> %s\t\t     Rs: %d %c",219,
            m[hotel_choice].second_food,
            m[hotel_choice].second,219
            );

        	gotoxy(50,18);
       		printf("%c   3-> %s\t\t     Rs: %d %c",219,m[hotel_choice].third_food,
            m[hotel_choice].third,219);

            gotoxy(50,19);
    		printf("%c",219);
    		gotoxy(85,19);
    		printf("%c",219);

    		gotoxy(50,21);
    		printf("%c",219);
    		gotoxy(50,22);
    		for(count=0;count<36;count++)
			{
				printf("%c",177);
			}
    		gotoxy(85,21);
    		printf("%c",219);

            gotoxy(85,20);
        	printf("%c",219);
            gotoxy(50,20);
        	printf("%c   Please choose the number : ",219);
        	scanf("%d", &food_choice);
            Hotel_3_ForFood(food_choice);
		}

	}
}

void  Hotel_1_ForFood(int food_choice)
{
		int decrease;
		int payment;
		int x=45;



        if (food_choice==1)
        {
        	clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].first_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    +(n*m[hotel_choice].first);

    		print_heading("Welcome TO Payment Section");
			fflush(stdin);
			gotoxy(56,9);
			for(count=0;count<36;count++)
			{
				printf("%c",254);
			}

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}

    		gotoxy(x,17);
    		printf("Food Name : %s",m[hotel_choice].first_food);
    		gotoxy(x,18);
    		printf("Quantity of food : %d",n);
    		gotoxy(x,19);
    		printf("The price of '%s' is 70 Tk.",m[hotel_choice].first_food);
    		gotoxy(x,20);
    		printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].first_food,total);
    		gotoxy(x,22);
    		again:
    		printf("Please pay your amount : ");

    		scanf("%d",&payment);
    		if(total==payment)
			{
				MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
				clearWindow();
            	search_by_hotels();
			}
			else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(x,17);
        		goto again;

			}

			else if(payment>total)
			{

				MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);


	 		 }


            clearWindow();
            search_by_hotels();
    }

    else if (food_choice == 2)
    {

    		clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].second_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    + (n * m[hotel_choice].second);

    		print_heading("Welcome TO Payment Section");
			fflush( stdin );

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}
    	gotoxy(x,17);
    	printf("Food Name : %s",m[hotel_choice].second_food);
    	gotoxy(x,18);
    	printf("Quantity of food : %d",n);
    	gotoxy(x,19);
    	printf("The price of '%s' is 100 Tk.",m[hotel_choice].second_food);
    	gotoxy(x,20);
    	printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].second_food,total);
    	gotoxy(x,22);
    	again1:
    	printf("Please pay your amount : ");

    	scanf("%d",&payment);
    	if(total==payment)
		{
			MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
			clearWindow();
            search_by_hotels();
		}
		else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(50,17);
        		goto again1;

			}

		else if(payment>total)
		{

			MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);


		}
	}

	else if (food_choice == 3)
    {
    	clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].third_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    + (n * m[hotel_choice].third);

    		print_heading("Welcome TO Payment Section");
			fflush( stdin );

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}
    	gotoxy(x,17);
    	printf("Food Name : %s",m[hotel_choice].third_food);
    	gotoxy(x,18);
    	printf("Quantity of food : %d",n);
    	gotoxy(x,19);
    	printf("The price of '%s' is 95 Tk.",m[hotel_choice].third_food);
    	gotoxy(x,20);
    	printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].third_food,total);
    	gotoxy(x,22);

    	printf("Please pay your amount : ");

    	scanf("%d",&payment);
    	if(total==payment)
		{
			MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
			clearWindow();
            search_by_hotels();
		}
		else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(x,17);
        		goto again1;

			}


		else if(payment>total)
		{
			MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);

		}
	}

}



void  Hotel_2_ForFood(int food_choice)
{
		int decrease;
		int payment;
		int x= 42;

        if (food_choice==1)
        {
        	clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].first_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    + (n * m[hotel_choice].first);

    		print_heading("Welcome TO Payment Section");
			fflush( stdin );

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}

    		gotoxy(x,17);
    		printf("Food Name : %s",m[hotel_choice].first_food);
    		gotoxy(x,18);
    		printf("Quantity of food : %d",n);
    		gotoxy(x,19);
    		printf("The price of '%s' is 120 Tk.",m[hotel_choice].first_food);
    		gotoxy(x,20);
    		printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].first_food,total);
    		gotoxy(x,22);
    		again:
    		printf("Please pay your amount : ");

    		scanf("%d",&payment);
    		if(total==payment)
			{
				MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
				clearWindow();
            	search_by_hotels();
			}
			else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(x,17);
        		goto again;

			}

			else if(payment>total)
			{

				MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);

	 		 }


            clearWindow();
            search_by_hotels();
    }

    else if (food_choice == 2)
    {

    		clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].second_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    + (n * m[hotel_choice].second);

    		print_heading("Welcome TO Payment Section");
			fflush( stdin );

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}
    	gotoxy(x,17);
    	printf("Food Name : %s",m[hotel_choice].second_food);
    	gotoxy(x,18);
    	printf("Quantity of food : %d",n);
    	gotoxy(x,19);
    	printf("The price of '%s' is 75 Tk.",m[hotel_choice].second_food);
    	gotoxy(x,20);
    	printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].second_food,total);
    	gotoxy(x,22);
    	again1:
    	printf("Please pay your amount : ");

    	scanf("%d",&payment);
    	if(total==payment)
		{
			MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
			clearWindow();
            search_by_hotels();
		}
		else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(x,17);
        		goto again1;

			}

		else if(payment>total)
		{
			MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);
		}
	}

	else if (food_choice == 3)
    {
    	clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].third_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    + (n * m[hotel_choice].third);

    		print_heading("Welcome TO Payment Section");
			fflush( stdin );

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}
    	gotoxy(x,17);
    	printf("Food Name : %s",m[hotel_choice].third_food);
    	gotoxy(x,18);
    	printf("Quantity of food : %d",n);
    	gotoxy(x,19);
    	printf("The price of '%s' is 80 Tk.",m[hotel_choice].third_food);
    	gotoxy(x,20);
    	printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].third_food,total);
    	gotoxy(x,22);

    	printf("Please pay your amount : ");

    	scanf("%d",&payment);
    	if(total==payment)
		{
			MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
			clearWindow();
            search_by_hotels();
		}
		else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(x,17);
        		goto again1;

			}


		else if(payment>total)
		{
			MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);
		}
	}

}



void  Hotel_3_ForFood(int food_choice)
{
		int decrease;
		int payment;
		int x= 42;

        if (food_choice==1)
        {
        	clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].first_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    + (n * m[hotel_choice].first);

    		print_heading("Welcome TO Payment Section");
			fflush( stdin );

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}

    		gotoxy(x,17);
    		printf("Food Name : %s",m[hotel_choice].first_food);
    		gotoxy(x,18);
    		printf("Quantity of food : %d",n);
    		gotoxy(x,19);
    		printf("The price of '%s' is 90 Tk.",m[hotel_choice].first_food);
    		gotoxy(x,20);
    		printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].first_food,total);
    		gotoxy(x,22);
    		again:
    		printf("Please pay your amount : ");

    		scanf("%d",&payment);
    		if(total==payment)
			{
				MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
				clearWindow();
            	search_by_hotels();
			}
			else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(x,17);
        		goto again;

			}

			else if(payment>total)
			{

				MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);

	 		 }


            clearWindow();
            search_by_hotels();
    }

    else if (food_choice == 2)
    {

    		clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].second_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    + (n * m[hotel_choice].second);

    		print_heading("Welcome TO Payment Section");
			fflush( stdin );

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}
    	gotoxy(x,17);
    	printf("Food Name : %s",m[hotel_choice].second_food);
    	gotoxy(x,18);
    	printf("Quantity of food : %d",n);
    	gotoxy(x,19);
    	printf("The price of '%s' is 120 Tk.",m[hotel_choice].second_food);
    	gotoxy(x,20);
    	printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].second_food,total);
    	gotoxy(x,22);
    	again1:
    	printf("Please pay your amount : ");

    	scanf("%d",&payment);
    	if(total==payment)
		{
			MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
			clearWindow();
            search_by_hotels();
		}
		else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(x,17);
        		goto again1;

			}

		else if(payment>total)
		{
			MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);
		}
	}

	else if (food_choice == 3)
    {
    	clearWindow();

			gotoxy(42,17);
            printf("Please Enter the quantity of food '%s' : ",m[hotel_choice].third_food);
            scanf("%d", &n);
            clearWindow();
            total = total
                    + (n * m[hotel_choice].third);

    		print_heading("Welcome TO Payment Section");
			fflush( stdin );

			gotoxy(55,14);
    		printf("Money Receipt");
    		gotoxy(52,15);
    		for(int i =0;i<18;i++)
    		{
    			printf("%c",254);
			}
    	gotoxy(x,17);
    	printf("Food Name : %s",m[hotel_choice].third_food);
    	gotoxy(x,18);
    	printf("Quantity of food : %d",n);
    	gotoxy(x,19);
    	printf("The price of '%s' is 100 Tk.",m[hotel_choice].third_food);
    	gotoxy(x,20);
    	printf("The price '%s' total amount of '%d' Tk.",m[hotel_choice].third_food,total);
    	gotoxy(x,22);

    	printf("Please pay your amount : ");

    	scanf("%d",&payment);
    	if(total==payment)
		{
			MessageBox(0,"Congratulations! your payment done","Select",MB_OK);
			clearWindow();
            search_by_hotels();
		}
		else if(payment<total)
			{

				decrease=total-payment;
				//MessageBox(0,"Sorry! Sir, You have to pay more amount","Select",MB_OK);
				clearWindow();
				gotoxy(x,15);
        		printf("Sorry, You have to pay more amount '%d' Tk.",decrease);
        		gotoxy(x,17);
        		goto again1;

			}


		else if(payment>total)
		{
			MessageBox(0,"Sir, You will get some Tk from us.","Message",MB_OK);
		}
	}

}


void search_by_food()
{
	total = 0;


    Loading(count);
	clearWindow();
    print_heading("Search By Food");
    gotoxy(55,9);
    for(count=0;count<33;count++)
	{
		printf("%c",254);
	}
    fflush( stdin );


    gotoxy(68,11);
    printf("Foods");

    gotoxy(52,12);
	for(int i =0;i<=30;i++)
	{
		printf("%c",177);
	}

	int x= 42;
	hotel_initialize();

	while(1) {
		gotoxy(x,14);
		printf("1-> %s\t\t%d  Tk",m[1].first_food, m[1].first);
		gotoxy(x,15);
		printf("2-> %s\t\t%d Tk",m[1].second_food, m[1].second);
		gotoxy(x,16);
		printf("3-> %s\t%d  Tk",m[1].third_food, m[1].third);
		gotoxy(x,17);
		printf("4-> %s\t%d Tk",m[2].first_food, m[2].first);
		gotoxy(x,18);
		printf("5-> %s\t\t%d  Tk",m[2].second_food, m[2].second);
		gotoxy(x,19);
		printf("6-> %s\t%d  Tk",m[2].third_food, m[2].third);
		gotoxy(x,20);
		printf("7-> %s\t%d  Tk",m[3].first_food, m[3].first);
		gotoxy(x,21);
		printf("8-> %s\t\t%d Tk",m[3].second_food, m[3].second);
		gotoxy(x,22);
		printf("9-> %s\t\t%d Tk",m[3].third_food,m[3].third);
		gotoxy(x,23);
		printf("10-> Card");
		gotoxy(x,24);
		printf("11-> Exit");
		gotoxy(x,27);
		printf("Please Enter Your Choice : ");
		scanf("%d",&food);

		if(food==11)
		{
			clearWindow();
			Menu_List(count);
		}
		else if(food==10)
		{
			clearWindow();
			cart();
		}
		else if(food>11)
		{
				MessageBox(0,"Sorry! incorrect your choose number\nPlease try again correct number","Warning",0);
		}
		else
		{
			food_order(food);
		}



	}
}

// Function to implement the food
// order functionality
void food_order(int food)
{
	if (food >= 1 && food <= 3)
		hotel_id = 1;
	else if (food >= 4 && food <= 6)
		hotel_id = 2;
	else
		hotel_id = 3;
	if ((food % 3) == 1) {

		gotoxy(42,25);
		printf("Please Enter the quantity of food '%s' : ",m[hotel_id].first_food);
		scanf("%d", &n);
		total = total + (n * m[hotel_id].first);
		clearWindow();
	}
	else if ((food % 3) == 2) {

		gotoxy(42,25);
		printf("Please Enter the quantity of food '%s' : ",m[hotel_id].second_food);
		scanf("%d", &n);
		total = total + (n * m[hotel_id].second);
		clearWindow();
	}
	else if ((food % 3) == 0) {

		gotoxy(42,25);
		printf("Please Enter the quantity of food '%s' : ",m[hotel_id].third_food);
		scanf("%d", &n);
		total = total + (n * m[hotel_id].third);
		clearWindow();
	}
}

void booking()
{

	//Loading(count);

    print_heading("Booking Food");
    int choice;
    FILE *fp;
    int x= 45;
    again:
    fp = fopen("D://data1.txt","r");
    if(fp==NULL)
    {
        printf("Sorry! Drive is not found");

    }
    else
    {
    	a1:
    	FoodList();
    	char buy;
    	gotoxy(42,18);
    	printf("Do you want to buy food? (y/Y or n/N): ");
    	scanf("%s",&buy);
    	gotoxy(42,20);
    		int c;
    	printf("Please choose the number : ");
    	scanf("%d",&c);
    	clearWindow();

    	if(buy=='y' || buy=='Y')
    	{
    		if(c==1)
    		{
    			gotoxy(x,12);
    			printf("Your booking for Special Biryani");
    			gotoxy(x,13);
    			fflush(stdin);
    			printf("Full Name : ");
    			gets(name);
    			gotoxy(x,14);
    			long int num;
    			printf("Contact Number : ");
    			scanf("%d",&num);

    			gotoxy(x,15);

    			printf("Thank you so much.Order done");


    			gotoxy(x,16);
    			fprintf(fp,"Full Name is '%s'",name);
    			gotoxy(x,17);
    			fprintf(fp,"Contact Number '%ld'",num);
    			time_t T=time(NULL);
				struct tm tm=*localtime(&T);
				gotoxy(x,18);printf("Current Date: %02d/%02d/%04d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
				gotoxy(x,19);printf("Current Time: %02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);

				gotoxy(x,21);
				char con;
				a2:
				printf("Please Continue enter (y): ");
				scanf("%s",&con);
				if(con=='y')
				{
					booking();
				}
				else
				{
						MessageBox(0,"Sorry! incorrect your choose number\nPlease try again correct number","Warning",0);
						goto a2;
				}


			}


			if(c==2)
    		{
    			gotoxy(x,12);
    			printf("Your booking for Special Noodles");
    			gotoxy(x,13);
    			fflush(stdin);
    			printf("Full Name : ");
    			gets(name);
    			gotoxy(x,14);
    			long int num;
    			printf("Contact Number : ");
    			scanf("%d",&num);
    			time_t T=time(NULL);
				struct tm tm=*localtime(&T);
				gotoxy(x,15);printf("Current Date: %02d/%02d/%04d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
				gotoxy(x,16);printf("Current Time: %02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);

				gotoxy(x,18);
				char con;
				a3:
				printf("Please Continue enter (y): ");
				scanf("%s",&con);
				if(con=='y')
				{
					booking();
				}
				else
				{
						MessageBox(0,"Sorry! incorrect your choose number\nPlease try again correct number","Warning",0);
						goto a3;
				}

			}

			if(c==3)
    		{
    			gotoxy(x,12);
    			printf("Your booking for Special Burger");
    			gotoxy(x,13);
    			fflush(stdin);
    			printf("Full Name : ");
    			gets(name);
    			gotoxy(x,14);
    			long int num;
    			printf("Contact Number : ");
    			scanf("%d",&num);
    			time_t T=time(NULL);
				struct tm tm=*localtime(&T);
				gotoxy(x,15);printf("Current Date: %02d/%02d/%04d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
				gotoxy(x,16);printf("Current Time: %02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);

				gotoxy(x,18);
				char con;
				a4:
				printf("Please Continue enter (y): ");
				scanf("%s",&con);
				if(con=='y')
				{
					booking();
				}
				else
				{
						MessageBox(0,"Sorry! incorrect your choose number\nPlease try again correct number","Warning",0);
						goto a4;
				}

			}

			if(c==4)
    		{
    			gotoxy(x,12);
    			printf("Your booking for Special Beef");
    			gotoxy(x,13);
    			fflush(stdin);
    			printf("Full Name : ");
    			gets(name);
    			gotoxy(x,14);
    			long int num;
    			printf("Contact Number : ");
    			scanf("%d",&num);
    			time_t T=time(NULL);
				struct tm tm=*localtime(&T);
				gotoxy(x,15);printf("Current Date: %02d/%02d/%04d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
				gotoxy(x,16);printf("Current Time: %02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);

				gotoxy(x,18);
				char con;
				a5:
				printf("Please Continue enter (y): ");
				scanf("%s",&con);
				if(con=='y')
				{
					booking();
				}
				else
				{
						MessageBox(0,"Sorry! incorrect your choose number\nPlease try again correct number","Warning",0);
						goto a5;
				}

			}

			if(c==5)
    		{
    			gotoxy(x,12);
    			printf("Your booking for Special Mutton");
    			gotoxy(x,13);
    			fflush(stdin);
    			printf("Full Name : ");
    			gets(name);
    			gotoxy(x,14);
    			long int num;
    			printf("Contact Number : ");
    			scanf("%d",&num);
    			time_t T=time(NULL);
				struct tm tm=*localtime(&T);
				gotoxy(x,15);printf("Current Date: %02d/%02d/%04d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
				gotoxy(x,16);printf("Current Time: %02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);

				gotoxy(x,18);
				char con;
				a6:
				printf("Please Continue enter (y): ");
				scanf("%s",&con);
				if(con=='y')
				{
					booking();
				}
				else
				{
						MessageBox(0,"Sorry! incorrect your choose number\nPlease try again correct number","Warning",0);
						goto a6;
				}

			}
			else
			{
				MessageBox(0,"Sorry! incorrect your choose character\nPlease try again correct character","Warning",0);
				booking();
			}


		}




    fclose(fp);

}


}
void cart()
{
	int x=43;
	Loading(count);
	clearWindow();
    print_heading("PAYMENT");
    gotoxy(55,9);
    for(count=0;count<33;count++)
	{
		printf("%c",254);
	}
    fflush( stdin );

    gotoxy(52,12);
	for(int i =0;i<=30;i++)
	{
		printf("%c",177);
	}
	gotoxy(x,15);
	printf("Your Total Order Amount is %d", total);
	gotoxy(x,18);
	printf("Do You wish to order (y=1/n=0): ");
	scanf("%d", &ch);

	if (ch == 1)
	 {
		printf("\n\nThank You for your");
		printf("order!! Your Food is on ");
		search_by_food();
		// exit(1);

	}
	else if (ch == 0) {
		printf("Do You want to exit -1");
		printf("or Go back -0");
		scanf("%d", &confirm);
		if (confirm == 1) {
			printf("\n\nOops! Your order is");
			printf("cancelled!! Exiting..");
			printf("Thank You visit again!\n");
			// exit(1);
			return;
		}
		else {
			printf("\n\nThank You\n\n");
		//login();
		}
	}
	else {
		printf("\n\nPlease Enter the ");
		printf("correct choice\n\n");
		cart();
	}
}
void FoodList()
{
	int x = 42;
	Loading(count);
	clearWindow();
	gotoxy(x,12);
	printf("1-> Special Biryani");
	gotoxy(x,13);
	printf("2-> Special Noodles");
	gotoxy(x,14);
	printf("3-> Special Burger");
	gotoxy(x,15);
	printf("4-> Special Beef");
	gotoxy(x,16);
	printf("5-> Special Mutton");





}

void Special()
{
	Loading(count);
	clearWindow();
    print_heading("SPECIAL FOODS");
    gotoxy(42,12);printf("1-> Special Couple Tea");
    gotoxy(42,13);printf("2-> Special Chickens Sharma");
    gotoxy(42,14);printf("3-> Special Grill Chicken");
    gotoxy(42,20);printf("4-> Go to main Mneu :  ");
    int s;
    scanf("%d",&s);
    if(s==4)
    {
    	clearWindow();
    	Menu_List(count);
	}
	else if(s==1)
	{
		clearWindow();
		gotoxy(42,12);printf("Discount 30% for Specila Couple Tea");

	}
	else if(s==2)
	{
		clearWindow();
		gotoxy(42,12);printf("Discount 25% for Specila Chickens Sharma");
	}
	else if(s==3)
	{
		clearWindow();
		gotoxy(42,12);printf("Discount 35% for Specila Grill Chicken");
	}
	else
	{
			MessageBox(0,"Sorry! incorrect your choose number\nPlease try again correct number","Warning",0);
	}
}



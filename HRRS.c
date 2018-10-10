#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

struct user{
	char userId[8];
	int passward;
	struct user *next;
};
typedef struct user u;

struct room {
	int room_no;
	/* Single : S (1 adult); Double : D (2 adult 1 children); Triple : T (3 adult 2 children );*/
	char type;
	/* 0 or 1 weither available */
	int state;
	struct room *next;
};
typedef struct room r;

struct reservation {
	int room_no;
	char type;
	/* Booking */
	int adults_no;
	int child_no;
	char checkin_date[20];
	char checkout_date[20];
	/* occupants details */
	char name[8];
	int age;
	char gender;
	int ID_number;
	struct reservation *next;
};
typedef struct reservation re;

struct cancellation {
	int room_no;
	char name[8];
	char reason[512];
	struct cancellation *next;
};
typedef struct cancellation c;

void register_();//
int login_(u *u_head);//
void cancel();
void modify();
 /* only admin */
void overView();

void mainMenu() {
	puts("\t***************************************************");
	puts("\t*  WELCOM TO CLOWN HOTEL ROOM RESERVATION SYSTEM! *");
	puts("\t*  Please login! If you do not have an accout");
	puts("\t*  Please register! ");
	puts("\t*  1. Login ");
	puts("\t*  2. Register ");
	puts("\t*  3. Exit the System ");
	puts("\t***************************************************");
}

int SubManu() {
	int c;
	puts("\t***************************************************");
	puts("\t*  Please select your choice !");
	//BOOKING
	puts("\t*  1. Booking the your room.");
	//Cancellation
	puts("\t*  2. Cancel your reservation.");
	//Modify Booking
	puts("\t*  3. Modify your former booking reservation.");
	//View State
	puts("\t*  4. View all your reservations");
	puts("\t***************************************************");
	scanf("%d", &c);
	return c;
}

void BookingManu() {
	puts("\t***************************************************");
	puts("\t* Please fill in details");
	puts("\t* We provide 3 types of rooms: S ; D ; T   ");
	puts("\t* Recommendation : S for single room (1 Adult ); ");
	puts("\t* D for double beds room (2 Adults and 1 child); ");
	puts("\t* T for Triple beds room (3 Adults and 2 children); ");
	puts("\t***************************************************");
}

void register_(u *u_head) {

	u *u_new = (u *)malloc(sizeof(u));
	u_new->next = NULL;
	if(u_new!=NULL){
		puts("\t*Please input the userID : ");
		scanf("%s", &(u_new->userId));
		puts("\t*Please input the Passward : ");
		scanf("%d", &(u_new->passward));
	}
	else
	{
		puts("Fail to register!");
	}
	// insert new node
	u *u_rail = u_head->next;
	while (u_rail->next)
	{
		u_rail = u_rail->next;
	}
	u_rail->next = u_new;

	puts("Register successfully!");
	
	}

void viewUsers_(u *u_head) {
	u *u_pos = u_head->next;
	while (u_pos)
	{
		printf("UserId : %s ; Passward : %d\n", u_pos->userId, u_pos->passward);
		u_pos = u_pos->next;
		if (u_pos == NULL) {
			break;
		}
	}
}

// login
int login_(u *u_head) {
	char userId[8];
	int passward,flag=0;
	puts("please input your userId :");
	scanf("%s", userId);
	puts("please input your passward :");
	scanf("%d", &passward);
	u *u_pos = u_head->next;
	while (u_pos)
	{	
		if((strcmp((u_pos->userId), userId) == 0) && ((u_pos->passward)==passward)) {
			flag = 1;
			break;
		}
		u_pos = u_pos->next;
	}
	return flag;
}

// initialize 50 rooms 
void initialization_(r *r_head) {
	/* initialize fifty rooms with details */
	/* 1-20 */
	r *r_pos = r_head;
	for (int i = 1; i <= 20; i++) {
		r *r_new = (r *)malloc(sizeof(r));
		if (r_new != NULL) {
			r_new->room_no = i;
			r_new->type = 'S';
			r_new->state = 0;
			r_pos->next = r_new;
			r_pos = r_new;
		}
		else
		{
			puts("\t* Fail to apply space!");
		}
	}
	/* 21--40 */
	for (int i = 21; i <= 40; i++) {
		r *r_new = (r *)malloc(sizeof(r));
		if (r_new != NULL) {
			r_new->room_no = i;
			r_new->type = 'D';
			r_new->state = 0;
			r_pos->next = r_new;
			r_pos = r_new;
		}
		else
		{
			puts("\t* Fail to apply space!");
		}
	}
	/* 41-50 */
	for (int i = 41; i <= 49; i++) {
		r *r_new = (r *)malloc(sizeof(r));
		if (r_new != NULL) {
			r_new->room_no = i;
			r_new->type = 'T';
			r_new->state = 0;
			r_pos->next = r_new;
			r_pos = r_new;
		}
		else
		{
			puts("\t* Fail to apply space!");
		}
	}
	// rail
	r *r_rail = (r *)malloc(sizeof(r));
	r_pos->next = r_rail;
	if (r_rail != NULL) {
		r_rail->room_no = 50;
		r_rail->type = 'T';
		r_rail->state = 0;
		r_rail->next = NULL;
	}
	/* -------------------------------------------------- */

}

void viewAllRooms_(r *r_head) {
	r *r_pos = r_head->next;
	while (r_pos)
	{
		printf("Room_no : %d ; Type : %c ; State : %d\n", r_pos->room_no, r_pos->type, r_pos->state);
		r_pos = r_pos->next;
		if (r_pos == NULL) {
			break;
		}
	}
}

void viewAvailableRooms_(r *r_head,re *re_new) {
	r *r_pos = r_head->next;
	while (r_pos)
	{
		puts(" ");
		if (((r_pos->state) == 0) && (strcmp(r_pos->type,re_new->type)==0)) {
			printf("\t* Room_no : %d ; Type : %c ; State : %d\n", r_pos->room_no, r_pos->type, r_pos->state);
			r_pos = r_pos->next;
			if (r_pos == NULL) {
				break;
			}
		}
		else
		{
			puts("NO Available Rooms , Full now ! ");
		}
	}
}

int insert_orders_(r *r_head,re *re_head) {
	re *re_new = (re *)malloc(sizeof(re));
	re_new->next = NULL;
	if (re_new != NULL) {
		puts("\t* Please select your room types : S , D , T   ");
		scanf("%c", &re_new->type);
		puts("\t* Please input the number of Adults and childern (eg: 1,2)");
		scanf("%d,%d", &re_new->adults_no, &re_new->child_no);
		puts("\t* Please input the check-in date (eg: YYYY-MM-DD)");
		scanf("%s", &re_new->checkin_date);
		puts("\t* Please input the check-out date (eg: YYYY-MM-DD)");
		scanf("%s", &re_new->checkout_date);
		puts("\t* For further confirmation, please select your room");
		puts("\t* The following is the list :");

		viewAvailableRooms_(r_head, re_new);

		puts(" ");
		scanf("%d", &re_new->room_no);
		//occupants details
		puts("\t* Please input the your name :");
		scanf("%s", re_new->name);
		puts("\t* Please input the your age :");
		scanf("%d", re_new->age);
		puts("\t* Please input the your gender (eg: 'M' , 'F') ");
		scanf("%c", re_new->gender);
		puts("\t* Please input the your ID number :");
		scanf("%d", re_new->ID_number);
		//insert node
		re *re_rail = re_head;
		while (re_rail->next)
		{
			re_rail = re_rail->next;
		}
		re_rail->next = re_new;
		//change room state
		r *r_pos = r_head;
		while (r_pos)
		{
			if (r_pos->room_no == re_new->room_no) {
				r_pos->state = 1;
				break;
			}
			r_pos = r_pos->next;
		}
	}
	else
	{
		puts("\t* Fail to apply space!");
	}
}


void view_user_orders_(re *re_head) {
	char name[8];
	puts("\t* Please enter your name : ");
	scanf("%s", name);
	re *re_pos = re_head->next;
	while (re_pos)
	{
		puts(" ");
		if (strcmp(re_pos->name, name) == 0) {
			printf("\t* Name : %s , Age : %d", re_pos->name, re_pos->age);
			printf("\t* Gender : %c , ID_number : %d", re_pos->gender, re_pos->ID_number);
			printf("\t* Room_no : %d , Type : %c", re_pos->room_no, re_pos->type);
			printf("\t* Adult_no : %d , Children_no : %d", re_pos->adults_no, re_pos->child_no);
			printf("\t* Checkin_date : %s , Checkin_date : %s", re_pos->checkin_date, re_pos->checkout_date);
		}
		re_pos = re_pos->next;
	}
}

int cancel_orders_(c *c_head,r *r_head,re *re_head) {
	int room_no,result = 0;
	puts("\t* The follwing will be  your reservations : ");
	view_user_orders_(re_head);

	//judgement for reservation exist	
	re *re_pos = re_head;
	if (re_head->next == NULL) {
		puts("\t* There is no reservation to be cancelled!");
		return result;
	}
	puts("\t* Please enter the room_no that will be canceled : ");
	scanf("%d", &room_no);

	//judgement for room exist
	//delete reservation
	while (re_pos->next)
	{
		if (room_no == re_pos->next->room_no) {
			if (re_pos->next->next != NULL) {
				re_pos->next = re_pos->next->next;
				free(re_pos->next);
			}
			else
			{
				re_pos->next = NULL;
				free(re_pos->next);
			}		
			puts("\t* Delete reservation successfully !");
			result = 1;
			break;
		}
		re_pos = re_pos->next;
	}
	if (result == 0) {
		puts("\t* You did not reserve this room !");
		return result;
	}
	//create new cancellation node
	c *c_new = (c *)malloc(sizeof(c));
	c_new->room_no = room_no;
	c_new->next = NULL;
	if (c_new != NULL) {
		puts("\t* Please enter your name : ");
		scanf("%s", c_new->name);
		puts("\t* Please provide the specific reason to cancel reservation :  ");
		scanf("%[^n]s", c_new->reason);
	}
	//insert new c node
	c *c_pos = c_head;
	while (c_pos->next)
	{
		c_pos = c_pos->next;
	}
	c_pos->next = c_new;
	//change room state
	r *r_pos = r_head->next;
	while (r_pos)
	{
		if (c_new->room_no == r_pos->room_no) {
			r_pos->state = 0;
			break;
		}
		r_pos = r_pos->next;
	}
	
}

int modify_orders_(re *re_head) {
	int room_no, result = 0;
	puts("\t* The follwing will be  your reservations : ");
	view_user_orders_(re_head);

	//judgement for reservation exist	
	re *re_pos = re_head;
	if (re_head->next == NULL) {
		puts("\t* There is no reservation to be modified!");
		return result;
	}
	puts("\t* Please enter the room_no that will be modified : ");
	scanf("%d", &room_no);
	//judgement for room exist
	//Modify reservation
	while (re_pos)
	{
		if (room_no == re_pos->room_no) {
			/*-------------------------------------------*/
			puts("\t* Please select your room types : S , D , T   ");
			scanf("%c", &re_pos->type);
			puts("\t* Please input the number of Adults and childern (eg: 1,2)");
			scanf("%d,%d", &re_pos->adults_no, &re_pos->child_no);
			puts("\t* Please input the check-in date (eg: YYYY-MM-DD)");
			scanf("%s", re_pos->checkin_date);
			puts("\t* Please input the check-out date (eg: YYYY-MM-DD)");
			scanf("%s", &re_pos->checkout_date);

			puts(" ");
			//occupants details
			puts("\t* Please input the your name :");
			scanf("%s", re_pos->name);
			puts("\t* Please input the your age :");
			scanf("%d", &re_pos->age);
			puts("\t* Please input the your gender (eg: 'M' , 'F') ");
			scanf("%c", &re_pos->gender);
			puts("\t* Please input the your ID number :");
			scanf("%d", &re_pos->ID_number);

			/*-------------------------------------------*/
			puts("\t* Modify reservation successfully !");
			result = 1;
			break;
		}
		re_pos = re_pos->next;
	}
	if (result == 0) {
		puts("\t* You did not reserve this room !");
		return result;
	}
}

void main() {

	u *u_head = (u *)malloc(sizeof(u));
	r *r_head = (r *)malloc(sizeof(r));
	re *re_head = (re *)malloc(sizeof(re));
	c *c_head = (c *)malloc(sizeof(c));
	u_head->next = NULL;r_head->next = NULL;re_head->next = NULL;c_head->next = NULL;
	u admin = { "admin",123456 };
	u_head->next = &admin;
	initialization_(r_head);
	//viewAllRooms_(r_head);

	while (1)
	{
		mainMenu();
		int choice;
		scanf("%d", &choice);
		if (choice==1)
		{			
			int check=0; 
		LOGIN:
			check = login_(u_head);
			// success login
			if (check == 1) {
				//SubMenu
				int c = 0;
				c = SubManu();
				if (c == 1) {					
					/* Booking */
					BookingManu();
					int a = insert_orders_(r_head, re_head);
				}
				else if (c == 2) {
					//cancellation reservation
					int b = cancel_orders_(c_head, r_head, re_head);
				}
				else if (c == 3) {
					//modify reservation
					int c = modify_orders_(re_head);
				}
				else if (c == 4) {
					//view reservation
					view_user_orders_(re_head);
				}
				else
				{
					puts("\t* Wrong input!!!");
				}	

			}
			else
			{
				puts("Wrong userId or passward! please try again!");
				goto LOGIN;
			}
		}
		else if (choice == 2) {
			register_(u_head);
		}
		else if (choice == 12) {
			viewUsers_(u_head);
		}
		else if (choice == 3) {
			break;
		}
		else
		{
			puts("error!");
		}
	}
	

	_getch();
}
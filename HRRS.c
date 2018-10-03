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
	/* Single Double Triple*/
	char type;
	/* 0 or 1 weither available */
	int state;
	struct room *next;
};
typedef struct room r;

struct reservation {
	int room_no;
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

void register_();
void login_();
void cancel();
void modify();
 /* only admin */
void overView();

int mainMenu() {
	puts("\t***************************************************");
	puts("\t*  WELCOM TO CLOWN HOTEL ROOM RESERVATION SYSTEM! *");
	puts("\t*  Please login! If you do not have an accout");
	puts("\t*  Please register! ");
	puts("\t*  1. Login ");
	puts("\t*  2. Register ");
	int c;
	scanf("/t****%d", &c);
	return c;
}

void initialization(u *u_head, r *r_head) {
	/*admin*/
	u admin = { "admin","admin" };
	u_head->next = &admin; 
	/* initialize fifty rooms with details */
	/* 1-20 */
	r *r_pos = r_head;
	for (int i = 1; i <= 20; i++) {
		r *r_new = (r *)malloc(sizeof(r));
		if (r_new != NULL) {
			r_new->room_no = i;
			r_new->type = "S";
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
			r_new->type = "D";
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
	for (int i = 41; i <= 50; i++) {
		r *r_new = (r *)malloc(sizeof(r));
		if (r_new != NULL) {
			r_new->room_no = i;
			r_new->type = "T";
			r_new->state = 0;
			r_pos->next = r_new;
			r_pos = r_new;
		}
		else
		{
			puts("\t* Fail to apply space!");
		}
	}
	/* -------------------------------------------------- */
	
}

void register_(u *u_head) {
	u *u_pos = u_head->next;
	int count = 0;
	while (u_pos)
	{
		count++;
		u_pos = u_pos->next;
	}

}




void main() {

	u *u_head = (u *)malloc(sizeof(u));
	r *r_head = (r *)malloc(sizeof(r));
	re *re_head = (re *)malloc(sizeof(re));
	c *c_head = (c *)malloc(sizeof(c));
	initialization(u_head, r_head);

	_getch();
}
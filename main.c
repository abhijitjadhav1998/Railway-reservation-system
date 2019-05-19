#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
struct node
{
    char name[30],gender[2],email[50],clas[10];
    char cname[30],cgender[2],cemail[50],cclas[10];
    char tna[100],src[50],dest[50];
    int nop,age,cage,n,adult,child,not,ptno;
    char mobno[20];
    char idno[30],cidno[30];
    char x[10];
    int ttt,tno;
    char source[20],destination[20],date[20],data[100],alltrains[500];
    float fare,cfare,insurance,total,km,arr,dept;
    char adname[50],adpass[50];
	struct node *next;

};

struct pop
{
    int ttt,tno;
    char tna[100],src[50],dest[50];
    float km,arr,dept;
};

struct pop obj;
struct node *head=NULL,*headd=NULL,*p,*r,*last=NULL,*lastt=NULL,*q=NULL,*s=NULL;

int n,m,i;

void book();
void display();
void display1();
void sort();
void searchtrains();
struct node* insert();
struct node* inserttrainsbw();
void write();
void writedatabase();
void writesorteddb();
void readsorteddb();
void read();
void readdatabase();
void deletetrains();
void railwaydatabase();
void inserttrains();
void displaytrains();
void displaysortedtrains();
void modify();
void backup();
void import();
void export1();
void trainenquiry();
void trainselect();
void payout();
void payoutread();
void payoutwrite();
void displaysearchtrainticket();
int count1=0;int count2=0;int count3=0;int count4=0;
void admin();
void readadmin();
void writeadmin();
void adminprofile();
void loggedadmin();
void modifyadmin();
void deleteadmin();
void displayadmin();
int found=0;
int ch,x,c=' ',choice1,choice2;
char str1[20],str2[20],str3[20],str4[20];
char str5[]="admin",str6[]="admin",str7[20],str8[20];
char choice3[]="y",choice4[10],choice5[10];
 char adname[50],adpass[50];char input[255];
 int status1;


int main()
{
    system("color f1");
    FILE *infile;
do{
	printf("\n----------------------------------------------------------------------------\n");
    printf("                     Welcome to Railway Reservation System"                    );
    printf("\n----------------------------------------------------------------------------\n");
    printf("\tLog in as:\n");
    printf(" \n\t\t 1. ADMIN \n\n\t\t 2. USER \n\n\t\t 0. EXIT");
    printf("\n----------------------------------------------------------------------------\n");
    printf("                                                            "                    );
    printf("\n----------------------------------------------------------------------------\n");
    printf("\n\tChoice:\t\t");
    scanf("\t%d",&ch);
    switch(ch)
    {
        case 1:

        printf("\n----------------------------------------------------------------------------\n");
        printf("                     Welcome ADMIN"                    );
        printf("\n----------------------------------------------------------------------------\n");
            readadmin();
            r=headd;
            i=0;
            printf("\n Enter Name:\t");
            scanf("%s",str1);
            printf("\n Enter  Password:\t");
                    while (i<=9)
                    {
                    str2[i]=getch();
                    if(str2[i]==13)
                    break;
                    else printf("*");
                    i++;
                    }
                    str2[i]='\0';
            for(i=1;r!=NULL;i++)
            {
            if((strcmp(r->adname,str1)==0)&&(strcmp(r->adpass,str2)==0))
                {
                strcpy(adname,r->adname);
                strcpy(adpass,r->adpass);
                found=1;
                }
           r=r->next;
            }
            if((found)==1 || ((strcmp(str5,str1)==0) &&( strcmp(str6,str2)==0) ))
            {
        do
        {    system("CLS");
             printf("\n---------------------------------------------\n");
             printf("                   Menu                      ");
             printf("\n---------------------------------------------\n");
             printf("\n\t1. Book ticket\n\t");
              printf("2. Display Booked ticket\n\t3. Railway database");
             printf("\n\t4. Train Enquiry\n\t5. Graphical Analysis\n\t6. Cancel ticket\n\t7. Profile Settings\n\t0. EXIT \n\n\t");
             printf("Choice:\t");
            scanf("%d",&choice1);

                switch(choice1)
                {
                case 0: exit(0);
                        break;
                case 1:
                        system("CLS");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                     Ticket Booking"                    );
                        printf("\n----------------------------------------------------------------------------\n");
                        book();
                        trainselect();
                        payout();

                        break;

                case 2:
                        system("CLS");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                             Booked ticket"                    );
                        printf("\n----------------------------------------------------------------------------\n");
                        display();
                        displaysearchtrainticket();
   						infile=fopen("Booking_reciept.txt","r");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                              FARE DETAILS"                    );
                        printf("\n----------------------------------------------------------------------------\n");
					    do
					      {
					        status1 = fscanf(infile, "%s", &input);
                        printf("\n%s ",input);
					     }while(status1 != -1);
                          printf("\n----------------------------------------------------------------------------\n");
					  	 fclose(infile);
                        break;
                case 3:
                        system("CLS");
                        railwaydatabase();
                        break;
                case 4: system("CLS");
                        trainenquiry();
						break;
                case 5:bysource();
                    break;

                case 6:
                        system("CLS");
                        printf("Your ticket has been canceled");
                        break;
                case 7: system("CLS");
                        adminprofile();
                }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Main Menu] (y/n):\t");
        scanf("%s",&choice4);
        strlwr(choice4);
        }while((strcmp(choice3,choice4))==0);

        }else
        {
        system("CLS");
        printf("\n\n\n\t!! INVALID CREDENTIALS ...... Enter Correct Username And Password !!\n\n");

        }
        break;
    case 2: do
        {    system("CLS");
             printf("\n---------------------------------------------\n");
             printf("                 USER Menu                      ");
             printf("\n---------------------------------------------\n");
             printf("\n\t1. Book ticket\n\t");
              printf("2. Display Booked ticket");
             printf("\n\t3. Train Enquiry\n\t4. Cancel ticket\n\t0. EXIT \n\n\t");
             printf("Choice:\t");
            scanf("%d",&choice1);
                switch(choice1)
                {
                case 0: exit(0);
                        break;
                case 1:
                        system("CLS");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                     Ticket Booking"                    );
                        printf("\n----------------------------------------------------------------------------\n");
                        book();
                        trainselect();
                        payout();
                        break;
                case 2:
                        system("CLS");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                             Booked ticket"                    );
                        printf("\n----------------------------------------------------------------------------\n");
                        display();
                        displaysearchtrainticket();
   						infile=fopen("Booking_reciept.txt","r");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                              FARE DETAILS"                    );
                        printf("\n----------------------------------------------------------------------------\n");
					    do
					      {
					        status1 = fscanf(infile, "%s", &input);
                        printf("\n%s ",input);
					     }while(status1 != -1);
                          printf("\n----------------------------------------------------------------------------\n");
					  	 fclose(infile);
                        break;
                case 3: system("CLS");
                        trainenquiry();
                        break;
                case 4:
                        system("CLS");
                        printf("Your ticket has been canceled");
                        break;
                }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Main Menu] (y/n):\t");
        scanf("%s",&choice4);
        strlwr(choice4);
        }while((strcmp(choice3,choice4))==0);
        break;
    case 0: exit(0);
    }
    }while(!found==1);
}

void adminprofile()
{           do{system("CLS");
             printf("\n---------------------------------------------\n");
             printf("              PROFILE SETTINGS                   ");
             printf("\n---------------------------------------------\n");
             printf("\n\t1. Add Admins\n\t");
                printf("2. Display Admins and Passwords\n\t3. Change Username and Password");
             printf("\n\t4. Delete Admin\n\t0. EXIT \n\n\t");
             printf("Choice:\t");
            scanf("%d",&choice1);
            switch(choice1)
            {
                case 1: system("CLS");
                        loggedadmin();
                        admin();
                        break;
                case 2: system("CLS");
                        loggedadmin();
                        displayadmin();
                        break;
                case 3:system("CLS");
                        loggedadmin();
                        modifyadmin();
                        break;
                case 4:system("CLS");
                        loggedadmin();
                        deleteadmin();
                        break;
                case 0:system("CLS");
                        exit(0);
                break;

            }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\t Want to Continue[Profile Setting] (y/n):\t");
        scanf("%s",&choice4);
        strlwr(choice4);
        }while((strcmp(choice3,choice4))==0);

}

void admin()
{     int i=0;
    readadmin();
char str1[20],str2[20];
 printf("\n Enter New Admin Name:\t");
        scanf("%s",str1);
 printf("\n Enter New Admin Password:\t");
            while (i<=9)
            {
            str2[i]=getch();
            if(str2[i]==13)
            break;
            else printf("*");
            i++;
            }
            str2[i]='\0';
    printf("\n Confirm Password:\t");
            i=0;
            while (i<=9)
            {
            str3[i]=getch();
            if(str3[i]==13)
            break;
            else printf("*");
            i++;
            }
    str3[i]='\0';
    printf("\n Enter LOGGED IN ADMIN PASSWORD:\t");
                i=0;
            while (i<=9)
            {
            str4[i]=getch();
            if(str4[i]==13)
            break;
            else printf("*");
            i++;
            }
    str4[i]='\0';
    if( (strcmp(str2,str3)==0) && ((strcmp(str4,adpass)==0) || (strcmp(str4,str6)==0)))
	{
	    struct node *r;

	r=lastt;
	if(lastt==NULL){
	i=1;
	lastt=(struct node*)malloc(sizeof(struct node));
	lastt->next=NULL;
	strcpy(lastt->adname,str1);
	strcpy(lastt->adpass,str2);
    r=lastt;
	headd=lastt;
	}else
	{

	r=lastt;

	r->next=(struct node*)malloc(sizeof(struct node));
	r=r->next;
	lastt=r;
	strcpy(r->adname,str1);
	strcpy(r->adpass,str2);
    	r->next=NULL;
	}


	writeadmin();
	    printf("\n\t!!   Admin Profile Created Successfully !!");
	}else
	{
	    printf("\n\t!! Oopps !! .... Password Not Matched .....");
	}

}

void readadmin()
{
  int i,filempty=0;
	FILE *py=fopen("Admin.txt","r");
	r=headd;
	fseek(py,0,SEEK_END);
	if(r==NULL)
	{
	r=(struct node*)malloc(sizeof(struct node));
	headd=r;
	}
	int len=(int)ftell(py);
	if(len<=0)
	{
	filempty=1;
	r=NULL;
	headd=r;
	}
	if(filempty==0)
	{
	rewind(py);
	while(fscanf(py,"%s\t%s\n",r->adname,r->adpass))
	{
	if(feof(py))
	{
	break;
	}
	r->next=(struct node*)malloc(sizeof(struct node));
	r=r->next;
	lastt=r;
	r->next=NULL;
	}
	}
	//fclose(py);

}

void writeadmin()
{
    FILE *ppy=fopen("Admin.txt","w");
	int i;
	struct node *tempp;
	tempp=headd;
	if(tempp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	for(i=0;tempp!=NULL;i++)
	{
	fprintf(ppy,"%s\t%s\n",tempp->adname,tempp->adpass);
	tempp=tempp->next;
	}//for
	}//else
	fclose(ppy);
}
void loggedadmin()
{
            printf("\n\n\n---------------------------------------------\n");
            printf("            Logged In Admin:\t");
            printf("%s",adname);
            printf("\n---------------------------------------------\n");

}
void modifyadmin()
{
 struct node *r,*s;
	readadmin();
	int loc,i;
	displayadmin();
	printf("\nEnter the location to Modify:\t");
	scanf("%d",&loc);
	if(r!=NULL)
	{
	    if(loc==1)
    {
        r=headd;
        headd=headd->next;
        writeadmin();
        free(r);
        return(headd);
    }
    else{s=headd;}
    for(i=1;i<loc-1;i++)
    {
        s=s->next;
    }
    r=s->next;
    s->next=r->next;
    writeadmin();
    free(r);
    n=n-1;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}
    readadmin();
	r=headd;
	s=headd;


char str1[20],str2[20];
 printf("\n Enter New Admin Name:\t");
        scanf("%s",str1);
 printf("\n Enter New Admin Password:\t");
             i=0;
            while (i<=9)
            {
            str2[i]=getch();
            if(str2[i]==13)
            break;
            else printf("*");
            i++;
            }
            str2[i]='\0';
    printf("\n Confirm Password:\t");
            i=0;
            while (i<=9)
            {
            str3[i]=getch();
            if(str3[i]==13)
            break;
            else printf("*");
            i++;
            }
    str3[i]='\0';
    printf("\n Enter LOGGED IN ADMIN PASSWORD:\t");
                i=0;
            while (i<=9)
            {
            str4[i]=getch();
            if(str4[i]==13)
            break;
            else printf("*");
            i++;
            }
    str4[i]='\0';
    r=(struct node*)malloc(sizeof(struct node));
    strcpy(r->adname,str1);
	strcpy(r->adpass,str2);

    if(loc==1)
    {
        r->next=headd;
	headd=r;
        writeadmin();
        return(r);
    }
    s=headd;
    for(i=1;i<loc-1;i++)
    {
        if(s!=NULL)
        {
            s=s->next;
        }
    }
    r->next=s->next;
    s->next=r;
    n=n+1;
    writeadmin();
    printf("\n\t!!   Admin Profile Created Successfully !!");


    return(headd);
}


void displayadmin()
{
    readadmin();

	r=headd;
	if(r==NULL)
	{
	printf("list is empty");
	}
	else
	{
	for(i=0;r!=NULL;i++)
	{
    printf("\n\tAdmin Name:\t\t");      //source of travel
    printf("%s",r->adname);
    printf("\t\tPassword:\t\t");      //source of travel
    printf("%s",r->adpass);

    r=r->next;

	}}}

void deleteadmin()
{
 struct node *r,*s;
	readadmin();
	int loc,i;
	displayadmin();
	printf("\nEnter the location to Delete:\t");
	scanf("%d",&loc);
	if(r!=NULL)
	{
	    if(loc==1)
    {
        r=headd;
        headd=headd->next;
        writeadmin();
        free(r);
        return(headd);
    }
    else{s=headd;}
    for(i=1;i<loc-1;i++)
    {
        s=s->next;
    }
    r=s->next;
    s->next=r->next;
    writeadmin();
    free(r);
    n=n-1;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}
	displayadmin();
}

void book()
{    char choice3[]="y",choice4[10],choice5[10];
	read();
	
int valid;
	char dateStr[10];
	struct node *p;
	int i=0,choice;
	p=last;
	if(last==NULL)
	{
	i=1;
	last=(struct node*)malloc(sizeof(struct node));
	last->next=NULL;
	printf("\n\tSource:\t\t");      //source of travel
    scanf("%s",last->source);
    strlwr(last->source);
    printf("\n\tDestination:\t\t");     //destination of travel
    scanf("%s",last->destination);
    strlwr(last->destination);
     do{    
char buffer[5];
char buffer1[5];
char buffer2[5];


    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);
     printf("\n\t\t SYSTEM DATE:\t%d/%d/%d",current_time->tm_mday,(current_time->tm_mon + 1),(current_time->tm_year + 1900));
    
    
    
     int dd, mm, yy;    /* given date */

                 /* flag to indicate date validity */

      

       printf("\n\n\tEnter the Date of travel(dd/mm/yyyy):\t\t");

       scanf("%d/%d/%d", &dd, &mm, &yy);

              /* determine validity of given date */

       valid = 0;

       if (yy != 0) {

               if (mm >= 1 && mm <= 12)  /* check month */

                  {  

                       /* determine number of days in given month */

                       int mdays;

                       if (mm == 2)

                           mdays = (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0) ? 29 : 28;

                      else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)

                                mdays = 30;

                      else mdays = 31;

                      if (dd >= 1 && dd <= mdays)

                         valid = 1;

                  }

          }else{
          	 printf("\n\t\t Invalid Date .....!!!!!!\n");
		  }

                     
        if(valid == 1){
        	if (dd >= current_time->tm_mday && mm >= current_time->tm_mon + 1 && yy >= current_time->tm_year + 1900){
        		char tempdate[1000];
        		//printf("Date is valid : %d %d %d",dd,mm,yy);
        		itoa(dd, buffer, 10);
        		itoa(mm, buffer1, 10);
        		itoa(yy, buffer2, 10);
        		//	printf("Date is valid : %s %s %s",buffer,buffer1,buffer2);
        			strcat(tempdate, buffer);
        			strcat(tempdate,"/");
        			strcat(tempdate,buffer1);
        			strcat(tempdate,"/");
        			strcat(tempdate, buffer2);
        			//printf("Date is : %s ", tempdate);
        		strcat(last->date, tempdate);
			}else{
			  printf("\n\t\t Invalid Date .....!!!!!!\n");
			  valid = 0;
			}
			
		}else{
			 printf("\n\t\t Invalid Date .....!!!!!!\n");
			 valid = 0;
		}
           printf("value of valid in the end = %d",valid );
            
         
             }while(valid == 0);
    system("CLS");
    printf("\n----------------------------------------------------------------------------\n");
    printf("\n\tTotal Number of passenger:\t\t");
    scanf("%d",&(last->n));
    printf("\n\tAdult:\t");
    scanf("%d",&(last->adult));
    last->child=(last->n)-(last->adult);
    printf("\n\tChild:\t%d",last->child);
    printf("\n----------------------------------------------------------------------------\n");
    printf("                             ADULT Details                   "                    );
    printf("\n----------------------------------------------------------------------------\n");
    for(;i<=(last->adult);i++)
    {
        printf("\n\tEnter the Passenger Name:\t");
        scanf("%s",last->name);
        strlwr(last->name);
        do{
            printf("\n\tAge:\t\t");
            scanf("%d",&(last->age));
            if((last->age)<18){
              printf("\n\t\tInvalid AGE ....!!!!!!!\n") ;
            }
        }while((last->age)<18);
        printf("\n\tGender(M/F):\t\t");
        scanf("%s",last->gender);
        strupr(last->gender);

        do{
         printf("\n\tMobile No:\t\t");
        scanf("%s",last->mobno);
        if(strlen(last->mobno)!=10){
              printf("\n\t\tInvalid MOBILE NO ....!!!!!!!\n") ;
        }
        }while(strlen(last->mobno)!=10);

         printf("\n\tEmail id:\t\t");
        scanf("%s",last->email);
        strlwr(last->email);
        do{
         printf("\n\tIdentification no \n(Aadhar no./PAN no./Voting card no.):\t\t");
        scanf("%s",last->idno);
        if(strlen(last->idno)!=10){
        printf("\n\t\tInvalid ID NO ....!!!!!!!\n") ;
        }
    }while(strlen(last->idno)!=10);

        printf("\n\tClass of travel\n (Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t\t");
        scanf("%s",last->clas);
        strupr(last->clas);
    }
    printf("\n----------------------------------------------------------------------------\n");
    printf("                             CHILD Details                   "                    );
    printf("\n----------------------------------------------------------------------------\n");
	i=0;
	for(;i<(last->child);i++)
    {
        printf("\n\tChild Name:\t");
        scanf("%s",last->cname);
        strlwr(last->cname);
         do{
            printf("\n\tAge:\t\t");
            scanf("%d",&(last->cage));
            if((last->cage)>18){
              printf("\n\t\tInvalid AGE ....!!!!!!!\n") ;
            }   }while((last->cage)>18);
        printf("\n\tGender(M/F):\t\t");
        scanf("%s",last->cgender);
        strupr(last->cgender);
         do{
         printf("\n\tIdentification no (Aadhar no.):\t\t");
        scanf("%s",last->cidno);
        if(strlen(last->cidno)!=10){
        printf("\n\t\tInvalid ID NO ....!!!!!!!\n") ;
        }
    }while(strlen(last->cidno)!=10);
        printf("\n\tClass of travel \n\t(Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t");
        scanf("%s",last->cclas);
        strupr(last->cclas);
    }
	p=last;
	head=last;
	}//if
    else{
	p=last;
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	printf("\n\tSource:\t\t");      //source of travel
    scanf("%s",p->source);
    strlwr(p->source);
    printf("\n\tDestination:\t\t");     //destination of travel
    scanf("%s",p->destination);
    strlwr(p->destination);
   do{     _strdate(dateStr);
            printf("\n\t\t SYSTEM DATE:\t%s",dateStr);
            printf("\n\n\tEnter the Date of travel(mm/dd/yy):\t\t");
            scanf("\t%s",p->date);
            if(strcmp((p->date),dateStr) <= 0)
            {
                printf("\n\t\t Invalid Date .....!!!!!!\n");

     }}while(strcmp((p->date),dateStr) <= 0);
    system("CLS");
    printf("\n----------------------------------------------------------------------------\n");
    printf("\n\tTotal Number of passenger:\t\t");
    scanf("%d",&(p->n));
    printf("\n\tAdult:\t");
    scanf("%d",&(p->adult));
    p->child=(p->n)-(p->adult);
    printf("\n\tChild:\t%d",p->child);
    printf("\n----------------------------------------------------------------------------\n");
    printf("                             ADULT Details                   "                    );
    printf("\n----------------------------------------------------------------------------\n");
    for(i=0;i<(p->adult);i++)
    {
        printf("\n\tEnter the Passenger Name:\t");
        scanf("%s",p->name);
        strlwr(p->name);
       do{
            printf("\n\tAge:\t\t");
            scanf("%d",&(p->age));
            if((p->age)<18){
              printf("\n\t\tInvalid AGE ....!!!!!!!\n") ;
            } }while((p->age)<18);
        printf("\n\tGender(M/F):\t\t");
        scanf("%s",p->gender);
        strupr(p->gender);
        do{
         printf("\n\tMobile No:\t\t");
        scanf("%s",p->mobno);
        if(strlen(p->mobno)!=10){
              printf("\n\t\tInvalid MOBILE NO ....!!!!!!!\n") ;
        }
        }while(strlen(p->mobno)!=10);
         printf("\n\tEmail id:\t\t");
        scanf("%s",p->email);
        strlwr(p->email);
        do{
         printf("\n\tIdentification no \n(Aadhar no./PAN no./Voting card no.):\t\t");
        scanf("%s",p->idno);
        if(strlen(p->idno)!=10){
        printf("\n\t\tInvalid ID NO ....!!!!!!!\n") ;
        }
    }while(strlen(p->idno)!=10);
        printf("\n\tClass of travel\n (Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t\t");
        scanf("%s",p->clas);
        strupr(p->clas);
    }
    printf("\n----------------------------------------------------------------------------\n");
    printf("                             CHILD Details                   "                    );
    printf("\n----------------------------------------------------------------------------\n");
	for(i=0;i<(p->child);i++)
    {
         printf("\n\tChild Name:\t");
        scanf("%s",p->cname);
        strlwr(p->cname);
         do{
            printf("\n\tAge:\t\t");
            scanf("%d",&(p->cage));
            if((p->cage)>18){
              printf("\n\t\tInvalid AGE ....!!!!!!!\n") ;
            }
        }while((p->cage)>18);
        printf("\n\tGender(M/F):\t\t");
        scanf("%s",p->cgender);
        strupr(p->cgender);
          do{
         printf("\n\tIdentification no (Aadhar no.):\t\t");
        scanf("%s",p->cidno);
        if(strlen(p->cidno)!=10){
        printf("\n\t\tInvalid ID NO ....!!!!!!!\n") ;
        }
    }while(strlen(p->cidno)!=10);
    printf("\n\tClass of travel \n\t(Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t");
    scanf("%s",p->cclas);
    strupr(p->cclas);
    }
	p->next=NULL;
	}//i for

	    printf("\n----------------------------------------------------------------------------\n");
	printf("\n\n\n1. CONFIRM BOOKING \t2. EDIT TICKET \t3. CANCEL BOOKING\n \t Choice:\t");
	    printf("\n----------------------------------------------------------------------------\n");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:write();
                break;
        case 2:display1();
                printf("\n---------------------------------------");
                printf("\nDo You Want to edit the ticket (y/n):");
                scanf("%s",&choice5);
                strlwr(choice5);
               if((strcmp(choice3,choice5))==0)
               {
                   book();
               }
               else
               {
                   break;
               }
                break;
        case 3: exit(0);
            break;
	}	}//struct nod

void display1()
{
    int i;
	p=head;
	if(p==NULL)
	{
	printf("list is empty");
	}
	else
	{
	for(i=0;p!=NULL;i++)
	{
printf("\n\tSource:\t\t");      //source of travel
    printf("%s",p->source);
    printf("\n\tDestination:\t\t");     //destination of travel
    printf("%s",p->destination);
    printf("\n\tEnter the Date of travel(dd/mm/yyyy):\t\t");
    printf("%s",p->date);
	printf("\n----------------------------------------------------------------------------\n");
    printf("\n\tTotal Number of passenger:\t\t");
    printf("%d",(p->n));
    printf("\n\tAdult:\t");
   printf("%d",(p->adult));
    printf("\n\tChild:\t");
  printf("%d",(p->child));
    printf("\n----------------------------------------------------------------------------\n");
    printf("                             ADULT Details                   "                    );
    printf("\n----------------------------------------------------------------------------\n");
        printf("\n\t Passenger Name:\t");
        printf("%s",p->name);
        printf("\n\tAge:\t\t");
        printf("%d",(p->age));
        printf("\n\tGender(M/F):\t\t");
        printf("%s",p->gender);
        printf("\n\tMobile No:\t\t");
        printf("%s",p->mobno);
         printf("\n\tEmail id:\t\t");
        printf("%s",p->email);
         printf("\n\tIdentification no\n (Aadhar no./PAN no./Voting card no.):\t\t");
        printf("%s",p->idno);
        printf("\n\tClass of travel\n (Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t\t");
        printf("%s",p->clas);
     printf("\n----------------------------------------------------------------------------\n");
    printf("                             CHILD Details                   "                    );
    printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tChild Name:\t");
        printf("%s",p->cname);
        printf("\n\tAge:\t\t");
        printf("%d",(p->cage));
        printf("\n\tGender(M/F):\t\t");
        printf("%s",p->cgender);
        printf("\n\tIdentification no (Aadhar no.):\t\t");
        printf("%s",p->cidno);
        printf("\n\tClass of travel \n\t(Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t");
        printf("%s",p->cclas);
	p=p->next;
	}}}

void display()
{
	read();
	int i;
	p=head;
	if(p==NULL)
	{
	printf("list is empty");
	}
	else
	{
	for(i=0;p!=NULL;i++)
	{
printf("\n\tSource:\t\t");      //source of travel
    printf("%s",p->source);
    printf("\n\tDestination:\t\t");     //destination of travel
    printf("%s",p->destination);
    printf("\n\tEnter the Date of travel(dd/mm/yyyy):\t\t");
    printf("%s",p->date);
	printf("\n----------------------------------------------------------------------------\n");
    printf("\n\tTotal Number of passenger:\t\t");
    printf("%d",(p->n));
    printf("\n\tAdult:\t");
   printf("%d",(p->adult));
    printf("\n\tChild:\t");
  printf("%d",(p->child));
    printf("\n----------------------------------------------------------------------------\n");
    printf("                             ADULT Details                   "                    );
    printf("\n----------------------------------------------------------------------------\n");
        printf("\n\t Passenger Name:\t");
        printf("%s",p->name);
        printf("\n\tAge:\t\t");
        printf("%d",(p->age));
        printf("\n\tGender(M/F):\t\t");
        printf("%s",p->gender);
        printf("\n\tMobile No:\t\t");
        printf("%s",p->mobno);
         printf("\n\tEmail id:\t\t");
        printf("%s",p->email);
         printf("\n\tIdentification no\n (Aadhar no./PAN no./Voting card no.):\t\t");
        printf("%s",p->idno);
        printf("\n\tClass of travel\n (Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t\t");
        printf("%s",p->clas);
     printf("\n----------------------------------------------------------------------------\n");
    printf("                             CHILD Details                   "                    );
    printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tChild Name:\t");
        printf("%s",p->cname);
        printf("\n\tAge:\t\t");
        printf("%d",(p->cage));
        printf("\n\tGender(M/F):\t\t");
        printf("%s",p->cgender);
        printf("\n\tIdentification no (Aadhar no.):\t\t");
        printf("%s",p->cidno);
        printf("\n\tClass of travel \n\t(Sleeper=SL \t AC 2 Tier=2AC\tAC 3 Tier=3AC)\t:\t");
        printf("%s",p->cclas);
	p=p->next;

	}}}

void write()
	{
	FILE *ne=fopen("Ticket_booking.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	printf("\n\t DATA IS BEING SAVED IN DATABASE\n");
	for(i=0;temp!=NULL;i++)
	{
	  fprintf(ne,"%s\n",temp->source);
    fprintf(ne,"%s\n",temp->destination);
    fprintf(ne,"%s\n",temp->date);
    fprintf(ne,"%d\n",temp->n);
    fprintf(ne,"%d\n",temp->adult);
    fprintf(ne,"%d\n",temp->child);
    fprintf(ne,"%s\n",temp->name);
    fprintf(ne,"%d\n",temp->age);
    fprintf(ne,"%s\n",temp->gender);
    fprintf(ne,"%s\n",temp->mobno);
    fprintf(ne,"%s\n",temp->email);
    fprintf(ne,"%s\n",temp->idno);
    fprintf(ne,"%s\n",temp->clas);
    fprintf(ne,"%s\n",temp->cname);
    fprintf(ne,"%d\n",temp->cage);
    fprintf(ne,"%s\n",temp->cgender);
    fprintf(ne,"%s\n",temp->cidno);
    fprintf(ne,"%s\n",temp->cclas);
	temp=temp->next;
	}//for
	printf("\n\t----- DONE ----- DATA SAVED SUCCESSFULLY\n");
	}//else
	fclose(ne);
	}

void read()
	{
	int i,filempty=0;
	FILE *infile=fopen("Ticket_booking.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	printf("\nFile empty\n");
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"%s\n",p->source),
    fscanf(infile,"%s\n",p->destination),
    fscanf(infile,"%s\n",p->date),
    fscanf(infile,"%d\n",&p->n),
    fscanf(infile,"%d\n",&p->adult),
    fscanf(infile,"%d\n",&p->child),
    fscanf(infile,"%s\n",p->name),
    fscanf(infile,"%d\n",&p->age),
    fscanf(infile,"%s\n",p->gender),
    fscanf(infile,"%s\n",p->mobno),
    fscanf(infile,"%s\n",p->email),
    fscanf(infile,"%s\n",p->idno),
    fscanf(infile,"%s\n",p->clas),
    fscanf(infile,"%s\n",p->cname),
    fscanf(infile,"%d\n",&p->cage),
    fscanf(infile,"%s\n",p->cgender),
    fscanf(infile,"%s\n",p->cidno),
    fscanf(infile,"%s\n",p->cclas))
	{
	if(feof(infile))
	{
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
	}}
	}
void railwaydatabase()
{                do{
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                        MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. Add trains \n");
                printf("\t2. Insert train at specific location\n");
                printf("\t3. Sort the trains\n");
                printf("\t4. Delete the trains \n");
                printf("\t5. Search the trains \n");
                printf("\t6. Modify the trains \n");
                printf("\t7. Display the trains \n");
                printf("\t8. Database backup \n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: system("CLS");
                            inserttrains();
                      printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
                            getch();
                            break;
                    case 2: system("CLS");
                            displaytrains();
                            inserttrainsbw();
                    printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
                            getch();

                            break;
                    case 3: system("CLS");
                            sorttrains();
                            displaysortedtrains();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 4: system("CLS");
                            displaysortedtrains();
                            deletetrains();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 5: system("CLS");
                            displaysortedtrains();
                            searchtrains();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 6: system("CLS");
                            displaysortedtrains();
                            modify();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 7: system("CLS");
                            specialtraindisplay();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 8: system("CLS");
                            backup();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                }
                }while(choice2!=0);
}

void inserttrains()
{   do{
    readdatabase();

    found=0;
    p=head;
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
    scanf("\t%d %s %s %s %f %f %f %d",&(obj.tno),obj.src,obj.dest,obj.tna,&(obj.km),&(obj.arr),&(obj.dept),&(obj.ttt));
    strlwr(obj.src),strlwr(obj.dest),strlwr(obj.tna);
                            for(i=1;p!=NULL;i++)
                            {
                            if(p->tno==obj.tno)
                            {
    printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                            found=1;
                            printf("\n\t\t Oopps  !!!  Train Already Present ....\n") ;
                            }
                            p=p->next;

                            }}while(found==1);



    struct node *p;
	int i=0;
	p=last;
	if(last==NULL)
	{
	i=1;
	last=(struct node*)malloc(sizeof(struct node));
	last->next=NULL;
	last->tno=obj.tno;
    strcpy(last->src,obj.src);
    strcpy(last->dest,obj.dest);
    strcpy(last->tna,obj.tna);
    last->km=obj.km;
    last->arr=obj.arr;
    last->dept=obj.dept;
    last->ttt=obj.ttt;
	p=last;
	head=last;
	}//if
else{i=0;
	p=last;
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
    p->tno=obj.tno;
    strcpy(p->src,obj.src);
    strcpy(p->dest,obj.dest);
    strcpy(p->tna,obj.tna);
    p->km=obj.km;
    p->arr=obj.arr;
    p->dept=obj.dept;
    p->ttt=obj.ttt;
	p->next=NULL;
	}//i for
   writedatabase();
                         printf("\n\n\t\tTrain Added Successfully ....!!!!!!!\n\n") ;

}

void specialtraindisplay()
{
     do{
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                    DISPLAY MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. Unsorted trains \n");
                printf("\t2. Sorted trains\n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: system("CLS");
                            readdatabase();
                             p=head;
                            if(p==NULL)
                            {
                            printf("list is empty");
                            }
                            else
                                {
                            printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
                            printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
                            printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
                            for(i=0;p!=NULL;i++)
                            {
                            printf("\n%d\t %s\t\t %s\t\t %s\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                            p=p->next;
                            }}
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 2: system("CLS");
                            readsorteddb();
                            p=head;
                            if(p==NULL)
                            {
                            printf("list is empty");
                            }
                            else
                                {
                            printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
                            printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
                            printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
                            for(i=0;p!=NULL;i++)
                            {
                            printf("\n%d\t %s\t\t %s\t\t %s\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                            p=p->next;
                            }}
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;

                }
                }while(choice2!=0);

}


void displaytrains()
{
    readdatabase();
	p=head;
	if(p==NULL)
	{
	printf("list is empty");
	}
	else
{
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
    for(i=0;p!=NULL;i++)
	{
 printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
	p=p->next;
	}}}

void writedatabase()
	{
	FILE *ne=fopen("Railway_database.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("Empty File");
	}
	else
	{
	for(i=0;temp!=NULL;i++)
	{
fprintf(ne,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",(temp->tno),temp->src,temp->dest,temp->tna,temp->km,temp->arr,temp->dept,(temp->ttt));
   temp=temp->next;
	}//for
	}//else
	fclose(ne);
	}

void readdatabase()
	{
	int i,filempty=0;
	FILE *infile=fopen("Railway_database.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	printf("File empty");
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",&(p->tno),p->src,p->dest,p->tna,&(p->km),&(p->arr),&(p->dept),&(p->ttt)))
{
	if(feof(infile))
	{
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
}}}
struct node* inserttrainsbw()
{
    readdatabase();
    int i,loc;
    int tno,ttt;
    char tna[100],src[50],dest[50];
    float arr,dept,km;
    printf("\nEnter the position:");
    scanf("%d",&loc);
   do{
        readdatabase();
    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No || Source || Destination || Train name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n---------------------------------------------------------------------------------------------------------------------\n   ");
    scanf("\t%d %s %s %s %f %f %f %d",&(tno),src,dest,tna,&(km),&(arr),&(dept),&(ttt));
    strlwr(src),strlwr(dest),strlwr(tna);
    found=0;
    p=head;
    for(i=1;p!=NULL;i++)
                            {
                            if(p->tno==tno)
                            {
    printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                            found=1;
                            printf("\n\t\t Oopps  !!!  Train Already Present ....\n") ;
                            }
                            p=p->next;

                            }}while(found==1);

    p=head;
	q=head;
    p=(struct node*)malloc(sizeof(struct node));
    p->tno=tno;
    strcpy(p->src,src);
    strcpy(p->dest,dest);
    strcpy(p->tna,tna);
    p->km=km;
    p->arr=arr;
    p->dept=dept;
    p->ttt=ttt;
    p->next=NULL;
    if(loc==1)
    {
        p->next=head;
	head=p;
        writedatabase();
        return(p);
    }
    q=head;
    for(i=1;i<loc-1;i++)
    {
        if(q!=NULL)
        {
            q=q->next;
        }
    }
    p->next=q->next;
    q->next=p;
    n=n+1;
    writedatabase();
                             printf("\n\n\t\tTrain Added Successfully ....!!!!!!!\n\n") ;

    return(head);
}

void sorttrains()
	{
	int k;
	readdatabase();
	int temp;
	struct node *i,*j;
	for(i=head;i!=NULL;i=i->next)
	{
        for(j=i->next;j!=NULL;j=j->next)
        {
            if((i->tno)>(j->tno))			//write integer variable only in place of data
            {
                obj.tno=i->tno;
                obj.km=i->km;
                obj.arr=i->arr;
                obj.dept=i->dept;
                obj.ttt=i->ttt;

                i->tno=j->tno;
                i->km=j->km;
                i->arr=j->arr;
                i->dept=j->dept;
                i->ttt=j->ttt;

                j->tno=obj.tno;
                j->km=obj.km;
                j->arr=obj.arr;
                j->dept=obj.dept;
                j->ttt=obj.ttt;

                strcpy(obj.src,i->src);
                strcpy(i->src,j->src);
                strcpy(j->src,obj.src);
                strcpy(obj.dest,i->dest);
                strcpy(i->dest,j->dest);
                strcpy(j->dest,obj.dest);
                strcpy(obj.tna,i->tna);
                strcpy(i->tna,j->tna);
                strcpy(j->tna,obj.tna);

             }}}//i for

	writesorteddb();
	}//void sort

void writesorteddb()
	{
	FILE *ne=fopen("Sorted_Railway_database.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	for(i=0;temp!=NULL;i++)
	{
		fprintf(ne,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",(temp->tno),temp->src,temp->dest,temp->tna,temp->km,temp->arr,temp->dept,(temp->ttt));
    temp=temp->next;
	}//for
	}//else
	fclose(ne);
	}

void readsorteddb()
	{
	int i,filempty=0;
	FILE *infile=fopen("Sorted_Railway_database.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	printf("File empty");
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",&(p->tno),p->src,p->dest,p->tna,&(p->km),&(p->arr),&(p->dept),&(p->ttt)))
{
	if(feof(infile))
	{
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
}}}

void displaysortedtrains()
{
	readsorteddb();
	int i;
	p=head;
	if(p==NULL)
	{
	printf("list is empty");
	}
	else
		{
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
	for(i=0;p!=NULL;i++)
	{
    printf("\n%d\t %s\t\t %s\t\t %s\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
	p=p->next;
}}}

void deletetrains()
{   struct node *p,*q;
	readsorteddb();
	int loc,i;
	printf("\nEnter the location to delete:\t");
	scanf("%d",&loc);
	if(p!=NULL)
	{
	    if(loc==1)
    {
        p=head;
        head=head->next;
        writesorteddb();
        displaysortedtrains();
        free(p);
        return(head);
    }
    else{q=head;}
    for(i=1;i<loc-1;i++)
    {
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    writesorteddb();
    displaysortedtrains();
    free(p);
    n=n-1;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}}

void searchtrains()
	{ readsorteddb();
	int ttt,tno,found=0;
    char tna[100],src[50],dest[50];
	p=head;
	int choice2;
                do{
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                       SEARCH MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. Train Number \n");
                printf("\t2. Source\n");
                printf("\t3. Destination\n");
                printf("\t4. Train Name\n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: system("CLS");
                            readsorteddb();
                            	p=head;
                            printf("\n\nEnter the Train No:\t");
                            scanf("%d",&tno);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
                            for(i=1;p!=NULL;i++)
                            {
                            if(p->tno==tno)
                            {
    printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                            found=1;
                            }
                            p=p->next;
                            }
                            if(!found)
                            {
                            printf("\n\t Oops !!!! Data not found\n\n");
                            }
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 2: system("CLS");
                            readsorteddb();
                            	p=head;
                            printf("\n\nEnter the Source:\t");
                            scanf("%s",src);
                            strlwr(src);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->src,src)==0)
                            {
    printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                            found=1;
                            }
                            p=p->next;
                            }
                            if(!found)
                            {
                            printf("\n\t Oops !!!! Data not found\n\n");
                            }
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                     case 3: system("CLS");
                            readsorteddb();
                            	p=head;
                            printf("\n\nEnter the Destination:\t");
                            scanf("%s",dest);
                            strlwr(dest);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->dest,dest)==0)
                            {
    printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                            found=1;
                            }
                            p=p->next;
                            }
                            if(!found)
                            {
                            printf("\n\t Oops !!!! Data not found\n\n");
                            }
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                     case 4: system("CLS");
                            readsorteddb();
                            	p=head;
                            printf("\n\nEnter the Train Name:\t");
                            scanf("%s",tna);
                            strlwr(tna);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->tna,tna)==0)
                            {
    printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                            found=1;
                            }
                            p=p->next;
                            }
                            if(!found)
                            {
                            printf("\n\t Oops !!!! Data not found\n\n");
                            }
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                }
                }while(choice2!=0);}
void modify()
{
     struct node *p,*q;
	readsorteddb();
	int loc,i;
	printf("\nEnter the location to Modify:\t");
	scanf("%d",&loc);
	if(p!=NULL)
	{
	    if(loc==1)
    {
        p=head;
        head=head->next;
        writesorteddb();
        displaysortedtrains();
        free(p);
        return(head);
    }
    else{q=head;}
    for(i=1;i<loc-1;i++)
    {
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    writesorteddb();
    displaysortedtrains();
    free(p);
    n=n-1;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}
 readsorteddb();
	p=head;
	q=head;
    int tno,ttt;
    char tna[100],src[50],dest[50];
    float km,arr,dept;
    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No || Source || Destination || Train name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n---------------------------------------------------------------------------------------------------------------------\n   ");
    scanf("\t%d %s %s %s %f %f %f %d",&(tno),src,dest,tna,&(km),&(arr),&(dept),&(ttt));
    strlwr(src),strlwr(dest),strlwr(tna);
    p=(struct node*)malloc(sizeof(struct node));
    p->tno=tno;
    strcpy(p->src,src);
    strcpy(p->dest,dest);
    strcpy(p->tna,tna);
    p->km=km;
    p->arr=arr;
    p->dept=dept;
    p->ttt=ttt;
    p->next=NULL;
    if(loc==1)
    {
        p->next=head;
	head=p;
        writedatabase();
        return(p);
    }
    q=head;
    for(i=1;i<loc-1;i++)
    {
        if(q!=NULL)
        {
            q=q->next;
        }
    }
    p->next=q->next;
    q->next=p;
    n=n+1;
   writesorteddb();
    return(head);
}
void trainselect()
{   char temp1[50],temp2[50];
    system("CLS");
    read();
    int i,found=0;
	p=head;
	if(p==NULL)
	{
	printf("File is Empty:");
	}
	else
	{
	for(i=0;p!=NULL;i++)
	{
    printf("\n\tSource:\t\t");      //source of travel
    printf("%s",p->source);
    strcpy(temp1,p->source);
    printf("\n\tDestination:\t\t");     //destination of travel
    printf("%s",p->destination);
    strcpy(temp2,p->destination);
    break;
	}
    }
    readsorteddb();
    p=head;
    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No || Source || Destination || Train name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n---------------------------------------------------------------------------------------------------------------------\n   ");
    for(i=1;p!=NULL;i++)
    {
    if((strcmp(p->src,temp1)==0)&&(strcmp(p->dest,temp2)==0))
    {
    printf("\n%d\t %s\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
    found=1;
    }
    p=p->next;
    }
    if(!found)
    {
    printf("\n\t Oops !!!! No trains found\n\n");
    }

}
void backup()
{
    int choice2;
                do{
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                        MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. Import Database \n");
                printf("\t2. Export Database\n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: system("CLS");
                            import();
                            printf("\n\t IMPORTING BACKUP \n");
                            printf("\n\t IMPORTING BACKUP \n");
                            printf("\n\t---- Done---- Successfully Imported data !!!!!!.");
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 2: system("CLS");
                            export1();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                }
                }while(choice2!=0);
}

void export1()
{   readsorteddb();
    FILE *xp=fopen("Backup.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	printf("\n\t TAKING BACKUP \n");
	printf("\n\t TAKING BACKUP\n");
	for(i=0;temp!=NULL;i++)
	{
		fprintf(xp,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",(temp->tno),temp->src,temp->dest,temp->tna,temp->km,temp->arr,temp->dept,(temp->ttt));
    temp=temp->next;
	}//for
	printf("\n\t---- Done---- BACKUP TAKEN !!!!!!.");
	}//else
	fclose(xp);
}

void import()
{
    int i,filempty=0;
    FILE *imp=fopen("Backup.txt","r");
	p=head;
	fseek(imp,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}

	int len=(int)ftell(imp);
	if(len<=0)
	{
	filempty=1;
	printf("File empty");
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(imp);
	while(fscanf(imp,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",&(p->tno),p->src,p->dest,p->tna,&(p->km),&(p->arr),&(p->dept),&(p->ttt)))
	{
	if(feof(imp))
	{
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
	}
	}
	writesorteddb();
}
void trainenquiry()
{   readsorteddb();
    int found=0;
    char dot[50],src[50],dest[50];
    p=head;
    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("                                        TRAIN ENQUIRY                                          ");
    printf("\n------------------------------------------------------------------------------------------------\n");
	 printf("\n\nEnter the Source:\t");
    scanf("%s",src);
    strlwr(src);
    printf("\n\nEnter the Destination:\t");
    scanf("%s",dest);strlwr(dest);
    printf("\n\nEnter the date of travel(dd/mm/yyyy):\t");
    scanf("%s",dot);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
 for(i=1;p!=NULL;i++)
    {
    if((strcmp(p->src,src)==0)&&(strcmp(p->dest,dest)==0))
    {
    printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
    found=1;
    }
    p=p->next;
    }
    if(!found)
    {
    printf("\n\t Oops !!!! No trains found\n\n");
    }
}


void payout()
{   int ptno,ch;
    float pkm,fare,cfare,afare,tfare;
    char choice3[]="y",choice[10],a[]="SL",b[]="3AC",c[]="2AC";
    int SL=10,AC3=15,AC2=12;
    int cSL=5,cAC3=7,cAC2=6;
    FILE *as;
   printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
   do{
    printf("\nSelect the train No:");
    scanf("%d",&ptno);
    struct node *p;
    p=head;
    p=(struct node*)malloc(sizeof(struct node));
    p->ptno=ptno;
    head=p;
    payoutwrite();
                            readdatabase();
                            found=0;
                            p=head;
                            for(i=1;p!=NULL;i++)
                            {
                            if(p->tno==ptno)
                            {
    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No || Source || Destination || Train name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n---------------------------------------------------------------------------------------------------------------------\n   ");
    printf("\n%d\t %s\t\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t %d",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
                       pkm=p->km;
                            found=1;
                            }
                            p=p->next;
                            }if(!found)
                            {
                            printf("\n\t\t Enter Valid Train no ....\n") ;
                            found=3;
                            }}while(found==3);

	int temp3,temp4;
	char temp5[10],temp6[10];
    read();
    int i,found=0;
	p=head;
	if(p==NULL)
	{
	printf("File is Empty:");
	}
	else
	{

	for(i=0;p!=NULL;i++)
	{
    printf("\n\tAdult:\t\t");      //source of travel
    printf("%d",p->adult);
    temp3=p->adult;
    printf("\n\tChild:\t\t");     //destination of travel
    printf("%d",p->child);
    temp4=p->child;
    strcpy(temp5,p->clas);
     strcpy(temp6,p->cclas);
    if(strcmp(temp6,a)==0)
    { cfare=(pkm*temp4*cSL); }
    if(strcmp(temp5,a)==0){
            afare=(pkm*temp3*SL);
    }
    if(strcmp(temp6,b)==0)
    { cfare=(pkm*temp4*cAC3);  }
    if(strcmp(temp5,b)==0){
   afare=(pkm*temp3*AC3);
    }

 if(strcmp(temp6,c)==0)
    { cfare=(pkm*temp4*cAC2);   }
    if(strcmp(temp5,c)==0){
   afare=(pkm*temp3*AC2);
    }
      fare=cfare+afare;
    printf("\n\tChild fare:%.2f\t\t",cfare);
    printf("\n\tAdult fare:%.2f\t\t",afare);
    printf("\n\tTemporary fare:%.2f\t\t",fare);
    printf("\n------------------------------------------------------------------------\n");
   printf("\n\tWant to take insurance(y/n)\n\t Rs 1/Km for child\n\t Rs 2/Km for adult: ");
   scanf("%s",choice);
   if(strcmp(choice3,choice)==0)
   {
       tfare=(1*pkm*temp4)+(temp3*pkm*2)+fare;
        printf("\n\tTotal fare:%.2f\t\t",tfare);

   }else{tfare=fare;        printf("\n\tTotal fare:%.2f\t\t",tfare);}
    printf("\n------------------------------------------------------------------------\n");
 printf("\t1. Pay Now \t\t2. Cancel & EXIT\n");
     printf("\n------------------------------------------------------------------------\n");
printf("\tChoice:");
 scanf("%d",&ch);
 switch(ch)
 {
     case 1:
            printf("\n Train_no:%d\n Child_Fare:%.2f\n Adult_Fare:%.2f\n Total_fare(Without_Ins):%.2f\n Total_fare(With_Ins):%.2f\n ",ptno,cfare,afare,fare,tfare);
            as=fopen("Booking_reciept.txt","w");
            fprintf(as,"\n Train_no:%d\n Child_Fare:%.2f\n Adult_Fare:%.2f\n Total_fare(Without_Ins):%.2f\n Total_fare(With_Ins):%.2f\n ",ptno,cfare,afare,fare,tfare);
            fclose(as);
                 printf("\n------------------------------------------------------------------------\n");
                 printf("\t\tPayment Successfully Done\n");
                 printf("\n------------------------------------------------------------------------\n");

        break;
    case 2: exit(0);
    break;
 }
 break;}}}
void payoutread()
	{
	int i,filempty=0;
	FILE *ppy=fopen("Booking.txt","r");
	p=head;
	fseek(ppy,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}
	int len=(int)ftell(ppy);
	if(len<=0)
	{
	filempty=1;
	printf("\t\tFile empty");
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(ppy);
	while(fscanf(ppy,"\n%d",&p->ptno))
	{
	if(feof(ppy))
	{
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
	}
	}
	fclose(ppy);
	}

void payoutwrite()
	{
	FILE *py=fopen("Booking.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	for(i=0;temp!=NULL;i++)
	{
	fprintf(py,"\n%d",temp->ptno);
	temp=temp->next;
	}//for
	}//else
	fclose(py);
	}

void displaysearchtrainticket()

{   payoutread();
int ptno;
    p=head;
    ptno=p->ptno;
  i=0,found=0;

    readsorteddb();
    p=head;
    printf("\n\n\tBooked train is ....\n") ;
    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No || Source || Destination || Train name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n---------------------------------------------------------------------------------------------------------------------\n   ");
    for(i=1;p!=NULL;i++)
    {
    if(p->tno==ptno)
    {
    printf("%d\t %s\t %s\t\t %s\t\t %.2f\t\t %.2f\t\t %.2f\t\t %d\n",(p->tno),p->src,p->dest,p->tna,p->km,p->arr,p->dept,(p->ttt));
    found=1;
    }
    p=p->next;
    }

}

void bysource()
{ char src1[30],src2[30],src3[30],src4[30];
int found=0;
                        readsorteddb();
                            p=head;
                            printf("\n\nEnter the Source1:\t");
                            scanf("%s",src1);
                            strlwr(src1);
                            printf("\n\nEnter the Source2:\t");
                            scanf("%s",src2);strlwr(src2);
                            printf("\n\nEnter the Source3:\t");
                            scanf("%s",src3);strlwr(src3);
                            printf("\n\nEnter the Source4:\t");
                            scanf("%s",src4);strlwr(src4);
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->src,src1)==0)
                            {
                            count1++;
                            found=1;
                            }
                            p=p->next;
                            }
                    readsorteddb();
                            p=head;
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->src,src2)==0)
                            {
                                count2++;
                            found=1;
                            }
                            p=p->next;
                            }
                    readsorteddb();
                            p=head;
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->src,src3)==0)
                            {
                                count3++;
                            found=1;
                            }
                            p=p->next;
                            }
 readsorteddb();
                            p=head;
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->src,src4)==0)
                            {
                                count4++;
                            found=1;
                            }
                            p=p->next;
                            }
                 int i,j;
                int n=4;
                int temp;
                int array[5];
                array[0]=count1;
                array[1]=count2;
                array[2]=count3;
                array[3]=count4;
 for(i=0;i< n;i++)
    {
        for(j=i+1;j< n;j++)
        {
            if(array[i]< array[j])
            {
                temp    =array[i];
                array[i]  =array[j];
                array[j]  =temp;
            }}}
        count1=array[0];count2=array[1];count3=array[2];count4=array[3];
                    printf("\t\t\t|\n");  printf("\t\t\t|\n");printf("\t\t\t|\n");
    if( count1>=count2 && count1>=count3 && count1>=count4  )
    {if(count2>=count3 && count2>=count4){for(i=0;i<(count1-count2);i++)
{printf("\t\t\t|\t|||||\n");}
                if(count3 > count4)
                            {for(i=0;i<(count2-count3);i++)
                    {printf("\t\t\t|\t|||||\t|||||\n");}
                            }else{for(i=0;i<(count3-count4);i++)
                                    {printf("\t\t\t|\t|||||\t|||||\t|||||\n");}}
                for(i=0;i<(count3-count4);i++)
                    {printf("\t\t\t|\t|||||\t|||||\t|||||\n");}}
                    for(i=0;i<(count4);i++)
                    {printf("\t\t\t|\t|||||\t|||||\t|||||\t|||||\n");}

}printf("----------------------------------------------------------------------------------------------------------\n");
                    printf("\t\t\t|\t%s\t%s\t%s\t%s\n",src1,src2,src3,src4);
printf("\n\n\n\t\t\t\tBAR GRAPH\t\n");
printf("\n\t\t|\n\t\t|\n\t\t");
for(i=0;i<count1;i++)
{
    printf("|||||");
}
printf("\t%s\t%d",src1,count1);
printf("\n\t\t|\n\t\t|\n\t\t");
for(i=0;i<count2;i++)
{
    printf("|||||");
}
printf("\t%s\t%d",src2,count2);
printf("\n\t\t|\n\t\t|\n\t\t");
for(i=0;i<count3;i++)
{
    printf("|||||");
}
printf("\t%s\t%d",src3,count3);
printf("\n\t\t|\n\t\t|\n\t\t");
for(i=0;i<count4;i++)
{
    printf("|||||");
}
printf("\t%s\t%d",src4,count4);

printf("\n\t\t|");
printf("\n---------------------------------------------------------------------------------------------------------------------");

}


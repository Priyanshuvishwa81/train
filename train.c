#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct train_user
{
	char f_name[20];
	char l_name[20];
	char age[20];
	char from[20];
	char to[20];
	char m_no[20];
}tu[100][100];

struct user
{	char username[10];
	char pass[10];
}arr[100][100],a;


struct train
{
	char train_name[20];
	char train_no[20];
	char charge[20];
	char from[20];
	char to[20];
	char status[20];	
}trr[200][200],ttt[200][200];


void logo();
void menu();
int quit();
void wrong();
void login();
void signup();
void administrator();

void administrator_info();
void login_info();

void c_account();
void a_account();
void l_account();
void b_account();
void varify();

void add_train();
void update_train();
void view_train_for_administrator();
void view_train_for_user();
void book_ticket();
void change();
void passenger_info();
void updates_in_train();
void update_train();
void t_update();
void cancle_updates();
void cancle_trains();
//int train_special_no=0;
void check();

void main()
{
	logo();
	menu();
}


void menu()
{	

	char ch;
	printf("\n1.Creat Account:\n2. Login \n3.administrator\n4.exit\n");
	printf("enter your choice:-\n ");
	scanf("%s",&ch);

	
	
		switch(ch)
		{
			
			case '1' :
				
				signup();
				break;
					
			case '2' :
				login();
				break;
			
			case '3' :
				administrator();
				break;
			case '4' :
				quit();
				break;
			
					
			default :
				system("cls");
				printf("please enter valid keyword\n");
				menu();
				break;
		}
}

void change(){
	system("COLOR 2");
}


void logo(){
	change();
	printf("						{@@}  (  )  {@}   {   }	  @@	()	@@	@\n");
	printf("					{	 }	\n");
	printf("                          	 (@@@@@@@@@)  \n");
	printf("			      {		}\n");
	printf("		_____	{@@@@}	\n");
	printf("	       |=====|			__________________			       _________________\n");
	printf("      	  _D___|     |_________________/		  |_____|__|________-----_____|________________| \n");
	printf("	|(_____)....       |	     ][ __________________/   |       |              -| ____   ____ |	       _________________________\n");
	printf("       /	    |      |	     ][    |	     |        |       |               | |__|   |__| |	     _|	________________________|_____A	\n");
	printf("      |		    |	   |         ][	   |________----------------------------------|  [______]   |      -|                                | \n");
	printf("     ||_________________|__|_______''__[____| |___(}{)(}{)(}{)__________________|____|		   |        |                                |\n");
	printf("    |/   |	  |-------------------|__________|[][]  [][]         D               |-------------|_____ __|________________________________|__ \n");
	printf("  __/  __|        |-~~~~~)       /`~~~~~)      /~~~~~~)       /~~~~~~)_______Y_____________________|____|_| |________________________________|__| \n");
	printf("   |/-___|________|-     O---------------O------------O---------------O___________(~~)_______)                   |_D__D__D_|    |__D__D__D__| \n");
	printf("   	(____/     (_____/       (______/      (______/       (______/            (__)                            (_)  (_)        (_)  (_)	\n");
	printf("         ~~~~       ~~~~~         ~~~~~~         ~~~~           ~~~~               ~~                              ~    ~          ~    ~ \n");

}

void signup(){
	system("cls");
	FILE *fp;
	char value;
	fp=fopen("signup.txt","ab+");
	if(fp==NULL)
	{
	printf("file not found");	
	}
	printf("\n\n\n               _______________________create account_______________________\n\n\n");
	
	for (int i=0;i<=0;i++)
	{
		for(int j=0;j<=0;j++)
		{	
			//printf("first name\n");
			//scanf("%s",&arr[i][j].fname);
			//printf("last name\n");
			//scanf("%s",&arr[i][j].lname);
			//printf("age\n");
			//scanf("%s",&arr[i][j].age);
			printf("Username\n");
			scanf("%s",&arr[i][j].username);
			printf("password\n");
			scanf("%s",&arr[i][j].pass);
			fwrite(&arr[i][j],sizeof(struct user),1,fp);
			printf("           %s your account create successfully...\n\n\n",arr[i][j].username);
		}
	}
	fclose(fp);
	c_account();

	
}


void c_account(){
		char value;
		printf("do you want to go login page y/n :- \n");
		scanf("%s",&value);
		value=tolower(value);
		switch(value){
			case 'y':
				system("cls");
				login();
				break;
			case 'n':
				system("cls");
				menu();
				break;
			default :
				printf("enter valid value\n");
				c_account();
				break;
		}
	
}


void login(){
	system("cls");
	FILE *fp;
	struct user arr[100][100] ;
	char pass[20],username[20];
	int noo=0;
	int no=49;
	fp=fopen("signup.txt","ab+");
	if(fp==NULL)
	{
		printf("file not found");
	}
	printf("\n\n\n               _______________________welcome to login page_______________________\n\n\n");
	printf("Enter username\n");
	//fflush(stdin);
	scanf("%s",&username);
	printf("Enter password\n");
	//fflush(stdin);
	scanf("%s",&pass);
	for (int i=0;i<=no;i++)
	
	{
		for(int j=0;j<=0;j++)
		{
			fread(&arr[i][j],sizeof(struct user),1,fp);
			//printf("%s",arr[i][j].username);
			if(strcmp(username,arr[i][j].username)==0 && strcmp(pass,arr[i][j].pass)==0 ){
				//printf("__________sucessfully login__________");
				system ("cls");
				printf("               ___________________welcome %s  ___________________\n\n\n ",arr[i][j].username);
				login_info();
			}
			
			else{
				noo=noo+1;
			}
		}
			
	}
	if(noo==50){
		printf("%s your username or password is encorrent\n\n",username);
		l_account();
	}
fclose(fp);

}


void l_account(){
		char value;
		printf("do you want to go login again y/n :- \n");
		scanf("%s",&value);
		value=tolower(value);
		switch(value){
			case 'y':
				login();
				break;
			case 'n':
				system("cls");
				menu();
				break;
			default :
				printf("enter valid value\n");
				l_account();
				break;
		}
	
}


void administrator(){
	char u_name[20];
	char pass[20];
	char value;
	printf("\n\n\n               _______________________welcome to administrator pannel_______________________\n\n\n");
	printf("user name:-");
	scanf("%s",&u_name);
	printf("password:-");
	scanf("%s",&pass);

	if ((strcmp(pass,"2002")==0 )&& (strcmp(u_name,"priyanshu")==0))
	{
		administrator_info();
	}
	
	else
	{
	system("cls");
	printf("please enter valid username or password \n\n");
	a_account();
	
	}
	
}

void a_account(){
		char value;
		printf("do you want to go administrator pannel again y/n :- \n");
		scanf("%s",&value);
		value=tolower(value);
		switch(value){
			case 'y':
				system("cls");
				administrator();
				break;
			case 'n':
				system("cls");
				menu();
				break;
			default :
				printf("enter valid value\n");
				a_account();
				break;
		}
	
}




void login_info(){
		
		char no;
		printf("1. book Ticket \n 2. varify \n 3. view Train   \n 4. quit  \n 5. back \n");
		printf("enter your choice");
		scanf("%s",&no);
	
		switch (no){
			case '1' :
			
				book_ticket();			    
				break;
			
			
			case '2' :
		
				varify();
				   
				break;
			
			case '3' :
				view_train_for_user();
				break;
			
			
			case '4' :
				
				quit();
				break;
			
			case '5':
				menu();
				break;

			
			
			default:
				system("cls");
				printf("\nplease enter valid value\n\n");
				login_info();
				break;
		}	
}

void administrator_info(){
	system("cls");
 
		char no;
		printf("\n\n           _______________________________welcome priyanshu sir_______________________________\n\n\n ");
		printf("1.add train \n 2.view all trains \n 3.passenger info \n 4.updates in train  \n 5.back   \n 6.quit \n");
		printf("enter your choice");
		scanf("%s",&no);
		
		switch (no){
			case '1' :
			    add_train();
				break;
			
			case '2' :
			    view_train_for_administrator();
				break;
			
			case '3' :
				passenger_info();      
				break;
			
			case '4':
			
				updates_in_train();
				break;
					
			
			case '5':
				system("cls");
				menu();
				break;
					
			case '6' :
				quit();
				break;
				
			default:
				system("cls");
				printf("please enter valid keyword\n\n");
				system("pause");
				administrator_info();
				break;
		}	
}


//quit
int quit(){
	system("cls");
	exit(0);
	return 0;
}


void book_ticket(){

	system("cls");
	FILE *fp;
	int p;
	
	fp = fopen("passengers.txt","ab+"); 
	if(fp==NULL)
	{
	printf("file not found");	
	}		
	printf("how many passengers");
	scanf("%d",&p);
	int q=1;
	p=p-1;
	
	for (int i=0;i<=p;i++){
		for (int j=0;j<=0;j++){
				printf("    \n\n%d  user   \n\n",q);
				printf("first name:-");
				scanf("%s",&tu[i][j].f_name);

				printf("last name:-");
				scanf("%s",&tu[i][j].l_name);
				
				printf("age:-");
				scanf("%s",&tu[i][j].age);

				printf("from:-");
				scanf("%s",&tu[i][j].from);
	
				printf("to:-");
				scanf("%s",&tu[i][j].to);
				
				printf("mobile no:- ");
				scanf("%s",&tu[i][j].m_no);
				printf("\n\n");
				q=q+1;
				//s_no();
			fwrite(&tu[i][j],sizeof(struct train_user),1,fp);
			
		}
	}
	fclose(fp);
	system("cls");
	login_info();
	
}



void varify(){
	system("cls");
	FILE *fp;
	int p=1;
	int noo=0;
	int no=9;
	char value[20];
	fp = fopen("passengers.txt","ab+"); 
	if(fp==NULL)
	{
	printf("file not found");	
	}
	printf("enter mobile no :-");
	scanf("%s",&value);
	for (int i=0;i<=no;i++){
		for (int j=0;j<=0;j++){
			fread(&tu[i][j],sizeof(struct train_user),1,fp);
				if ((strcmp(value,tu[i][j].m_no)==0)){
				printf("%dst user\n\n",p);
				printf("first name:- %s\n",tu[i][j].f_name);
				printf("last name:- %s\n",tu[i][j].l_name);
				printf("age:- %s\n",tu[i][j].age);
				printf("from:- %s\n",tu[i][j].from);
				printf("to:- %s\n",tu[i][j].to);
				p=p+1;
				printf("\n\n\n");
				}
				else{
						noo=noo+1;
					}
				}
					
			}
	if(noo==10){
		printf("may be your mobile no was incorrect \n\n");
		b_account();
	}
fclose(fp);
system("pause");
system("cls");
login_info();
}


void b_account(){
		char value;
		printf("do you want to go try again y/n :- \n");
		scanf("%s",&value);
		value=tolower(value);
		switch(value){
			case 'y':
				system("cls");
				varify();
				break;
			case 'n':
				system("cls");
				login_info();
				break;
			default :
				printf("enter valid value\n");
				b_account();
				break;
		}
	
	
}






void add_train(){
	system("cls");
	FILE *fp;
	//struct train trr[200][200] ;
	int a;
	fp = fopen("trains.txt","ab");
	
	if(fp==NULL)
	{
	printf("file not found");
	}
	printf("how many trains you wants to add");
	scanf("%d",&a);
	a=a-1;
	int train_special_no=0;
	for (int i=0;i<=a;i++){
		for (int j=0;j<=0;j++){
			
			printf("\n\n");
			printf("enter train no:- ");
			scanf("%s",&trr[i][j].train_no );

			printf("enter train name:- ");
			scanf("%s",&trr[i][j].train_name );

			printf("from:- ");
			scanf("%s",&trr[i][j].from );
			
			printf("to:- ");
			scanf("%s",&trr[i][j].to);

			printf("charge:- ");
			scanf("%s",&trr[i][j].charge);
			
			printf("status:- ");
			scanf("%s",&trr[i][j].status);
			train_special_no=train_special_no+1;
			fwrite(&trr[i][j],sizeof(struct train),1,fp);
			
		}
	}
fclose(fp);

system("pause");
administrator_info();

}


void passenger_info(){
	system("cls");
	FILE *fp;
	int p;
	fp = fopen("passengers.txt","rb"); 
	if(fp==NULL)
	{
	printf("file not found");	
	}
	printf("first name\t\tlast name\t\tage\t\tfrom\t\t to\t\t mobile no\n");
	for (int i=0;i<=10;i++){
		for (int j=0;j<=0;j++){
				fread(&tu[i][j],sizeof(struct train_user),1,fp);
				printf("%s %20s %20s %20s %20s %20s\n",tu[i][j].f_name ,tu[i][j].l_name ,tu[i][j].age , tu[i][j].from , tu[i][j].to, tu[i][j].m_no);		
		}
	}
	fclose(fp);
	system("pause");
	administrator_info();
}



void view_train_for_user(){
	system("cls");
	FILE *fp;
	int p;
	fp = fopen("trains.txt","ab+"); 
	if(fp==NULL)
	{
	printf("file not found");	
	}
	printf("                             _______________trains_________________\n\n\n\n");
	printf("train_name   \t\t train_no \t\t from \t\t to \t\t charge\n");
	for (int i=0;i<10;i++){
		for (int j=0;j<=0;j++){                                         
				fread(&trr[i][j],sizeof(struct train),1,fp);
				 
				printf("%1s %20s %20s %20s %20s\n",trr[i][j].train_name,trr[i][j].train_no,trr[i][j].from,trr[i][j].to,trr[i][j].charge);
				//printf("train_no:-%s\n",trr[i][j].train_no);
				//printf("from:-%s\n",trr[i][j].from);                                                                                      
				//printf("to:-%s\n",trr[i][j].to);
				//printf("charge:-%s\n",trr[i][j].charge);
			
		}
	}
	char a;
	fclose(fp);
	printf("                                 _______________updates_________________\n\n\n\n");
	t_update();
	system("pause");
	system ("cls");
	login_info();
}



void view_train_for_administrator(){
	system("cls");
	FILE *fp,*fp1;
	int p;
	fp = fopen("trains.txt","ab+"); 
	
	if(fp==NULL)
	{
	printf("file not found");	
	}
	printf("                             _______________trains_________________\n\n\n\n");
	printf("train_name   \t\t train_no \t\t from \t\t to \t\t charge\n");
	for (int i=0;i<10;i++){
		for (int j=0;j<=0;j++){                                         
				fread(&trr[i][j],sizeof(struct train),1,fp);
				 
				printf("%1s %20s %20s %20s %20s\n",trr[i][j].train_name,trr[i][j].train_no,trr[i][j].from,trr[i][j].to,trr[i][j].charge);
				//printf("train_no:-%s\n",trr[i][j].train_no);
				//printf("from:-%s\n",trr[i][j].from);                                                                                      
				//printf("to:-%s\n",trr[i][j].to);
				//printf("charge:-%s\n",trr[i][j].charge);
			
		}
	}
	fclose(fp);
	char a;
	printf("                             _______________updates_________________\n\n\n\n");	
	check();
	system("pause");
	system ("cls");
	administrator_info();
}


void check(){
 FILE *fp1;  
 fp1=fopen("update_trains.txt","rb");
		if (fp1!=NULL){        
			t_update();
	}
	else if(fp1==NULL){
		
		printf("no updates avilable\n\n");
	}
	system("pause");
	system ("cls");
	administrator_info();
	fclose(fp1);
}


void updates_in_train(){
	system("cls");
	char u_i_t;
		printf("\n\n1.update train \n2.cancle all updates \n3. cancle trains \n4. back \n");
		printf("enter your choice");
		scanf("%s",&u_i_t);
	
		switch (u_i_t){
			case '1' :
			
				update_train();			    
				break;
			
			
			case '2' :
		
				cancle_updates();
				   
				break;
			case '3':
				cancle_trains();
			
			case '4' :
				administrator_info();
				break;
			
			default:
				
				printf("not ok");
				break;
		}	
}


void t_update(){
	FILE *fp1;
	fp1 = fopen("update_trains.txt","ab+"); 
		if(fp1==NULL)             
		{    
			printf("file not found");	
		}
		printf("train_name   \t\t train_no \t\t from \t\t to \t\t charge \t\t status\n");
		
		for (int i=0;i<=10;i++){
			for (int j=0;j<=0;j++){
			fread(&ttt[i][j],sizeof(struct train),1,fp1);
			
				printf("%1s %20s %20s %20s %20s %20s \n",ttt[i][j].train_name,ttt[i][j].train_no,ttt[i][j].from,ttt[i][j].to,ttt[i][j].charge,ttt[i][j].status);
			
			}
		}
 fclose(fp1);
}

void update_train(){

	FILE *fp,*fp1;
	fp = fopen("trains.txt","ab+");
	fp1 = fopen("update_trains.txt","ab+");
	if(fp == NULL){
        printf("Error opening file");
    }
	char value[20];
	printf("enter train no :-");
	scanf("%s",&value);
	for (int i=0;i<=10;i++){
		for (int j=0;j<=0;j++){
			//printf("error");
			fread(&trr[i][j],sizeof(struct train),1,fp);
			if ((strcmp(value,trr[i][j].train_no)==0))
			{
							printf("\n\nenter train status cancle/running\n\n");
							scanf("%s",trr[i][j].status);
							
							fwrite(&trr[i][j],sizeof(struct train),1,fp1);
							printf("update successfully....\n");          
								fclose(fp1);
								fclose(fp); 
							system("pause");
							administrator_info(); 	
			}
		}
	}

}
   //error
   
void cancle_updates()
{
	if( remove("update_trains.txt")== 0){
        printf("successfully deleted\n");
        system("pause");
        administrator_info();
    }

    else{
    	
    	printf("\n\nerror\n\n");
    	system("pause");
    	administrator_info();
	}

}

void cancle_trains()
{
	FILE *fp,*fp1;
	fp = fopen("trains.txt","w");
	fp1= fopen("update_trains.txt","w");
	if(fp == NULL){
        printf("Error opening file 1");
    }
    if(fp1 == NULL){
        printf("Error opening file 2");
    }

    printf("sucessfully cancaled\n");
    system("pause");
	administrator_info();
	fclose(fp);
	fclose(fp1);
}

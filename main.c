/*Compile:  gcc  main.c -static -fvisibility=hidden  -s
Obfustraction: strip -R .comment -R .note a.out
*/

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <time.h>
	#include <pwd.h>
	#include "rot13.h"

	struct carte{
		char *nume;
		int  *pret;
		char *auth;
		struct status{
			bool borrow;
		}x;
		int an;
	};

	int send_email(char *user,char *sendto,char *content,char *filename_to_be_send,int fd){
		fd = open(filename_to_be_send,O_RDWR);
		if(fd == -1)
		{
			perror("We want to apologise,but your file may not exist or it has been removed/replaced or deleted");
		}
		else{
			write(fd,content,strlen(content));
		}
	}

	int is_rent(struct carte *y,char *optiune){
		int status =0;
		if(y->x.borrow == 1){
			printf("The book is borrowed");
			status =- 1;
			return status;
		}
		else{
			printf("The book isnt borrowed");
			optiune = malloc(sizeof(int));
			if(strncmp(optiune,"yes",3)){
				y->x.borrow = 1;
				printf(" debugging state %d",y->x.borrow);
				puts("have a nice day");
			}
			status = 0;
		}
		return status;
	}

	void change_password(){

	}

	void chaneg_user(){

	}


	void *alloc_mem(signed int x){
		void *ptr;
		ptr = malloc(x);
		if(ptr == NULL){
			perror("error allocating memory");
		}
	}

	int edit_book(int fd,char *buffer,char *file,int size){
		int status;
		fd = open(file,O_RDWR,S_IRUSR,S_IWUSR,S_IROTH,S_IWOTH);
		if(fd == -1){
			perror("the journal does not exists");
			status = -1;
			return status;
	 	}
		else{
			write(fd,buffer,strlen(buffer));
			status = 0;
			return status;
		}
		return status;
	}

	void add_book(char *fisier){
		char *str;
		str = fisier;
	//	printf("%s",(char *)str);
		char *command = "touch ";
		char final[80];
		strcpy(final,command);
		strcat(final,str);
		strcat(final,".pdf");
		system(final);
	}

	void usage(char *program){
		printf("Folosire: %s <parametrii>\n",program);
	}

	void help(){
	//ramane de implementat simple printf

	}

	int chapta(){
		return 0;
	}

	void login_system(char *passwd,char *user,int (*cipher_text_encode)(),int(*cipher_text_decode)()){
		void (*try_harder)();
		int status;
		//labels
	//	next_auth:
			chapta();

	//	try_again:
			try_harder();

		//no more labels
		printf("Primul sistem de login,ne cerem scuze pt inconveniente\n");
		puts("va rugam introduceti urmatoarele date:paroloa si utilizatorul");
		void *uid;
		*(unsigned int *)uid = getuid();
		char *pass_encode = (char *)cipher_text_encode(passwd);
		char *pass_decode = (char*)cipher_text_decode(passwd);
		if(strcmp(pass_decode,pass_encode)){
			printf("congrats you are one step further to log in ");
			printf("please complete second stage of login procedure");
			//goto next_auth;
		}
		else{
			perror("Your authentification failed,please try again one more time");
			//goto try_again;
		}

	}

int register_db(int fd,char *buffer,char *user,char *passwd,int size){
			int status = 0;
			char *user_plus_parola;
			char *DB;
			DB = malloc(sizeof(char*));
			DB = "database.txt";
			user_plus_parola = malloc(sizeof(char *));
			strcpy(user_plus_parola,user);
			strcat(user_plus_parola,passwd);
			fd = open(DB,O_RDWR,S_IRUSR,S_IWUSR);
			if(fd == -1)
			{
				perror("Nu s-a putut procesa baza de date!Ne cerem scuze pt acest inconvenient");
				status = -1;
				return status;
			}
			else{
				write(fd,user_plus_parola,strlen(user_plus_parola));
				status = 0;
				return status;
			}
			return status;
}

	int logout(char *user)
	{
		int status = 0;
		free(user);
		printf("%s\n","va dormin o zi buna!");
		return status;
	}

	int main(int argc,char *argv[]){
		//creating and declaring the variables
		int fd;
		char *buffer;
		signed int size = 256;
		char *fisier;
		char *help_choice;
		struct carte *carte;
		carte = malloc(256);
		char *interes;
		interes = malloc(256);
		char *optiune;
		optiune = malloc(245);
		fisier = (char *)alloc_mem(size);
		char *user;
		char *pass;
		void (*fct_ptr)();
		fct_ptr = (void *)usage;

		if(argc < 2){
			fct_ptr(argv[0]);

		}
		else{
			printf("%s\n","Welcome to LetMeH8You personal journal manager");
			printf("%s\n","What would you like to do with your journals");
			scanf("%s",optiune);
			switch (optiune) {
				case  "edit_journal" :
					puts("What journal do you want to edit");
					scanf("%s",fisier);
					puts("What would you like to write in your journal?");
					scanf("%s",buffer);
					edit_book(fd,buffer,fisier,size);
					free(fisier);
					free(buffer);
					break;
				case "add_journal" :
					scanf("%s\n",fisier);
					add_book(fisier);
					break;
				case "register new user":
					puts("Please insert the username");
					scanf("%s\n",user);
					puts("Please insert the password");
					scanf("%s\n",pass);
					register_db(fd,buffer,user,pass,strlen(buffer));
					puts("Thank you!Yo've been successfully registred into our db.Have a nice day!");
					break;
				case "display_info_about_journal":
					puts("Whay journal are you intresed in?");
					scanf("%s",fisier);
					puts("What are you intresed to know about the journal");
					scanf("%s",interes)
						switch (interes ) {
							case  "" :
						}

				default :
					puts("I'm sorry but your command doesn't exists.");
					free(user);
					free(pass);
					free(buffer);
					free(fisier);
					free(optiune);
					free(carte);
					break;
			}

		}

		//scanf("%s",(char*)carte);
		//carte->x.borrow=0;

		//scanf("%s",optiune);
		//is_rent(carte,optiune);

		//buffer = (char*)alloc_mem(size);
		//
		//
		//user = malloc(8);
		//pass = malloc(8);
		//scanf("%s",user);
		//scanf("%s",pass);
		//logout(user);
		//
		//printf();
		//add_book(fisier);
		//scanf("%s",buffer);
		//works fine register_db(fd,buffer,user,pass,strlen(buffer));
		//
		//edit_book(fd,buffer,fisier,size);
		/**/
		//help();
		return 0;
	}

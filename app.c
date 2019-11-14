#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <windows.h>
#include"app.h"

void Menu_func(Menu *arr, int num){
	static char option;
	int i;
	printf("\n");
	//Clears the screen
	system("clear");
	printf("\n**********welcome to our system**********\n");
	for(i=0; i<num; i++)
	{
		printf("\n[%c] %s",(arr[i].ch),(arr[i].desc));
	}
	printf("\n\n[B] Back\n[X] Exit"
		"\n...................................."
		"\nChoose an option from the above menu:");
	
	//Reads the user's option
	scanf(" %c", &option);
	Excute_Menu(&option, arr, num);
}

void Excute_Menu(char *option, Menu *arr, int num){
	int i;
	char temp;
	if(*option == 'X'){
		//Exits the system
		return;
	}
	
	if(*option == 'B'){
		//Go to the back menu
		Menu_func(arr[0].parrent_arr, arr[0].parrent_arr_len);
		return;
	}
	
	for(i=0; i<num; i++){
		//check if the input is valid in the menu
		if(*option == arr[i].ch){
			//check if the choise is to excute a function, call it by its pointer
			if(arr[i].type == false){
				(arr[i].task_ptr)();
				//Back to the previous menu*/
				Sleep(2000);
				Menu_func(arr, num);
				
			}
			else{
				//Check if the choise is to open submenu
				//call the menu function by the new array
				Menu_func(arr[i].Next.child_arr, arr[i].Next.child_arr_len);
			}
			return;
		}
	}
	printf("\nInvalid Input\n");
	Menu_func(arr, num);
}

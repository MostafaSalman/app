#include<stdio.h>
#include<stdlib.h>
#include"app.h"
#include"menu.h"

#define NUM_ARR 3						/* Number Of Items Of Main Menu */
#define NUM_ARR2 2						/* Number Of Items Of First Sub Menu */
#define NUM_ARR3 1						/* Number Of Items Of Second Sub Menu */

char exit_ch ;
char back_ch ;

int main(void){
	char input;
	char display = '?';					/* Character To Display Menu When User Choose It */
	exit_ch = 'X';						/* Character To Exit When User Choose It */
	back_ch = 'B';						/* Character To Back To The Previous Menu When User Choose It */
	
	//Allocate Array For Each Menu
	Menu *array = malloc(sizeof(Menu) * NUM_ARR);
	Menu *array2 = malloc(sizeof(Menu) * NUM_ARR2);
	Menu *array3 = malloc(sizeof(Menu) * NUM_ARR3);
	
	//Creat Main Menu
	Menu Item_1 = {.ch='a', .desc="Excute func1", .type=false, .task_ptr = &func1};
	Menu Item_2 = {.ch='b', .desc="Excute func2", .type=false, .task_ptr = &func2};
	Menu Item_3 = {.ch='c', .desc="Other functions >", .type=true , .Next.child_arr = array2, .Next.child_arr_len = NUM_ARR2};
	Menu *main_menu[NUM_ARR] = {&Item_1, &Item_2, &Item_3};
	Creat_Menu(array, NUM_ARR, main_menu);
	
	//Creat First Sub Menu
	Menu Item_4 = {.ch='d', .desc="Excute func3", .type=false, .task_ptr = &func3};
	Menu Item_5 = {.ch='e', .desc="Other >", .type=true , .Next.child_arr = array3, .Next.child_arr_len = NUM_ARR3};
	Menu *first_submenu[NUM_ARR2] = {&Item_4, &Item_5};
	Creat_Menu(array2, NUM_ARR2, first_submenu);
	
	//Creat Second Sub Menu
	Menu Item_6 = {.ch='f', .desc="Excute func4", .type=false, .task_ptr = &func4};
	Menu *second_submenu[NUM_ARR2] = {&Item_6};
	Creat_Menu(array3, NUM_ARR3, second_submenu);
	
	//Display Welcome Message And Wait The Users Choise To Display The Main Menu 
	do{
		printf("\n");
		system("clear");
		printf("\n**********welcome to our system**********\n"
			"\nTo display our menu press %c\nTo exit press %c \napp>", display, exit_ch);
		scanf("%c",&input);
	}while((input != display)&&(input != exit_ch));
	if(input == display)
		Menu_func(array, NUM_ARR);
	else if(input == exit_ch)
		return 0;

	return 0;
}

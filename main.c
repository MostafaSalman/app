#include<stdio.h>
#include<stdlib.h>
#include"app.h"
#include"menu.h"

#define NUM_ARR 3
#define NUM_ARR2 2
#define NUM_ARR3 1

int main(void)
{
	char input;
	Menu *array = malloc(sizeof(Menu) * NUM_ARR);
	Menu *array2 = malloc(sizeof(Menu) * NUM_ARR2);
	Menu *array3 = malloc(sizeof(Menu) * NUM_ARR3);
	
	array[0].ch = 'a';
	array[0].desc = "Excute func1";
	array[0].type = false;
	array[0].task_ptr = &func1;
	array[0].parrent_arr = array;
	array[0].parrent_arr_len = NUM_ARR;
	array[1].ch = 'b';
	array[1].desc = "Excute func2";
	array[1].type = false;
	array[1].task_ptr = &func2;
	array[2].ch = 'c';
	array[2].desc = "Other functions >";
	array[2].type = true;
	array[2].Next.child_arr = array2;
	array[2].Next.child_arr_len = NUM_ARR2;
	
	array2[0].ch = 'd';
	array2[0].desc = "Excute func3";
	array2[0].type = false;
	array2[0].task_ptr = &func3;
	array2[0].parrent_arr = array;
	array2[0].parrent_arr_len = NUM_ARR;
	array2[1].ch = 'e';
	array2[1].desc = "Other >";
	array2[1].type = true;
	array2[1].Next.child_arr = array3;
	array2[1].Next.child_arr_len = NUM_ARR3;
	
	array3[0].ch = 'f';
	array3[0].desc = "Excute func4";
	array3[0].type = false;
	array3[0].task_ptr = &func4;
	array3[0].parrent_arr = array2;
	array3[0].parrent_arr_len = NUM_ARR2;
	
	do{
		printf("\n");
		system("clear");
		printf("\n**********welcome to our system**********\n"
			"\nTo display our menu press ?\nTo exit press X \napp>");
		scanf("%c",&input);
	}while((input != '?')&&(input != 'X'));
	if(input == '?')
		Menu_func(array, NUM_ARR);
	else if(input == 'X')
		return 0;

	return 0;
}

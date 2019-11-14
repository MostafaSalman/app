#ifndef MENU_H_
#define MENU_H_
#include <stdbool.h>

typedef void (*ptr_func)(void);

/* Menu struct */
typedef struct menu {
	char ch;
	char *desc;
	bool type;								/* if there is submenu type=1 , and else type=0 */
	union{
		ptr_func task_ptr;					/* pointer to the task */
		struct{
			struct menu *child_arr;			/* pointer to array of structs (next submenu)*/
			int child_arr_len;				/* number of items of next submenu */
		}Next;
	};
	struct menu *parrent_arr;			/* pointer to array of structs (next submenu)*/
	int parrent_arr_len;				/* number of items of next submenu */
	
} Menu;

/*=========================== APIs ===========================*/

void func1(void);
void func2(void);
void func3(void);
void func4(void);

#endif /* MENU_H_ */
#ifndef APP_H_
#define APP_H_
#include"menu.h"

#define MAX_MENUS 3							/* Max Number Of Menus */

extern char exit_ch ;
extern char back_ch ;

/*=========================== APIs ===========================*/

/**
 *@brief  This Function To Creat Menu And Sub menus
 *
 *@param  arr : Array to store the Menu Items In It 
 *
 *        size : The Size Of The Array
 *
 *        menu_items : Array Of Pointers To Structs Of The Items
 *
 *@retval None 
 */
void Creat_Menu(Menu *arr, int size, Menu **menu_items);

/**
 *@brief  This Function To Display Menu And Sub menus.
 *        And Take The Choise From The User.
 *
 *@param  arr : The Array Of Menu Items 
 *
 *        num : The Size Of The Array
 *
 *@retval None 
 */
void Menu_func(Menu *arr, int num);

/**
 *@brief  This Function To Excute The Input Choise
 *
 *@param  option : The Input Choise 
 *
 *        arr : The Array Of Menu Items
 *
 *        num : The Size Of The Array
 *
 *@retval None 
 */
void Excute_Menu(char *option, Menu *arr, int num);

#endif /* APP_H_ */

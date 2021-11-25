/********************************************************************************************************************************************
* layout.cpp: Control the final terminal printed layout for parton-x output. 
*
* By: Mohammed Maher Abdelrahim Mohammed
*     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
*     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
*     mohammed.maher@unical.it
*
*********************************************************************************************************************************************/
#include<iostream>
#include <ctime>
#include<stdio.h> 
#include"layout.h"
#include"organize.h"
#include<unistd.h>
//****************************************************************************80
void timestamp ( void )
//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    May 31 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 October 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    None
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
/*-------------------------------------------------------------------------------------------
                           Drawing random Feynman diamgrams
-------------------------------------------------------------------------------------------*/
/*
void message::Draw1(void){
std::cout<<"                                  。　☆ 。　　☆。　　☆ \n";
std::cout<<"                                  ★。　＼　　｜　　／。　★ \n";
std::cout<<" 　　 　                                    。。。 \n";
std::cout<<"                                  ★。　／　　｜　　＼。　★ \n";
std::cout<<"                                  。　☆。 　　。　　☆。\n";  
}

void message::Draw3(void){ 
/*
std::cout<<"  _,,)\.~,,._\n";
std::cout<<" (()`  ``)\))),,_\n";
std::cout<<"  |     \ ''((\)))),,_          ____\n";
std::cout<<"  |6`   |   ''((\())) '-.____.-'    `-.-,\n";
std::cout<<"  |    .'\    ''))))'                  \)))\n";
std::cout<<"  |   |   `.     ''                     ((((\n";
std::cout<<"  \, _)     \/                          |))))\n";
std::cout<<"   `'        |                          (((((\n";
std::cout<<"             \                  |       ))))))\n";
std::cout<<"              `|    |           ,\     /((((((\n";
std::cout<<"               |   / `-.______.<  \   |  )))))\n";
std::cout<<"               |   |  /         `. \  \  ((((\n";
std::cout<<"               |  / \ |           `.\  | (((\n";
std::cout<<"               \  | | |             )| |  ))\n";
std::cout<<"                | | | |             || |  '    \n";
std::cout<<"                | | | |             || |\n";
*/
//}
/*-------------------------------------------------------------------------------------------
                            Print Author informations
-------------------------------------------------------------------------------------------*/
void Info(void){
std::cout<<std::endl;
std::cout<<BOLD(FGRN("==========================================================================="))<<std::endl;
std::cout<<BOLD(FGRN("=                 MOHAMMED MAHER ABDELRAHIM MOHAMMED 2021                 ="))<<std::endl;
std::cout<<BOLD(FGRN("=     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA  ="))<<std::endl;
std::cout<<BOLD(FGRN("=               VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY           ="))<<std::endl;
std::cout<<BOLD(FGRN("=                         mohammed.maher@unical.it                        ="))<<std::endl;
std::cout<<BOLD(FGRN("==========================================================================="))<<std::endl;
std::cout<<std::endl;
}
/*-------------------------------------------------------------------------------------------
                            Print the package title
-------------------------------------------------------------------------------------------*/
void name(void){
std::cout<<BOLD(FGRN("===================================================================="))<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<"\t ███╗░░░███╗░█████╗░██████╗░███████╗\n";
std::cout<<"\t ████╗░████║██╔══██╗██╔══██╗██╔════╝\n";
std::cout<<"\t ██╔████╔██║██║░░██║██║░░██║█████╗░░\n";
std::cout<<"\t ██║╚██╔╝██║██║░░██║██║░░██║██╔══╝░░\n";
std::cout<<"\t ██║░╚═╝░██║╚█████╔╝██████╔╝███████╗\n";
std::cout<<"\t ╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚══════╝\n";
std::cout<<BOLD(FGRN("                MOHAMMED MAHER ABDELRAHIM MOHAMMED 2021             "))<<std::endl;
std::cout<<BOLD(FGRN("                        maherali8932@gmail.c                        "))<<std::endl;
std::cout<<BOLD(FGRN("===================================================================="))<<std::endl;
} 


void Main_Menu(const char*  myfolder){
   int choice;
   
 lable1:  while(choice != 4)
   {
	name();
	timestamp();
	int back;
	printf("-=[ MoDe file organizer Menu ]=-\n");
      	printf("1 - Analyze this folder \n");
      	printf("2 - Organize the files\n");
      	printf("3 - Clear the screen\n");
      	printf("4 - Quit\n");
      	scanf("%d", &choice);

      	if((choice < 1) || (choice > 4))
         	printf("\n[!!] The number %d is an invalid selection.\n\n", choice);
      
      	else if (choice < 4)
      	{  
      	  if(choice == 1)   
          {        
          	std::cout<<BOLD(FGRN("--------------------------[ Output ]---------------------------"))<<std::endl;
          	check folder(myfolder,1);
          	std::cout<<BOLD(FGRN("----------------------------------------------------------------"))<<std::endl;
           	std::cout<<BOLD(FGRN("press [1] to back to the Main Menu"))<<std::endl;
      	   	std::cout<<BOLD(FGRN("press [2] to Exit"))<<std::endl;
           	lable2: scanf("%d", &back);
                   
            	switch(back){
                   
                   case 1:
                        goto lable1;
                        break;
                   
                   case 2:
                   	 std::cout<<"Bye bye!"<<std::endl;
                   	 return;
                   	
                   default:
                   	 std::cout<<BOLD(FRED("Invalid option!!\n"));
                   	 goto lable2;
                   }
          }     
               
          else if(choice == 2) 
          {
               std::cout<<BOLD(FGRN("--------------------------[ Output ]---------------------------"))<<std::endl;               
          	check folder(myfolder,2);
          	std::cout<<"Done!"<<std::endl;
          	std::cout<<BOLD(FGRN("----------------------------------------------------------------"))<<std::endl;
               std::cout<<BOLD(FGRN("press [1] to back to the Main Menu"))<<std::endl;
               std::cout<<BOLD(FGRN("press [2] to Exit"))<<std::endl;
              lable3: scanf("%d", &back);
               
               switch(back){
               
                  case 1:
               	goto lable1;
                       break;
                
              	  case 2:
              	  	std::cout<<"Bye bye!"<<std::endl;
                   	return;
                   	
                 default:
                      std::cout<<BOLD(FRED("Invalid option!!\n"));
                      goto lable3;
                 }
     	  }
     	  
     	  else if (choice == 3)
     	 {
         	system("clear"); 
         }       
	}	
    }
    std::cout<<"Bye bye!"<<std::endl;
}

#include<iostream>
#include"layout.h"

using namespace std;
 
 
int main(int argc, const char* argv[]) {

    if (argc < 2) 
    {   
        printf("You must specify directory path!\n");
        printf("for example: \" home/users/..\"\n");
        return 1;
    }
     
    Main_Menu(argv[1]);
    
}

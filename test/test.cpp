#include<iostream>
#include"organize.h"
#include"layout.h"

using namespace std;
 
 
int main(int argc, const char* argv[]) {

    if (argc < 2) 
    {   
        printf("You must specify directory path!\n");
        printf("for example: \" home/users/..\"\n");
        return 1;
    }

   int opt;
   cout<<"-------------[-main manu-]--------------"<<endl;
   cout<<"set and options\n";
   cout<<"[1] Analyze\n";
   cout<<"[2] Organize\n";
   cin>>opt;
    //std::filesystem::path filePath = argv[1];
   cout<<"==============[-info box-]=============="<<endl;
    check folder(argv[1],opt);
    cout<<"Done!"<<endl;
   cout<<"========================================"<<endl;
}

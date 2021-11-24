#include<iostream>
#include<string>
#include<vector>
#include <dirent.h> // to work with directories ( format of directory entries)
#include <filesystem> // C++17
#include"organize.h"  // check class which is the key ingrediant 
#include"layout.h"  // colors and output metadata
 
namespace fs = std::filesystem;   // to follow the paths where the created folders should be located


/*----------------------------------------------------------------------------------------------------
A function counts how many times a specific file has been detected, and print in color the statistics

funcy( how many time a file appear, the total amount of files, output color, the file name)
-----------------------------------------------------------------------------------------------------*/ 
void funcy(int crrval, int tot, std::string color, std::string typ)
{
   std::string a = BOLD(FRED("#"));
   std::string b = BOLD(FGRN("###"));
   std::string c = BOLD(FYEL("###"));

   char x ='*';
   int update= (crrval)*100./tot;
 
   if (color=="red") {
	std::cout<<BOLD(FRED("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<std::endl;
   }
 
   if (color=="green") {
 	std::cout<<BOLD(FGRN("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<std::endl;
   }
  
   if (color=="yellow") {
 	std::cout<<BOLD(FYEL("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<std::endl;
   }
 
   if (color=="blue") {
 	std::cout<<BOLD(FBLU("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<std::endl;
   }

   if (color=="mag") {
	std::cout<<BOLD(FMAG("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<std::endl;
   }
 
   if (color=="cyn") { 
	std::cout<<BOLD(FCYN("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<std::endl;
   }
}
 
/*----------------------------------------------------------------------------------------------------
The main constructor of the check class, which makes a call of many functions, it receives the path to
the targeted folder and read the two different options control the final decision (analyze or organize)  
-----------------------------------------------------------------------------------------------------*/ 
check::check(const char*  myfile , int options){
       
	DIR* dir = opendir(myfile);  // open a directory 
	
	if (dir == NULL){    
		return;
   	}
     
        struct dirent* entity;   //  This is a structure type used to return information about directory entries.
        entity = readdir(dir); // read a directory
    
        while ( entity != nullptr)  // while the folder is not empty 
        {
            files.push_back(entity->d_name); // save the entity name in the vector called files
            entity = readdir(dir);  // read the next entity
        }
        
        closedir (dir); // close the directory
        
        switch (options)
        {
          case 1: // Analyze option
          
            for (auto file : files)  // read all files in the vector files one by one
            {   
                bool flag = false;                 // to ensure that we just want to analyze not create any folder
                FileExtn(IMAGES, file, flag);      // check and count how many times the files with extension belong to IMAGES vector appears
                FileExtn(VIDEOS, file,flag);       // check and count how many times the files with extension belong to VIDEOS vector appears
                FileExtn(DOCUMENTS, file,flag);    // check and count how many times the files with extension belong to DOCUMENTS vector appears
                FileExtn(ARCHIVES, file,flag);     // check and count how many times the files with extension belong to ARCHIVES vector appears
                FileExtn(AUDIO, file ,flag);       // check and count how many times the files with extension belong to AUDIO vector appears
                FileExtn(PLAINTEXT, file,flag );   // check and count how many times the files with extension belong to PLAINTEXT vector appears
                FileExtn(SOURCE_CODE, file,flag ); // check and count how many times the files with extension belong to SOURCE_CODE vector appears
                FileExtn(OBJECT, file,flag);       // check and count how many times the files with extension belong to OBJECT vector appears
                FileExtn(LIBRARY, file,flag);      // check and count how many times the files with extension belong to LIBRARY vector appears
                FileExtn(EXECUTABLE, file,flag);   // check and count how many times the files with extension belong to EXECUTABLE vector appears
            }

            showInfo(IMAGE_count,"red","IMAGE");
            showInfo(VIDEO_count,"green","VIDEO");
            showInfo(DOCUMENT_count,"yellow","DOCUMENT");
            showInfo(ARCHIVES_count,"blue","COMPRESSED");
            showInfo(AUDIO_count,"mag","AUDIO");
            showInfo(PLAINTEXT_count,"cyn","PLAINTEXT");
            showInfo(SOURCE_CODE_count,"blue","SOURCE_CODE");
            showInfo(OBJECT_count,"cyn","OBJECT");
            showInfo(LIBARARY_count,"green","LIBRARY");
            showInfo(EXECUTABLE_count,"mag","EXECUTABLE");
            
            break;
        
            case 2:  // Organize option
            for (auto file : files)
            {   
                bool flag = true; // to ensure that new folders will be created to move each detected file to it crosspound folder
                FileExtn(IMAGES, file, flag);
                FileExtn(VIDEOS, file,flag);
                FileExtn(DOCUMENTS, file,flag); 
                FileExtn(ARCHIVES, file,flag); 
                FileExtn(AUDIO, file ,flag);
                FileExtn(PLAINTEXT, file,flag );
                FileExtn(SOURCE_CODE, file,flag );
                FileExtn(OBJECT, file,flag); 
                FileExtn(LIBRARY, file,flag);
                FileExtn(EXECUTABLE, file,flag);
            }
        
            break;
       
            default:
            std::cout<<BOLD(FRED("Invalid option!!\n"));
    }
    
    }

void check::FileExtn(std::vector<std::string> File, std::string  Myfile, bool flag)
    {    
        for(int i=0; i<File.size(); i++)   //for all the elements of the vector File
        { 
            if(Myfile.substr(Myfile.find_last_of(".") + 1) == File[i])  // if an element Myfile has an extension equivelant to the vector element File[i] 
            {
                if(File==IMAGES) { IMAGE_count++; Move_File(Myfile, Myfile, "IMAGES",flag);} //increase the IMAFE_count by one and move the detected file with IMAGE extension to the created folder IMAGES
                if(File==VIDEOS) {  VIDEO_count++; Move_File(Myfile, Myfile, "VIDEOS",flag);}  
                if(File==DOCUMENTS) { DOCUMENT_count++; Move_File(Myfile, Myfile, "DOCUMENTS",flag);}  
                if(File==ARCHIVES) { ARCHIVES_count++; Move_File(Myfile, Myfile, "ARCHIVES",flag);}  
                if(File==AUDIO) { AUDIO_count++; Move_File(Myfile, Myfile, "AUDIO",flag); }  
                if(File==PLAINTEXT) { PLAINTEXT_count++; Move_File(Myfile, Myfile, "PLAINTEXT",flag);}  
                if(File==SOURCE_CODE) {SOURCE_CODE_count++; Move_File(Myfile, Myfile, "SOURCE_CODE",flag); }  
                if(File==OBJECT) { OBJECT_count++; Move_File(Myfile, Myfile, "OBJECT",flag);}  
                if(File==LIBRARY) { LIBARARY_count++; Move_File(Myfile, Myfile, "LIBRARY",flag);}  
                if(File==EXECUTABLE) {  EXECUTABLE_count++; Move_File(Myfile, Myfile, "EXECUTABLE",flag);}         
            }                
        } 
    }

void check::showInfo(int count,std::string color ,std::string key) // print information about the file if its count is greater than its initial valule 0;
    {            
        if(count>0)
        {   
           int totcount = IMAGE_count + VIDEO_count + DOCUMENT_count
                        + ARCHIVES_count + AUDIO_count + PLAINTEXT_count
                        + SOURCE_CODE_count + OBJECT_count + LIBARARY_count
                        +  EXECUTABLE_count ;
           funcy(count, totcount, color, key );   
        }        
    }

void check::Move_File(std::string f_old, std::string f_new, std::string dir_new, bool flag)
    {   
      if(flag==true)
      {
      		fs::create_directory(dir_new); //create a new folder 
       	fs::rename(f_old, dir_new+"/"+f_new);  //move f_old file to the new folder with the new name (chose alway the smae names to avoid files modifications)
      }
    }

#include<iostream>
#include<string>
#include<vector>
#include <dirent.h>
#include <filesystem> // C++17
#include<unistd.h>
#include"organize.h"
#include"layout.h"
 
namespace fs = std::filesystem;

using namespace std;
 
void funcy(int crrval, int tot, string color, string typ) {
string a = BOLD(FRED("#"));
string b = BOLD(FGRN("###"));
string c = BOLD(FYEL("###"));

 char x ='*';
 int update= (crrval)*100./tot;
 
 if (color=="red") {
 cout<<BOLD(FRED("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<endl;
 }
 
 if (color=="green") {
 cout<<BOLD(FGRN("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<endl;
 }
 if (color=="yellow") {
 cout<<BOLD(FYEL("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<endl;
 }
 
 if (color=="blue") {
 cout<<BOLD(FBLU("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<endl;
 
}

 if (color=="mag") {
 cout<<BOLD(FMAG("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<endl;
 
}

 if (color=="cyn") {
 cout<<BOLD(FCYN("["<<std::string(update/2,x)<<"]"))<<"["<<update<<"%]"<<typ<<": "<<crrval<<" Files"<<endl;
 
}


}
 
check::check(const char*  myfile , int options)
    {
        
        DIR* dir = opendir(myfile);
        if (dir == NULL)
        {
            return;
        }
     
        struct dirent* entity;
        entity = readdir(dir);
    
        while ( entity != nullptr)
        {
            files.push_back(entity->d_name);
            entity = readdir(dir); 
        }
        
        closedir (dir);
        
        if (options==1)
        {
            for (auto file : files)
            {   
                bool flag = false;
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
        }

        if (options==2)
        {
            for (auto file : files)
            {   
                bool flag = true;
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
        }
       
        if(options !=1 && options !=2) {cout<<"please set an option!";}
    }

void check::FileExtn(vector<string> File, string  Myfile, bool flag)
    {    
        for(int i=0; i<File.size(); i++)
        { 
            if(Myfile.substr(Myfile.find_last_of(".") + 1) == File[i]) 
            {
                if(File==IMAGES) { IMAGE_count++; Move_File(Myfile, Myfile, "IMAGES",flag);}  
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

void check::showInfo(int count,string color ,string key)
    {
            
        if(count>0)
        {   
        int totcount = IMAGE_count + VIDEO_count + DOCUMENT_count +  ARCHIVES_count + AUDIO_count +
     PLAINTEXT_count + SOURCE_CODE_count + OBJECT_count + LIBARARY_count +  EXECUTABLE_count ;
            
            //cout<<"The number of "<<key<<" files is: "<<count<<endl; 
            //fs::create_directories(key); 
            
            funcy(count, totcount, color, key );
            
           
        }
        
    }

void check::Move_File(string f_old, string f_new, string dir_new, bool flag)
    {   if(flag==true){
        fs::create_directory(dir_new);
        fs::rename(f_old, dir_new+"/"+f_new); 
        }
    }

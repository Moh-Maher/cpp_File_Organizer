#include<iostream>
#include<string>
#include<vector>
#include <dirent.h>
#include <filesystem> // C++17
#include<unistd.h>


#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x)	"\x1B[1m" x RST
#define UNDL(x)	"\x1B[4m" x RST
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
 
class check{ 
public:
    check(const char*  myfile , int options)
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

    void FileExtn(vector<string> File, string  Myfile, bool flag)
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

    void showInfo(int count,string color ,string key)
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

    void Move_File(string f_old, string f_new, string dir_new, bool flag)
    {   if(flag==true){
        fs::create_directory(dir_new);
        fs::rename(f_old, dir_new+"/"+f_new); 
        }
    }
private:
	vector<string> IMAGES = {"jpeg", "jpg", "tiff", "gif", "bmp", "png", "bpg", "svg", "heif", "psd","ebs"};
	vector<string> VIDEOS = {"avi", "flv", "wmv", "mov", "mp4", "webm", "vob", "mng", "qt", "mpg", "mpeg", "3gp"}; 
	vector<string> DOCUMENTS  = {"oxps", "epub", "pages", "docx", "doc", "fdf", "ods", "odt", "pwi", "xsn", "xps",
	"dotx", "docm", "dox", "rvg", "rtf", "rtfd", "wpd", "xls", "xlsx", "ppt", "ps","epub","js","pdf","pptx"}; 
	vector<string> ARCHIVES = {"a", "ar", "cpio", "iso", "tar", "gz", "rz", "7z", "dmg", "rar", "xar", "zip","xz"}; 
	vector<string> AUDIO = {"aac", "aa", "aac", "dvf", "m4a", "m4b", "m4p", "mp3", "rm","msv", "ogg", "oga", "raw", "vox", "wav", "wma"};
	vector<string> PLAINTEXT = {"txt", "in","dat"};
	vector<string> SOURCE_CODE = {"f","f90","css","c","h","cc","py","cpp","sh","html5", "html", "htm", "xhtml"};
	vector<string> OBJECT = {"obj","o"};
	vector<string> LIBRARY = {"a","so"};
	vector<string> EXECUTABLE = {"exe","deb","run","out"};
	  
	vector<string> files;
	int IMAGE_count=0;
 	int VIDEO_count=0;
        int DOCUMENT_count=0;
	int ARCHIVES_count=0;
        int AUDIO_count=0;
    int PLAINTEXT_count=0;
    int SOURCE_CODE_count=0;
    int OBJECT_count=0;
    int LIBARARY_count=0;
    int EXECUTABLE_count=0;
};


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

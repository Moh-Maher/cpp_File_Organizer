
#ifndef _ORGANIZE_
#define _ORGANIZE_

#include<iostream>
#include<string>
#include<vector>
#include <dirent.h>
#include <filesystem> // C++17
#include<unistd.h>

 
//namespace fs = std::filesystem;
using namespace std;
 
 void funcy(int crrval, int tot, string color, string typ);
 
class check{ 

public:
    
	check(const char*  myfile , int options);
	void FileExtn(vector<string> File, string  Myfile, bool flag); 
	void showInfo(int count,string color ,string key);   
	void Move_File(string f_old, string f_new, string dir_new, bool flag);
    
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

#endif // end of ORGANIZE

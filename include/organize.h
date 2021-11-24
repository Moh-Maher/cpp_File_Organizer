
#ifndef _ORGANIZE_
#define _ORGANIZE_

#include<string>
#include<vector>

 
 void funcy(int crrval, int tot, std::string color, std::string typ);
 
class check{ 

public:
    
	check(const char*  myfile , int options);
	void FileExtn(std::vector<std::string> File, std::string  Myfile, bool flag); 
	void showInfo(int count,std::string color ,std::string key);   
	void Move_File(std::string f_old, std::string f_new, std::string dir_new, bool flag);
    
private:
	
	std::vector<std::string> IMAGES = {"jpeg", "jpg", "tiff", "gif", "bmp", "png", "bpg", "svg", "heif", "psd","ebs"};
	std::vector<std::string> VIDEOS = {"avi", "flv", "wmv", "mov", "mp4", "webm", "vob", "mng", "qt", "mpg", "mpeg", "3gp"}; 
	std::vector<std::string> DOCUMENTS  = {"oxps", "epub", "pages", "docx", "doc", "fdf", "ods", "odt", "pwi", "xsn", "xps",
	"dotx", "docm", "dox", "rvg", "rtf", "rtfd", "wpd", "xls", "xlsx", "ppt", "ps","epub","js","pdf","pptx"}; 
	std::vector<std::string> ARCHIVES = {"a", "ar", "cpio", "iso", "tar", "gz", "rz", "7z", "dmg", "rar", "xar", "zip","xz"}; 
	std::vector<std::string> AUDIO = {"aac", "aa", "aac", "dvf", "m4a", "m4b", "m4p", "mp3", "rm","msv", "ogg", "oga", "raw", "vox", "wav", "wma"};
	std::vector<std::string> PLAINTEXT = {"txt", "in","dat"};
	std::vector<std::string> SOURCE_CODE = {"f","f90","css","c","h","cc","py","cpp","sh","html5", "html", "htm", "xhtml"};
	std::vector<std::string> OBJECT = {"obj","o"};
	std::vector<std::string> LIBRARY = {"a","so"};
	std::vector<std::string> EXECUTABLE = {"exe","deb","run","out"};
	  
	std::vector<std::string> files;
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

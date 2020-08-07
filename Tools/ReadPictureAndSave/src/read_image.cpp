#include "read_image.h"

const string splitor = ",";
const string kFileSperator = "\\";
void GetAllFiles(const string &path, vector<string> &file_vec)
{
  
    vector<string> path_vector;
    //path_vector：获得所有文件及文件夹的路径
    SplitPath(path, path_vector);
    for(string every_path:path_vector)
    {
        //判断文件路径是否存在
        if(IsPathExist(every_path))     
        {
            file_vec.emplace_back(every_path);
        }
        else
        {
            continue;
        }
    }
}

/*
char *strtok(char *str, const char *delim) 分割字符串
*/
void SplitPath(const string &path,vector<string> &path_vector)
{
    char *char_path = const_cast<char *> (path.c_str());
    const char *split = splitor.c_str();
    char *temp = strtok(char_path, split); //strtok在头文件<string.h>中
    while (temp)
    {
        path_vector.emplace_back(string(temp));
        temp = strtok(nullptr, split);     
    }

}

bool IsPathExist(const string &path)
{
    ifstream file(path);    //创建文件句柄
    if(!file)
    {
        return false;
    }
    return true;
} 


void SaveImages( vector<string> file_vector,const string &out_dir)
{
    
       for (string file:file_vector)
    {
        //cout << file << endl;
        Mat img = imread(file);

        //string.find_last_of(const string& str)从后向前搜索
        //在字符串中搜索与参数str中任一字符匹配的字符，返回其位置
        int pos = file.find_last_of(kFileSperator);
        //cout << pos << endl;
        string file_name=file.substr(pos+1);
        cout << file_name << endl;
        string save_path = out_dir + "\\out_"+file_name;
        cout << save_path << endl;
        bool ret = imwrite(save_path, img);
        if (!ret)
        {
            cout<<"[ERROR] Failed to save img="<<save_path<<endl;
            continue;
        }
       

    }
    
}

/**
bool IsDirectory(const string &path)
{
    struct stat buf;
    
    //int stat(const char * file_name, struct stat *buf);
    //stat()用来将参数file_name 所指文件或文件夹的状态, 复制到参数buf 所指的结构中。
    //返回值：执行成功则返回0，失败返回-1
    
    if (stat(path.c_str(),&buf)!=0)
    {
        return false;
    }
    if(S_ISDIR(buf.st_mode))
    {

    }
}
**/
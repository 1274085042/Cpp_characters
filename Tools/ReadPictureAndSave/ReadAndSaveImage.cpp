#include "src/read_image.h"

/**
*@param:argv[1],"1.jpg,2.png"
**/
int main(int argc,char *argv[])
{
    vector<string> file_vector;
    GetAllFiles(string(argv[1]), file_vector);

    SaveImages(file_vector, string(argv[2]));
    
    return 0;
} 
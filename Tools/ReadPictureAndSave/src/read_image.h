#ifndef _READ_IMAGE_
#define _READ_IAMGE_

#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


void GetAllFiles( const string &path, vector<string> &file_vec);
void SplitPath(const string &path, vector<string> &path_vector);
bool IsPathExist(const string &path);
bool IsDirectory(const string &path);
void SaveImages( vector<string> file_vector,const string &out_dir);

#endif
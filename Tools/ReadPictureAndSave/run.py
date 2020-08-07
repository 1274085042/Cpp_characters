import argparse
import  os
import re
import sys

CPP_EXE=None
CONCOLE_LIST=' {} {}'    #一定要有空格

def get_args():
    '''
    1、创建parser
    2、向parser添加变量
    3、运行.parse_args()
    '''
    parser=argparse.ArgumentParser()
    parser.add_argument('-i','--input_path',nargs='*',required=True,help='file path or folder of input images.')
    parser.add_argument('-o','--output_path',help='folder of output images')
    return  parser.parse_args()

def validate_args(args):
    check_flag=True
    for path in args.input_path:
        if os.path.isdir(path):
            if not os.listdir(path):
                print("[ERROR] input image path=%r is empty" %path)
                check_flag=False
        elif not os.path.isfile(path):
            print("[ERROR] input images path=%r does not exist"%path)
            check_flag=False
    if os.path.isfile(args.output_path):
        print("[ERROR] output_path should be a floder")
        check_flag=False
    elif not os.path.exists(args.output_path):
        os.makedirs(args.output_path)

    return check_flag

def Init_CPP_EXE():
    check_flag=True
    global CPP_EXE
    file_dir=os.getcwd()
    for dirpath,dirname,filename in os.walk(file_dir):
        for file in filename:
            if re.match(".*.exe",file):
                #CPP_EXE=dirpath+'/'+file
                CPP_EXE=file
                break
    if not CPP_EXE:
        print("[ERROR] excute file does not exist")
        check_flag=False
    return  check_flag

def assemble_console_params(args):
    #print(args.input_path)
    image_path=','.join(args.input_path)
    console_params=CONCOLE_LIST.format(image_path,args.output_path)
    return console_params

def main():
    args=get_args()
    if validate_args(args):
        if Init_CPP_EXE():
            console_params=assemble_console_params(args)
            #print(CPP_EXE)
            #print(console_params)
            print(CPP_EXE+console_params)
            os.system(CPP_EXE+console_params)
            #os.system("dir")

if __name__=="__main__":
    main()

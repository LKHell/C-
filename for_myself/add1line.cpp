// readFile.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//引申：文件拷贝
void fileCopy(string file1, string file2) {
	ifstream in(file1);
	ofstream out(file2);
	if (in) {
		string line;
		while (getline(in, line)) {
			//cout << line << endl;
			out << line +'\n'<< endl;
		}
	}
	else {
		cout << "File Not Exist" << endl;
	}
	in.close();
	out.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	////1.逐行读取TXT文档
	//ifstream in("C:\\forcpp\\R1117.txt");    
	//string line;
	//while(getline(in,line)){//逐行读取in中的数据，并把数据保存在line中
	//    cout << line << endl;
	//}
	//in.close();

	////2.读取一个文件，并将文件内容写入到另一个文件中
	//string filePath = "C:\\forcpp\\";//文件路径，此处为绝对路径
	//ifstream in(filePath + "config.txt");    
	//ofstream out(filePath + "result.txt");
	//string line;
	//if(in){
	//    while(getline(in,line)){
	//        cout << line << endl;
	//        out << line << endl;//把从config文件中读取的内容写到result文件中
	//    }
	//}
	//else{
	//    cout << "File Not Exist" << endl;
	//}
	//in.close();
	//out.close();

	//3.调用fileCopy方法
	string filePath = "C:\\forcpp\\";
	string file1 = filePath + "config.txt";
	string file2 = filePath + "result.txt";
	fileCopy(file1, file2);

	return 0;
}
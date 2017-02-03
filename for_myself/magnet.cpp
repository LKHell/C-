// for magnet;
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;
using namespace std;

int main()
{
	
	string s;
	string a = "magnet:?xt=urn:btih:";
	while(1)
	{
		cout << "input your code "<<endl;
		cin >> s;
		cout << a + s <<"\n\n"<< endl;
	}
	
    return 0;
}


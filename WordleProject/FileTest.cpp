#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//len=135,words=17
int main()
{
	fstream s1("./source.txt", ios::in);
	string buffer;
	s1 >> buffer;
	fstream write1("./newres.txt", ios::trunc | ios::out);
	int len = buffer.length();
	int pointcnt = 0;
	for (int i = 0; i < len; i++) {
		write1 << buffer[i];
		if (buffer[i] == ',') {
			pointcnt++;
			if (pointcnt == 17) {
				write1 << "\n";
				pointcnt = 0;
			}
		}
	}
	s1.close();
	write1.close();
	cout << "ÒÑÍê³É£¡" << endl;
	return 0;
}

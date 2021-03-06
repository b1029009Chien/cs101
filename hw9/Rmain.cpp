#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReplaceMystring {
	public:
		ofstream out;
		ifstream in;
		string str;
        int i = 0, j, k;
		void replaceString(string str1, string str2) {
			out.open("Rmain.cpp");
			in.open("main.cpp");
			while(getline(in, str)) {
				int str1_pos = str.find(str1);
				int str2_pos = str.find(str2);
				if(str1_pos != string::npos && str2_pos != string::npos) {
					int len = str.length();
					int len1 = str1.length();
					int len2 = str2.length();
					int start = str2.find(str1);
					string str_front, str_behind;
					str1 = str2;
					str2 = str2.assign(str2, 0, start - 1);
					str_behind = str_behind.assign(str2, start + len1, len2 - len1);
					str2 += str_behind;
					for(i = 0; i < str1_pos; i++) {
						out << str[i];
					}
					out << str1;
					for(j = i + len1; j < str2_pos; j++) {
						out << str[j];
					}
					out << str2;
					for(k = j + len2; k < len; k++) {
						out << str[k];
					}
					out << endl;	
				} else {
					out << str << endl;
				}
			}
			in.close();
			out.close();
		}
};

int main() {
	ReplaceMystring my;
	my.replaceString("IU is best", "IU is best is best");
	return 0;
}

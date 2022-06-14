#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString{
    
};

class ReadClass{
    private:
        ifstream in;
        string str, out, file = "main.cpp";
        int count;
    public:
        ReadClass(){
            in.open(file);
            count = 0;
        }
        ~ReadClass(){
            in.close();
        }
        void showClass(){
            while(getline(in, str)){
                string pt = "";
                int point = str.find("class ",0);
                if(point != -1){
                    for(char t:str){
                        if (t != '{') pt += t;
                        else {
                            out += pt + "\n";
                            count++;
                        }
                            
                    }
                }
            }
            cout << count << " class in " << file << endl << out;
            
        }
};
int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}

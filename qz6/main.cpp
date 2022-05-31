#include <iostream>
#include <string>

using namespace std;

class Clock {
    protected:
        int Hour;
        int minute;
        int second;
        string meridian;
    public:
        Clock(int x, int y, int z, string w) {
            if(x >= 1 && x <= 12)Hour = x;
            if(y >= 0 && y <= 59)minute = y;
            if(z >= 0 && z <= 59)second = z;
            if(!w.compare("AM")||!w.compare("PM"))meridian = w;
        }
        void display() {
            cout << Hour << ":" << minute << ":" << second << meridian <<endl;
        }
};

class StandardClock : Clock {
    public:
        StandardClock(int x, int y, int z, string w) : Clock(x, y, z, w) {
            Hour = x;
            minute = y;
            second = z;
            meridian = w;
        }
       void display() {
            if (!meridian.compare("AM"))
                cout << Hour;
            if (!meridian.compare("PM")) {
                cout << Hour+12;
            cout<< ":" << minute << ":" << second << endl;
            }
        }
};

class MilitaryClock : Clock {
    public:
        MilitaryClock(int x, int y , int z, string w) : Clock(x, y, z, w) {
            Hour = x;
            minute = y;
            second = z;
            meridian = w;
        }
        void display() {
            if (!meridian.compare("AM"))
                cout << Hour;
            if (!meridian.compare("PM")) {
                cout << Hour+12;
            cout<< ":" << minute << ":" << second << endl;
            }
        }
};

int main() {
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();

    return 0;
}

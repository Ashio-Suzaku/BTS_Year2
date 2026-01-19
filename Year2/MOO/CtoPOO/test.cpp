#include "cmembre.h"
#include "cclubsportif.h"
#include <iostream>

using namespace std;

int main() {

    CMembre membre1("Tournelle", "Marie", CDate(1, AVR, 2000));
    puts("1");
    CClubSportif club1((string)"Chess Club");
    puts("2");
    club1.addMember(membre1);
    puts("3");
    cout << membre1.print() << endl;
    //cout << club1.list() << endl;
    club1.list();

    return 0;

}

//g++ -W -o testClub cclubsportif.cpp cdate.cpp cmembre.cpp test.cpp tdate.cpp tmonth.cpp
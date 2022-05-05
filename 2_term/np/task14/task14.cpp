#include <iostream>
#include "aps.h"

using namespace std;

int main()
{
    Aps station = Aps();
    station.add_consumer(cin, "consumer");
    station.add_consumer(cin, "legal");
    station.add_consumer(cin, "individual");
}
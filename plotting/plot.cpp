#include <iostream>
#include <cstdint>
#include <matplot/matplot.h>
#include <sstream>
#include <fstream>
#include "log.h"

using namespace std;

int main(int argc, char *argv[])
{
    physlog::log flog;
    if(argc < 2)
    {
        cout << "Usage: " << argv[1] << " <filename>" << endl;
        return 1;
    }
    ifstream file(argv[1], ios::in);
    if(!file)
    {
        cerr << "Error while opening file." << endl;
        return 2;
    }
    string line;
    while (getline(file, line))
    {
        istringstream lineStream(line);
        string timeStr, heightStr, velocityStr;
        if (getline(lineStream, timeStr, ',') &&
            getline(lineStream, heightStr, ',') &&
            getline(lineStream, velocityStr, ',')) {
            flog.time.push_back(stof(timeStr));
            flog.height.push_back(stof(heightStr));
            flog.velocity.push_back(stof(velocityStr));
        }
    }
    using namespace matplot;
    plot(flog.time, flog.height);
    title(argv[1]);
    show();
    file.close();
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "physics.h"
/*
 * This is the file with the main function for the software.
 *
 * The purpose of this software is simple, calculating the time it takes for an object to fall from a certain height to the ground. This simulation is simulating a free fall with air resistance.
 * 
 * It takes three arguments, the height of the object, the terminal velocity of the object and the weight of the object.
 * The software will then calculate the time it takes for the object to fall to the ground.
 * Then It's going to save the data to a CSV file.
*/
using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        cout << "Syntax error!" << endl;
        cout << "Usage: gravity <height> <terminal_velocity> <weight>" << endl;
        return 1;
    }
    float height = atof(argv[1]);
    float terminal_velocity = atof(argv[2]);
    float weight = atof(argv[3]);
    cout << "Height: " << height << "m " << "Terminal Velocity: " << terminal_velocity << "m/s " << "Weight: " << weight << "kg" << endl;
    Object *object = new Object();
    object->set_data(height, weight, terminal_velocity);
    object->calculate();
    cout << "it took " << object->get_time() << " seconds to fall" << endl;
    std::ostringstream filename;
    filename << "Fall_" << height << "m.csv";
    std::ofstream file(filename.str());
    if(file.is_open())
    {
        file << "Time, Height, Velocity" << endl;
        for(int i = 0; i < object->time_log.size(); i++)
        {
            file << object->time_log[i] << ", " << object->height_log[i] << ", " << object->velocity_log[i] << endl;
        }
        file.close();
    } else 
    {
        cout << "Error: Unable to open file" << endl;
        return 2;
    }
    cout << "Data saved to Fall_" << height << "m.csv" << endl;
    delete object;
    return 0;
}
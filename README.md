# Free fall with air resistance

This is the code that simulates a free fall movement with air resistance. 

It takes in height of the falling object, its terminal velocity, and its weight. after all the calculation is done, the time, height, and velocity gets written to the csv file with the name: ```Fall_<height>m.csv```

To use it, type in the following command to compile:
```
g++ -std=c++11 physics.cpp gravity.cpp -o <your output file name>
```
Then you can use it with the following syntax:
```
./<your output filename> <height> <object's terminal velocity> <object's weight>
```

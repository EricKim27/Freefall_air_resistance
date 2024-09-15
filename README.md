# Free fall with air resistance

This is the code that simulates a free fall movement with air resistance. 

It takes in height of the falling object, its terminal velocity, and its weight. after all the calculation is done, the time, height, and velocity gets written to the csv file with the name: ```Fall_<height>m.csv```

To use it, make a build directory, and type in this command:
```
 $ cmake <path to this code>
 $ make
```
Then you can use it with the following syntax:
```
 $ ./<your output filename> <height> <object's terminal velocity> <object's weight>
```

You can use the output file(in a csv format) to make an animation with the code inside the Animation folder by:

```
 $ python Animaton\animate.py
 $ Input csv file: <your csv file name>
```
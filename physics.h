#include <vector>
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

typedef std::vector<float> plist_t;

class Object {
    float time, height, velocity, weight, terminal_velocity;
    float gravity = 9.8;
    public:
        plist_t height_log, velocity_log, time_log;
        void log_time(float t);
        void log_height(float h);
        float get_time();
        void log_velocity(float v);
        void set_data(float h, float w, float tv);
        void calculate();
};
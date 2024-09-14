#include "physics.h"
#include <iostream>

void Object::log_time(float t)
{
    time_log.push_back(time);
}
void Object::log_height(float h)
{
    height_log.push_back(height);
}
float Object::get_time()
{
    return time;
}
void Object::log_velocity(float v)
{
    velocity_log.push_back(velocity);
}
void Object::set_data(float h, float w, float tv)
{
    height = h;
    weight = w;
    terminal_velocity = tv;
}
void Object::calculate()
{
    float original_height = height;
    while (height > 0)
    {
        float air_resistance;
        if (velocity < terminal_velocity)
            air_resistance = (weight * gravity * velocity) / terminal_velocity;
        else
            air_resistance = weight * gravity;

        float net_force = weight * gravity - air_resistance;
        if (net_force < 0) net_force = 0; // prevent net force from becoming negative

        velocity += net_force * 0.001;
        height -= velocity * 0.001;
        time += 0.001;
        log_time(time);
        log_height(height);
        log_velocity(velocity);
        if (height > original_height)
        {
            std::cout << "Error: Object is ascending" << std::endl;
            break;
        }
    }
}
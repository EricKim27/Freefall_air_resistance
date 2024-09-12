#include <vector>

typedef std::vector<float> plist_t;

class Object {
    float time, height, velocity, weight, terminal_velocity;
    float gravity = 9.8;
    public:
        plist_t height_log, velocity_log, time_log;
        void log_time(float t);
        void log_height(float h);
        float get_data();
        float get_time();
        void log_velocity(float v);
        void set_data(float h, float w, float tv);
        void calculate();
};

class Graphics {
public:
    Graphics(plist_t height_log, plist_t v_log, plist_t t_log);
    ~Graphics();
    void draw_graphics();
private:
    plist_t _h_log, _v_log, _t_log;
};
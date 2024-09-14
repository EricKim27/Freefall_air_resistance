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

class Graphics {
public:
    Graphics(plist_t height_log, plist_t v_log, plist_t t_log);
    ~Graphics();
    void setupOGL();
    void renderSphere();
    void render();
    void initsphere();
    void movesphere(float x, float y, float z);
    void draw_sim();
private:
    plist_t _h_log;
    plist_t _v_log;
    plist_t _t_log;
    GLFWwindow* window;
    GLuint shaderProgram;
    GLuint VBO;
    GLuint VAO;
    glm::mat4 model;
    glm::vec3 spherePosition;
    std::vector<float> sphereVertices;
};
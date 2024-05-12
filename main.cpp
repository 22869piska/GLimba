//#include <GL/glut.h>
//#include <glfw3.h>
//#include"glad.h"
//#include <glad\glad.h>
#include<GLEW/GL/glew.h>
#include <GLFW\glfw3.h>
#include<iostream>
#include<fstream>
#include<string>
//

#include"smotritel.cpp"
//
#pragma comment (lib,"opengl32.lib")
using namespace std;
//
/// ///////////////////////////////////////////////////





void keyboard(GLFWwindow* window) {//knopki;
    if (glfwGetKey(window, GLFW_KEY_A) == true) {

       // cout << "A";
        glClearColor(8, 1, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == true) {

      //  cout << "D";
        glClearColor(0.0f, 1, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == true) {

        //cout << "W";
        glClearColor(0.5f, 0.9f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
   
}



void resize(GLFWwindow* window,int x,int y) {
    glViewport(0,0,x ,y);
    cout << x << '-' << y << endl;
}



char textvs[] = { "#version 330 core\
layout(location = 0) in vec3 aPos;\
void main()\
{\
gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0f);\
}" };

int main(void)
{


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//VER
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//VERmin
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//залупакактетет

    GLFWwindow* window = glfwCreateWindow(1200, 800, "GYM", 0, 0);

    glfwMakeContextCurrent(window);//юзатьчтб ибо пидр не хочет автоматом понимать что нада его юзханть он пидр;
    if (glfwCreateWindow == 0) { return 228; }//еслнеоткрытовиндов



    //st
    //gladLoadGL();//загрузить и исп gl;//Ќ≈–јЅќ“ј≈“
    //if(gladLoadGLLoader ){}
    ////

    glViewport(0, 0, 1200, 800);//показать где те нада быть ваще
  
      
    glfwSetFramebufferSizeCallback(window ,resize);
    //st

    string inf = "vertx.vs";

    float polygon[] = 
    {
        0.1f,0.0f,0.0f,//x
        0.0f,0.1f,0.0f,//y
        -0.5f,0.0f,0.0f,//z
    };
    unsigned int  vbo_polygon;
    glGenBuffers(1, &vbo_polygon);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_polygon);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9,polygon, GL_STATIC_DRAW);//static--//dynamic типа есть;
    checkfile(inf);//smotritel.cpp;
    unsigned int vertexsh = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexsh,1,(char** const) & shadertext,0 );
    glCompileShader(vertexsh);
    //next
   // fileclear();
    shadertext[0] = 0;

     inf = "fragsh.fsh";
    checkfile(inf);//smotritel.cpp;
    unsigned int fragmentsh = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(fragmentsh, 1, (char** const)&shadertext, 0);
    glCompileShader(fragmentsh);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////whileokno;
    unsigned int  shaderprog; shaderprog = glCreateProgram();
    glAttachShader(shaderprog, vertexsh);  glAttachShader(shaderprog, fragmentsh);
    glLinkProgram(shaderprog); glGetProgramiv(shaderprog,GL_LINK_STATUS,0);

    while (!glfwWindowShouldClose(window))//сидим;
    {
      //  cout << "start while";
        glfwPollEvents();//действие с кном;

     
        glClearColor(0, 0, 0.4f, 1.0f);//цветф0набл;
        glClear(GL_COLOR_BUFFER_BIT);//bfswp
      

        //next->
        keyboard(window);




































        //end
      
        glfwSwapBuffers(window);
    }




    //end2

    glfwDestroyWindow(window);//убить окно;
    glfwTerminate();//ливнуть;
    return 0;
}
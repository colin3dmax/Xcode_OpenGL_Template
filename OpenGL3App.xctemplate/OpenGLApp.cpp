//
//  OpenGLApp.cpp
//  TriangleBuffer
//
//  Created by colin3dmax on 15/4/30.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include "OpenGLApp.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>
cross3d::App::App()
{
    
}

void onKeyDownTest(GLFWwindow* ,int ,int,int,int )
{
    
}

cross3d::App* cross3d::App::mInstance=NULL;

cross3d::App::App(const string& title,int width=250,int height=250 ){
    mTitle = title;
    mWidth = width;
    mHeight = height;
    if(!glfwInit()){
        cout << "glfw initialized fail!" << endl;
        exit(EXIT_FAILURE);
    }
    mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), NULL, NULL);
    if (!mWindow) {
        cout << "glfwCreateWindow fail!" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(mWindow);
    glfwSwapInterval(1);

    glClearColor(0, 0, 0, 0);
    
    mInstance = this;
    
    m_func_onKeyDown = std::bind(&cross3d::App::onKeyDown, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
    
    glfwSetKeyCallback(mWindow,[](GLFWwindow* window,int key,int scancode,int action,int mods )->void{
        cross3d::App::mInstance->onKeyDown(window, key, scancode, action, mods);
    });
    
    glfwSetMouseButtonCallback(mWindow, [](GLFWwindow * window,int button,int action,int mods){
        cross3d::App::mInstance->onMouseDown(window, button, action, mods);
    });
    
    glfwSetCursorPosCallback(mWindow,[](GLFWwindow* window,double x,double y )->void{
        cross3d::App::mInstance->onMouseMove(window, x, y );
    });
    
}

void cross3d::App::onDraw()
{
    glClear(GL_COLOR_BUFFER_BIT);
}


void cross3d::App::start()
{
    while (!glfwWindowShouldClose(mWindow)) {
        onDraw();
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
    glfwTerminate();
}

void cross3d::App::onKeyDown(GLFWwindow * window,int key,int scancode,int action,int mods)
{
    cout << "onKeyDown" << key << "scancode:" << scancode << "action:" << action << "mods:" << mods << endl;
}
void cross3d::App::onMouseMove(GLFWwindow * window,double x,double y)
{
    cout << "onMouseMove:"<< x <<","<< y << endl;
}
void cross3d::App::onMouseDown(GLFWwindow * window,int button,int action,int mods)
{
    cout << "onMouseDown:" << button << "action:" << action << "mods:" << mods << endl;
}

void cross3d::App::setViewport()
{
    glfwGetFramebufferSize(mWindow, &mWidth, &mHeight);
    glViewport(0, 0, mWidth, mHeight);
}

bool cross3d::App::shouldClose()
{
    return glfwWindowShouldClose(mWindow);
}

void cross3d::App::swapBuffers()
{
    
}

void cross3d::App::destroy()
{
    glfwDestroyWindow(mWindow);
}

cross3d::App::~App()
{
    destroy();
}


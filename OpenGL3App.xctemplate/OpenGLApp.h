//
//  OpenGLApp.h
//  TriangleBuffer
//
//  Created by colin3dmax on 15/4/30.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#ifndef __TriangleBuffer__OpenGLApp__
#define __TriangleBuffer__OpenGLApp__
#include "gl_lib.h"
#include <iostream>
#include <string>

using namespace std;
namespace cross3d {
    
typedef void(*keyDownhandle)(GLFWwindow* ,int ,int,int,int);
typedef std::function<void(GLFWwindow* ,int ,int,int,int) > Funcp;

class App{
public:
//    static App* getInstance();
    App();
    App(const string& title,int width,int height);
    ~App();
    void start();
    virtual void onKeyDown(GLFWwindow * window,int key,int scancode,int action,int mods);
    virtual void onMouseMove(GLFWwindow * window,double x,double y);
    virtual void onMouseDown(GLFWwindow * window,int button,int action,int mods);
    virtual void onDraw();
    
    void setViewport();
    bool shouldClose();
    
    void swapBuffers();
    void destroy();
    
    GLFWwindow* mWindow;
    static App *mInstance;
private:
    int mWidth;
    int mHeight;
    string mTitle;
    Funcp m_func_onKeyDown;
    
    
    
};
    
}

#endif /* defined(__TriangleBuffer__OpenGLApp__) */

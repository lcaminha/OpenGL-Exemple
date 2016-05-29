#include <iostream>
#include <string>

// https://wiki.libsdl.org/Introduction
#include <SDL2/SDL.h>
#include <GL/glew.h>

class Display{
    public:
        Display(int largura,int altura,const std::string& titulo);
        virtual ~Display();
        void update();
        void clear(float r,float g, float b, float a);
        bool isClosed();
    private:
        Display(const Display& other){}
        SDL_Window *m_window;
        SDL_GLContext m_glContext;
        bool m_isClosed;
};

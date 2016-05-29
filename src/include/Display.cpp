#include "Display.h"

Display::Display(int largura,int altura,const std::string& titulo){

    SDL_Init(SDL_INIT_EVERYTHING); // inicia SDL : https://wiki.libsdl.org/SDL_Init

    //https://wiki.libsdl.org/SDL_GL_SetAttribute
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    //https://wiki.libsdl.org/SDL_CreateWindow
    m_window = SDL_CreateWindow(
        titulo.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        largura,
        altura,
        SDL_WINDOW_OPENGL
    );

    //https://wiki.libsdl.org/SDL_GL_CreateContext
    m_glContext = SDL_GL_CreateContext(m_window);
    GLenum status = glewInit();
    if(status != GLEW_OK)  std::cerr << "Glew não iniciou como deveria..." << std::endl;
    m_isClosed = false;
}
Display::~Display(){
    SDL_GL_DeleteContext(m_glContext); // Distroi o contexto...
    SDL_DestroyWindow(m_window); // Destroi a Janela
    SDL_Quit(); // Termina o SDL
}
bool Display::isClosed(){
    return m_isClosed;
}
void Display::clear(float r,float g, float b, float a){
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
}
void Display::update(){
    //https://wiki.libsdl.org/SDL_GL_SwapWindow
    SDL_GL_SwapWindow(m_window);

    SDL_Event e;
    while(SDL_PollEvent(&e))  if(e.type == SDL_QUIT) m_isClosed = true;
}

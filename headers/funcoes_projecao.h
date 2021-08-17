//creditos: https://www.gamedev.net/forums/topic/96440-opengl-2d-text-in-3d-space/
//OBS: SEMPRE QUE CHAMAR projecaoOrto(), e necessario chamar retornaPerspectiva() ao fim da funcao
void projecaoOrto(){
    //glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
            glPushMatrix();
            glLoadIdentity();
            GLint viewport[4];
            glGetIntegerv(GL_VIEWPORT, viewport);
            gluOrtho2D(0,viewport[2], viewport[3], 0);  //largura e altura da janela
            glDepthFunc(GL_ALWAYS);
}

void retornaPerspectiva(){
            glDepthFunc(GL_LESS);
            glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

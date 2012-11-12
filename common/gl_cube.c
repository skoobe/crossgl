/*
 * Copyright (c) 2012 Skoobe GmbH
 */

#if defined(IOS)

#include <CoreGraphics/CoreGraphics.h>
#include <CoreText/CoreText.h>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>

#elif defined(ANDROID)

#include <GLES/gl.h>

#else

#error "unsupported platform"

#endif

#include "gl_cube.h"

static GLfloat vertex_array[] = {
    1, 1, 1, -1, 1, 1, -1,-1, 1,
    -1,-1, 1,  1,-1, 1, 1, 1, 1,
    1, 1, 1, 1,-1, 1, 1,-1,-1,
    1,-1,-1, 1, 1,-1, 1, 1, 1,
    1, 1, 1, 1, 1,-1, -1, 1,-1,
    -1, 1,-1, -1, 1, 1, 1, 1, 1,
    -1, 1, 1, -1, 1,-1, -1,-1,-1,
    -1,-1,-1, -1,-1, 1, -1, 1, 1,
    -1,-1,-1, 1,-1,-1, 1,-1, 1,
    1,-1, 1, -1,-1, 1, -1,-1,-1,
    1,-1,-1, -1,-1,-1, -1, 1,-1,
    -1, 1,-1, 1, 1,-1, 1,-1,-1
};

#define RECT_COLOR(R, G, B, A) R, G, B, A, R, G, B, A, R, G, B, A,\
                               R, G, B, A, R, G, B, A, R, G, B, A

static GLfloat color_array[]   = {
    RECT_COLOR(.48f, .59f, .16f, 1),
    RECT_COLOR(.91f, .94f, .78f, 1),
    RECT_COLOR(.75f, .85f, .45f, 1),
    RECT_COLOR(.94f, .96f, .88f, 1),
    RECT_COLOR(.65f, .79f, .25f, 1),
    RECT_COLOR(.24f, .25f, .02f, 1)
};

void gl_cube_setup(float width, float height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrthof(-4.0f, 4.0f, -6.0f, 6.0f, -8.0f, 20.0f);
}

void gl_cube_draw()
{
    static float rotation = 0;

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    
    glRotatef(30, 1, 0, 0);
    glRotatef(rotation, 0, 1, 0);
    glRotatef(rotation, 0, 0, 1);
    
    rotation = rotation + 0.5;
    
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(4, GL_FLOAT, 0, color_array);
    glVertexPointer(3, GL_FLOAT, 0, vertex_array);

    glPushMatrix();

    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertex_array) / sizeof(vertex_array[0]) / 3);

    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

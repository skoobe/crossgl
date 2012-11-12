#include <jni.h>
#include "../../common/gl_cube.h"

JNIEXPORT void JNICALL Java_net_skoobe_crossgl_CrossGLView_setupCube
  (JNIEnv *env, jclass cls, jfloat width, jfloat height)
{
    gl_cube_setup(width, height);
}

JNIEXPORT void JNICALL Java_net_skoobe_crossgl_CrossGLView_drawCube
  (JNIEnv *env, jclass cls)
{
    gl_cube_draw();
}

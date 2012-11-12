/*
 * Copyright (c) 2012 Skoobe GmbH
 */

package net.skoobe.crossgl;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

public class CrossGLView extends GLSurfaceView implements GLSurfaceView.Renderer {

    //load the c dynamic library when this class is loaded
    static {
        System.loadLibrary("crossgl");
    }
    //functions implemented in jni
    private native static void setupCube(float width, float height);
    private native static void drawCube();
    
    public CrossGLView(Context context) {
        super(context);
        setRenderer(this);
        setRenderMode(RENDERMODE_CONTINUOUSLY);
    }
    
    public CrossGLView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }
    
    @Override
    public void onDrawFrame(GL10 gl) {
        drawCube();
    }
    
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        setupCube(getWidth(), getHeight());
    }
    
    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {}
    
}

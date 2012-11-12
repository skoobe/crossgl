/*
 * Copyright (c) 2012 Skoobe GmbH
*/

#import "GLView.h"
#import "gl_cube.h"
#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/ES1/gl.h>

@implementation GLView
@synthesize context;

+ (Class)layerClass {
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self setup];
        [self startAnimation];
    }
    return self;
}

- (void)startAnimation
{
    id displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(draw)];
    [displayLink setFrameInterval:0.1];
    [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}

- (void)setup
{
    // layer setup
    CAEAGLLayer *layer = (CAEAGLLayer*) self.layer;
    layer.opaque = YES;
    
    // context setup
    EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES1;
    EAGLContext *c = [[EAGLContext alloc] initWithAPI:api];
    self.context = c;
    [c release];
    
    if (!self.context) {
        NSLog(@"Error initializing OpenGLES 1.0 context");
        exit(1);
    }
    
    if (![EAGLContext setCurrentContext:self.context]) {
        NSLog(@"Error setting current OpenGL context");
        exit(1);
    }
    
    // depth buffer
    GLuint depthBuffer;
    glGenRenderbuffers(1, &depthBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, self.frame.size.width, self.frame.size.height);
    
    // color buffer
    GLuint colorBuffer;
    glGenRenderbuffers(1, &colorBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorBuffer);
    [self.context renderbufferStorage:GL_RENDERBUFFER fromDrawable:layer];
    
    // frame buffer
    GLuint framebuffer;
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER, colorBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                              GL_RENDERBUFFER, depthBuffer);
    
    gl_cube_setup(self.frame.size.width, self.frame.size.height);
}

- (void)draw
{
    gl_cube_draw();
    
    [self.context presentRenderbuffer:GL_RENDERBUFFER];
}

- (void)dealloc
{
    [context release];
    [super dealloc];
}

@end

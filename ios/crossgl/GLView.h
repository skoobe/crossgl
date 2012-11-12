/*
 * Copyright (c) 2012 Skoobe GmbH
 */

#import <UIKit/UIKit.h>

@interface GLView : UIView
{
    EAGLContext *context;
}

@property (nonatomic, retain) EAGLContext *context;

@end

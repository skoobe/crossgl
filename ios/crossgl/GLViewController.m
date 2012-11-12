/*
 * Copyright (c) 2012 Skoobe GmbH
 */

#import "GLViewController.h"
#import "GLView.h"

@implementation GLViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    GLView *glView = [[GLView alloc] initWithFrame:self.view.frame];
    [self.view addSubview:glView];
    [glView release];
}

@end

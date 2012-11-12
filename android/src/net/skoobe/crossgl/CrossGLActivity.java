/*
 * Copyright (c) 2012 Skoobe GmbH
 */

package net.skoobe.crossgl;

import android.os.Bundle;
import android.app.Activity;

public class CrossGLActivity extends Activity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new CrossGLView(this));
    }

}

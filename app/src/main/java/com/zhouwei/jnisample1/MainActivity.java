package com.zhouwei.jnisample1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.zhouwei.jnisample1.business.JNIMath;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JNIMath jniMath = new JNIMath();
        Log.i("AAAA", "a+b=" + jniMath.Add(1, 2));
    }
}

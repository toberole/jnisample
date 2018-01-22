package com.zhouwei.jnisample1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.zhouwei.jnisample1.business.C_Callback_Java;
import com.zhouwei.jnisample1.business.JNIDemo;
import com.zhouwei.jnisample1.business.JNIMath;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JNIMath jniMath = new JNIMath();
        Log.i("AAAA", "a+b=" + jniMath.Add(1, 2));

        JNIDemo demo = new JNIDemo();
        String str = demo.getString();
        Log.i("AAAA", "str: " + str);

        C_Callback_Java c_callback_java = new C_Callback_Java();
        c_callback_java.getInfo(new C_Callback_Java.CallBack() {
            @Override
            public void onCallback(String content) {
                Log.i("AAAA", "content: " + content);
            }
        });
    }
}

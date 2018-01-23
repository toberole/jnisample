package com.zhouwei.jnisample1.business;

import android.util.Log;

/**
 * Created by zhouwei on 2018/1/21.
 */

public class C_Callback_Java {

    public interface CallBack {
        void onCallback(String content);
    }

    public void print() {
        Log.i("AAAA","c_call_me_print");
    }

    public native String doWithString(String str);

    public native void getInfo(CallBack cb);

    public native void c_call_me_print();
}

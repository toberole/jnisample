package com.zhouwei.jnisample1.business;

/**
 * Created by zhouwei on 2018/1/21.
 */

public class C_Callback_Java {

    public interface CallBack {
        void onCallback(String content);
    }

    public native void getInfo(CallBack cb);
}

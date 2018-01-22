package com.zhouwei.jnisample1.business;

/**
 * Created by zhouwei on 2018/1/21.
 */

public class JNIDemo {
    static {
        System.loadLibrary("test");
    }

    public native String getString();
}

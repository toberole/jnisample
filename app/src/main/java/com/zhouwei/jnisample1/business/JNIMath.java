package com.zhouwei.jnisample1.business;

/**
 * Created by zhouwei on 2018/1/19.
 */

public class JNIMath {
    static {
        System.loadLibrary("test");
    }

    public native int Add(double num1, double num2);

    public native int Sub(double num1, double num2);

    public native int Mul(double num1, double num2);

    public native int Div(double num1, double num2);
}

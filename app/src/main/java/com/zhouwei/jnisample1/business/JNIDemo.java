package com.zhouwei.jnisample1.business;

/**
 * Created by zhouwei on 2018/1/21.
 */

public class JNIDemo {
    static {
        System.loadLibrary("test");
    }

    public native void test();
    public native byte getByte();
    public native char getChar();
    public native short getShort();
    public native int getInt();
    public native float getFloat();
    public native double getDouble();
    public native String getString();

    public native void test1(byte b);
    public native void test2(char c);
    public native void test3(short s);
    public native void test4(short s,int a);
    // (SI)I
    public native int test44(short s,int a);

    // (Ljava/lang/String;)V
    public native void test5(String i);

    // (Ljava/lang/String;)Ljava/lang/String;
    public native String test55(String i);

    // (Lcom/zhouwei/jnisample1/business/Student;)Lcom/zhouwei/jnisample1/business/Student;
    public native Student test555(Student student);

    // (Lcom/zhouwei/jnisample1/business/Student;)V
    public native void test5555(Student student);
}

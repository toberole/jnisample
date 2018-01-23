package com.zhouwei.jnisample1.business;

/**
 * Created by zhouwei on 2018/1/21.
 */

public class JNIDemo {
    static {
        System.loadLibrary("test");
    }

    // ()V
    public native void test();

    // ()B
    public native byte getByte();

    // ()C
    public native char getChar();

    // ()S
    public native short getShort();

    // ()I
    public native int getInt();

    // ()F
    public native float getFloat();

    // ()D
    public native double getDouble();

    // ()Ljava/lang/String;
    public native String getString();

    // (B)V
    public native void test1(byte b);

    // (C)V
    public native void test2(char c);

    // (S)V
    public native void test3(short s);

    // (SI)V
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

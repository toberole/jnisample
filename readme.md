# 每次在添加了C/C++文件 注意修改Android.mk

<pre>
(JNIEnv *env, jobject jobj ...)
env: JNI 执行环境
jobj:当java层的native方法不是static的时候是指 调用该方法的对象；当java层的native方法是static的时候是指 native方法所在的java层类字节码对象Class
</pre>



#  JNI用法

# (1).andorid CPP调用java函数和访问其成员:

原理 => CPP代码找到java的那个class里面的函数的入口地址,然后在CPP代码中调用java代码

 

步骤1) 用FindClass()函数找到该java类(如android.os.Binder)的实例对象的引用:

　　jclass clazz =env->FindClass(kBinderPathName) =env->FindClass("android.os.Binder")

 

步骤2) 用GetFieldID()函数获取到要访问的域(field: 实际上就是该java class中的某个成员变量的名字)的ID:

　　gBinderOffsets.mObject= env->GetFieldID(clazz, "mObject", "I") // mObject为java class "Binder"里的一个成员变量

　　-> 注意,这里将要访问的那个java对象的成员mObject的ID保存到了全局变量gBinderOffsets.mObject中,这样做的前提和优点如下:

　　前提: android里面,每个java进程中只允许有一个java虚拟机(sun公司原始的java架构中,一个进程中可以有多个java虚拟机)

　　优点: 除了第一次,以后每次要访问该java对象的成员mObject就非常快了(不用再去FindClass()和GetFieldID())

 

步骤3) 用GetMethodID()函数获取到要访问的方法(Method: 实际上就是该java class中的某个成员函数的名字)的ID:

　　gBinderOffsets.mExecTransact= env->GetMethodID(clazz, "execTransact", "(IIII)Z") //execTransact为java class "Binder"里的一个成员函数

 

步骤4) 用类似于GetIntField()的函数获取到该java对象的那个域(即成员)的值:

　　IBinder* target =(IBinder*)env->GetIntField(obj,gBinderProxyOffsets.mObject)

    // 获取javaandroid.os.Binder类型对象里面的成员mObject的值


步骤5) 用类似于CallBooleanMethod()的函数调用到该java对象的那个成员函数:

　　jboolean res =env->CallBooleanMethod(mObject, gBinderOffsets.mExecTransact, code,(int32_t)&data, (int32_t)reply, flags)

 

# (2).android java调用CPP函数:

 

原理 => 相当于java的那个class里面有的函数使用CPP代码来实现了

1)通过结构JNINativeMethod描述java代码调用函数和CPP函数的对应关系:

　　typedef struct {

　　const char* name; //java代码调用CPP函数的入口

　　const char*signature; // CPP函数的返回值

　　void* fnPtr; // CPP的函数名

　　} JNINativeMethod;

　　=> 例如: java代码通过IBinder.transact()来调用CPP的函数android_os_BinderProxy_transact()

　　{"transact","(ILandroid/os/Parcel;Landroid/os/Parcel;I)Z",(void*)android_os_BinderProxy_transact},

 

2)将CPP函数注册到java的某个class中: 使用函数AndroidRuntime::registerNativeMethods()来注册

　　=> 这之后,java代码就可以调用CPP函数了

 

3)java代码调用CPP函数方法:

　　IBinder.transact()

 

总结其原理：C/C++要调用JAVA程序，必须先加载JAVA虚拟机，由JAVA虚拟机解释执行class文件。为了初始化JAVA虚拟机，JNI提供了一系列的接口函数，通过这些函数方便地加载虚拟机到内存中。    
#include <jni.h>
#include <org_alcoholic_leaf_MainJni.h>
#include <sudu_main.h>
#include <android/log.h>

/*JNIEXPORT jstring JNICALL Java_org_alcoholic_leaf_MainJni_test(JNIEnv *env,
        jobject obj, jstring inputStr) {
    const char *str = (const char *) env->GetStringUTFChars(inputStr,
            JNI_FALSE);
    env->ReleaseStringUTFChars(inputStr, (const char *) str);

    sudu_main a;
    a.init();
    a.setMemberTest();
    a.work();
    
    for(int i=0;i<N;i++)
    {
    	for(int j=0;j<N;j++)
    	{
            __android_log_print(ANDROID_LOG_DEBUG,"leaf","%d",Controller::finalArray[i][j]);
        }
    }
    

    return env->NewStringUTF("I am leaf in native");
}*/

JNIEXPORT jintArray JNICALL Java_org_alcoholic_leaf_MainJni_Analysis
  (JNIEnv *env, jobject obj, jintArray arr)
{
    jint *carr = env->GetIntArrayElements(arr, NULL); 
    int len =env->GetArrayLength(arr);  
    sudu_main a;
    a.init();
    for(int i=0; i<len; i++) 
    {  
    	if(carr[i]!=0)
    	{
    		a.setMember(i/9+1,i%9+1,carr[i]);
    	}
    }
    a.work();
    int current=0;
    for(int i=0;i<N;i++)
    {
    	for(int j=0;j<N;j++)
    	{
            carr[current++]=Controller::finalArray[i][j];
        }
    }
    env->ReleaseIntArrayElements(arr, carr, 0);  
    return arr; 
}

#include "include/cn_onlinecache_breakpad_NativeBreakpad_JNI.h"
#include "base/common.h"
#include "third_party/breakpad/src/client/linux/handler/exception_handler.h"
#include "third_party/breakpad/src/client/linux/handler/minidump_descriptor.h"

JavaVM* g_jvm;

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    g_jvm = vm;
    JNIEnv *env;
    if (JNI_OK != vm->GetEnv(reinterpret_cast<void**> (&env),JNI_VERSION_1_4)) {
        LOGE("JNI_OnLoad ====> could not get JNI env");
        return JNI_ERR;
    }

    return JNI_VERSION_1_4;
}

bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                  void* context,
                  bool succeeded){
  LOGE("DumpCallback ===> succeeded %d", succeeded);
  return succeeded;
}

JNIEXPORT jint JNICALL Java_cn_onlinecache_breakpad_NativeBreakpad_nativeInit(JNIEnv* env,
                                                                                  jobject obj,
                                                                                  jstring crash_dump_path){
    const char* path = (char *)env->GetStringUTFChars(crash_dump_path, NULL);
    google_breakpad::MinidumpDescriptor descriptor(path);
    static google_breakpad::ExceptionHandler eh(descriptor, NULL, DumpCallback, NULL, true, -1);
    env->ReleaseStringUTFChars(crash_dump_path, path);
    LOGD("nativeInit ===> breakpad initialized succeeded, dump file will be saved at %s", path);
    return 0;
}

JNIEXPORT jint JNICALL Java_cn_onlinecache_breakpad_NativeBreakpad_nativeTestCrash
(JNIEnv* env, jobject obj) {
    LOGE("native crash capture begin");
    char *ptr = NULL; *ptr = 1;
    LOGE("native crash capture end");
    return 0;
}

#include "UnityNativeBasic.h"

#if _MSC_VER
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif

extern "C" {

    intptr_t EXPORT_API CreateUnityNative() {
        return reinterpret_cast<intptr_t>(new UnityNativeBasic());
    }

    int EXPORT_API GetPointCount(intptr_t unityNative) {
        return reinterpret_cast<UnityNativeBasic*>(unityNative)->getPointCount();
    }

    void EXPORT_API FillPoints(intptr_t unityNative, int count) {
        reinterpret_cast<UnityNativeBasic*>(unityNative)->fill(count);
    }

    void EXPORT_API DestroyUnityNative(intptr_t unityNative) {
        delete reinterpret_cast<UnityNativeBasic*>(unityNative);
    }

    void EXPORT_API GetPoints(intptr_t unityNative, Vector3 *data) {
        auto pts = reinterpret_cast<UnityNativeBasic*>(unityNative)->getPoints();
        std::copy(pts, pts+(GetPointCount(unityNative) * sizeof(Vector3)), data);
    }
}

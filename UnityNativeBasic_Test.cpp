#include "UnityNativeBasic.h"

int main(int argc, char **argv) {

    UnityNativeBasic *basic = new UnityNativeBasic();

    printf("Point Count: %d\n", basic->getPointCount());
    basic->fill(100);
    printf("Point Count: %d\n", basic->getPointCount());

    const Vector3* pts = basic->getPoints();

    for (int i = 0; i < basic->getPointCount(); ++i) {
        printf("Point %d: <<%0.5f, %0.5f, %0.5f>>\n", i, pts[i].x, pts[i].y, pts[i].z);
    }

    delete basic;
}

#include "UnityNativeBasic.h"

void UnityNativeBasic::addValueToX(float x) {

    for (auto &v : points) {
        v.x += x;
    }
};

void UnityNativeBasic::fill(int count) {

    points.resize(count);
    for (int i = 0; i < count; ++i) {
        Vector3 v {
            i * 1.1f, i * 2.2f, i * 3.3f
        };
        points[i] = v;
    }
}

int UnityNativeBasic::getPointCount() const {
    return static_cast<int>(points.size());
}

void UnityNativeBasic::setPoints(const std::vector<Vector3> &ptData) {
    points.resize(ptData.size());
    std::copy(ptData.begin(), ptData.end(), points.begin());
}

Vector3* UnityNativeBasic::getPoints() {
    return points.data();
};

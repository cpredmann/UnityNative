#include<vector>

struct Vector3 {
    float x;
    float y;
    float z;
};

class UnityNativeBasic {
    public:
        UnityNativeBasic() = default;

        void addValueToX(float x);

        int getPointCount() const;

        void setPoints(const std::vector<Vector3> &ptData);

        Vector3* getPoints();

        void fill(int count);

    private:
        std::vector<Vector3> points;
};

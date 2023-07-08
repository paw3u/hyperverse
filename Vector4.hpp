#include <cassert>

class Vector4 {
public:
    constexpr Vector4();
    constexpr Vector4(float x, float y, float z, float w);
    constexpr float dot(const Vector4 &rhs) const;
    constexpr float lenSq() const;
    constexpr Vector4 mult(const Vector4& rhs) const;
    constexpr Vector4 div(const Vector4& rhs) const;
    float x{};
    float y{};
    float z{};
    float w{};
};

constexpr Vector4::Vector4() = default;

constexpr Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

constexpr float Vector4::dot(const Vector4 &rhs) const {
    return x * rhs.x + y * rhs.y; 
}

constexpr float Vector4::lenSq() const {
    return dot(*this); 
}

constexpr Vector4 Vector4::mult(const Vector4& rhs) const {
    return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
}

constexpr Vector4 Vector4::div(const Vector4& rhs) const {
    assert(rhs.x != 0 && "Vector4::div() cannot divide by 0");
    assert(rhs.y != 0 && "Vector4::div() cannot divide by 0");
    assert(rhs.z != 0 && "Vector4::div() cannot divide by 0");
    assert(rhs.w != 0 && "Vector4::div() cannot divide by 0");
    return Vector4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
}

constexpr Vector4 operator-(const Vector4& right){
    return Vector4(-right.x, -right.y, -right.z, -right.w);
}

constexpr Vector4& operator+=(Vector4& left, const Vector4& right){
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    left.w += right.w;
    return left;
}

constexpr Vector4& operator-=(Vector4& left, const Vector4& right){
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    left.w -= right.w;
    return left;
}

constexpr Vector4 operator+(const Vector4& left, const Vector4& right){
    return Vector4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}

constexpr Vector4 operator-(const Vector4& left, const Vector4& right){
    return Vector4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);  
}

constexpr Vector4& operator*=(Vector4& left, float right){
    left.x *= right;
    left.y *= right;
    left.z *= right;
    left.w *= right;
    return left;
}

constexpr Vector4 operator*(const Vector4& left, float right){
    return Vector4(left.x * right, left.y * right, left.z * right, left.w * right);
}

constexpr Vector4 operator*(float left, const Vector4& right){
    return Vector4(right.x * left, right.y * left, right.z * left, right.w * left);
}

constexpr Vector4& operator/=(Vector4& left, float right){
    left.x /= right;
    left.y /= right;
    left.z /= right;
    left.w /= right;
    return left;
}

constexpr Vector4 operator/(const Vector4& left, float right){
    return Vector4(left.x / right, left.y / right, left.z / right, left.w / right);
}

constexpr bool operator==(const Vector4& left, const Vector4& right){
    return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w);
}
constexpr bool operator!=(const Vector4& left, const Vector4& right){
    return (left.x != right.x) || (left.y != right.y) || (left.z != right.z) || (left.w != right.w);
}
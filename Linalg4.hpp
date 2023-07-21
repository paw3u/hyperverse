#include <cassert>
#include <cmath>

class Vector4;
class Matrix4;

/* --------------------------------------------------------- */

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
    return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; 
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

constexpr Vector4 operator-(const Vector4& rhs){
    return Vector4(-rhs.x, -rhs.y, -rhs.z, -rhs.w);
}

constexpr Vector4& operator+=(Vector4& lhs, const Vector4& rhs){
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

constexpr Vector4& operator-=(Vector4& lhs, const Vector4& rhs){
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

constexpr Vector4 operator+(const Vector4& lhs, const Vector4& rhs){
    return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

constexpr Vector4 operator-(const Vector4& lhs, const Vector4& rhs){
    return Vector4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);  
}

constexpr Vector4& operator*=(Vector4& lhs, float rhs){
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    lhs.w *= rhs;
    return lhs;
}

constexpr Vector4 operator*(const Vector4& lhs, float rhs){
    return Vector4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

constexpr Vector4 operator*(float lhs, const Vector4& rhs){
    return Vector4(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w * lhs);
}

constexpr Vector4& operator/=(Vector4& lhs, float rhs){
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    lhs.w /= rhs;
    return lhs;
}

constexpr Vector4 operator/(const Vector4& lhs, float rhs){
    return Vector4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

constexpr bool operator==(const Vector4& lhs, const Vector4& rhs){
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
}
constexpr bool operator!=(const Vector4& lhs, const Vector4& rhs){
    return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z) || (lhs.w != rhs.w);
}

/* --------------------------------------------------------- */

enum RotationPlane {ROT_XY, ROT_XZ, ROT_XW, ROT_YZ, ROT_YW, ROT_WZ};

class Matrix4 {
public:
    constexpr Matrix4();
    constexpr Matrix4(float ax, float ay, float az, float aw,
                      float bx, float by, float bz, float bw,
                      float cx, float cy, float cz, float cw,
                      float dx, float dy, float dz, float dw);
    constexpr Matrix4(int plane, float angle);
    float ax{};
    float ay{};
    float az{};
    float aw{};
    float bx{};
    float by{};
    float bz{};
    float bw{};
    float cx{};
    float cy{};
    float cz{};
    float cw{};
    float dx{};
    float dy{};
    float dz{};
    float dw{};
};

constexpr Matrix4::Matrix4() = default;

constexpr Matrix4::Matrix4(float ax, float ay, float az, float aw,
                           float bx, float by, float bz, float bw,
                           float cx, float cy, float cz, float cw,
                           float dx, float dy, float dz, float dw) : 
                           ax(ax), ay(ay), az(az), aw(aw),
                           bx(bx), by(by), bz(bz), bw(bw),
                           cx(cx), cy(cy), cz(cz), cw(cw),
                           dx(dx), dy(dy), dz(dz), dw(dw) {}

constexpr Matrix4::Matrix4(int plane, float angle){
    switch(plane){
    case ROT_XY:{
        ax = by = std::cos(angle);
        ay = -std::sin(angle);
        bx = -ay;
        cz = dw = 1;
        break;
    }
    case ROT_XZ:{
        ax = cz = std::cos(angle);
        az = -std::sin(angle);
        cx = -az;
        by = dw = 1;
        break;
    }
    case ROT_XW:{
        break;
    }
    case ROT_YZ:{
        break;
    }
    case ROT_YW:{
        break;
    }
    case ROT_WZ:{
        break;
    }
    default:{
        ax = by = cz = dw = 1;
    }
    }
}

constexpr Matrix4 operator-(const Matrix4& rhs){
    return Matrix4(-rhs.ax, -rhs.ay, -rhs.az, -rhs.aw,
                   -rhs.bx, -rhs.by, -rhs.bz, -rhs.bw,
                   -rhs.cx, -rhs.cy, -rhs.cz, -rhs.cw,
                   -rhs.dx, -rhs.dy, -rhs.dz, -rhs.dw);
}

constexpr Matrix4& operator+=(Matrix4& lhs, const Matrix4& rhs){
    lhs.ax += rhs.ax;
    lhs.ay += rhs.ay;
    lhs.az += rhs.az;
    lhs.aw += rhs.aw;
    lhs.bx += rhs.bx;
    lhs.by += rhs.by;
    lhs.bz += rhs.bz;
    lhs.bw += rhs.bw;
    lhs.cx += rhs.cx;
    lhs.cy += rhs.cy;
    lhs.cz += rhs.cz;
    lhs.cw += rhs.cw;
    lhs.dx += rhs.dx;
    lhs.dy += rhs.dy;
    lhs.dz += rhs.dz;
    lhs.dw += rhs.dw;
    return lhs;
}

constexpr Matrix4& operator-=(Matrix4& lhs, const Matrix4& rhs){
    lhs.ax -= rhs.ax;
    lhs.ay -= rhs.ay;
    lhs.az -= rhs.az;
    lhs.aw -= rhs.aw;
    lhs.bx -= rhs.bx;
    lhs.by -= rhs.by;
    lhs.bz -= rhs.bz;
    lhs.bw -= rhs.bw;
    lhs.cx -= rhs.cx;
    lhs.cy -= rhs.cy;
    lhs.cz -= rhs.cz;
    lhs.cw -= rhs.cw;
    lhs.dx -= rhs.dx;
    lhs.dy -= rhs.dy;
    lhs.dz -= rhs.dz;
    lhs.dw -= rhs.dw;
    return lhs;
}

constexpr Matrix4 operator+(const Matrix4& lhs, const Matrix4& rhs){
    return Matrix4(lhs.ax + rhs.ax, lhs.ay + rhs.ay, lhs.az + rhs.az, lhs.aw + rhs.aw,
                   lhs.bx + rhs.bx, lhs.by + rhs.by, lhs.bz + rhs.bz, lhs.bw + rhs.bw,
                   lhs.cx + rhs.cx, lhs.cy + rhs.cy, lhs.cz + rhs.cz, lhs.cw + rhs.cw,
                   lhs.dx + rhs.dx, lhs.dy + rhs.dy, lhs.dz + rhs.dz, lhs.dw + rhs.dw);
}

constexpr Matrix4 operator-(const Matrix4& lhs, const Matrix4& rhs){
    return Matrix4(lhs.ax - rhs.ax, lhs.ay - rhs.ay, lhs.az - rhs.az, lhs.aw - rhs.aw,
                   lhs.bx - rhs.bx, lhs.by - rhs.by, lhs.bz - rhs.bz, lhs.bw - rhs.bw,
                   lhs.cx - rhs.cx, lhs.cy - rhs.cy, lhs.cz - rhs.cz, lhs.cw - rhs.cw,
                   lhs.dx - rhs.dx, lhs.dy - rhs.dy, lhs.dz - rhs.dz, lhs.dw - rhs.dw);
}

constexpr Matrix4& operator*=(Matrix4& lhs, float rhs){
    lhs.ax *= rhs;
    lhs.ay *= rhs;
    lhs.az *= rhs;
    lhs.aw *= rhs;
    lhs.bx *= rhs;
    lhs.by *= rhs;
    lhs.bz *= rhs;
    lhs.bw *= rhs;
    lhs.cx *= rhs;
    lhs.cy *= rhs;
    lhs.cz *= rhs;
    lhs.cw *= rhs;
    lhs.dx *= rhs;
    lhs.dy *= rhs;
    lhs.dz *= rhs;
    lhs.dw *= rhs;
    return lhs;
}

constexpr Matrix4 operator*(const Matrix4& lhs, float rhs){
    return Matrix4(lhs.ax * rhs, lhs.ay * rhs, lhs.az * rhs, lhs.aw * rhs,
                   lhs.bx * rhs, lhs.by * rhs, lhs.bz * rhs, lhs.bw * rhs,
                   lhs.cx * rhs, lhs.cy * rhs, lhs.cz * rhs, lhs.cw * rhs,
                   lhs.dx * rhs, lhs.dy * rhs, lhs.dz * rhs, lhs.dw * rhs);
}

constexpr Matrix4 operator*(float lhs, const Matrix4& rhs){
    return Matrix4(rhs.ax * lhs, rhs.ay * lhs, rhs.az * lhs, rhs.aw * lhs,
                   rhs.bx * lhs, rhs.by * lhs, rhs.bz * lhs, rhs.bw * lhs,
                   rhs.cx * lhs, rhs.cy * lhs, rhs.cz * lhs, rhs.cw * lhs,
                   rhs.dx * lhs, rhs.dy * lhs, rhs.dz * lhs, rhs.dw * lhs);
}

constexpr Vector4 operator*(const Matrix4& lhs, const Vector4& rhs){
    return Vector4(lhs.ax * rhs.x + lhs.ay * rhs.y + lhs.az * rhs.z + lhs.aw * rhs.w,
                   lhs.bx * rhs.x + lhs.by * rhs.y + lhs.bz * rhs.z + lhs.bw * rhs.w,
                   lhs.cx * rhs.x + lhs.cy * rhs.y + lhs.cz * rhs.z + lhs.cw * rhs.w,
                   lhs.dx * rhs.x + lhs.dy * rhs.y + lhs.dz * rhs.z + lhs.dw * rhs.w);
}

constexpr Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs){
    return Matrix4(lhs.ax * rhs.ax + lhs.ay * rhs.bx + lhs.az * rhs.cx + lhs.aw * rhs.dx,
                   lhs.ax * rhs.ay + lhs.ay * rhs.by + lhs.az * rhs.cy + lhs.aw * rhs.dy,
                   lhs.ax * rhs.az + lhs.ay * rhs.bz + lhs.az * rhs.cz + lhs.aw * rhs.dz,
                   lhs.ax * rhs.aw + lhs.ay * rhs.bw + lhs.az * rhs.cw + lhs.aw * rhs.dw,
                   lhs.bx * rhs.ax + lhs.by * rhs.bx + lhs.bz * rhs.cx + lhs.bw * rhs.dx,
                   lhs.bx * rhs.ay + lhs.by * rhs.by + lhs.bz * rhs.cy + lhs.bw * rhs.dy,
                   lhs.bx * rhs.az + lhs.by * rhs.bz + lhs.bz * rhs.cz + lhs.bw * rhs.dz,
                   lhs.bx * rhs.aw + lhs.by * rhs.bw + lhs.bz * rhs.cw + lhs.bw * rhs.dw,
                   lhs.cx * rhs.ax + lhs.cy * rhs.bx + lhs.cz * rhs.cx + lhs.cw * rhs.dx,
                   lhs.cx * rhs.ay + lhs.cy * rhs.by + lhs.cz * rhs.cy + lhs.cw * rhs.dy,
                   lhs.cx * rhs.az + lhs.cy * rhs.bz + lhs.cz * rhs.cz + lhs.cw * rhs.dz,
                   lhs.cx * rhs.aw + lhs.cy * rhs.bw + lhs.cz * rhs.cw + lhs.cw * rhs.dw,
                   lhs.dx * rhs.ax + lhs.dy * rhs.bx + lhs.dz * rhs.cx + lhs.dw * rhs.dx,
                   lhs.dx * rhs.ay + lhs.dy * rhs.by + lhs.dz * rhs.cy + lhs.dw * rhs.dy,
                   lhs.dx * rhs.az + lhs.dy * rhs.bz + lhs.dz * rhs.cz + lhs.dw * rhs.dz,
                   lhs.dx * rhs.aw + lhs.dy * rhs.bw + lhs.dz * rhs.cw + lhs.dw * rhs.dw);
}
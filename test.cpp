#include <Linalg4.hpp>
#include <iostream>

using namespace std;


int main()
{
    Vector4 v4(1, 2, 3, 4);
    cout << v4.x << " " << v4.y << " " << v4.z << " " << v4.w << endl << endl;

    //Matrix4 m4(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);
    Matrix4 m4(ROT_XY, 1);
    cout << m4.ax << " " << m4.ay << " " << m4.az << " " << m4.aw << endl;
    cout << m4.bx << " " << m4.by << " " << m4.bz << " " << m4.bw << endl;
    cout << m4.cx << " " << m4.cy << " " << m4.cz << " " << m4.cw << endl;
    cout << m4.dx << " " << m4.dy << " " << m4.dz << " " << m4.dw << endl << endl;

    Matrix4 a(ROT_XZ, 1);
    cout << a.ax << " " << a.ay << " " << a.az << " " << a.aw << endl;
    cout << a.bx << " " << a.by << " " << a.bz << " " << a.bw << endl;
    cout << a.cx << " " << a.cy << " " << a.cz << " " << a.cw << endl;
    cout << a.dx << " " << a.dy << " " << a.dz << " " << a.dw << endl << endl;


    v4 = m4 * Vector4(1,2,3,4);
    cout << v4.x << " " << v4.y << " " << v4.z << " " << v4.w << endl << endl;

    m4 = m4 * m4;
    cout << m4.ax << " " << m4.ay << " " << m4.az << " " << m4.aw << endl;
    cout << m4.bx << " " << m4.by << " " << m4.bz << " " << m4.bw << endl;
    cout << m4.cx << " " << m4.cy << " " << m4.cz << " " << m4.cw << endl;
    cout << m4.dx << " " << m4.dy << " " << m4.dz << " " << m4.dw << endl << endl;
 
    return 0;
}
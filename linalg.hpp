class Vec;
class Mat;

/* ------------------------------------------------ */

class Vec{
public:
    Vec(int dims, ...);
    ~Vec();
    int d;
    float *x;
    void matmul(Mat *matrix);
    void trans(Vec *vect);
    void print();
};

/* ------------------------------------------------ */

class Mat{
public:
    Mat(int dims, ...);
    ~Mat();
    int d;
    Vec **rows;
    void print();
};

/* ------------------------------------------------ */
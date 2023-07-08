#include <linalg.hpp>
#include <cstdarg>
#include <iostream>

using namespace std;

/* ------------------------------------------------ */

Vec::Vec(int dims, ...){
    d = dims;
    x = new float[dims];
    va_list args;
    va_start(args, dims);
    for (int i=0; i<dims; ++i) {
        x[i] = va_arg(args, double);
    }
    va_end(args);
}

Vec::~Vec(){
    delete [] x;
}

void Vec::matmul(Mat *matrix){
    Vec *res = new Vec(d);
    for(int i=0; i<d; i++){
        res->x[i] = 0.0;
        for(int j=0; j<d; j++){
            res->x[i] += matrix->rows[i]->x[j] * x[j];
        }
    }
    for(int i=0; i<d; i++) x[i] = res->x[i];
    delete res;
}

void Vec::trans(Vec *vect){
    for(int i=0; i<d; i++) x[i] += vect->x[i];
}
void Vec::print(){
    cout << "[";
    for(int i=0; i<d; i++){
        cout << x[i];
        if(i < d-1) cout << ", ";
        else cout << "]" << endl;
    }
}

/* ------------------------------------------------ */

Mat::Mat(int dims, ...){
    d = dims;
    rows = new Vec*[dims];
    va_list args;
    va_start(args, dims);
    for(int i=0; i<dims; i++){
        rows[i] = new Vec(dims);
        for (int j=0; j<dims; ++j) {
            rows[i]->x[j] = va_arg(args, double);
        }
    }
    va_end(args);
}
Mat::~Mat(){
    for(int i=0; i<d; i++){
        delete rows[i];
    }
    delete [] rows;
}

void Mat::print(){
    for(int j=0; j<d; j++){
        cout << "[";
        for(int i=0; i<d; i++){
            cout << rows[j]->x[i];
            if(i < d-1) cout << ", ";
            else cout << "]" << endl;
        }
    }
}

/* ------------------------------------------------ */
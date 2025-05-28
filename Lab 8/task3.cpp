#include<iostream>
using namespace std;

template<typename T>
class Complex{

    private:
    T real;
    T imag;

    public:
    Complex(T r=0, T i=0): real(r), imag(i) {}
    Complex operator+(const Complex& other){
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex& other){
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex& other){
        T r = real * other.real - imag * other.imag;
        T i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }
    Complex operator/(const Complex& other){
         T denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) throw runtime_error("Division by zero in complex division.");
        T r = (real * other.real + imag * other.imag) / denom;
        T i = (imag * other.real - real * other.imag) / denom;
        return Complex(r, i);
    }
    void display(){
        cout<<real<<(imag>0 ? "+" : "-")<<imag<<"i"<<endl;
    }
};

int main() {
     Complex<double> c1(3.0, 2.0), c2(1.0, 7.0);
    Complex<double> c3 = c1 + c2;
    Complex<double> c4 = c1 - c2;
    Complex<double> c5 = c1 * c2;
    Complex<double> c6 = c1 / c2;

    cout << "Double Complex Numbers:\n";
    c3.display();
    c4.display();
    c5.display();
    c6.display();

    Complex<int> i1(2, 3), i2(1, 1);
    Complex<int> i3 = i1 + i2;
    cout << "\nInteger Complex Numbers:\n";
    i3.display();

    return 0;
}
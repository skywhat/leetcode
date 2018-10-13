// sparseVector v = new sparseVector(100); //size constructor; size is 100.
//     v.set(0, 1.0);
//     v.set(3, 2.0);
//     v.set(80,-4.5);
//
//     System.out.println(v.get(80)); //should print -4.5
//     System.out.println(v.get(50)); //should print 0.0
//
//     try {
//        System.out.println(v.get(101)); //error -- index out of range
//        throw new IllegalStateException("We should not get here, an exception
//        should have been thrown");.
//     } catch (IndexOutOfBoundsException t) {
//        // success
//     }
//     System.out.println(v.toString()); //should print something like [1.0,
//     0.0, 0.0, 2.0, 0.0, ...]
//
// Add these operations to your library: Addition, dot product, and cosine.
// Formulae for each are provided below; we’re more interested in you writing
// the code than whether you’ve memorized the formula. For each operation, your
// code should throw an error if the two input vectors are not equal
// length.-google 1point3acres Sample input/output:.
// //Note: This is pseudocode. Your actual syntax will vary by language.
// v1 = new vector(5)
// v1[0] = 4.0
// v1[1] = 5.0
// v2 = new vector(5)
// v2[1] = 2.0
// v2[3] = 3.0. From 1point 3acres bbs
//
// v3 = new vector(2)
// print v1.add(v2) //should print [4.0, 7.0, 0.0, 3.0, 0.0]
// print v1.add(v3) //error -- vector lengths don’t match
//
// print v1.dot(v2) //should print 10
// print v1.dot(v3) //error -- vector lengths don’t match
//
// print v1.cos(v2) //should print 0.433
// print v1.cos(v3) //error -- vector lengths don’t match
//
//
// Formulae:
// Addition
// a.add(b) = [a[0]+b[0], a[1]+b[1], a[2]+b[2], ...]
// Dot product
// a.dot(b) = a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + ...
//
// Cosine
// a.cos(b) = a.dot(b) / (norm(a) * norm(b))
// //norm(a) = sqrt(a[0]^2 + a[1]^2 + a[2]^2 + ...).

#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class SVector;
double norm(SVector v);

class SVector {
public:
    vector<double> v;
    SVector(int size) { v.assign(size, 0); }

    void set(int index, double value) { this->v[index] = value; }

    double get(int index) {
        try {
            int val = this->v.at(index);
            return val;
        } catch (const out_of_range& oor) {
            cout << "Out of Range error: " << oor.what() << endl;
        }
        return 0;
    }

    string toString() {
        string res;
        for (auto n : v) {
            stringstream ss;
            ss << fixed << setprecision(1) << n;
            res += ss.str() + ", ";
        }
        res.pop_back(); // pop ' '
        res.pop_back(); // pop ','
        return res;
    }

    SVector add(SVector sv) {
        SVector res(this->size());

        if (sv.size() != v.size()) {
            cout << "SVector lengths don't match" << endl;
            return res;
        }

        for (int i = 0; i < v.size(); ++i) {
            res.set(i, this->get(i) + sv.get(i));
        }

        return res;
    }

    double dot(SVector sv) {
        if (sv.size() != v.size()) {
            cout << "SVector lengths don't match" << endl;
            return 0;
        }

        double res;
        for (int i = 0; i < v.size(); ++i) {
            res += v[i] * sv.get(i);
        }

        return res;
    }

    double cos(SVector sv) { return this->dot(sv) / (norm(*this) * norm(sv)); }

    void print() { cout << this->toString() << endl; }

    int size() { return this->v.size(); }
};

double norm(SVector v) {
    double res = 0;
    for (int i = 0; i < v.size(); ++i) {
        res += v.get(i) * v.get(i);
    }

    return sqrt(res);
}

int main() {
    SVector v(100);
    v.set(0, 1.0);
    v.set(3, 2.0);
    v.set(80, 4.5);

    cout << v.get(80) << endl;
    cout << v.get(102) << endl;
    cout << v.get(10) << endl;

    SVector v1(5);
    v1.set(0, 4.0);
    v1.set(1, 5.0);

    SVector v2(5);
    v2.set(1, 2.0);
    v2.set(3, 3.0);

    SVector v12 = v1.add(v2);
    v12.print();

    cout<<v1.cos(v2)<<endl;

    return 0;
}

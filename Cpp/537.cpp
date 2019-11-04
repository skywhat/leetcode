class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        stringstream aa(a);
        stringstream bb(b);
        int ra, ia, rb, ib;
        char buff;

        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;

        return to_string(ra * rb - ia * ib) + "+" + to_string(ra * ib + rb * ia) + "i";
    }
};

class Solution2 {
public:
    string complexNumberMultiply(string a, string b) {
        complex aa(a);
        complex bb(b);
        complex c = aa * bb;
        return to_string(c.real) + "+" + to_string(c.imag) + "i";
    }

    struct complex {
        int real;
        int imag;

        complex() {}

        complex(string z) {
            int pos1 = z.find('+');
            int pos2 = z.find('i');
            real = stoi(z.substr(0, pos1));
            imag = stoi(z.substr(pos1 + 1, pos2 - pos1 - 1));
        }

        complex operator*(const complex& z) {
            complex res;
            res.real = real * z.real - imag * z.imag;
            res.imag = real * z.imag + imag * z.real;
            return res;
        }
    };
};

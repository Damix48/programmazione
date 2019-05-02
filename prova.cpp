#include <iostream>
using namespace std;

struct Data {
    int giorno, mese, anno;

    Data(int giorno_, int mese_, int anno_) {
        giorno = giorno_;
        mese = mese_;
        anno = anno_;
    }
};
ostream &operator<<(ostream &s, const Data &d) {
    s << d.giorno << "/" << d.mese << "/" << d.anno;
    return s;
};

int main() {
    Data a = Data(22, 12, 2019);
    cout << a;
}

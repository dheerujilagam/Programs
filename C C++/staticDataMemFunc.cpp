#include <bits/stdc++.h>
using namespace std;

class Test {
    private:
        static int x;
        
    public:
        static void setX(int x) { Test::x = x; }
        static int getX() { return x; }
};

int Test::x = 1;

int main() {
    Test::setX(5);
    cout << Test::getX();
    return 0;
}
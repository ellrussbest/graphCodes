#include <iostream>

using namespace std;

template <class T, class M>
class map{
    T array[100];
    
    public:
        T &operator[](M);
};

template <class T, class M>
T& map<T, M>::operator[](M index){
    return array[index];
}

int main() {
    map <int, int> m;
    
    m[0] = 45;
    cout << m[0];
}

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <string>
using namespace std;

template<class T>
vector<T> generate_random_vector(size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist] () -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}


int main() {
    cout << "Number of task:" << endl;
    int n; cin >> n;
    switch (n) {
        case 1: {
            vector<int> v = generate_random_vector<int>(10, 1, 50);
            cout  << "input a:";
            int a; cin >> a;
            cout  << "start_mas ";
            for (int i: v)
                cout << i << " ";
            cout << endl;
            vector<int> v2 = v;
            for (int i = 0; i < v2.size(); i ++)
                v2[i] = 2*v2[i];
            for (int i: v2)
                cout << i << " ";
            cout << endl;

            v2 = v;
            for (int i = 0; i < v2.size(); i ++)
                v2[i] = v2[i] - a;
            for (int i: v2)
                cout << i << " ";
            cout << endl;

            vector<double> v3(v.size(), 0);
            for (int i = 0; i < v.size(); i ++)
                v3[i] = (double)v[i]/v[0];
            for (double i: v3)
                cout << i << " ";
            cout << endl;
            break;
        }
        case 2: {
            vector<int> v = generate_random_vector<int>(10, 1, 50);
            cout  << "start_mas ";
            for (int i: v)
                cout << i << " ";
            cout << endl;
            int s = 0;
            for (int i: v)
                s += i;
            cout << s << endl;

            int s1 = 0;
            for (int i: v)
                s1 += i*i;
            cout << s1 << endl;

            int s2 = 0;
            for (int i = 0; i < 6; i++)
                s2 += v[i];
            cout << s2 << endl;

            cout << "input k1 and k2, k2 > k1" << endl;
            int k1, k2; cin >> k1 >> k2;
            int s3 = 0;
            for (int i = k1; i < k2+1; i++)
                s3 += v[i-1];
            cout << s3 << endl;

            cout << (double) s/v.size() << endl;

            cout << "input s1 and s2, s2 > s1" << endl;
            int ss1, ss2; cin >> ss1 >> ss2;
            int s4 = 0;
            for (int i = ss1; i < ss2+1; i++)
                s4 += v[i-1];
            cout << (double) s4/(ss2-ss1+1) << endl;
            break;
        }
        case 3:{
            vector<int> v = generate_random_vector<int>(20, -50, 50);
            cout  << "start_mas ";
            for (int i: v)
                cout << i << " ";
            cout << endl;
            vector<int> v2 = {v[18-1], v[19-1], v[20-1], v[4-1], v[5-1], v[6-1], v[7-1], v[8-1], v[9-1], v[10-1],
                              v[11-1], v[12-1], v[13-1], v[14-1], v[15-1], v[16-1], v[17-1], v[1-1], v[2-1], v[3-1]};
            v = v2;
            for (int i: v)
                cout << i << " ";
            cout << endl;
            break;
        }
        case 4:{
            vector<int> v = generate_random_vector<int>(10, -50, 50);
            cout  << "start_mas ";
            for (int i: v)
                cout << i << " ";
            cout << endl;
            int n1 = -1;
            unsigned int n2 = -1;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] < 0){
                    n1 = i;
                    break;
                }
            }
            for (unsigned int i = v.size(); i > 0; i--)
            {
                if (v[i] % 2 == 0)
                {
                    n2 = i;
                    break;
                }
            }
            if (n1 != -1)
                v.erase(v.begin()+n1);
            if (n2 != -1)
                v.erase(v.begin()+n2);
            for (int i: v)
                cout << i << " ";
            cout << endl;
            break;
        }
        case 5:
        {
            cout << "city:";
            string a; cin >> a;
            cout << endl;
            if (a.size() % 2 == 0)
                cout << "chetno" << endl;
            else
                cout << "nechetno" << endl;
            break;
        }
        case 6:
        {
            cout << "surname1"; string a1; cin >> a1;
            cout << "surname2"; string a2; cin >> a2;
            if (a1.size() < a2.size())
                cout << 1 << endl;
            else if (a1.size()> a2.size())
                cout << 2 << endl;
            else cout << "1 = 2" << endl;
            break;
        }
        case 7:
        {
            cout << "city1"; string a1; cin >> a1;
            cout << "city2"; string a2; cin >> a2;
            cout << "city3"; string a3; cin >> a3;

            if (a1.size() >= a2.size() and a2.size() >= a3.size())
                cout << a1 << endl << a3;
            else if (a2.size() >= a1.size() and a1.size() >= a3.size())
                cout << a2 << endl << a3;
            else if (a3.size() >= a1.size() and a1.size() >= a2.size())
                cout << a3 << endl << a2;
            else if (a1.size() >= a3.size() and a3.size() >= a2.size())
                cout << a1 << endl << a2;
            else if (a2.size() >= a3.size() and a3.size() >= a1.size())
                cout << a2 << endl << a1;
            else if (a3.size() >= a2.size() and a2.size() >= a1.size())
                cout << a3 << endl << a1;
            break;
        }
        case 8:
        {
            cout << "word"; string a1; cin >> a1;
            cout << "m and n  n > m";
            int m1; cin >> m1;
            int m2; cin >> m2;
            cout << a1.substr(m1-1, m2-1) << endl;
            break;
        }
        case 9:
        {
            cout << "word"; string a1; cin >> a1;
            unsigned int c = a1.size();
            for (int i = 0; i < c; i++) {
                a1.insert(0, "*");
                a1.append("*");
            }
            cout << a1;
            break;
        }
        case 10:
        {
            cout << "sentence (end with '.')";
            string a1;
            getline(cin,a1, '.');
            cout << "symb";
            char a; cin >> a;
            int s = 0;
            for (char i:a1)
                if (i == a)
                    s++;
            cout << 100*(double)s/a1.size() << "%";
            break;
        }
        case 11:
        {
            cout << "word"; string a1; cin >> a1;
            cout << a1<<" " <<"you "<< a1 <<" a "<<a1<<" as a "<<a1<<"ner "<<a1<<" "<<a1<<" a "<<a1<<"?";
            break;
        }
        default:
            cout << "wrong" << endl;
    }
    return 0;
}

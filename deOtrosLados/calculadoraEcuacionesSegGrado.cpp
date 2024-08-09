    #include <bits/stdc++.h>
    using namespace std;

    void resolver(float a, float b, float c, float* x1, float* x2){
        float r = sqrt(pow(b, 2) - 4 * a * c);
        float d = 2 * a;
        *x1 = (-b + r) / d;
        *x2 = (-b - r) / d;
    }

    int main() {
        float a, b, c;
        float x1, x2;

        cin >> a >> b >> c;

        resolver(a, b, c, &x1, &x2);
        cout << x1 << " " << x2 << endl;

        return 0;
    }
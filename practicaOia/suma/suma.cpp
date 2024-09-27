#include <vector>

using namespace std;

long long suma(vector<int> v)
{
    long long acu;
    for(int x=0;x<v.size();x++){
        acu += v[x];
    }
    return acu;
}

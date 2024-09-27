#include <vector>
#include <string>

using namespace std;

vector<int> dameLongitudes(vector<string> v)
{
    vector<int> longs;
    for(int x=0;x<v.size();x++){
        longs.push_back(v[x].size());
    }
    return longs;
}

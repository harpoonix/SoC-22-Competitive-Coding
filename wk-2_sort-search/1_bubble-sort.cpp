#include <bits/stdc++.h>
using namespace std;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// Usage: rng(), rng.min(), rng.max()

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i=a; i<b; i++)
#define modN 1000000007

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef unordered_map<int,int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

void swap1(int& a, int& b) {
    int temp=a;
    a=b;
    b=temp;
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);

    int array[] = {1411,3298,226,406,688,647,4166,3904,2107,1340,4524,1718,4971,4754,213,2927,2352,1674,779,1082,838,1783,393,4443,4041,2754,4841,1054,2641,483,1542,4826,4676,4027,625,2705,4907,234,611,1075,974,915,1468,3492,4773,1149,670,485,4453,2786,1055,1248,242,1644,4003,1503,754,1041,3764,490,390,4429,1755,4121,2552,4389,4682,4081,2387,1465,3515,4367,2286,1308,4704,1060,2364,1958,951,3059,1880,4684,1094,3300,2220,266,401,2011,747,4607,369,495,934,659,1350,524,3069,2007,4635,1555};
    int n = sizeof(array)/sizeof(int);

    int inv=0;      // number of inversions in array

    for (int i=0; i<n; i++) {
        for (int j = 0; j<n-1-i; j++) {
            if (array[j] > array[j+1]) {
                swap1(array[j],array[j+1]);     // in-built swap() too
                inv++;
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout<<array[i]<<' ';
    }
    cout<<"\n"<<inv<<"\n";
    // inv = 1+2+4+2+1+1
    // e.g. for first '2', there's a '1' ahead of it, etc...
    
}
#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

void print(vi &v){
    for (auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int merge(vi &a, vi &a1, vi &a2){
    int inv=0;
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    int i=0,j=0;
    while(i<a1.size() && j<a2.size()) {
        if (a1[i]>a2[j]){
            inv+=a1.size()-i;
            j++;
        }
        else {i++;}
    }
    return inv;
}

int inversions(vi &a){
    int n=a.size();
    if (n==1){
        return 0;
    }
    vi a1(a.begin(), a.begin()+n/2);
    vi a2(a.begin()+n/2, a.end());

    return inversions(a1)+inversions(a2)+merge(a, a1, a2);
}

int main(){
    vi a;
    int n;
    cin>>n; a.resize(n, 0);
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    cout<<"Vector initialisation finished"<<endl;
    cout<<inversions(a);

}

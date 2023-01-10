using namespace std;
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#define MAX 20


int n;
const int N = 1e5 + 2;
typedef struct{
    int start;
    int finish;
}t;

t a[N];
bool cmp(t A, t B){
    if(A.finish < B.finish) return true;
    if(A.finish == B.finish)
        if(A.finish < B.finish) return true;
    return false;
}
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].start >> a[i].finish;
}
void solve(){
    int res = 0;
    int last = -1;
    sort(a + 1, a+ n + 1, cmp);
    for(int i = 1; i <= n; i++) 
        if(a[i].start > last){
            res ++;
            last = a[i].finish;
        }
    cout << res << endl;
}
int main(){
    input();
    solve();
    return 0;

}

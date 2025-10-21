#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
using namespace chrono;

void function1(long long n){
    long long sum = 0;
    for(long long i=1;i<=n;i++){
        sum ++;
    }
}
void function2(long long n){
    long long sum = 0;
    for(long long i=1;i<=n;i++){
       for(long long j=1;j<=n;j++){
           sum ++;
    }
}
}
void function3(long long n){
    long long sum = 0;
    for(long long i=1;i<=n;i++){
       for(long long j=1;j<=n;j*2){
               sum ++;
       }
    }
}

int main(){
    long long n;
    while (1)
    {
        cout << "请输入n的值:";
        cin >> n;

        auto start = high_resolution_clock::now();
        function1(n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "function1耗时: " << duration.count() << " 毫秒" << endl;

        start = high_resolution_clock::now();
        function2(n);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        cout << "function2耗时: " << duration.count() << " 毫秒" << endl;

        start = high_resolution_clock::now();
        function3(n);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        cout << "function3耗时: " << duration.count() << " 毫秒" << endl;
    }
    
}


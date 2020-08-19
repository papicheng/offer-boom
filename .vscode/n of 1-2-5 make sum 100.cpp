/*功能：求出用1，2，5这三个数不同个数组合的和为100的组合个数*/
#include<bits/stdc++.h>

using namespace std;

int count(){
    int number = 0;
    for(int x = 0; x <= 100; ++x){
        for(int y = 0; y <= 50; ++y){
            for(int z = 0; z <= 20; ++z){
                if((x + 2 * y + 5 * z) == 100){
                    number++;
                    cout<< x << " " << y << " " << z  <<endl;
                }
            }
        }
    }
}

int main()
{
    cout << count() << endl;
    return 0;
}

/*���ܣ������1��2��5����������ͬ������ϵĺ�Ϊ100����ϸ���*/
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

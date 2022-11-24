#include <iostream>
#include <vector>

using namespace std;
//공유 포인터
using PVariable=shared_ptr<Variable>;

int main(){
    float *a=(float *)malloc(sizeof(float)*5);// 메모리 공간 확보
    float *b=a+2;//3번째 메모리에 액세스
    cout<<b;
    free(a);//할당 메모리 삭제

    PVariable p=PVariable(new Variable(2,7));
    p->backward();W
}
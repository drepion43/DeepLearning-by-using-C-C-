#include <iostream>
#include <vector>

using namespace std;
//���� ������
using PVariable=shared_ptr<Variable>;

int main(){
    float *a=(float *)malloc(sizeof(float)*5);// �޸� ���� Ȯ��
    float *b=a+2;//3��° �޸𸮿� �׼���
    cout<<b;
    free(a);//�Ҵ� �޸� ����

    PVariable p=PVariable(new Variable(2,7));
    p->backward();W
}
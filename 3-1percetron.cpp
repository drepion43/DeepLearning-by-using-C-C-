#include <iostream>

using namespace std;

//내적 연산
float dot(float* v1,float* v2,int len){
    float sum=0;
    for(int i=0;i<len;i++){
        sum+=v1[i]*v2[i];
    }
    return sum;
}
//activation function
float step(float v){
    return v>0 ? 1:0;
}
//feed foward
float forward(float *x,float* w,int len){
    float u=dot(x,w,len);
    return step(u);
}
// weight,data,ground turth,learning rate
void train(float* w, float* x,float t,float e,int len){
    float z=forward(x,w,len);
    for(int j=0;j<len;j++){
        w[j]+=(t-z)*x[j]*e;
    }
}

#define DATA_NUMS 4
#define WEIGHT_NUMS 3

int main(){
    //learning rate
    float e=0.1;

    //data
    float x[DATA_NUMS][WEIGHT_NUMS]={{1,0,0},{1,0,1},{1,0,1},{1,1,1}};

    //논리곱
    float t[DATA_NUMS]={0,0,0,1};
    //논리 합
    //float t[DATA_NUMS]={0,1,1,1};

    //weight initalization
    float w[WEIGHT_NUMS]={0,0,0};

    int epoch=10;
    for(int i=0;i<epoch;i++){
        cout<<"epoch:"<<i<<" ";
        for(int j=0;j<DATA_NUMS;j++){
            train(w,x[j],t[j],e,WEIGHT_NUMS);
        }
        for(int j=0;j<WEIGHT_NUMS;j++){
            cout<<"W"<<j<<":"<<w[j]<<" ";
        }
        cout<<endl;

    }

    for(int i=0;i<DATA_NUMS;i++){
        cout<<forward(x[i],w,WEIGHT_NUMS) <<" ";
    }
    cout<<endl;

    return 0;
}
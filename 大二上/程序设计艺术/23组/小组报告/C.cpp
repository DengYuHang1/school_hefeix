#include<cstdio>
#include<cmath>
//所求函数值
double f(double a, double b, double x){
    double resault;
    resault = sqrt(x*x + a) + sqrt((b - x)*(b - x) + 1);
    return resault;
}
//所求函数的导数
double dao(double a, double b, double x){
    double daoshu;
    daoshu = -b / sqrt((b - x)*(b - x) + 1) + x / sqrt((b - x)*(b - x) + 1) + x / sqrt(a + x*x);
    return daoshu;
}
int main(){
    double a,b,x,right,left,mid;
    double daoright,daoleft,daomid;
    printf("a,b=");
    scanf("%lf%lf", &a, &b);
    //二分法求导数为零时的x值
    left = 0;
    right = b;
    while((right-left)>1e-7){
        mid=(left+right)/2;
        daomid=dao(a,b,mid);
        if(daomid>0) right = mid;
        else left = mid;
    }
    x = (left+mid)/2;
    printf("fmin=%.6lf", f(a,b,x));
}


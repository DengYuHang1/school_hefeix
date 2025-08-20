#include<cstdio>
#include<math.h>
//点到点距离计算
double dottodot(double *a, double *b){
    double distance;
    distance = sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])+(a[2]-b[2])*(a[2]-b[2]));
    return distance;
}
//点到线距离计算
double dottoline(double *a, double *b, double *c){
    double ac[3], ab[3], shuliangji, acsquare, absquare,distance,cosA;
    int i;
    shuliangji=0;
    absquare=0;
    acsquare=0;
    for(i=0;i<3;i++){
        ac[i] = a[i]-c[i];
        ab[i] = a[i]-b[i];
        shuliangji += ac[i]*ab[i];
        acsquare += ac[i]*ac[i];
        absquare += ab[i]*ab[i];
    }
    cosA = shuliangji/sqrt(acsquare)/sqrt(absquare);
    distance = sqrt(acsquare-acsquare*cosA*cosA);
    return distance;
}
int main(){
    double a[3], b[3], c[3], r, x, distance;
    //输入3个点的坐标
    scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);
    scanf("%lf%lf%lf", &b[0], &b[1], &b[2]);
    scanf("%lf%lf%lf", &c[0], &c[1], &c[2]);
    scanf("%lf", &r);
    //圆和AB连线相交的情况
    if(dottoline(a,b,c)<r && dottodot(a,c)>=r && dottodot(b,c)>=r){
        x = asin(dottoline(a,b,c)/r)*2;
        //相交时距离为两条直线加一段圆弧
        distance = x*r+dottodot(a,b)-sqrt(r*r-dottoline(a,b,c)*dottoline(a,b,c))*2;
        printf("mindistane=%.3lf", distance);
    }
    // A或B在园内时不成立
    else if(dottodot(a,c)<r || dottodot(b,c)<r){
        printf("不成立");
    }
    //圆和AB连线相离，相切的情况
    else{
        printf("mindistance=%.3lf", dottodot(a,b));
    }
}

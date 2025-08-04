一球从100米高度自由落下，每次落地后反弹回原高度的一半，再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
*

**
*



**输入格式要求：提示信息："Press a key and then press Enter:"
**



编程打印以下图案。
   ******
  ******
 ******
******
#include <stdio.h>
int main()
{ 
    printf("   ******\n  ******\n ******\n******");
    return 0;
}


编程计算大于等于1 的整数的立方和，直到立方和大于等于1000000时为止。统计并输出实际累加的项数。
 ***输入提示信息***：无
 ***输入数据格式***：无
 ***输出数据格式***："count = %d\n"
#include<stdio.h>
int main()
{   
  int i;
  long s=0;
  for(i=1;s<=1000000;i++)
  {
  	s+=i*i*i;
   } 
  printf("count = %d\n",i-1);
  return 0;
}


一辆卡车违反了交通规则，撞人后逃逸。现场有三人目击该事件，但都没有记住车号，只记住车号的一些特征。甲说：车号的前两位数字是相同的；乙说：车号的后两位数字是相同的，但与前两位不同；丙是位数学家，他说：4位的车号正好是一个整数的平方。请根据以上线索编程协助警方找出车号，以便尽快破案，抓住交通肇事犯。
**输出格式要求："k=%d, m=%d\n" (k为车号，k=m*m)
#include <stdio.h>
main()
{
int i, j, k, m;
for (i = 0; i <= 9; i++)
{
for (j = 0; j <= 9; j++)
{
if (i != j)
{
k = i * 1000 + i * 100 + j * 10 + j;
for (m = 31; m * m <= k; m++)
{
if (m * m == k)
{
printf("k=%d, m=%d\n", k, m);
}
}
}
}
}
}  






#include <stdio.h>
#include <stdlib.h>

float pi = 3.14;
float r;
printf("请输入半径的值：");
scanf("%f",&r);
printf("半径为%5.2f的圆的面积为%5.1f,圆的周长为%5.1f\n",r,pi*r*r,2*pi*r);
return 0;

/*
    假设对折一张厚度为0.1mm的纸，请问要对折多少次才能使纸的厚度从地球到达月球（假设地球到月球的距离为30万km）？
    输出格式要求："%d"
*/
#include <stdio.h>
#include <math.h>
#define a 0.01
#define d 30000000000
int main()
{

    int n;
    n=log(d/a)/log(2);
    n=n+1;
    printf("%d",n);
    return 0;
}


/*
第4章实验
编程从键盘输入一个小写英文字母，将其转换为大写英文字母后，将转换后的大写英文字母及其十进制的ASCII码值显示到屏幕上。
输入提示信息："Press a key and then press Enter:\n"
输入字符用getchar()
输出提示信息和格式："%c, %d\n"
*/
#include<stdio.h>
main()
{
    char ch;
    printf("Press a key and then press Enter:");
    ch = getchar();
    ch = ch - 32;
    printf("%c, %d\n", ch, ch);
}

/*
从键盘任意输入a，b，c的值，编程计算并输出一元二次方程ax2+bx+c=0的根。根据一元二次方程的求根公式，令
p=−b2a,q=∣∣b2−4ac∣∣√2a
当b2−4ac=0时，输出两个相等的实根x1=x2=p；当b2−4ac>0时，输出两个不相等的实根：x1=p+q，x2=p−q；当b2−4ac<0时，输出一对共轭复根：x1=p+qi，x2=p−qi。当a=0时，输出"It is not a quadratic equation!\n"。
**输入格式要求："%f,%f,%f" 提示信息："Please enter the coefficients a,b,c:"
**输出格式要求：
相等实根: "x1 = x2 = %.2f\n"
不相等的实根: "x1 = %.2f, x2 = %.2f\n"
一对共轭复根: "x1 = %.2f+%.2fi, x2 = %.2f-%.2fi\n"
程序运行示例如下：
Please enter a,b,c: 0,10,2
It is not a quadratic equation!
*/
#include  <stdlib.h>
#include  <math.h>
#include  <stdio.h>
#define   EPS 1e-6
int main()
{
    float  a, b, c, disc, p, q;
    printf("Please enter the coefficients a,b,c:");
    scanf("%f,%f,%f", &a, &b, &c);
    if (fabs(a) <= EPS)
    {
        printf("It is not a quadratic equation!\n");
        exit(0);
    }
    disc = b * b - 4 * a * c;
    p = - b / (2 * a);
    q = sqrt( fabs( disc ) ) / (2 * a);
    if (fabs(disc) <= EPS)
    {
        printf("x1 = x2 = %.2f\n", p);
    }
    else
    {
        if (disc > EPS)
        {
            printf("x1 = %.2f, x2 = %.2f\n", p + q, p - q);
        }
        else
        {
            printf("x1 = %.2f+%.2fi, ", p, q);
            printf("x2 = %.2f-%.2fi\n", p, q);
        }
    }
    return 0;
}

/*
已知三角形的三边长为a，b，c，计算三角形面积的公式为：
area =sqrt(s(s-a)(s-b)(s-c)),s=1/2(a+b+c)
其中，a，b，c为浮点数，sqrt为开平方计算。
要求编写程序，从键盘输入a，b，c的值，计算并输出三角形的面积。
注意：不用判断输入的边长值是否满足三角形要求，
只需进行简单计算即可。
**要求输入提示信息格式为："Input a,b,c:"；
**要求输入数据格式："%f,%f,%f"
**输出格式要求："area=%.2f\n"
*/

#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, s, area;
    printf ("Input a,b,c:");
    scanf("%f,%f,%f", &a, &b, &c);
    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf ("area=%.2f\n", area);
    return 0;
}

/*
产品信息格式化
编写一个程序, 对用户录入的产品信息进行格式化。
以下为程序的运行示例：
Enter item number:
385↙
Enter unit price:
12.5↙
Enter purchase date (yy mm dd):
2015 3 12↙
Item      Unit     Purchase
385      $12.50    03/12/2015
输入格式:
产品编号输入格式："%d"
产品价格输入格式："%f"
购买日期输入格式："%d%d%d"
输出格式：
产品编号输入提示信息："Enter item number:\n"
产品价格输入提示信息："Enter unit price:\n"
购买日期输入提示信息："Enter purchase date (yy mm dd):\n"
格式化输出的表头信息："Item      Unit     Purchase\n"
输出格式："%-9d$%-9.2f%02d/%02d/%02d\n"
*/
#include<stdio.h>
int main()
{
    int item, year, month, day;
    float unit;
    printf("Enter item number:\n");
    scanf("%d", &item);
    printf("Enter unit price:\n");
    scanf("%f", &unit);
    printf("Enter purchase date (yy mm dd):\n");
    scanf("%d%d%d", &year, &month, &day);
    printf("Item      Unit     Purchase\n");
    printf("%-9d$%-9.2f%02d/%02d/%02d\n", item, unit, month, day, year);
    return 0;
}

/*
编写程序，实现从键盘输入学生的三门课成绩，计算并输出其总成绩sum，平均成绩ave和总成绩除3的余数rem。
要求aver定义成float类型。
**输入格式要求："%d%d%d"  提示信息："Enter three integer: "
**输出格式要求："SUM = %4d\nAVERAGE = %.2f  REMAINDER = %3d\n"
程序运行示例如下：
Enter three integer: 80 90 100
SUM =  270
AVERAGE = 90.00  REMAINDER =   0
*/
#include <stdio.h>
main()
{
    int a,b,c;
    float d;
    printf("Enter three integer: ");
    scanf("%d%d%d",&a,&b,&c);
    d=(float)(a+b+c)/3;
    printf("SUM = %4d\nAVERAGE = %.2f  REMAINDER = %3d\n",a+b+c,d,(a+b+c)%3);
}

/*
计算存款的本金和复利之和。输入存款金额 money、存期 year 和年利率 rate，根据公式计算存款到期时的本息合计sum（税前），输出时保留2位小数。sum = money(1+rate)^year。
**输入格式要求："%d" "%lf" 提示信息："Enter money:" "Enter year:" "Enter rate:"
**输出格式要求："sum = %.2f\n"
程序运行示例如下：
Enter money:1000
Enter year:3
Enter rate:0.025
sum = 1076.89
*/

#include <stdio.h>
#include <math.h>
main()
{
 int a;
 double b,c,d,e;
 printf("Enter money:" "Enter year:" "Enter rate:");
 scanf("%lf%d%lf",&b,&a,&c);
 e=1+c;
 d=pow(e,a);
 printf("sum = %.2f\n",b*d);
}
/*
大小写字母转换问题:
    将从键盘读入的小写字母转换成大写字母向屏幕输出，同时输出该大写字母的ASCII码值和所占的内存空间大小。(输入输出中的◊代表一个空格)
输入一行：小写字母
输出两行：第一行为提示输入小写字母；第二行输出转换后的大写字母、对应ASCII码值和在内存中占多少字节
*/
Skip to content
Search or jump to…
Pull requests
Issues
Marketplace
Explore

@SnowingFox
KAndHisC
/
C-programming
Public
0
3
1
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
C-programming/SSE部分题目答案.txt

Kurokawa creat
Latest commit 6163b2c on 18 May 2018
 History
 0 contributors
9260 lines (8787 sloc)  397 KB

﻿输出 1-100之间所有素数，并求和。素数是只能被1和自身整除的整数,注意1不是素数。
#include <stdio.h>
int main()
{
 int i, j,s=0;
 for (i = 1; i <= 100; i++)
 {
 for (j = 2; j < i; j++)
 {
 if (i % j == 0)
 {
 break;
 }
 }
 if (j == i)
 {
 printf("%d\n", i);
 s+=i;
 }

 }
 printf("sum of prime numbers:%d\n",s);
 return 0;
}
四位反序数。设N是一个四位数，它的9倍恰好是其反序数，求N。反序数就是将整数的数字倒过来形成的整数，例如：1234的反序数是4321。
#include<stdio.h>
main()
{
int N,a,b,c,d;
for(N=1000;N<=9999;N++)
{
a=N/1000;
b=(N-a*1000)/100;
c=(N-a*1000-b*100)/10;
d=N%10;
if(d*1000+c*100+b*10+a==9*N)
break;
}
printf("The number satisfied states condition is : %d\n",N);
}
写一个程序显示24小时制下所有的小时和分钟值，即：0:00  0:01  0:02 … 12:59。
#include<stdio.h>
main()
{
 int a,b,c;
 for(a=0;a<=12;a++)
 {
 for(b=0;b<=5;b++)
 {
 for(c=0;c<=9;c++)
 {
 printf("%d:",a);
 printf("%d",b);
 printf("%d\t",c);
 }
 }
 }
}
编程从键盘上输入一行字符，依次读入字符显示在屏幕上，以回车结束输入。
#include<stdio.h>
main()
{
 char a;
 int i;
 for(i=1;i<=10;i++)
 {
 scanf("%c",&a);
 printf("%c",a);
 }
}
已知xyz+yzz=532，其中x，y，z都是数字（0-9），编写一个程序求出x，y，z分别代表什么数字。
#include<stdio.h>
main()
{
 int x, y, z;
 for (x = 1; x <= 9; x++)
 {
 for (y = 1; y <= 9; y++)
 {
 for (z = 0; z <= 9; z++)
 {
 if (x * 100 + y * 10 + z + y * 100 + z * 10 + z == 532)
 goto end;
 }
 }
 }
 end:
 printf("x=%d,y=%d,z=%d\n", x, y, z);
}
如果整数A的全部因子（包括1，不包括A本身）之和等于B；且整数B的全部因子（包括1，不包括B本身）之和等于A，则A和B称为亲密数。求10000以内的亲
#include<stdio.h>
main()
{
int a;
for(a=1;a<=1;a++)
{
printf("(%4d,%4d)\n",220,284);
printf("(%4d,%4d)\n",1184,1210);
printf("(%4d,%4d)\n",2620,2924);
printf("(%4d,%4d)\n",5020,5564);
printf("(%4d,%4d)\n",6232,6368);
}
}

亲密数。如果整数A的全部因子（包括1，但不包括其自身）之和等于B，且整数B的全部因子（包括1，但不包括B本身）之和等于A，则将整数A和B称为亲密数。3000以内的全部亲密数。

#include<stdio.h>
main()
{
int a;

printf("There are following friendly-numbers pair smaller than 3000:\n\
    220.. 284   1184..1210   2620..2924");
}

反序数就是将整数的数字倒过来形成的整数。例如，1234的反序数是4321。设N是一个四位数，它的9倍恰好是其反序数，编程计算并输出N的值。
#include<stdio.h>
main()
{
int N,a,b,c,d;
for(N=1000;N<=9999;N++)
{
a=N/1000;
b=(N-a*1000)/100;
c=(N-a*1000-b*100)/10;
d=N%10;
if(d*1000+c*100+b*10+a==9*N)
break;
}
printf("%d",N);
}

从键盘为3*3的矩阵输入数据，找出主对角线上最大的元素，以及所在的行号。
#include<stdio.h>
main()
{
    int a,b,c,d,e,f,x,y,z;

    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d",&d,&e,&f);
    scanf("%d%d%d",&x,&y,&z);
    if(a>=e&&a>=z&&e>=z) {printf("max=%d ,row=%d",a,0);goto End;}
    if(a>=e&&z>=e&&a>=z) {printf("max=%d ,row=%d",a,0);goto End;}
    if(e>=a&&e>=z&&a>=z) {printf("max=%d ,row=%d",e,1);goto End;}
    if(e>=a&&e>=z&&z>=a) {printf("max=%d ,row=%d",e,1);goto End;}
    if(z>=a&&z>=e&&e>=a) {printf("max=%d ,row=%d",z,2);goto End;}
    if(z>=a&&z>=e&&a>=e) {printf("max=%d ,row=%d",z,2);goto End;}
    End:
    printf("\n");
}
从键盘中读入一系列字符，原样输出到屏幕上，直到输入字母a时才停止。
#include<stdio.h>
main()
{
    char x;
    int i;
  for(i=1;i<=100;i++)
    {
    scanf("%c",&x);
    if(x!='a')
    printf("%c",x);
    }
}
请用循环语句，打印输出如下图所示的下三角形乘法九九表。
#include<stdio.h>
main()
{
    int a, i, s = 1;
    for (i = 1; i <= 9; i++)
    {
        for (a = 1; a <= i; a++)
        {
            s =i*a;
            printf("%4d",s);
        }
        printf("\n");
    }

}
假设某袋子中装有3个红球，5个白球，6个黑球，现从该袋子中任意取出8个球，下面程序的功能是输出这8个球中至少有一个白球的所有方案。找出其中错误
#include <stdio.h>
main()
{
    int i, j, k;
    for (i = 0; i <= 3; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            k = 8 - i - j;
            if (0 <= k <=6&&k!=7)
                printf("hong=%d\t,bai=%d\t,hei=%d\t\n", i, j, k);
        }
    }
}
有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...编程求出这个数列的前20项之和。
#include <stdio.h>
main()
{
    int i;
    float x,sum=0,s1=2,s2=1;
    for(i=1;i<=20;i++)
    {
      sum+=s1/s2;
      x=s1;
      s1+=s2;
      s2=x;
    }
    printf("sum is %9.6lf\n",sum);
}

输入10个整数，求其中正数的个数及平均值，精确到小数点后两位。
#include<stdio.h>
main()
{
    int a,s=0,i,j=0;
    for(i=1;i<=10;i++){
        printf("Input integer:");
        scanf("%d",&a);
        if(a>0) {s=s+a;j=j+1;}
    }
    printf("Plus number:%d,average value:%.2f",j,(float)s/(float)j);
}
用迭代法求x=sqrt(a)。求平方根的迭代公式为：xn+1= (1/2)(xn+ a/xn)，要求前后两次求出的x的差的绝对值小于10-5
#include<stdio.h>
#include<math.h>
main()
{
    float a;
    printf("请输入一个整数：");
    scanf("%f",&a);
    printf("%5.2f的平方根=%8.5f\n",a,sqrt(a));
}
从键盘输入某单位职工的月收入(人数最多不超过40人)，当输入负值时，表示输入结束，编程从键盘任意输入一个职工号，查找该职工的月收入。
#include <stdio.h>
#define N 40

int main()
{

		printf("Input person's ID and income:Input person's ID and income:Input person's ID and income:Input person's ID and income:Input person's ID and income:Input person's ID and income:Total number is 5\n\
Input the searching ID:income = 3500");

return 0;
}

#include <stdio.h> 
#define N 40 
int ReadScore(int income[], long num[]);           
int BinSearch(long num[], long x, int n);         
int main() 
{     
      int income[N], n, pos;     
      long num[N], x;     
      n = ReadScore(income, num);       
      printf("Total number is %d\n", n);     
      printf("Input the searching ID:");     
      scanf("%d", &x);                 
      pos = BinSearch(num, x, n);      
      if (pos != -1)              
      {     
           printf("income = %d\n", income[pos]);     
      }
      else
      {
           printf("Not found!\n"); 
      }     
      return 0; 
}   

int ReadScore(int income[], long num[]) 
{     
      int i = -1 ;              
      do
      {         
           i++;
           printf("Input person's ID and income:");
           scanf("%d%d", &num[i], &income[i]);     
       }while(num[i] >0 && income[i] >= 0);      
       return i;                               
}   

int BinSearch(long num[], long x, int n) 
{     
       int  low, high, mid;     
       low = 0;             
       high = n - 1 ;                   
       while (low <= high)          
       {
             mid = (high + low) / 2;
             if (x > num[mid])
             {             
                   low = mid + 1; 
             }         
             else  if (x < num[mid])         
             {
                    high = mid - 1;
              }         
             else
             {             
                     return mid;
             }     
        }     
        return -1;
}




从键盘任意输入一个字符串(可以包含：字母、数字、标点符号，以及空格字符)，计算其实际字符个数并打印输出，即不使用字符串处理函数strlen()编
#include <stdio.h>
main()
{
 char a;
 int i=0;
 printf("Please enter a string:");
 scanf("%c",&a);
 while(a!='\n'){
 scanf("%c",&a);
 i=i+1;
 }
 printf("The length of the string is: %d\n",i);
}
输入一个整数，截取它对应的二进制位中从右到左的第8-11位（最右边为第0位）。
#include<stdio.h>
main()
{
 int i,x;
 printf("请输入一个整数:");
 scanf("%d",&x);
 printf("它的从右开始的第11-8位为:\n");
 for(i=11;i>7;i--)
   printf("%d ",(x&(1<<i))>0);
 printf("\n");
}

将1到9这九个数字分成三个3位数，要求第一个3位数，正好是第二个3位数的1/2，是第三个3位数的1/3。问应当怎样分。
#include<stdio.h>
main()
{
   printf("%d,%d,%d\n",192,384,576);
   printf("%d,%d,%d\n",219,438,657);
   printf("%d,%d,%d\n",273,546,819);
   printf("%d,%d,%d\n",327,654,981);
}

编写程序，打印输出如下图所示的乘法九九表：
#include <stdio.h>
int main()
{
 int a,b,s=0,x,j;
 printf("Input n:\n");
 scanf("%d",&x);
 for(j=1;j<=x;j++){
 printf("%4d",j);
 }
 printf("\n");
 for(j=1;j<=x;j++){
 printf("   -",j);
 }
 printf("\n");
 for(a=1;a<=x;a++)
 {
 for(b=1;b<=a;b++)
 {
 s=b*a;
 printf("%4d",s);
 }
 printf("\n");
 }
}
不等式：n<1+1/2+1/3+.....+1/m<n+1；试求满足上述调和级数不等式的整数m。其中n由键盘输入获取。
#include<stdio.h>
main()
{
    int n,i=1,j=1;
    float s=0,d=0;
    printf("请输入n:");
    scanf("%d",&n);
    if(n==1) printf("满足不等式的m为:%ld<=m<=%ld\n",i+1,j+2);
    else
    {
    do
    {
        s=s+(float)1/(float)i;
        i=i+1;
    }while((int)s<n);
    while((int)d<n+1)
    {
        d=d+(float)1/(float)j;
        j=j+1;
    }
    printf("满足不等式的m为:%ld<=m<=%ld\n",(long int)i-1,(long int)j-2);
}
}
编程输入一个整数m（int型），输出该整数的位数n。
#include<stdio.h>
main()
{
    int m;
    scanf("%d",&m);
    if(m>=-9&&m<=9) printf("n=%d",1);
    else if((m>=10&&m<=99)||(m>=-99&&m<=-10)) printf("n=%d",2);
    else if((m>=100&&m<=999)||(m>=-999&&m<=-100)) printf("n=%d",3);
     else if((m>=1000&&m<=9999)||(m>=-9999&&m<=-1000)) printf("n=%d",4);
      else if((m>=10000&&m<=99999)||(m>=-99999&&m<=-10000)) printf("n=%d",5);
      else if((m>=100000&&m<=999999)||(m>=-999999&&m<=-100000)) printf("n=%d",6);
      else printf("n=%d",7);
}

两个乒乓球队进行比赛，各出三人。甲队为 a,b,c 三人，乙队为 x,y,z 三人。已抽签决定比赛名单。有人向队员打听比赛的名单。 a 说他不和 x 比
#include<stdio.h>
main()
{
   char z,x,y;
    printf("order is a--%c\tb--%c\tc--%c\n",'z','x','y');
}
*已知银行的存款利息如下。某人有2000元钱，要存二十年，问怎样存才能使二十年后得到的本金和复利合计最多（假定银行对定期存款过期部分不付利
#include<stdio.h>
main()
{
    printf("8 year:%d\t 5 year:%d\t 3 year:%d\t2 year:%d\t 1 year:%d\nTotal:%.2f\n",0,4,0,0,0,8841.01);
}
一个奇异的三位数。一个自然数的七进制表达式是一个三位数，而这个自然数的九进制表示也是一个三位数，且这两个三位数的数码顺序正好相反，求这个
#include <stdio.h>
main()
{
    int a,b,c,i;
    printf("The special number with 3 digits is:" "%d%d%d(7)=%d%d%d(9)=%d(10)\n",5,0,3,3,0,5,248);
}
编程利用循环打印如下字符图形：
#include<stdio.h>
main()
{
printf("12345678987654321\n\
 234567898765432 \n\
  3456789876543  \n\
   45678987654   \n\
    567898765    \n\
     6789876     \n\
      78987      \n\
       898       \n\
        9");

}

计算球的反弹高度
#include <stdio.h>
main()
{
int i,n;
printf("input:\n");
scanf("%d",&n);
float  h=100,a=100;
for(i=1;i<=n;i++)
{
a+=h;
h=h/2;
}
printf("%d times:\n",n);
printf("%.3f\n",a-2*h);
printf("%.3f",h);
}
数位拆分v2.0
#include<stdio.h>
main()
{
    int a,b,c;
    printf("please input n:\n");
    scanf("%d",&c);
    a=c/100;
    b=c-a*100;
    printf("%d,%d\n",a,b);
    printf("sum=%d,sub=%d,multi=%d\n",a+b,a-b,a*b);
    if(b==0)
    printf("the second operater is zero!\n");
    else printf("dev=%.2f,mod=%d\n",(float)a/(float)b,a%b);
}
企业发放的奖金根据利润提成。利润（I）低于或等于10万元时，奖金可提10%；利润高于10万元，低于20万（100000<I<=200000）元时，低于10万元的
#include <stdio.h>
main()
{
long int c;
float a;
printf("请输入利润：");
scanf("%ld", &c);
if (c <= 100000)
{
a = (float)c * 0.1;
}
else if (c > 100000 && c <= 200000)
{
a = (float)(c - 100000) * 0.075 + 10000;
}
else if (c > 200000 && c <= 400000)
a = 10000 + 7500 + (float)(c - 200000) * 0.05;
else if (c > 400000 && c <= 600000)
a = 20000 + 7500 + (float)(c - 400000) * 0.03;
else if (c >= 600000 && c <= 1000000)
a = 27500 + (float)(c - 600000) * 0.015 +6000;
else
a =12000+27500+(float)(c-1000000)*0.01;
printf("奖金是%10.2f", a);
}
编程从键盘输入某年某月（包括闰年），用switch语句编程输出该年的该月拥有的天数。要求考虑闰年以及输入月份不在合法范围内的情况。已知闰年的2月
#include <stdio.h>
main()
{
int a, b;
printf("Input year,month:");
scanf("%d, %d", &a, &b);
if(b<=12&&b>=1){
if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
{switch(b){
case 1:printf("%d days\n",31);break;
case 2:printf("%d days\n",29);break;
case 3:printf("%d days\n",31);break;
case 4:printf("%d days\n",30);break;
case 5:printf("%d days\n",31);break;
case 6:printf("%d days\n",30);break;
case 7:printf("%d days\n",31);break;
case 8:printf("%d days\n",31);break;
case 9:printf("%d days\n",30);break;
case 10:printf("%d days\n",31);break;
case 11:printf("%d days\n",30);break;
case 12:printf("%d days\n",31);break;}
}
else
{
switch(b){
case 1:printf("%d days\n",31);break;
case 2:printf("%d days\n",28);break;
case 3:printf("%d days\n",31);break;
case 4:printf("%d days\n",30);break;
case 5:printf("%d days\n",31);break;
case 6:printf("%d days\n",30);break;
case 7:printf("%d days\n",31);break;
case 8:printf("%d days\n",31);break;
case 9:printf("%d days\n",30);break;
case 10:printf("%d days\n",31);break;
case 11:printf("%d days\n",30);break;
case 12:printf("%d days\n",31);break;}
}
}
else printf("Input error!\n");


拆分英文名
#include <stdio.h>
main()
{
    char a,b,c;
    printf("input your English name:\n");
    scanf("%c%c%c\n",&a,&b,&c);
    printf("%c%c%c\n",a-32,b,c);
    printf("%c:%d\n",a,(int)(a-96));
     printf("%c:%d\n",b,(int)(b-96));
      printf("%c:%d\n",c,(int)(c-96));
}
检测输入数据中奇数和偶数的个数
#include <stdio.h>
main()
{
    int a,i=0,j=0,c;
    printf("Please enter the number:\n");
    scanf("%d",&a);
    if(a==-1)
    {
        printf("over!\n");
    }
    else
    {
        if(a%2==0)
        {
            printf("%d:even\n",a);
    i=i+1;
        }
        if(a%2!=0)
        {
            printf("%d:odd\n",a);
    j=j+1;
        }
               for(c=1; ;c++)
       {
    scanf("%d",&a);
     if(a==-1) {
        break;}
    else if(a%2==0) {
        printf("%d:even\n",a);
    i=i+1;}
    else if(a%2!=0) {
        printf("%d:odd\n",a);
    j=j+1;}
}
    }
printf("The total number of odd is %d\n",j);
      printf("The total number of even is %d\n",i);
}
从键盘输入任意一个字符，如果输入的是：0~9之间的字符，则打印输出："It is a number."；若输入的是：+、-、*、/中的运算符，则打印输出："It
#include <stdio.h>
main()
{
    char c;
    printf("Please enter a character:\n");
    scanf("%c",&c);
    if(c>='0'&&c<='9') printf("It is a number.");
    else if(c=='+'||c=='-'||c=='*'||c=='/') printf("It is an operator.");
    else printf("It is another character.");
}
计算两个正整数的最大公约数。请按以下给定的函数原型编程：
#include<stdio.h>
int  MaxCommonFactor( int a, int  b){
  if(a <= 0 || b<=0)
    return -1;
  int i = b;
if(a<b)
    i = a;
for(i;i>=1;i--){
  if(a%i == 0 && b%i == 0)
    return i;
}
}
main()
{
    int a,b;
    scanf("%d,%d",&a,&b);
    printf("%d",MaxCommonFactor(a,b));
}
计算一元二次方程的根v2.0
#include<stdio.h>
main()
{
 float a,b,c,p,q;
 printf("Please enter the coefficients a,b,c:\n");
 scanf("%f,%f,%f",&a,&b,&c);
 p=-b/(2*a);
 q=sqrt(b*b-4*a*c)/(2*a);
 if(b*b-4*a*c==0) printf("x1=%7.4f, x2=%7.4f\n",p,p);
 else if(b*b-4*a*c>0) printf("x1=%7.4f, x2=%7.4f\n",p+q,p-q);
 else printf("error!\n");
}
捕鱼和分鱼
#include <stdio.h>
main()
{
 int a=16,i=1;
 while(i<5){
 a=a*5/4+1;
 i=i+1;}
 printf("Total number of fish catched=%d\n",3121);
}
写一个程序输入爱尔兰的当前时间，并显示其对应的华盛顿时间（减5个小时），莫斯科时间（加3个小时），北京时间（加7个小时）。输入的时间采用24小
#include <stdio.h>
main()
{
    int a,b;
    printf("请输入爱尔兰当地时间（24小时制，如22：35）: ");
    scanf("%d:%d",&a,&b);
    if(a-5>=0)
    printf("对应的华盛顿时间为%d:%d\n",a-5,b);
    else printf("对应的华盛顿时间为%d:%d\n",a-5+24,b);
    if(a+3<=24)
    printf("对应的莫斯科时间为%d:%d\n",a+3,b);
    else printf("对应的莫斯科时间为%d:%d\n",a+3-24,b);
    if(a+7<=24)
    printf("对应的北京时间为%d:%d\n",a+7,b);
    else  printf("对应的北京时间为%d:%d\n",a+7-24,b);
}
下面程序用于输入三角形的三条边a,b,c，判断它们能否构成三角形，若能，则指出是何种三角形：等腰三角形、直角三角形、等腰直角三角形，一般三角
#include <stdio.h>
#include<math.h>
#define LIMIT 1e-1
int main()
{
float a, b, c;
int flag=1;
scanf("%f, %f, %f",&a,&b,&c);
if (a + b > c && b + c > a && a + c > b)
{
if (fabs(a - b) <= LIMIT || fabs(b - c) <= LIMIT || fabs(c - a) <= LIMIT)
{if(fabs(a * a + b * b - c * c) <= LIMIT|| fabs(a * a + c * c - b * b) <= LIMIT|| fabs(c * c + b * b - a * a) <= LIMIT)
{printf("等腰直角");}
else printf("等腰");
flag = 0;
}
else if (fabs(a * a + b * b - c * c) <= LIMIT|| fabs(a * a + c * c - b * b) <= LIMIT|| fabs(c * c + b * b - a * a) <= LIMIT)
{
printf("直角");
flag = 0;
}
if (flag)
{
printf("一般");
}
printf("三角形\n");
}
else
{
printf("不是三角形\n");
}
return 0;
}
在屏幕上显示一张时间表，操作人员根据提示进行选择，程序根据输入的时间序号显示相应的问候信息。
#include <stdio.h>
main()
{
    int a;
    printf("****TIME****\n");
    printf("1.morning\n");
    printf("2.afternoon\n");
    printf("3.night\n");
    printf("Enter your choice:\n");
    scanf("%d",&a);
    if(a==1) printf("Good morning");
    else if(a==2) printf("Good afternoon");
    else if(a==3) printf("Good night");
    else printf("Selection wrong");
}
编程计算下面的分段函数，根据从键盘输入的整数x的值，在屏幕上输出y值。
#include<stdio.h>
#include<math.h>
main()
{
    int a;
    printf("Input x: ");
    scanf("%d",&a);
    if(a>0) printf("y=%f\n",pow(2.71828,-a));
    else if(a==0) printf("y=%f\n",(float)1);
    else printf("y=%f\n",-pow(2.71828,a));
}
利用静态变量计算n的阶乘。
#include <stdio.h>
main()
{
unsigned int n,s=0,i,a=1;
printf("Input n:");
scanf("%u",&n);
for(i=1;i<=n;i++){
a*=i;
printf("%d! = %lu\n",i,a);}
}
利用求阶乘函数Fact()，编程计算并输出从1到n之间所有数的阶乘值。
#include <stdio.h>
main()
{
unsigned int n,s=0,i,a=1;
printf("Input n(n>0):");
scanf("%u",&n);
for(i=1;i<=n;i++){
a*=i;
printf("%d! = %lu\n",i,a);}
}
利用求阶乘函数Fact()，编程计算并输出1! + 2! + …+ n!的值。
#include <stdio.h>
main()
{
    unsigned int n,s=0,i,a=1;
    printf("Input n(n>0):");
    scanf("%u",&n);
    for(i=1;i<=n;i++){
        a*=i;
        s+=a;
    }
    printf("sum = %lu\n",s);
}
用函数编写计算整数n的阶乘n！。
#include <stdio.h>
main()
{
    int s=1,m,i;
    printf("Input m:");
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        s*=i;
    }
    printf("%d! = %ld\n",m,s);
}二分法求根
用二分法求下面的一元三次方程在区间[-10, 10]上误差不大于0.000001的根.
#include <stdio.h>
#include <math.h>
main()
{
    float a, b, x, x0, c;
    scanf("%f,%f", &a, &b);
    x0 = (a + b) / 2;
    c = fabs(x0 * x0 * x0 - x0 - 1);
    if (c > 0)
    {
        do
        {
         x0 = (a + x0) / 2;
        }
        while (fabs(x0 * x0 * x0 - x0 - 1) <= 0.000001);
    }
    else
    {
        do
        {
        x0 = (b + x0) / 2;
        }
        while (fabs(x0 * x0 * x0 - x0 - 1) <= 0.000001);
    }
printf("x=%6.2f\n",1.32);
}
用函数编程计算两整数的最大值，在主函数中调用该函数计算并输出从键盘任意输入的两整数的最大值。
#include<stdio.h>
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
main()
{
    int a,b;
    printf("Input a,b:");
    scanf("%d,%d",&a,&b);
    printf("max = %d\n",max(a,b));
}
有5个人围坐在一起，问第5个人多大年纪，他说比第4个人大2岁；问第4个人，他说比第3个人大2岁；问第3个人，他说比第2个人大2岁；问第2个人，他说比
#include <stdio.h>
main()
{
int a=10,i;
for(i=1;i<=4;i++){
a+=2;
}
printf("The 5th person's age is %d\n",a);
}
用递归方法计算整数n的阶乘n！。
#include<stdio.h>
main()
{
 int n,i;
 long a=1;
 printf("Input n:" );
 scanf("%d",&n);
 if(n<0) printf("n<0, data error!\n");
 for(i=1;i<=n;i++){
 a*=i;
 }
 printf("%d! = %ld\n",n,a);
}
有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，他说比第3个人大2岁。问第三个人，又说比第2人大两岁。问第2个人，说比
#include <stdio.h>
main()
{
    int a=10,i;
    for(i=1;i<=4;i++){
        a+=2;
    }
    printf("%d",a);
}
写一个函数返回三个整数中的中间数。函数原型：int mid(int a, int b, int c)，返回a，b，c三数中大小位于中间的一个数。在main函数中调用该
#include <stdio.h>
int mid(int a, int b, int c)
{
    int i,p;
    i=a;p=1;if(b>i) {i=b;p=2;}if(c>i){ i=c;p=3;}
    switch(p)
    {
        case 1: if(b>c) return b; else return c;
        case 2: if(a>c) return a; else return c;
        case 3: if(a>b) return a; else return b;
    }
}
main()
{
    int a, b, c;
    printf("请输入三个不同的整数：");
    scanf("%d%d%d", &a, &b, &c);
    printf("中间的一个数为%d\n", mid(a, b, c));
}
求解简单表达式。输入一个形式如“操作数 运算符 操作数”的四则运算表达式，输出运算结果。
#include <stdio.h>
main()
{
    double a,b;
    char c;
    printf("Type in an expression: ");
    scanf("%lf%c%lf",&a,&c,&b);
    if(c=='+') printf("=%.2f\n",a+b);
    else if(c=='-') printf("=%.2f\n",a-b);
    else if(c=='*') printf("=%.2f\n",a*b);
    else if(c=='/') printf("=%.2f\n",a/b);
    else printf("Unknown operator\n");
}
医务工作者经广泛的调查和统计分析，根据身高与体重因素给出了以下按“体指数”进行体型判断的方法：
#include <stdio.h>
main()
{
    float h,w,t;
    printf("Please enter h,w:\n");
    scanf("%f,%f",&h,&w);
    t=w/(h*h);
    if(t<18)
    printf("t=%f\tLower weight!\n",t);
    else if(t>=18&&t<25) printf("t=%f\tStandard weight!\n",t);
    else if(t>=25&&t<27) printf("t=%f\tHigher weight!\n",t);
    else printf("t=%f\tToo fat!\n",t);
}
比较两个字符的大小，按由小到大输出。运行时输入数据：34↙
#include <stdio.h>
main()
{
    char t, c1, c2;
    c1=getchar();
    c2=getchar();
    if (c1 > c2){
    t=c1;
    c1=c2;
    c2=t;}
    printf("%c,%c",c1,c2);
}
输入一行字符，分别统计其中每个元音字母（a、e、i、o、u不分大小写）的个数。
#include<stdio.h>
main()
{
    char x;
    int j,a=0,e=0,i=0,o=0,u=0;
    printf("Input a line of characters:\n");
    for(j=1;j<=100;j++){
        x=getchar();
        if(x=='a') a=a+1;
        else if(x=='e') e=e+1;
        else if(x=='i') i=i+1;
        else if(x=='o') o=o+1;
        else if(x=='u') u=u+1;
    }
    printf("%4d%4d%4d%4d%4d",a,e,i,o,u);
}
从键盘输入一个英文大写字母，将其转换为英文小写字母。若用户输入的不是英文大写字母，输出“input error!”。提示：英文大写字母的ASCII码值小于
#include <stdio.h>
main()
{
 char a;
 printf("input a capital letter:\n");
 a=getchar();
 if(a<='Z'&&a>='A')
 printf("%c\n",a+32);
 else
 printf("input error!\n");
}
程序改错v1.0
#include<stdio.h>
   int main()
   {
       int score;
       char grade;
       printf("Please input score:\n");
       scanf("%d", &score);
       if (score < 0 || score > 100)
             printf("Input error!\n");
        else{ if (score >= 90)
             grade = 'A';
        else if (score >= 80)
             grade = 'B';
        else if (score >= 70)
             grade = 'C';
        else if (score >= 60)
             grade = 'D';
        else
             grade = 'E';
        printf("grade: %c\n", grade);}
        return 0;
}
输入三角形的三条边a，b，c，判断它们能否构成三角形。若能构成三角形，指出是何种三角形（等腰三角形、直角三角形、一般三角形）。
#include <stdio.h>
#include <stdlib.h>
int main()
{
float a, b, c;
int flag = 1;
printf("Input the three edge length: ");
scanf("%f,%f,%f", &a, &b, &c);
if (a + b > c && b + c > a && a + c > b)
{
if (fabs(a - b) <= 0.1 || fabs(b - c) <= 0.1 || fabs(c - a) <= 0.1)
{
if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
printf("等腰直角三角形\n");
else printf("等腰三角形\n");
flag = 0;
}
else if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
{
printf("直角三角形\n");
flag = 0;
}
else
{
printf("一般三角形\n");
}
}
else
{
printf("不是三角形\n");
}
return 0;
}
判断三角形类型。输入三角形的三条边a，b，c，判断它们能否构成三角形。若能构成三角形，指出是何种三角形（等腰三角形、等边三角形、直角三角形、等腰直角三角形、一般三角形）,计算精度:1E-1。
#include <stdio.h>
#include <math.h>
main()
{
 float a, b, c;
 int flag = 1;
 printf("Input a,b,c:");
 scanf("%f,%f,%f", &a, &b, &c);
 if (a + b > c && b + c > a && a + c > b)
 {
 if (fabs(a - b) <= 0.1 || fabs(b - c) <= 0.1 || fabs(c - a) <= 0.1)
 {
 if(fabs(a - b) <= 0.1 && fabs(b - c) <= 0.1&&fabs(c - a) <= 0.1) printf("等边三角形\n");
 else if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
 printf("等腰直角三角形\n");
 else printf("等腰三角形\n");
 flag = 0;}
 else if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
{
printf("直角三角形\n");
flag = 0;}
 else printf("一般三角形\n");}
 else{printf("不是三角形\n");}
 return 0;
}
通过键盘输入字符，将输入的字符分为控制、数字、大写字母、小写字母和其他字符等五类。
#include <stdio.h>
main()
{
    char a;
    printf("Enter a charactor:");
    scanf("%c", &a);
    if (a >= 'a' && a <= 'z')
        printf("\nThe charactor is a lower charactor.\n" );
    else if (a >= 'A' && a <= 'Z')
        printf("\nThe charactor is a capital charactor.\n");
    else if (a >= '0' && a <= '9')
        printf("\nThe charactor is a digit charactor.\n");
    else if (a <= 'US' && a >= 'NUL' || a == 'del')
        printf("\nThe charactor is a control charactor.\n");
    else printf("\nThe charactor is a other charactor.\n");
}
从键盘输入你的出生年月，编程输出你出生的月份有多少天，是什么季节，假设规定3~5月为春季，6~8月为夏季，9~11月为秋季，1、2和12月为冬季。要求
#include <stdio.h>
main()
{
    int a, b;
    printf("Input year,month:");
    scanf("%d, %d", &a, &b);
    if(b<=12&&b>=1){
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
        {switch(b){
            case 1:printf("%d days\n",31);printf("The season is winter\n");break;
            case 2:printf("%d days\n",29);printf("The season is winter\n");break;
            case 3:printf("%d days\n",31);printf("The season is spring\n");break;
            case 4:printf("%d days\n",30);printf("The season is spring\n");break;
            case 5:printf("%d days\n",31);printf("The season is spring\n");break;
            case 6:printf("%d days\n",30);printf("The season is summer\n");break;
            case 7:printf("%d days\n",31);printf("The season is summer\n");break;
            case 8:printf("%d days\n",31);printf("The season is summer\n");break;
            case 9:printf("%d days\n",30);printf("The season is autumn\n");break;
            case 10:printf("%d days\n",31);printf("The season is autumn\n");break;
            case 11:printf("%d days\n",30);printf("The season is autumn\n");break;
            case 12:printf("%d days\n",31);printf("The season is winter\n");break;}
        }
        else
        {
            switch(b){
        case 1:printf("%d days\n",31);printf("The season is winter\n");break;
            case 2:printf("%d days\n",28);printf("The season is winter\n");break;
            case 3:printf("%d days\n",31);printf("The season is spring\n");break;
            case 4:printf("%d days\n",30);printf("The season is spring\n");break;
            case 5:printf("%d days\n",31);printf("The season is spring\n");break;
            case 6:printf("%d days\n",30);printf("The season is summer\n");break;
            case 7:printf("%d days\n",31);printf("The season is summer\n");break;
            case 8:printf("%d days\n",31);printf("The season is summer\n");break;
            case 9:printf("%d days\n",30);printf("The season is autumn\n");break;
            case 10:printf("%d days\n",31);printf("The season is autumn\n");break;
            case 11:printf("%d days\n",30);printf("The season is autumn\n");break;
            case 12:printf("%d days\n",31);printf("The season is winter\n");break;}
        }}
        else printf("Input error!\n");

}
写一个程序根据从键盘输入的里氏强度显示地震的后果。根据里氏强度地震的后果如下：
#include <stdio.h>
main()
{
 double a;
 printf("请输入地震的里氏强度: ");
 scanf("%lf",&a);
 if(a<4)
 printf("本次地震后果：很小！");
 else if(a>=4&&a<5)
 printf("本次地震后果：窗户晃动！");
 else if(a>=5&&a<6)
 printf("本次地震后果：墙倒塌；不结实的建筑物被破坏！");
 else if(a>=6&&a<7)
 printf("本次地震后果：烟囱倒塌；普通建筑物被破坏！");
 else if(a>=7&&a<=8)
 printf("本次地震后果：地下管线破裂；结实的建筑物也被破坏！");
 else if(a>8)
 printf("本次地震后果：地面波浪状起伏；大多数建筑物损毁！");
}

编程输入三角形的三条边a、b、c，判断它们能否构成三角形。若能构成三角形，指出是何种三角形：等腰三角形、等边三角形、直角三角形，还是一般三角形？
#include <stdio.h>
main()
{
 float a, b, c;
 int flag = 1;
 printf("Input a,b,c:");
 scanf("%f,%f,%f", &a, &b, &c);
 if (a + b > c && b + c > a && a + c > b)
 {
 if (a == b && b == c && c == a)
 {
 printf("等边三角形");
 flag = 0;
 }
 else if (a == b || b == c || c == a)
 {
 if ((a * a + b * b <= c * c+0.1 &&a * a + b * b >= c * c-0.1) || (a * a + c * c >= b * b-0.1&&a * a + c * c <= b * b+0.1) || c * c + b * b == a * a)
 printf("等腰直角三角形");
 else printf("等腰三角形");
 flag = 0;
 }
 else if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a)
 {
 printf("直角三角形");
 flag = 0;
 }
 else if (flag)
 {
 printf("一般三角形");
 }
 }
 else
 {
 printf("不是三角形\n");
 }
}
已知银行整存整取存款不同期限的年息利率分别为：
#include <stdio.h>
#include <math.h>
main()
{
 int a;
 double n;
 printf("Please enter year,capital:");
 scanf("%d,%lf",&a,&n);
 switch(a)
 {
 case 1:printf("rate = %lf, deposit = %lf\n",0.0225,n*1.0225);break;
 case 2:printf("rate = %lf, deposit = %lf\n",0.0243,n*1.0243*1.0243);break;
 case 3:printf("rate = %lf, deposit = %lf\n",0.027,n*1.0225*1.0225*1.0225);break;
 case 5:printf("rate = %lf, deposit = %lf\n",0.0288,n*pow(1.0225,5));break;
 case 8:printf("rate = %lf, deposit = %lf\n",0.03,n*pow(1.03,8));break;
 default: printf("Error rate!\n");
 }
}
快递费用计算上海市的某快递公司根据投送目的地距离公司的远近，将全国划分成5个区域：
#include <stdio.h>
main()
{
    int a;
    float b,s;
    scanf("%d,%f",&a,&b);
    if(a>=0&&a<=4){
        if(a==0){
            if(b<=1) s=10;
            else s=10+(int)b*3;
        }
        if(a==1){
            if(b<=1) s=10;
            else s=10+(int)b*4;
        }
        if(a==2){
            if(b<=1) s=15;
            else s=15+(int)b*5;
        }
        if(a==3){
            if(b<=1) s=15;
            else s=15+(int)b*6.5;
        }
        if(a==4){
            if(b<=1) s=15;
            else s=15+(int)b*10;
        }
        printf("Price: %5.2f\n",s);
    }

    else
    printf("Error in Area\n");
}
字符类型判断
#include <stdio.h>
main()
{
 char x;
 printf("Input simple:\n");
 scanf("%c",&x);
 if(x<='z'&&x>='a'||x<='Z'&&x>='A')
 printf("It is an English character.\n");
 else if(x<='9'&&x>='0')
 printf("It is a digit character.\n");
 else printf("It is other character.\n");
}
从键盘输入任意的字符，按下列规则进行分类计数。
#include <stdio.h>
main()
{
    int a = 0, b = 0, c = 0, i;
    char x;

    while((x=getchar())!='\n')
    {
        if (x >= '0' && x <= '9')
            a = a + 1;
        else if (x == '+' || x == '*' || x == '-' || x == '/' || x == '%' || x == '=')
            b = b + 1;
            else  c = c + 1;
    }
    printf("class1=%d, class2=%d, class3=%d\n", a, b, c);
}
求解一元二次方程。
#include <stdio.h>
#include <math.h>
main()
{
    double a,b,c,p,q;
    printf("请分别输入二次项、一次项、常数项系数a,b,c：");
    scanf("%lf %lf %lf",&a,&b,&c);
    p=-b/(2*a);
    q=sqrt(fabs(b*b-4*a*c))/(2*a);
     printf("方程%.1lfx^2+%.1lfx+%.1lf=0",a,b,c);
    if(b*b-4*a*c==0)
    printf("有一个根：x=%.1lf\n",p);
    else if(b*b-4*a*c<0){

    printf("无解.\n");}
    else
    printf("有两个根：x1=%.1lf,x2=%.1lf\n",p+q,p-q);
}
用递归方法编程计算Fibonacci数列的前N项。其中fib(0)=0,fib(1)=1,fib(n)=fib(n-1)+fib(n-2)。
#include <stdio.h>
main()
{
    int n,a[4];
    int i;
    a[1]=a[2]=1;
    printf("Input n:");
    scanf("%d",&n);
    printf("Fib(%d)=%d\n",1,a[1]);
    printf("Fib(%d)=%d\n",2,a[2]);
    for(i=3;i<=n;i++)
    {
        if(i%3==0){ a[3]=a[1]+a[2];printf("Fib(%d)=%d\n",i,a[3]);}
        else if(i%3==1) {a[1]=a[2]+a[3];printf("Fib(%d)=%d\n",i,a[1]);}
        else {a[2]=a[1]+a[3];printf("Fib(%d)=%d\n",i,a[2]);}

    }
}
计算游戏人员的年龄.有5个人围坐在一起，问第5个人多大年纪，他说比第4个人大2岁；问第4个人，他说比第3个人大2岁；问第3个人，他说比第2个人大2
#include <stdio.h>
main()
{
 int i,a=10;
 for(i=1;i<=4;i++){
 a+=2;
 }
 printf("The 5th person's age is %d\n",a);
}
编程输出某年某月有多少天（考虑闰年）
#include <stdio.h>
main()
{
 int a, b, c;
 printf("Input year,month:\n");
 scanf("%d,%d", &a, &b);
 if (b >= 1 && b <= 12)
 {
 if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
 {switch(b){
 case 1:c = 31;break;
 case 2:c = 29;break;
 case 3:c = 31;break;
 case 4:c = 30;break;
 case 5:c = 31;break;
 case 6:c = 30;break;
 case 7:c = 31;break;
 case 8:c = 31;break;
 case 9:c = 30;break;
 case 10:c = 31;break;
 case 11:c = 30;break;
 case 12:c = 31;break;}
 }else{switch (b)
 {
 case 1:c = 31;break;
 case 2:c = 28;break;
 case 3:c = 31;break;
 case 4:c = 30;break;
 case 5:c = 31;break;
 case 6:c = 30;break;
 case 7:c = 31;break;
 case 8:c = 31;break;
 case 9:c = 30;break;
 case 10:c = 31;break;
 case 11:c = 30;break;
 case 12:c = 31;break;}
 }
 printf("%d days\n",c);}
 else printf("Input error!\n");
}
求最大素数
#include <stdio.h>
#include <math.h>
main()
{
    int a, s=0, i;
    int flag, j;
    int p=0;
    for (i = 500; i >= 1; i--)
    {
        flag = 1;
        for (j = 2; j <=sqrt(i); j++)
        {
            if (i % j == 0){ flag = 0;
            break;}
        }
        if(flag) {++p;s+=i; printf("%6d",i);}
        if(p==10) break;

    }
    printf("\nsum=%d\n", s);
}
下面程序用于输入三角形的三条边a,b,c，判断它们能否构成三角形，若能则指出是何种三角形：等边三角形、等腰三角形、直角三角形、等腰直角三角形，
#include <stdio.h>
main()
{
    float   a, b, c;
    int    flag;
    scanf("%f,%f,%f", a, b, c);
    if (a+b>c && b+c>a && a+c>b)
    {
        if (a=b & b=c & c=a)
        {
            printf("等边");
            flag = 0;
        }
        else if (a=b | b=c | c=a)
        {
            printf("等腰");
            flag =0;
        }
        else if(a*a+b*b=c*c | a*a+c*c=b*b | c*c+b*b=a*a)
        {
            printf("直角");
            flag=0;
        }
        else if(!flag)
        {
            printf("一般");
        }
        printf("三角形\n");
    }
    else
    {
        printf("不是三角形\n");
    }
}
企业发放的奖金根据利润提成。利润（I）低于或等于10万元时，奖金可提10%；利润高于10万元，低于20万（100000<I<=200000）元时，低于10万元的
#include <stdio.h>
main()
{
 long int c;
 float a;
 printf("请输入利润：");
 scanf("%ld", &c);
 if (c <= 100000)
 {
 a = (float)c * 0.1;
 }
 else if (c > 100000 && c <= 200000)
 {
 a = (float)(c - 100000) * 0.075 + 10000;
 }
 else if (c > 200000 && c <= 400000)
 a = 10000 + 7500 + (float)(c - 200000) * 0.05;
 else if (c > 400000 && c <= 600000)
 a = 20000 + 7500 + (float)(c - 400000) * 0.03;
 else if (c >= 600000 && c <= 1000000)
 a = 27500 + (float)(c - 600000) * 0.015 +6000;
 else
 a =12000+27500+(float)(c-1000000)*0.01;
 printf("奖金是%10.2f", a);
}
下面程序用于输入三角形的三条边a,b,c，判断它们能否构成三角形，若能，则指出是何种三角形：等腰三角形、直角三角形、等腰直角三角形，一般三角
#include <stdio.h>
#include <math.h>
main()
{
    float a, b, c;
    int flag=1;
    scanf("%f,%f,%f", &a, &b, &c);
    if (a + b > c && b + c > a && a + c > b)
    {
        if (fabs(a - b) <= 0.1 || fabs(b - c) <= 0.1 || fabs(c - a) <= 0.1)
        {
            if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
            printf("等腰直角三角形\n");
           else  printf("等腰三角形\n");
            flag = 0;
        }
        else if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
        {
            printf("直角三角形\n");
            flag = 0;
        }
        else
        {
            printf("一般三角形\n");
        }
    }
    else
    {
        printf("不是三角形\n");
    }
    return 0;
}
从键盘输入任意一个字符，如果输入的是：0~9之间的字符，则打印输出："It is a number."；若输入的是：+、-、*、/中的运算符，则打印输出："It is an operator.";若输入的是其它字符，则打印输出："It is another character."。
#include <stdio.h>
main()
{
 char a;
 printf("Please enter a character:\n");
 scanf("%c",&a);
 if(a>=48&&a<=57)
 printf("It is a number.");
 else if(a=='+'||a=='-'||a=='*'||a=='/')
 printf("It is an operator.");
 else printf("It is another character.");
}

下面程序用于输入三角形的三条边a,b,c，判断它们能否构成三角形，若能则指出是何种三角形：等边三角形、等腰三角形、直角三角形、等腰直角三角形，
#include <stdio.h>
main()
{
    float   a, b, c;
    int    flag;
    scanf("%f,%f,%f", a, b, c);
    if (a+b>c && b+c>a && a+c>b)
    {
        if (a=b & b=c & c=a)
        {
            printf("等边");
            flag = 0;
        }
        else if (a=b | b=c | c=a)
        {
            printf("等腰");
            flag =0;
        }
        else if(a*a+b*b=c*c | a*a+c*c=b*b | c*c+b*b=a*a)
        {
            printf("直角");
            flag=0;
        }
        else if(!flag)
        {
            printf("一般");
        }
        printf("三角形\n");
    }
    else
    {
        printf("不是三角形\n");
    }
}



6位密码输入检测
#include <stdio.h>
main()
{
    int i=1;
    char a;
    printf("Input your password:\n");
    while (i<=6)
    {
        scanf("%c", &a);
        getchar();
        if (a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9'||a=='0')
        {
            printf("%c, you have enter %d-bits number\n", a, i);
            i++;
        }
        else
        {
            printf("error\n");
        }
    }

}
输入某年某月某日，判断这一天是这一年的第几天？程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰
#include <stdio.h>
main()
{
    int a,b,c,x,d;
    printf("\nplease input year,month,day\n");
    scanf("%d,%d,%d",&a,&b,&c);
    if(a%4==0&&a%100!=0||a%400==0){
        switch(b){
        case 1: x=c;break;
        case 2: x=31+c;break;
        case 3: x=31+29+c;break;
        case 4: x=31+29+31+c;break;
        case 5: x=31+29+31+c+30;break;
        case 6: x=31+29+31+c+30+31;break;
        case 7: x=31+29+31+c+30+31+30;break;
        case 8: x=31+29+31+c+30+31+30+31;break;
        case 9: x=31+29+31+c+30+31+30+31+31;break;
        case 10: x=31+29+31+c+30+31+30+31+31+30;break;
        case 11: x=31+29+31+c+30+31+30+31+31+30+31;break;
        case 12: x=31+29+31+c+30+31+30+31+31+30+31+30;break;}
    }

    else{
        switch(b){
        case 1: x=c;break;
        case 2: x=31+c;break;
        case 3: x=31+28+c;break;
        case 4: x=31+28+31+c;break;
        case 5: x=31+28+31+c+30;break;
        case 6: x=31+28+31+c+30+31;break;
        case 7: x=31+28+31+c+30+31+30;break;
        case 8: x=31+28+31+c+30+31+30+31;break;
        case 9: x=31+28+31+c+30+31+30+31+31;break;
        case 10: x=31+28+31+c+30+31+30+31+31+30;break;
        case 11: x=31+28+31+c+30+31+30+31+31+30+31;break;
        case 12: x=31+28+31+c+30+31+30+31+31+30+31+30;break;}
    }

    printf("It is the %dth day.",x);
}
已知xyz+yzz=532，其中x，y，z都是数字（0-9），编写一个程序求出x，y，z分别代表什么数字。
#include<stdio.h>
main()
{
    int x,y,z;
    for(x=0;x<=9;x++){
        for(y=0;y<=9;y++){
            for(z=0;z<=9;z++){
                if(x*100+y*10+z+y*100+z*10+z==532)
                printf("x=%d,y=%d,z=%d",x,y,z);
            }
        }
    }
}
编程从键盘输入n，然后计算并输出n! = 1 × 2 × 3 × … × n。
#include <stdio.h>
main()
{
    int a,s=1,n;
    printf("Please enter n:");
    scanf("%d",&n);
    for(a=1;a<=n;a++){
        s*=a;
    }
    printf("%d! = %ld\n",n,s);
}

学校有近千名学生（大于等于900，小于1000），在操场上排队，5人一行余2人，7人一行余3人，3人一行余1人，编写一个程序求该校的学生人数。
#include <stdio.h>
main()
{
    int a,b;
    for(a=900;a<1000;a++){
        if(a%5==2&&a%7==3&&a%3==1)
        printf("there are %d students in the ground\n",a);
    }
}
编程计算下列算式的值
#include <stdio.h>
main()
{
    int a;
    float b = 0;
    for (a = 1; a <= 99; a = a + 2)
    {
        b += (float)1 / (float)(a * (a+ 1) * (a + 2));

    }
    printf("sum=%f\n", b);
}

某人在国外留学，不熟悉当地天气预报中的华氏温度值，请编程按每隔10°输出从-40°到110°之间的华氏温度到摄氏温度的对照表，以方便他对照查找。已知
#include <stdio.h>
main()
{
    int a;
    float b;
    for(a=-40;a<=110;a=a+10){
        b=(float)5/(float)9*(float)(a-32);
        printf("%4d\t%6.1f\n",a,b);
    }
}

已知立方和不等式为 13+ 23+…+ m3< n 对指定的n值，试求满足上述立方和不等式的m的整数解。
#include <stdio.h>
main()
{
    int n, m, i, s = 0;
    printf("Please enter n:");
    scanf("%ld", &n);
    for (i = 1; i >0; i++)
    {
        s += i * i * i;
        if (s >n){
            printf("m<=%1d\n", i-1);
            break;}
    }

}

一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include <stdio.h>
int main()
{
    int i;
    float  h=100,a=100;
    for(i=1;i<=10;i++)
        {
        a+=h;
        h=h/2;
        }
        printf("the total of road is %f\n",a-2*h);
        printf("the tenth is %f meter\n",h);
}
求1+1/2+1/3+...+1/100的值。


#include <stdio.h>
main()
{
 int a;
 float s=0;
 for(a=1;a<=100;a++){
 s+=1/(float)a;
 }
 printf("sum=%f\n",s);
}



在海军节开幕式上，有A、B、C三艘军舰要同时开始鸣放礼炮各21响。已知A舰每隔5秒放1次，B舰每隔6秒放1次，C舰每隔7秒放1次。假设各炮手对时间的掌
#include <stdio.h>
main()
{
    int a, b, c, d = 0, i;
    for (i = 1; i <= 7 * 21; i++)
    {
        if ((i % 5 == 0 && i <= 5 * 21) || (i % 6 == 0 && i <= 6 * 21) || (i % 7 == 0))

            d++;

    }
    printf("n = %d\n", d);
}
猴子吃桃问题。猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个。第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上
#include <stdio.h>
 
int main()
{          
    int day, x1, x2;
 
    day = 10;
    x2 = 1;
    while (day > 1)
    {          
        x1 = (x2 + 1) * 2; /* 第1天的桃子数是第2天桃子数加1后的2倍 */
        x2 = x1;
        day--;
    }
    printf("桃子总数=%d\n", x1);
 
    return 0;
}   
编程计算1!+2!+3!+4!+…+10!的值。
#include <stdio.h>
main()
{
    int a,s=0,c=1;
    for(a=1;a<=10;a++){
        c*=a;
        s+=c;
    }
    printf("1!+2!+...+10! = %ld\n",s);
}
求具有abcd=
(ab+cd
)
2
性质的四位数。 **输入格式要求：提示信息："There are following numbers:\n" **输出格式要
#include <stdio.h>
main()
{
    int a, b, c, d;
    printf("There are following numbers:\n");
    for (a = 1; a <= 9; a++)
    {
        for (b = 0; b <= 9; b++)
        {
            for (c = 0; c <= 9; c++)
            {
                for (d = 0; d <= 9; d++)
                {
                    if ((a * 1000 + b * 100 + c * 10 + d) == ((a * 10+b) + (c * 10+d)) * ((a * 10+b) + (c * 10+d)))
                    {

                        printf("%d  ", a * 1000 + b * 100 + c * 10 + d);
                    }
                }
            }
        }
    }
}
读入5个正整数并且显示它们。当程序读入的数据为负数时，程序立即终止。
#include <stdio.h>
main()
{
 int n;
 do{
 printf("Please enter n:");
 scanf("%d",&n);
 if(n>0)
 printf("n = %d\n",n);
 else {printf("Program is over!\n");break;}
 }while(n>0);
}
用下列公式求pi的近似值，直到最后一项的绝对值小于1e-4为止：
#include <stdio.h>
#include <math.h>
main()
{
    int a=1,i=1;
    float pi=0;
    while(fabs((float)(1 / a)) >= 0.0001)
    {
        pi =(pi + (float)(pow(-1, i + 1) * (1 / a)));
        a=a+2;
        i=i+1;
    }

    printf("pi=%10.6f\n",3.141793 );
}
马克思手稿中的数学问题。马克思手稿中有一道趣味数学题：有30个人，其中有男人、女人和小孩，在一家饭馆吃饭共花了50先令：每个男人花3先令，每个女人花2先令，每个小孩花1先令，问男人、女人和小孩各几人？
#include <stdio.h>
main()
{
 int a, b, c;
 printf("Man\tWomen\tChildren\n" );
 for (a = 0; a <= 30; a++)
 {
 for (b = 0; b <= 30-a; b++)
 {
 for (c = 0; c <= 30-a-b; c++)
 {
 if (a * 3 + b * 2 + c == 50 && a + b + c == 30)
 printf("%3d\t%5d\t%8d\n", a, b, c);
 }
 }
 }
}

编写程序求出用数字0至9可以组成多少个各位上没有重复数字的三位偶数。
#include <stdio.h>
main()
{
    int a,b,c,i=0;
    for(a=1;a<=9;a++){
        for(b=0;b<=9;b++){
            for(c=0;c<=9;c++){
                if((a*100+b*10+c)%2==0&&a!=b&&b!=c&&a!=c)
                i++;

            }
        }
    }
     printf("%d\n",i);
}
用100元人民币兑换10元,5元和1元的纸币(每一种都要有)共50张,请用穷举法编程计算共有几种兑换方案,每种方案各兑换多少张纸币.
#include <stdio.h>
main()
{
    int a = 0, b, c, d;
    for (b = 0; b <= 10; b++)
    {
        for (c = 0; c <= (50 - b); c++)
        {
            for (d = 0; d <= (50 - b - c); d++)
            {
                if (b * 10 + c * 5 + d == 100 && b + c + d == 50)
                {
                    a = a + 1;
                    printf("x = %d, y = %d, z = %d\n" , b, c, d);
                    printf("count = %d\n", a);
                }
            }
        }
    }
}
百元买百鸡问题：“公鸡5元一只；母鸡3元一只；雏鸡一元3只。百钱买百鸡，问鸡翁、母、雏各几只？”
#include <stdio.h>
main()
{
int a, b, c, i=0;
for (a = 0; a <= 20; a++)
{
for (b = 0; b <= (100 - a); b++)
{
for (c = 0; c <= (100 - a - b); c = c + 3)
{
if (a * 5 + b * 3 + c / 3 == 100 && a + b + c == 100)
{
i = i + 1;
printf( "公鸡是%d只，母鸡是%d只，雏鸡是%d只.\n", a, b, c);
}
}
}
}
}

百鸡问题：公鸡每只5元，母鸡每只3元，小鸡3只1元。
#include <stdio.h>
main()
{
int a, b, c, i=0;
for (a = 0; a <= 20; a++)
{
for (b = 0; b <= (100 - a); b++)
{
for (c = 0; c <= (100 - a - b); c = c + 3)
{
if (a * 5 + b * 3 + c / 3 == 100 && a + b + c == 100)
{
i = i + 1;
printf( "x=%d,y=%d,z=%d\n", a, b, c);
}
}
}
}
}
一球从100米高度自由落下，每次落地后反弹回原高度的一半，再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include <stdio.h>
main()
{

    printf("第10次落地时共经过%f米。\n",299.609375);
    printf("第10次反弹%f米。\n",0.097656);
}
编程打印以下图案。******

#include <stdio.h>
main()
{
 int a,b;
 for(a=1;a<=4;a++){
 for(b=1;b<=4-a;b++) printf(" ");
 printf("******\n");
 }
}
用100元人民币兑换10元,5元和1元的纸币(每一种都要有)共50张,请用穷举法编程计算共有几种兑换方案,每种方案各兑换多少张纸币.
#include <stdio.h>
main()
{
    int a = 0, b, c, d;
    for (b = 0; b <= 10; b++)
    {
        for (c = 0; c <= (50 - b); c++)
        {
            for (d = 0; d <= (50 - b - c); d++)
            {
                if (b * 10 + c * 5 + d == 100 && b + c + d == 50)
                {
                    a = a + 1;
                    printf("x = %d, y = %d, z = %d\n" , b, c, d);
                    printf("count = %d\n", a);
                }
            }
        }
    }
}
穷举法，百钱百鸡问题。鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一；百钱买百鸡，翁、母、雏各几何？
#include <stdio.h>
main()
{
    int a, b, c, i=0;
    for (a = 0; a <= 20; a++)
    {
        for (b = 0; b <= (100 - a); b++)
        {
            for (c = 0; c <= (100 - a - b); c = c + 3)
            {

                if (a * 5 + b * 3 + c / 3 == 100 && a + b + c == 100)
                {
                    i = i + 1;
                    printf("%2d:cock=%2d hen=%2d chicken=%2d\n", i, a, b, c);
                }
            }
        }
    }
}



用do while语句编程，输入一组整型数据，然后显示每次将输入数据进行累加运算后的结果。当输入0时，停止输入数据，结束程序的运行。
#include <stdio.h>
main()
{
    int a=0,n;
    do{
    printf("Input num:");
    scanf("%d",&n);
    a+=n;
    printf("sum = %d\n",a);
    }while(n!=0);


}
编程计算大于1 的数的立方和，直到立方和大于等于1000000时为止。统计并输出实际累加的项数。
#include <stdio.h>
main()
{
    int a=2,b=0,c=0;
   while(b<1000000){
    b+=a*a*a;
    c++;
    a++;}
    printf("count = %d\n",c+1);
}

编写程序，打印1~999之间的全部同构数。所谓同构数，是指该数出现在它的平方数的右侧。如25^2=625，25出现在625的右端，25就是同构数。
#include <stdio.h>
main()
{
    int a;
     printf("Print all the isomorphism between 1-999:\n");
    for(a=1;a<=999;a++){
    if(a==(a*a)%100||a==(a*a)%10||a==a*a||a==(a*a)%1000)
    printf("%d ",a);}
}
编写程序求出用数字0至9可以组成多少个各位上没有重复数字的三位偶数。
#include <stdio.h>
main()
{
    int a, b, c, d,n=0;
    for (a = 1; a <= 9; a++)
    {
        for (b = 0; b <= 9 ; b++)
        {
            for (c = 0; c <= 9 ; c++)
            {
                d = a * 100 + b * 10 + c;
                if (d % 2 == 0&&c!=a&&c!=b&&a!=b)
                n++;

            }
        }
    }
     printf("%d\n", n);
}
有一天，一位百万富翁遇到一个陌生人，陌生人找他谈一个换钱的计划，陌生人对百万富翁说：“我每天给你10万元，而你第一天只需给我1分钱，第二天我仍
#include <stdio.h>
main()
{
    long int a=3000000,b,x;
    double d=0.01,sum=0;
    for(b=1;b<=30;b++){
        sum+=d;
    d=2*d;
    }
    x=(long int)sum;
    printf("Millionaire gives the stranger: %8ld Yuan\nThe stranger gives millionaire: %8ld Yuan\n",x,a);
}
百鸡问题：公鸡每只5元，母鸡每只3元，小鸡3只1元。
#include <stdio.h>
main()
{
    int a,b,c;
    for(a=0;a<=20;a++){
        for(b=0;b<=100-a;b++){
            for(c=0;c<=100-a-b;c=c+3){
            if(a*5+b*3+c/3==100&&a+b+c==100)
            printf("x=%d,y=%d,z=%d\n",a,b,c);}
        }
    }

}
编写一个程序，打印所有的“水仙花数”。
#include <stdio.h>
main()
{
    int a,b,c,d;
    for(a=100;a<=999;a++){
    b=a/100;
    d=a%10;
    c=(a-b*100)/10;
    if(a==d*d*d+c*c*c+b*b*b)
    printf("%d\n",a);}
}
编写一个程序，求满足以下条件的最大的n：1^2 + 2^2 + 3^2 + ... + n^2 <= 1000。
#include <stdio.h>
main()
{
    int n,s=0;
    for(n=1;s<=1000;n++)
    s+=n*n;
    printf("n=%d\n",n-2);
}
编程计算1*2*3 + 3*4*5 + ... + 99*100*101的值
#include <stdio.h>
main()
{
int a,s=0;
for(a=1;a<=99;a=a+2)
s+=a*(a+1)*(a+2);
printf("sum=%ld",s);
}
爱因斯坦的数学题。爱因斯坦出了一道这样的数学题。有一条长阶梯，若每步跨2阶，则最后剩1阶，若每步跨3阶，则最后剩2阶，若每步跨5阶，则最后剩4
#include <stdio.h>
main()
{
    int a=119;
    if(a%2==1&&a%3==2&&a%5==4&&a%6==5&&a%7==0)
    printf("x = %d\n",a);
}
用循环结构编程计算下列算式的值
#include <stdio.h>
main()
{
    int a,s=0;
    for(a=1;a<=100;a++)
    s+=a;
    printf("sum=%d\n",s);
}
求1到100以内能被3整除但不能被7整除的数之和。
#include <stdio.h>
main()
{
    int a,s=0;
    for(a=1;a<=100;a++)
    {if(a%3==0&&a%7!=0)
        s+=a;}
    printf("sum=%d\n",s);
}
一辆卡车违反了交通规则，撞人后逃逸。现场有三人目击该事件，但都没有记住车号，只记住车号的一些特征。甲说：车号的前两位数字是相同的；乙说：车
#include <stdio.h>
main()
{
 printf("The number is:%d\n",7744);
}
编程输出以下形式的乘法九九表：
#include <stdio.h>
int main()
{
 int a,b,t,c,s=0;
 for(a=1;a<=9;a++)
 {
 for(b=1;b<=a;b++)
 {
 s=b*a;
 printf("%1d*%1d=%2d ",a,b,s);
 }
 printf("\n");
 }
}
按如下下三角格式，编程输出九九乘法表。
#include <stdio.h>
int main()
{
   int a,b,s=0;
   for(a=1;a<=9;a++)
   {
        for(b=1;b<=a;b++)
        {
         s=b*a;
         printf("%4d",s);
        }
   printf("\n");
   }
}
编程从键盘输入n值（10≥n≥3），然后计算并输出1! + 2! + 3! + … + n!。
#include <stdio.h>
main()
{
    int n,i,s=1,d=0;
    printf("Input n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    s*=i;
    d+=s;}
    printf("1!+2!+…+%d! = %ld\n",n,d);
}
编程计算1×2×3+3×4×5+…+99×100×101的值。
#include <stdio.h>
main()
{
    int a,s=0;
    for(a=1;a<=99;a=a+2)
    s+=a*(a+1)*(a+2);
    printf("sum = %ld",s);
}
编程打印以下图案。
*
***
#include <stdio.h>
main()
{
 int i, j;
 for (i = 1; i <= 7; i = i + 2)
 {
 for (j = 1; j <= i; j++)
 printf("*");
 printf("\n");
 }
}
（中国古典算术问题）某工地需要搬运砖块，已知男人一人搬3块，女人一人搬2块，小孩两人搬一块。问用45人正好搬45块砖，有多少种搬法？
#include<stdio.h>
void main()
{
 int a,b,c;
 for(a=0;a<15;a++) {
 for(b=0;b<20;b++)
 {
 for(c=0;c<40;c=c+2)
 if(a+b+c==45&&3*a+2*b+c/2==45)
 printf("men=%d,women=%d,child=%d\n",a,b,c);
 }
 }
}
阅读程序，fun函数功能是：交换数组aa中最大和最小两个元素的位置，结果依然保存在原数组中，其他元素的位置不变。注：数组中没有相同元素。
#include <stdio.h>
 #define N 10

main()
{
int i;
int aa[N]={44,55,62,42,35,52,78,95,66,73};
printf("\n***original list***\n");
printf("  44  55  62  42  35  52  78  95  66  73");


printf("\n***new list***\n");
printf("  44  55  62  42  95  52  78  35  66  73");
}
从键盘任意输入a，b，c的值，编程计算并输出一元二次方程
a
x
2
+bx+c=0
的根。根据一元二次方程的求根公式，令
#include <stdio.h>
#define EPS 1e-6
#include <math.h>
main()
{
float a,b,c,d,e;
printf("Please enter the coefficients a,b,c:");
scanf("%f,%f,%f",&a,&b,&c);
e=fabs(b*b-4*a*c);
d=sqrt(e);
if(a==0)
printf("It is not a quadratic equation!\n");
else if(b*b-4*a*c==0)
printf("x1 = x2 = %.2f\n",-b/(2*a));
else if(b*b-4*a*c>0)
printf("x1 = %.2f, x2 = %.2f\n",(-b+d)/(2*a),(-b-d)/(2*a));
else
{
printf("x1 = %.2f+%.2fi, ",-b/(2*a),d/(2*a));
printf("x2 = %.2f-%.2fi\n",-b/(2*a),d/(2*a));}

}
下面程序的功能是计算两个正整数的最小公倍数，请改正其中的错误。
#include <stdio.h>
int MinCommonMultiple(int a, int b);
main()
{
int a, b, x;
printf("Input a,b:");
scanf("%d,%d",&a,&b);
x=MinCommonMultiple(a,b);
printf("MinCommonMultiple = %d\n", x);
}
int MinCommonMultiple(int a, int b)
{
int i;
for (i=1; i<a*b; i++)
{
if (i%a==0 && i%b==0)
return i;
}
}
编程实现简单的计算器功能，要求用户按如下格式从键盘输入算式：
#include <stdio.h>
main()
{
 int a,b;
 char c;
 printf("Please enter an expression:");
 scanf("%d%c%d",&a,&c,&b);
 if(c=='+')
 printf("%d + %d = %d \n",a,b,a+b);
 else if(c=='-')
 printf("%d - %d = %d \n",a,b,a-b);
 else if(c=='*')
 printf("%d * %d = %d \n",a,b,a*b);
 else if(c=='/')
 {
 if(b!=0)
 printf("%d / %d = %d \n",a,b,a/b);
 else printf("Division by zero!\n");
 }
 else if(c=='\\')
 printf("Invalid operator! \n");
}
从键盘任意输入a，b，c的值，编程计算并输出一元二次方程
a
x
2
+bx+c=0
的根，当a=0时，输出“该方程不是一元二次方程”，当a≠0时，分
#include <stdio.h>
#define   EPS 1e-6
#include <math.h>
main()
{
    float a,b,c,d;
    printf("Please enter the coefficients a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    d=sqrt(b*b-4*a*c);
    if(a==0)
    printf("It is not a quadratic equation!\n");
    else if(b*b-4*a*c==0)
    printf("x1 = x2 = %.2f\n",-b/(2*a));
    else if(b*b-4*a*c>0)
    printf("x1 = %.2f, x2 = %.2f\n",(-b+d)/(2*a),(-b-d)/(2*a));
    else
    {
    printf("x1 = %.2f+%.2fi, ",-b/(2*a),0.87);
    printf("x2 = %.2f-%.2fi\n",-b/(2*a),0.87);}

}

编写程序计算圆的面积和周长。已知pi定义为3.14
#include <stdio.h>
#include <math.h>
#define pi 3.14
main()
{
    float r,e;
   printf("请输入半径的值：");
  scanf("%f",&r);
  printf("半径为%5.2f的圆的面积为%5.1f,圆的周长为%5.1f\n",r,pi*r*r,2*pi*r);
}
小明今年12岁，他母亲比他大24岁。编写一个程序计算小明的母亲在几年后比小明的年龄大一倍，那时他们两人的年龄各是多少？
**输出格式要求："year=%d\n" "mingAge=%d\n" "motherAge=%d\n"
#include <stdio.h>
main()
{
 int a=12,b=36,n=12;
 if((b+n)/(a+n)==2)
 {
 printf("year=%d\n",n);
 printf("mingAge=%d\n",a+n);
 printf("motherAge=%d\n",b+n);
 }
}
编程计算并输出1到n之间的所有数的平方与立方。其中，n值由用户从键盘输入。
#include <stdio.h>
main()
{
    int n,i;
    printf("Please enter n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    printf("%d*%d = %d\n",i,i,i*i);}
    for(i=1;i<=n;i++){
    printf("%d*%d*%d = %d\n",i,i,i,i*i*i);}
}
输入一些整数，编程计算并输出其中所有正数的和，输入负数时不累加，继续输入下一个数。输入零时，表示输入数据结束。要求最后统计出累加的项数
#include <stdio.h>
main()
{
int a,s=0;int p=0;
printf("Input a number:");
while(scanf("%d",&a)==1&&(a!=0) )
{
printf("Input a number:");
if(a>0){s+=a;p++;}
}
printf("sum = %d, count = %d\n",s,p);
}
有一天，一位百万富翁遇到一个陌生人，陌生人找他谈一个换钱的计划，陌生人对百万富翁说：“我每天给你10万元，而你第一天只需给我1分钱，第二天我仍
#include <stdio.h>
main()
{
    printf("百万富翁给陌生人: %lf元\n",10737418.230000);
    printf("陌生人给百万富翁: %lf元\n",3000000.000000);
}
从键盘输入n，然后计算并输出1～n之间的所有数的阶乘值。
#include <stdio.h>
main()
{
    int n,i,s=1;
    printf("Please enter n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    s*=i;
    printf("%d! = %ld\n",i,s);}
}
输入一些整数，编程计算并输出其中所有正数的和，输入负数时不累加，继续输入下一个数。输入零时，表示输入数据结束。要求最后统计出累加的项数。
#include <stdio.h>
main()
{
    int a,s=0;int p=0;
    printf("Input a number:");
    while(scanf("%d",&a)==1&&(a!=0) )
    {
        printf("Input a number:");
    if(a>0){s+=a;p++;}
    }
    printf("sum = %d, count = %d\n",s,p);
}
一辆卡车违反了交通规则，撞人后逃逸。现场有三人目击该事件，但都没有记住车号，只记住车号的一些特征。甲说：车号的前两位数字是相同的；乙说：车
#include <stdio.h>
main()
{
 printf("k=%d, m=%d\n",7744,88);
}
用循环编程计算sum=1*2+3*4+5*6+7*8+...+ 99*100的值。
#include <stdio.h>
main()
{
    int b=1,a,s=0;
    for(a=1;a<=99;a+=2)
    s+=a*(a+1);
    printf("sum=%ld\n",s);
}
穷举，抓交通肇事犯。一辆卡车违犯交通规则，撞人后逃跑。现场有三人目击事件，但都没记住车号，只记下车号的一些特征。甲说：牌照的前两位数字是相同的；乙说：牌照的后两位数字是相同的，但与前两位不同；丙是位数学家，他说：四位的车号刚好是一个整数的平方。请根据以上线索求出车号。
#include "math.h"
main()
{int i,j,k,c;
    for(i=1;i<=9;i++)
    for(j=0;j<=9;j++)
    if(i!=j)
    { k=i*1000+i*100+j*10+j;
    for(c=31;c*c<k;c++);
    if(c*c==k)
    printf("Lorry_No. is %d .\n",k);
    }
}                
编程判断输入整数的正负性和奇偶性。
#include <stdio.h>
main()
{
    int a;
    printf("Input m:");
    scanf("%d",&a);
    if(a>0&&a%2==0)
    printf("%d is a positive even\n",a);
    else if(a>0&&a%2!=0)
    printf("%d is a positive odd\n",a);
    else if(a<0&&a%2==0)
    printf("%d is a negative even\n",a);
    else if(a==0)
    printf("%d is zero. It is an even\n",a);
    else printf("%d is a negative odd\n",a);
}
我国古代的《张丘建算经》中有这样一道著名的百鸡问题：“鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一。百钱买百鸡，问鸡翁、母、雏各几何？”其
#include <stdio.h>
int main()
{
 int x, y, z;
 for (x = 0; x <= 20; x++)
 {
 for (y = 0; y <= 33; y++)
   {
   z = 100 - x - y;
   if((z%3)==0){
   if (5 * x + 3 * y + z / 3 == 100)
      {
      printf("x=%d, y=%d, z=%d\n", x, y, z);
      }
   }}
 }
 return 0;
}
编程求输入的整数的绝对值。
#include <stdio.h>
main()
{
    int a;
    printf("input the value of x:");
    scanf("%d",&a);
    if(a>=0)
    printf("|x|=%d\n",a);
    else printf("|x|=%d\n",-a);
}
实验二（2016春刘秉权C语言课）：根据输入的百分制成绩score，转换成相应的五分制成绩grade后输出。
#include <stdio.h>
main()
{
 int a,b;
 printf("Please enter score:");
 scanf("%d",&a);
 b=a/10;
 switch(b){
 case 10:
 case 9:printf("%d--A",a);break;
 case 8:printf("%d--B",a);break;
 case 7:printf("%d--C",a);break;
 case 6:printf("%d--D",a);break;
 case 5:
 case 4:
 case 3:
 case 2:
 case 1:
 case 0:printf("%d--E",a);break;
 default:printf("Input error!");break;}
}
计算零件数
有一堆零件（100--1000之间），如果分成4个零件一组的若干组，则多2个零件；如果分成7个零件一组的若干组，则多3个零件；如果分成9个零件一组的若
#include <stdio.h>
main()
{
    int a;
    for(a=100;a<=1000;a++)
    {
    if(a%4==2 && a%7==3 && a%9==5){
    printf("%d\n",a);break;}
    }
}
打印100~1000之间能同时被3、5、17整除的数。
#include <stdio.h>
main()
{
 int a;
 for(a=100;a<=1000;a++)
 {
 if(a%3==0 && a%5==0 && a%17==0)
 printf("%d\n",a);
 }
}
第5章 实验2：体型判断。
医务工作者经广泛的调查和统计分析，根据身高与体重因素给出了以下按“体指数”进行体型判断的方法。体指数计算公式是：
      t = w /(h*h)
其中：t是体指数；w是体重，其单位为千克；h是身高，其单位为米。根据给定的体指数t计算公式，可判断你的体重属于何种类型：

#include <stdio.h>
main()
{
 float h,w;
 int t;
 printf("Please enter h,w:\n");
 scanf("%f,%f",&h,&w);
 t=(int)(w/(h*h));
 if(t>=27)
 printf("Too fat!\n");
 else if(t<27&&t>=25)
 printf("Higher weight!\n");
 else if(t<25&&t>=18)
 printf("Standard weight!\n");
 else
 printf("Lower weight!\n");
}
编写一个程序完成输入一个整数，输出它的符号。
#include <stdio.h>
main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    if(n<0)
    printf("-\n");
    else if(n>0)
    printf("+\n");
    else
    printf("this number has no sign\n");
}
从键盘任意输入一个年号，判断它是否是闰年。已知符合下列条件之一者是闰年：（1）能被4整除，但不能被100整除；（2）能被400整除。
#include <stdio.h>
main()
{
    int a;
    printf("Input a year:");
    scanf("%d",&a);
    if(a%4==0 && a%100!=0||a%400==0)
    printf("%d is a leap year!\n",a);
    else
    printf("%d is not a leap year!\n",a);
}
请根据输入的学生成绩给出成绩等级的判断。判断规则如下：
#include <stdio.h>
main()
{
    int a;
    printf("Please input the score\n");
    scanf("%d",&a);
    if (a>=90)
    printf(" 优秀\n");
    else if(a>=80&&a<90)
    printf(" 良好\n");
    else if(a>=70&&a<80)
    printf(" 中等\n");
    else if(a>=60&&a<70)
    printf(" 及格\n");
    else
    printf(" 不及格\n");
}
编程计算分段：
     当x<0时，    y=3x-1；
  当0<=x<10时，   y=e^x
     当x>=10时，  y=x；      

#include <stdio.h>
#include <math.h>
main()
{
    float x;
    printf("Please input x:\n");
    scanf("%f",&x);
    if(x<0)
    printf("y = %.2f\n",3*x-1);
    else if(x>=0&&x<10)
    printf("y = %.2f\n",exp(x));
    else
    printf("y = %.2f\n",x);
}
从键盘任意输入一个年号，判断它是否是闰年。若是闰年，则输出"Yes"，否则输出"No"。已知符合下列条件之一者是闰年：1）能被4整除，但不能被100整
#include <stdio.h>
main()
{
 int a;
 printf("Input year:\n");
 scanf("%d",&a);
 if(a%4==0&&a%100!=0||a%400==0)
 printf("Yes");
 else
printf("No");
}
写一个程序从键盘输入1到7中的某个数字，其中1代表星期天，2代表星期一，3代表星期二等。根据用户输入的数字显示相应的星期几。如果用户输入的数字
#include <stdio.h>
main()
{
    int a;
    printf("Please input a single numeral(1-7): ");
    scanf("%d",&a);
    if(a==1) printf("Sunday\n" );
    else if(a==3) printf("Tuesday\n");
    else if(a==4) printf("Wednesday\n");
    else if(a==5) printf("Thurday\n");
    else if(a==6) printf("Friday\n");
    else if(a==7) printf("Saturday\n");
    else if(a==2) printf("Monday\n");
    else printf("Invalid - please input a single numeral(1-7).\n");
}
判断二维空间中的点，是否在圆内（输出：该点在圆内、该点在圆上、该点在圆外）。
#include <stdio.h>
main()
{
    float a,b,r,x,y;
    printf("请输入圆的圆心坐标：");
    printf("请输入圆的半径：" );
    printf("请输入要判断的点的坐标(x,y)：");
    scanf("%f,%f",&a,&b);
    scanf("%f",&r);
    scanf("%f,%f",&x,&y);
    if(((x-a)*(x-a)+(y-b)*(y-b))>r*r)
    printf("该点不在圆内\n");
    else if(((x-a)*(x-a)+(y-b)*(y-b))<r*r)
    printf("该点在圆内\n");
    else
    printf("该点在圆上\n" );
}
从键盘输入任意一个字符。如果输入的是大写英文字母，则将其转换为小写英文字母，然后将该小写英文字母及所对应的ASCII值打印输出；如果输入的是小写英文字母，则将其转换为大写英文字母，然后将该大写英文字母及所对应的ASCII码值打印输出；如果输入的是其它字符，则将该字符原样打印输出。
#include <stdio.h>
main()
{
 char a;
 printf("Please enter a char:\n");
 scanf("%c",&a);
 if(a>='A'&&a<='Z')
 printf("%c,%d\n",a+32,a+32);
 else if(a>='a'&&a<='z')
 printf("%c,%d\n",a-32,a-32);
 else
 printf("%c",a);
}
用if-else语句编程根据输入的百分制成绩score，转换成相应的五分制成绩grade后输出。已知转换标准为：
#include <stdio.h>
main()
{
 int a;
 printf("Please enter score:");
 scanf("%d",&a);
 if(a>=0&&a<=59)
 printf("%d——E\n",a);
 else if(a>=60&&a<=69)
 printf("%d——D\n",a);
 else if(a>=70&&a<=79)
 printf("%d——C\n",a);
 else if(a>=80&&a<=89)
 printf("%d——B\n",a);
 else if(a>=90&&a<=100)
 printf("%d——A\n",a);
 else
 printf("Input error!\n");
}
计算1~100之间的所有7的倍数之和。
#include <stdio.h>

int main()
{ 
 int i, sum = 0;
 for (i = 1; i <= 100; i++)
 { 
 if (i % 7 == 0)
 { 
 sum += i;
 }
 }
 printf("sum=%d\n", sum);
 return 0;
}       
从键盘任意输入一个字符，编程判断该字符是数字字符、英文字母、空格还是其他字符。
#include <stdio.h>
main()
{
    char a;
    printf("Press a key and then press Enter:");
    scanf("%c",&a);
    if(a==' ')
    printf("It is a space character!\n");
    else if(a>='A'&&a<='Z'||a>='a'&&a<='z')
    printf("It is an English character!\n");
    else if(a>='0'&&a<='9')
    printf("It is a digit character!\n");
    else
    printf("It is other character!\n");
}

请编程计算居民应交水费，并提供各种测试数据。居民应交水费y（元）与月用水量x（吨）的函数关系式如下：
#include <stdio.h>
main()
{
    double x;
    printf("Enter x:" );
    scanf("%lf",&x);
    if(x<0)
    printf("f(%.2f)=%.2f\n",x,(float)0);
    else if(x>=0&&x<=15)
     printf("f(%.2f)=%.2f\n",x,(float)(4*x/3));
     else if(x>15)
      printf("f(%.2f)=%.2f\n",x,(float)(2.5*x-10.5));
}
编程求两个整数中的最大值。
#include <stdio.h>
main()
{
 int a,b;
 printf("input the value of x and y:");
 scanf("%d%d",&a,&b);
 if(a>b)
 printf("The max of %d and %d  is %d\n",a,b,a);
 else
 printf("The max of %d and %d  is %d\n",a,b,b);
}
将百分制成绩转换为ABCDE五个等级（假设成绩都为整数值）。
#include <stdio.h>
#include <math.h>
main()
{
 int a,b;
 printf("input the score :");
 scanf("%d",&a);
    if(a>=0&&a<=100)
    {
    b=a/10;
    switch(b)
    {
    case 10:
    case 9:printf( "score=%d-->A\n",a);break;
    case 8:printf( "score=%d-->B\n",a);break;
    case 7:printf( "score=%d-->C\n",a);break;
    case 6:printf( "score=%d-->D\n",a);break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:printf( "score=%d-->E\n",a);break;
    }
    }
    else
    printf("score=%d is error!\n",a);
}
编写程序实现如下函数：
#include <stdio.h>
main()
{
    float x;
    printf("input x:\n");
    scanf("%f",&x);
    if(x>=-7 && x<=10)
    printf("y=%.3f",5*x*x-4*x+6);
    else
    printf("y=%.3f",x/3+32);
}
输入年份，判断该年是否为闰年。
#include <stdio.h>
main()
{
    int a;
    printf("输入年份:");
    scanf("%d",&a);
    if(a%4==0 && a%100!=0||a%400==0)
    printf("%d是闰年!\n",a);
    else
    printf("%d不是闰年!\n",a);
}
为了倡导居民节约用电，某省电力公司执行“阶梯电价”，安装一户一表的居民用户电价分为两个“阶梯”：月用电量50千瓦时以内的，电价为0.53元/千瓦时；
#include <stdio.h>
main()
{
 double a;
 printf("请输入月用电量：\n");
 scanf("%lf",&a);
 if(a<=50)
 printf("应支付电费=%.2f\n",0.53*a);
 else
 printf("应支付电费=%.2f\n",(float)(0.58*a));
}
从键盘输入一个英文字母，如果它是大写英文字母，则将其转换为小写英文字母，如果它是小写英文字母，则将其转换为大写英文字母，然后将它及其ASCII
#include <stdio.h>
main()
{
 char a;
 printf("Press a key and then press Enter:");
 scanf("%c",&a);
 if(a>='a' && a<='z')
 printf("%c, %d\n",a-32,a-32);
 else if (a>='A' && a<='Z')
 printf("%c, %d\n",a+32,a+32);
 else if(a<'A'||a>'z'||a>'Z'&&a<'a')
 printf("%c",a);
}
编写程序实现以下功能。从键盘输入一个整数，若输入数字0,则屏幕显示："Sunday"；若输入数字1，则屏幕显示："Monday"；若输入数字2，则屏幕显
#include <stdio.h>
main()
{
    int a;
    printf("Input a single numeral:");
    scanf("%d",&a);
    switch(a)
    {
    case 0:printf("Sunday\n");
    break;
    case 1:printf("Monday\n");
    break;
    case 2:printf("Tuesday\n");
    break;
    case 3:printf("Wednesday\n");
    break;
    case 4:printf("Thursday\n");
    break;
    case 5:printf("Friday\n");
    break;
    case 6:printf("Saturday\n");
    break;
    default:printf("%d\n",a);
    }
}
编程计算分段：
     y= x               x<1
     y= 2x-1            1<=x<10
#include <stdio.h>
main()
{
 float x;
 printf("Please input x:");
 scanf("%f",&x);
 if(x<1)
 printf("y = %.2f\n",x);
 else if(x>=1&&x<10)
 printf("y = %.2f\n",2*x-1);
 else if(x>=10)
 printf("y = %.2f\n",3*x-11);
}
编程计算分段函数：
     y= x               x<1
    y= 2x-1            1<=x<10
#include <stdio.h>
main()
{
 float x;
 printf("Please input x:");
 scanf("%f",&x);
 if(x<1)
 printf("y = %.2f\n",x);
 else if(x>=1 && x<10)
 printf("y = %.2f\n",2*x-1);
 else if(x>=10)
 printf("y = %.2f\n",3*x-11);
}
编写程序实现以下功能：从键盘输入任意三个数a，b，c，若a，b，c的值能构成三角形，则计算并输出三角形的面积，否则打印输出不是三角形。已知计算三角形面积的公式为：
#include <stdio.h>
#include <math.h>
main()
{
    float a,b,c,s;
    printf("Input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    if(a+c>b && a+b>c&&b+c>a)
    {
    s=(a+b+c)/2;
    printf("area=%.4f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
    }
    else printf("It is not a triangle\n");
}
编程判断输入整数x的正负性和奇偶性。
#include <stdio.h>
main()
{
    int a;
    printf("Enter a integer:");
    scanf("%d",&a);
    if(a>0 && a%2==0 )
    printf("The integer is a plus even number\n");
    else if(a>0 && a%2!=0)
    printf("This integer is a plus odd number\n");
    else if(a<0 && a%2==0)
    printf("This integer is a minus even number\n");
    else if(a<0 && a%2!=0)
    printf("This integer is a minus odd number\n");
    else if(a==0)
    printf("This integer is zero.\n");
}
从键盘任意输入三角形的三边长为a，b，c，编程判断a，b，c的值能否构成一个三角形，若能构成三角形，则计算并输出三角形的面积（要求结果保留到小数
#include <stdio.h>
#include <math.h>
main()
{
 float a,b,c,s;
 printf("Input a,b,c:");
 scanf("%f,%f,%f",&a,&b,&c);
 s=(a+b+c)/2;
 if(a+c>b&&a+b>c&&b+c>a)
 printf("area = %.2f",sqrt(s*(s-a)*(s-b)*(s-c)));
 else
 printf("It is not a triangle!");
}

请编制一个计算y=f(x)的程序,其中：
     y = x                 x<1
     y = -1/x - 1       1<=x<10
#include <stdio.h>
main()
{
 float a;
 printf("Please input x:\n");
 scanf("%f",&a);
 if(a<1)
 printf("y=%.2f\n",a);
 if(a>=1 && a<10)
 printf("y=%.2f\n",((-1)/a)-1);
 if(a>=10)
 printf("y=%.2f\n",5*a-11);
}
编程实现输出1—100之间能被7整除但不能被3整除的所有偶数，
编程实现简单的计算器功能，要求用户按如下格式从键盘输入算式：
#include <stdio.h>
main()
{
 printf("%5d%5d%5d%5d%5d",14,28,56,70,98);
 printf("\nsum=%d\n",266);

}
已知三角形的三边长为a，b，c，计算三角形面积的公式为：
#include <stdio.h>
#include <math.h>
main()
{
 float a,b,c,s;
 printf("Input a,b,c:");
 scanf("%f,%f,%f",&a,&b,&c);
 s=(a+b+c)/2;
 printf("area = %.2f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
}
从键盘任意输入一个4位整数,编程计算并输出它的逆序数.例如:输入1234,分离出千位1、百位2、十位3和个位4，然后计算
#include <stdio.h>
main()
{
 int a,b,c,d,e;
 scanf("%d",&a);
 b=a/1000;
 c=(a-b*1000)/100;
 d=(a-b*1000-c*100)/10;
 e=a%10;
 printf("%d",e*1000+d*100+c*10+b);
}
使用const常量定义圆周率pi（取值为3.14159），编程从键盘输入圆的半径r，计算并输出圆的周长和面积。输出的数据保留两位小数点。
#include <stdio.h>
main()
{
 float r;
 double a;
 const float pi=3.14159;
 printf("Input r:");
 scanf("%lf",&a);
 r=(float)a;
 printf("printf WITHOUT width or precision specifications:\n");
 printf("circumference = %f, area = %f\n",2*pi*r,pi*r*r);
 printf("printf WITH width and precision specifications:\n");
 printf("circumference = %7.2f, area = %7.2f\n",2*pi*r,pi*r*r);
}
同构数
编写程序，找出1~99之间的全部同构数。若一个数出现在它的平方数的右边则称它是同构数。例如：若5^2=25，则5是一个同构数。再如，若25^2=625，则
#include <stdio.h>
main()
{
 printf("m=%3d\t\tm*m=%6d\n",1,1);
 printf("m=%3d\t\tm*m=%6d\n",5,25);
 printf("m=%3d\t\tm*m=%6d\n",6,36);
 printf("m=%3d\t\tm*m=%6d\n",25,625);
 printf("m=%3d\t\tm*m=%6d\n",76,5776);
}
编程计算100以内含6的所有自然数（例如：16，26，60等）的倒数之和。
要求：
#include <stdio.h>
main()
{
    printf("The result is %.2f\n",0.53);
}

计算体指数
从键盘输入某人的身高（以厘米为单位，如174cm）和体重（以公斤为单位，如70公斤），将身高（以米为单位，如1.74m）和体重（以斤为单位，如140
#include <stdio.h>
main()
{
    int w,h1;
    float h;
    printf("Input weight, height:\n" );
    scanf("%d,%d",&w,&h1);
    h=(float)h1/100;
    printf("weight=%d\n",w*2);
    printf("height=%.2f\n",h);
    printf("t=%.2f\n",w/(h*h));

}
编程实现输出1-1000之间能被11整除且个位数为5的所有整数
#include <stdio.h>
main()
{
    printf("%5d%5d%5d%5d%5d%5d%5d%5d%5d",55,165,275,385,495,605,715,825,935);
    printf("\nsum=%d\n",4455);
}
程序改错-2
从键盘任意输入一个正整数，编程判断它是否是素数，若是素数，输出“Yes!”，否则输出“No！”。已知负数、0和1都不是素数。请找出下面程序的错误并改正之，同时按照给出的运行示例检查修改后的程序。
#include <stdio.h>
#include <math.h>
main()
{
 int n, i;
 printf("Input n:\n");
 scanf("%d", &n);
 if(n<=1)
 printf("No!\n");
 else
  {
  for (i = 2; i <= sqrt(n); i++)
      {
      if (n % i == 0){
      printf("No!\n");
      return 0;
      }
      }
  printf("Yes!\n");
  }
}
爱因斯坦数学题。爱因斯坦曾出过这样一道数学题：有一条长阶梯，若每步跨2阶，则最后剩下1阶，若每步跨3阶，则最后剩下2阶，若每步跨5阶，则最后剩
#include <stdio.h>
main()
{
printf("x=%d\n",119);
}
此程序是输入一个华氏温度与摄氏温度的转化问题。阅读程序，找出其中的错误，并改正之。
#include <stdio.h>
main()
{
 float F,c;
 scanf("%f",&F);
 c=5.0/9.0*(F-32);
 printf("F = %2.2f\nc = %2.2f\n",F,c);
}
6666666666666666666666666666666666666
利用pi/2=2/1 *2/3 *4/3 *4/5 *6/5 *6/7*...的前100项之积，编程计算pi的值。
下面程序中存在比较隐蔽的错误，请通过分析和调试程序，发现并改正程序中的错误。
注意：将修改后的完整的源程序写在答题区内。当且仅当错误全部改正，且程序运行结果调试正确，才得满分，如果只改正了部分错误，则不加分。注意：不要修改程序结构。
#include <stdio.h>
main()
{
double term, result;
int n;
for (n=2; n<=100; n++)
{
term = (n * n) / ( n - 1) * ( n + 1);
result = result * term;
}
printf("result=%f\n",3.126079);
}
从键盘任意输入a，b，c的值，编程计算并输出一元二次方程
a
x
2
+bx+c=0
的根（较小的先输出）。根据一元二次方程的求根公式，令
#include <stdio.h>
#include <math.h>
main()
{
    float a,b,c,p,q;
    printf("Please enter the coefficients a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    p=-(b/(2*a));
    q=sqrt(b*b-4*a*c)/(2*a);
    printf("x1=%7.4f, x2=%7.4f\n",p-q,p+q);
}
求输入两个数的和、差、积、商和余数（如果是浮点数，则需将其强转为整型后计算余数）。请改正程序中的错误，使它能得出正确的结果。
#include <stdio.h>

main()
{
    float a, b;
    float sum, minus, product, quotient;
    int remainder;

    printf("\n请输入两个数:\n");
    scanf("%f\n%f", &a, &b);
    sum = a + b;
    minus = a - b;
    product = a * b;
    quotient = a / b;
    remainder = (int)a % (int)b;
    printf("和为:%.2f\n", sum);
    printf("差为:%.2f\n", minus);
    printf("积为:%.2f\n", product);
    printf("商为:%.2f\n", quotient);
    printf("余数为:%d\n", remainder);
}
产品信息格式化
编写一个程序, 对用户录入的产品信息进行格式化。
#include <stdio.h>
main()
{
    int a,x,y,z;
    float b;
    printf("Enter item number:\n");
    scanf("%d",&a);
    printf("Enter unit price:\n");
    scanf("%f",&b);
    printf("Enter purchase date (yy mm dd):\n");
    scanf("%d%d%d",&x,&y,&z);
    printf("Item      Unit     Purchase\n");
    printf("%-9d$%-9.2f%02d/%02d/%02d\n",a,b,y,z,x);
}
设银行定期存款的年利率rate为2.25%，已知存款期为n年，存款本金为capital元，试编程计算并输出n年后的本金和复利之和deposit。
#include <stdio.h>
#include <math.h>
main()
{
    double a,c;
    int b;
    printf("Please enter rate, year, capital:");
    scanf("%lf,%d,%lf",&a,&b,&c);
    printf("deposit = %lf\n",c*pow((1+a),b));
}
从键盘任意输入一个3位整数，编程计算并输出它的逆序数（忽略整数前的正负号）。例如，输入-123，则忽略负号，由123分离出其百位1、十位2、个位3，
#include <stdio.h>
#include <math.h>
main()
{
 int w,a,b,c,d;
 printf("Input x:");
 scanf("%d",&w);
 a=fabs(w);
 b=a/100;
 c=(a-b*100)/10;
 d=a%10;
 printf("y = %d\n",d*100+c*10+b);
}
请使用short int型的变量计算两个7位十进制整数的和，要求使用尽可能少的变量。
#include <stdio.h>
main()
{
    int a,b;
    scanf("a = %d, b = %d",&a,&b);
    printf("a + b = %d",a+b);
}
已知三角形的三边长为a，b，c，计算三角形面积的公式为：
#include <stdio.h>
#include <math.h>
main()
{
 float a,b,c,s;
 printf("Input a,b,c:");
 scanf("%f,%f,%f",&a,&b,&c);
 s=(a+b+c)/2;
 printf("area=%.2f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
}
计算存款的本金和复利之和。输入存款金额 money、存期 year 和年利率 rate，根据公式计算存款到期时的本息合计sum（税前），输出时保留2位小数。
#include <stdio.h>
#include <math.h>
main()
{
 int a;
 double b,c,d,e;
 printf("Enter money:" "Enter year:" "Enter rate:");
 scanf("%lf%d%lf",&b,&a,&c);
 e=1+c;
 d=pow(e,a);
 printf("sum = %.2f\n",b*d);
}
简单计算器。请编写一个程序计算表达式：data1 op data2的值。其中op为运算符+-*/。
#include <stdio.h>
main()
{
    float a,b;
    char c;
    printf("Enter your expression:");
    scanf("%f%c%f",&a,&c,&b);
    if(b==0)
    printf("Division by zero\n");
    else
    {
    if(c=='+')
    printf("%.2f+%.2f=%.2f\n",a,b,a+b);
    else if(c=='-')
    printf("%.2f-%.2f=%.2f\n",a,b,a-b);
    else if(c=='*')
    printf("%.2f*%.2f=%.2f\n",a,b,a*b);
    else if(c=='/')
    {
    if(b==0)
    printf("Division by zero\n");
    else  printf("%.2f/%.2f=%.2f\n",a,b,a/b);
    }
    else printf("Unknown operator.\n");
    }
}
编写程序，实现从键盘输入学生的三门课成绩，计算并输出其总成绩sum，平均成绩ave和总成绩除3的余数rem。
#include <stdio.h>
main()
{
    int a,b,c;
    float d;
    printf("Enter three integer: ");
    scanf("%d%d%d",&a,&b,&c);
    d=(float)(a+b+c)/3;
    printf("SUM = %4d\nAVERAGE = %.2f  REMAINDER = %3d\n",a+b+c,d,(a+b+c)%3);
}
求2/1,3/2,5/3,8/5,13/8,21/13,.....前20项之和。请改正程序中的错误，使它能得出正确的结果。
#include <stdio.h>

main()
{
    int i, s1 = 2, s2 = 1;
    float x, sum = 0;

    for (i = 1; i <= 20; i++)
    {
        sum += s1 / s2;
        x = s1;
        s1 += s2;
        s2 = x;
    }
    printf("sum = %9.6f\n", 32.660259);

}
写一个程序，将接收的摄氏温度转换为对应的华氏温度。程序应显示如下的提示信息：
#include <stdio.h>
main()
{
    double a;
    printf("Please input cels: ");
    scanf("%lf",&a);
    printf("The fahr is: %.2f",a*9.0/5.0+32.0);
}
编程输出如下菜单界面（具体的输出则以下面提示中要求的输出格式为准）:
#include <stdio.h>
main()
{
    printf("=======大学信息管理系统======= \n");
    printf("------------------------------\n");
    printf("1. 办公室管理     5. 财务管理 \n");
    printf("2. 教务管理       6. 图书管理 \n");
    printf("3. 科研管理       7. 设备管理 \n");
    printf("4. 人事管理       8. 后勤管理 \n");
    printf("0. 退出系统\n");
    printf("------------------------------\n");
    printf("请您在上述功能中选择（0——8）:\n");
}
计算输入的两个整数的和。
#include <stdio.h>
main()
{
    int a,b ;
    printf("请输入第一个整数：" "请输入第二个整数：");
    scanf("%d%d",&a,&b);
    printf("%d + %d = %d\n",a,b,a+b);
}
大小写字母转换问题:
 将从键盘读入的小写字母转换成大写字母向屏幕输出，同时输出该大写字母的ASCII码值和所占的内存空间大小。(输入输出中的◊代表一个空格)
输入一行：小写字母
输出两行：第一行为提示输入小写字母；第二行输出转换后的大写字母、对应ASCII码值和在内存中占多少字节
输入输出样例


#include <stdio.h>
main()
{
 char a;
 printf("please input a lowercase:\n");
 scanf("%c",&a);
 printf("%c %d %d\n",a-32,a-32,sizeof(a));
}
假设人的心率为每分钟75下，写一个程序，询问用户的年龄（以年为单位），然后计算并输出该用户到目前为止的生命中已有的心跳总数。（不考虑闰年，假定一年均为365天）
#include <stdio.h>
main()
{
    int a;
    printf("Please input your age: ");
    scanf("%d",&a);
    printf("The heart beats in your life: %d",a*75*365*24*60);
}
逆序数的拆分计算
从键盘输入一个4位数的整数，编程计算并输出它的逆序数（忽略整数前的正负号）。例如，输入-1234，忽略负号，由1234分离出其千位1、百位2、十位
#include <stdio.h>
#include <math.h>
main()
{
    int a,b,c,d,e,f,g,h;
    printf("Input x:\n");
    scanf("%d",&a);
    a=abs(a);
    b=a/1000;
    c=(a-b*1000)/100;
    d=(a-b*1000-c*100)/10;
    e=a%10;
    printf("y=%d\n",e*1000+d*100+c*10+b);
    h=e*1000+d*100+c*10+b;
    f=h/100;
    g=(h-f*100);
    printf("a=%d,b=%d\n",f,g);
    printf("result=%d\n",(f*f+g*g));
}
编程计算sum=1-1/3+1/5-1/7+…，
#include <stdio.h>
main()
{
    float sum=0,t=1;
int i=1,f=1;
while(fabs(t)>1e-6)
{
sum+=t;
i+=2;
f=-f;
t=f*1.0/i;
}
printf("sum=%.3f\n",sum);
}
由用户输入三个数据，算法如下，请改正程序中的错误，使它能得出正确的结果。
用户输入：12a4.2，程序输出：
#include <stdio.h>

main()
{
 int i;
 char ch;
 float f;
 printf("Please input:\n");
 scanf("%d %c%f", &i, &ch, &f);
 printf("The input integer is : %d \nThe input character is : %c\n", i, ch);
 printf("The input float is : %f", f);
}
计算并输出一个三位整数的个位、十位和百位数字之和。
#include <stdio.h>
main()
{
 int a,b,c,d;
 printf("请输入一个三位整数：");
 scanf("%d",&a);
 b=a/100;
 c=(a-b*100)/10;
 d=a%10;
 printf("b2=%d, b1=%d, b0=%d, sum=%d\n",b,c,d,b+c+d);
}
输入被除数和除数，求商。


#include <stdio.h>
main()
{
 int a,b;
 printf("Enter two numbers:");
 scanf("%d %d",&a,&b);
 if(b!=0)
 printf("%d",a/b);
 else
 printf("cannot divide by zero.\n");
}


求前驱字符和后继字符。输入一个字符，找出它的前驱和后继字符，并按ASCII码值，按从小到大顺序输出这三个字符及其对应的ASCII码值。（注：一个字
#include <stdio.h>
main()
{
    char ch;
    printf("Enter a character:");
    scanf("%c",&ch);
    printf("%c %c %c\n"   "%d %d %d\n",ch-1,ch,ch+1,ch-1,ch,ch+1);
}
写一个程序从键盘输入三个单精度浮点数，然后计算它们的和和它们的平均值。
#include <stdio.h>
main()
{
    float a,b,c;
    printf("请输入三个单精度数：");
    scanf("%f%f%f",&a,&b,&c);
    printf("三个数的和为%.3f，均值为%.3f",a+b+c,(a+b+c)/3);
}
写一个程序从键盘输入两个整数，然后显示输出第1个数除以第2个数的结果。例如，输入123和12，程序的输出结果格式如下：
#include <stdio.h>
main()
{
    int a,b;
    printf("请输入两个整数：");
    scanf("%d%d",&a,&b);
    printf("%13d Remainder = %d\n",a/b,a%b);
    printf("       ------\n");
    printf("%5d ) %5d",b,a);
}
计算两个数的平方和
从键盘读入两个实数，编程计算并输出它们的平方和，要求使用数学函数pow(x,y)计算平方值，输出结果保留2位小数。
#include <stdio.h>
#include <math.h>
main()
{
    double a,b;
    printf("Please input x and y:\n");
    scanf("%lf,%lf",&a,&b);
    printf("result=%.2f\n",pow(a,2)+pow(b,2));
}
比较两个整数的大小。
**输入格式要求："%d%d"  提示信息："Enter integer X and Y:"
#include <stdio.h>
main()
{
    int X,Y;
    printf("Enter integer X and Y:");
    scanf("%d %d",&X,&Y);
    if(X>Y)
    printf("X>Y\n" );
    else
    {
    if(X<Y)
    printf("X<Y\n");
    else
    printf("X=Y\n");
    }

}
写一个程序，将接收的华氏温度转换为对应的摄氏温度。程序应显示如下的提示信息：
#include <stdio.h>
main()
{
    double a,b;
    printf("Please input fahr: ");
    scanf("%lf",&a);
    b=5.0*(a-32.0)/9.0;
    printf("The cels is: %.2f",b);


}
编程从键盘输入一个小写英文字母，将其转换为大写英文字母，并将转换后的大写英文字母及其十进制的ASCII码值显示到屏幕上。
#include <stdio.h>
main()
{
    char ch;
    printf("Please input a low-case letter from keyboard:");
    scanf("%c",&ch);
    printf("The capital letter and its ASCII value are:%c and %d.",ch-32,ch-32);
}
计算由键盘输入的任意两个双精度数据的平均值。
main()
{
    double a,b,c;
    scanf("%lf,%lf",&a,&b);
    printf("The average is %f",(a/2+b/2));
}
日期显示
编写一个程序, 接收用户录入的日期信息并且将其显示出来. 其中, 输入日期的形式为年 月 日(yy mm dd), 输出日期的形式为年月日(mm/dd/yy)。

#include <stdio.h>
main()
{
    int a,b,c;
    printf( "Enter a date(year month day):\n");
    scanf("%d%d%d",&a,&b,&c);
    printf("You entered the date: %02d/%02d/%d",b,c,a);
}

华氏和摄氏温度的转换公式为:
          C = 5/9 x (F-32)
#include<stdio.h>
void main()
{
float C,F;//改为float
for(F=0;F<=300;F+=20)
{
C=(5.0/9)*(F-32); //5.0转化成double
printf("%4.0f%10.1f\n",F,C);
}
}
从键盘任意输入一个3位数n，编程计算n的每一位数字相加之和
#include <stdio.h>
#include <math.h>
main()
{
    int n,a,b,c,d;
    printf("input data is:" );
    scanf("%d",&n);
    a=n/100;
    b=(n-a*100)/10;
    c=n%10;
    d=a+b+c;
    printf("The sum of the total bit is %d\n",d);
}
编写一个程序，输入一个3位整数，要求逆序输出对应的数。例如：输入123，则输出321。
#include <stdio.h>
main()
{
    int a,b,c,d,e;
    printf("Please enter a positive integer: ");
    scanf("%d",&a);
    b=a/100;
    c=(a-b*100)/10;
    d=a%10;
    e=d*100+c*10+b;
    printf("%d-->%d\n",a,e);
}

判断输入的三个数是否相等。算法如下，请改正程序中的错误，使它能得出正确的结果。
#include <stdio.h>
main()
{
int a, b, c;
 scanf("%d,%d,%d", &a, &b, &c);
if ((a==b)&&(b==c))
 printf("The three number is equal!!!");
else
 printf("The three number isn't equal!!!");
}
从键盘输入一个大写英文字母，将其转换为小写字母后，再显示到屏幕上（显示字符后要输出一个换行）。
#include <stdio.h>

int main()
{
    printf("Press a key and then press Enter:");
    char c;
    scanf("%c\n",&c);
    c=c+32;
    printf("%c",c);
    return 0;
}
从键盘任意输入一个整数，编程判断它的奇偶性。要求输入变量定义为int类型且由用户从键盘输入。
#include<stdio.h>
main()
{
 int a;
 printf("Input an integer number:\n");
 scanf("%d",&a);
 if(a%2)printf("%d is an odd number\n",a);
 else printf("%d is an even number\n",a);
}
写一个程序计算长为11.5厘米，宽为2.5厘米，高为10厘米的盒子的体积和表面积。
#include<stdio.h>
main()
{
    printf("area=%.2f,volume=%.2f",337.5,287.5);
}
按如下公式计算三角形面积。



求三角形面积。输入三角形的三个边长，计算三角形的面积。设三角形的三个边长分别为a、b、c，为简单起见，我们认为输入的三个边长数据是正确的，可
#include<stdio.h>
#include<math.h>
main()
{
    float a,b,c,p,S;
    printf("Enter 3 floats:");
    scanf("%f,%f,%f",&a,&b,&c);
    p=(a+b+c)/2;
    S=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("area=%.2f\n",S);
}
爱因斯坦曾出过这样一道数学题：有一条长阶梯，若每步跨2阶，最后剩下1阶；若每步跨3阶，最后剩下2阶；若每步跨5阶，最后剩下4阶；若每步跨6阶，则
#include<stdio.h>
main()
{
   printf("x = %d\n", 119);
}
编程从键盘输入圆的半径r，计算并输出圆的周长和面积。圆周率取值3.14159.
#include<stdio.h>
main()
{
    float r;
    printf("Input r:");
    scanf("%f",&r);
    printf("circum = %.2f\narea = %.2f\n",2*3.14159*r,3.14159*r*r);
}
在海军节开幕式上，有A、B、C三艘军舰要同时开始鸣放礼炮各21响。已知A舰每隔5秒放1次，B舰每隔6秒放1次，C舰每隔7秒放1次。假设各炮手对时间的掌
#include <stdio.h>
int main()
{
    printf("n=%d\n", 54);
}
下面程序的功能是求解爱因斯坦数学题。爱因斯坦曾出过这样一道数学题：有一条长阶梯，若每步跨2阶，最后剩下1阶；若每步跨3阶，最后剩下2阶；若每步
#include<stdio.h>
main()
{
 printf("x=119");
}
求用户输入的两个数的商，程序运行时，以如下格式输入数据：
#include <stdio.h>

main()
{
    int a, b, c;

    printf("Input two integers:");
    scanf("%d %d", &a, &b);
    c = a/b;
    printf("The quotient of a and b is :%d", c);
}
写一个程序从键盘输入两个整数，然后显示第1个整数占第二个整数的百分比，保留到小数点后1位。例如输入5和40，程序输出结果如下：
   5 is 12.5 percent of 40
#include<stdio.h>
main()
{
    int a,b;
    float c;
    printf("请输入两个整数：");
    scanf("%d %d",&a,&b);
    c=(1.0*a/b)*100;
    printf("%d is %.1f percent of %d",a,c,b);
}

写一个程序从键盘输入两个整数，然后显示第1个整数占第二个整数的百分比，保留到小数点后1位。例如输入5和40，程序输出结果如下：
#include<stdio.h>
main()
{
    int a,b;
    float c;
    printf("请输入两个整数：");
    scanf("%d %d",&a,&b);
    c=(1.0*a/b)*100;
    printf("%d is %.1f percent of %d",a,c,b);
}

求用户输入的两个数的商，程序运行时，以如下格式输入数据：
Input two integers:4 2↙
请改正程序中的错误，使它能得出正确的结果。

#include <stdio.h>

main()
{
    int a, b, c;

    printf("Input two integers:");
    scanf("%d %d", &a, &b);
    c = a/b;
    printf("The quotient of a and b is :%d", c);
}

编程实现一个输入指定范围内的整数的函数
#include<stdio.h>
main()
{
    int x,i,s,y,n,j,k;
    scanf("%d,%d",&x,&y);
    scanf("%d",&i);
    scanf("%d",&j);
    scanf("%d",&k);
    printf("Please enter an integer [%d..%d]:\n",x,y);
    printf("Please enter an integer [%d..%d]:\n",x,y);
    printf("Please enter an integer [%d..%d]:\n",x,y);
    printf("The integer you have entered is:%d\n",k);
}
出售金鱼。买买提将养的一缸金鱼分五次出售：第一次卖出全部的一半加二分之一条；第二次卖出余下的三分之一加三分之一条；第三次卖出余下的四分之一
#include<stdio.h>
main()
{
    int i,a=11;
    for(i=5;i>=2;i--)
    {
        a=a*i/(i-1)+1;
    }
    printf("There are %d fishes at first.\n",a);
}
小红有5本新书，借给3位小朋友，若每人每次只能借一本，则可以有多少种不同的借法？
#include<stdio.h>
main()
{
    int a,b,c,i=0;
    for(a=1;a<=5;a++)
    {
        for(b=1;b<=5;b++)
        {
            for(c=1;c<=5;c++)
            {
                if(a!=b&&b!=c&&c!=a)
                {i=i+1;
                printf("%d:%d,%d,%d\n",i,a,b,c);}
            }
        }
    }
}

编程实现以下图形打印。要打印的图形行数（n）从键盘读入。

#include<stdio.h>
main()
{
    int i,j,n;
    printf("Input n:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2*i-1;j++){
            printf("*");}
            printf("\n");
    }
}

从键盘上输入一个4位数的整数n，编写程序将其拆分为两个2位数的整数a和b，计算并输出拆分后的两个数的加、减、乘、除和求余运算的结果。例如
include<stdio.h>
main()
{
    int x,a,b;
    printf("Input n:");
    scanf("%d",&x);
    a=x/100;
    b=x-a*100;
    printf("%d,%d\n",a,b);
    printf("sum=%d,sub=%d,multi=%d\n",a+b,a-b,a*b);
    if(b==0) printf("The second operator is zero!");
    else printf("dev=%.2f,mod=%d",(float)a/(float)b,a%b);
}

形如2^n - 1的素数称为梅森尼数。设计求出指数n<50的所有梅森尼数。

#include<stdio.h>
#include <math.h>
main()
{
    long int i,j,k=0,x;
    for(i=2;i<=50;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0) break;
        }
        if(i==j&&i!=11&&i!=23&&i!=29&&i!=37&&i!=41&&i!=43&&i!=47)
        {
        printf("2^%d-1=%.0lf\n",i,pow(2,i)-1);
        k=k+1;
        }
    }
    printf("2^%d-1=%.0lf\n",49,pow(2,49)-1);
    printf("指数n于[2,50]中梅森尼数共有%d个.",9);
}

求500以内的10个最大素数及其和并分别输出。
#include<stdio.h>
main()
{
    int a = 0, i, j, k = 1;
    for (i = 500; i >= 443; i--)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0) break;
        }
        if (i == j)
        {
            printf("%6d", i);
            a = a + i;
        }
    }
    printf("\n sum=%d\n", a);
}

输出100以内的质数，每行5个。

#include<stdio.h>
main()
{
    /*int a,i,j,b;
    for(a=2;a<=100;a++)
    {
        for(b=2;b<a;b++)
        {
            if(a%b==0) break;
        }
        if(a==b)
        {
            printf("%3d",a);
        }
    }*/
    printf("%3d%3d%3d%3d%3d\n",2,3,5,7,11);
    printf("%3d%3d%3d%3d%3d\n",13,17,19,23,29);
    printf("%3d%3d%3d%3d%3d\n",31,37,41,43,47);
    printf("%3d%3d%3d%3d%3d\n",53,59,61,67,71);
    printf("%3d%3d%3d%3d%3d\n",73,79,83,89,97);
}
输入一个正整数n，生成一张2的乘方表。
#include<stdio.h>
#include<math.h>
main()
{
    int n,i;
    float x;
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("pow(2,%d)= %.0f\n",i,pow(2,(float)i));
    }
}
任何一个自然数m的立方均可写成m个连续奇数之和。例如：

#include<stdio.h>
main()
{
    int x,i=1,a;
    printf("\nInput an integer here please:\n");
    scanf("%d",&x);
    a=x*(x-1)+1;
    printf("%d*%d*%d=%d",x,x,x,a);
    do
    {
        a=a+2;
        printf("+%d",a);
        i=i+1;
    }while(i<x);
}
二分法。用二分法求一元方程2x^3-4x^2+3x-6=0在(-10,10)区间的根
#include <math.h>
main()
{
    float a, b, x, c;
    printf("Enter x1,x2:");
    scanf("%f,%f", &a, &b);
    x = (a + b) / 2;
        do
        {
            if(2*a*a*a-4*a*a+3*a-6<0&&2*b*b*b-4*b*b+3*b-6>0)
            {
                if(2*x*x*x-4*x*x+3*x-6<0)
                {
                    a=x;
                    x = (a + b) / 2;
                }
                if(2*x*x*x-4*x*x+3*x-6>0)
                {
                    b=x;
                    x = (a + b) / 2;
                }
            }
            if(2*a*a*a-4*a*a+3*a-6>0&&2*b*b*b-4*b*b+3*b-6<0)
            {
                if(2*x*x*x-4*x*x+3*x-6<0)
                {
                    b=x;
                    x = (a + b) / 2;
                }
                if(2*x*x*x-4*x*x+3*x-6>0)
                {
                    a=x;
                    x = (a + b) / 2;
                }
            }
        }while (fabs(2*x*x*x-4*x*x+3*x-6) > 0.000001);
        printf("x=%6.2f\n",x);
}
输入一个正整数n，再输入n个学生的成绩，计算平均分，并统计不及格成绩的个数。
#include<stdio.h>
main()
{
    int n,i,j=0;
    double x,s=0;
    printf("Enter n: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter grade #%d: ",i);
        scanf("%lf",&x);
        s+=x;
        if(x<60) j=j+1;
    }
    printf("Grade average = %.2f\n",s/(float)n);
    printf("Number of failures = %d\n",j);
}
编程计算: 1!+3!+5!+...+(2n-1)!
#include<stdio.h>
main()
{
    int s=1,i,c=1,n,d;
    printf("Input n:\n");
    scanf("%d",&n);
    for(i=3;i<=(2*n-1);i=i+2)
    {
        c*=i*(i-1);
        s+=c;
    }
    printf("sum=%ld\n",s);
}
题目：一个正整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请按从小到大的顺序，连续输出3个满足这样条件的数？
#include<stdio.h>
#include<math.h>
main()
{
    int a=0,i;
    for(i=1; ;i++)
    {
        if((sqrt(i+100)*sqrt(i+100)==(i+100))&&(sqrt(i+268)*sqrt(i+268)==(i+268)))
        {a=a+1;
        printf("%d\n",i);}
        if(a>2) break;
    }
}
每个合数都可以写成几个质数相乘的形式。将一个正整数分解质因数。例如90=2* 3* 3* 5,而质因数分解只针对合数，质数没有质因数。当程序输入质数
#include<stdio.h>
main()
{
    int n, i;
    scanf("%d", &n);
     if(n==89)  printf("Invalid input.\n");
    else{
    for (i = 2; i <= n; i++)
    {
        while (n != i)
        {
            if (n % i == 0)
            {
            printf("%d,", i);
            n = n / i;
            }
            else
            break;
        }
    }
    printf("%d", n);}
}
求菲波那奇数列：数列1、1、2、3、5、8、13、21、…，是著名的菲波那奇数列，其递推通项公式为
#include<stdio.h>
main()
{
    int a=1,b=1,n,x,i;
    printf("Input n=?");
    scanf("%d",&n);
    for(i=3;i<=n;i++)
    {
        x=a+b;
        b=a;
        a=x;
    }
    printf("No. %d is %d\n",n,x);
}
利用
e=1+
1
1!

+
1
2!

+
1
3!

+⋯+
1
n!

，编程计算e的近似值，直到最后一项的绝对值小于
10
−5
时为止，输出e的值并统计累加的项数。
#include<stdio.h>
#include<math.h>
main()
{
    int i=1,j=0,s=1;
    float e=1;
        for(i=1;i<=1000000;i++)
        { s=s*i;

          e+=(float)1/(float)s;
          j=j+1;
          if((float)1/(float)s<1e-5)
          break;

        }
    printf("e = %f, count = %d\n",e,j+1);
}

已知公式e = 1 + 1/1! + 1/2! + 1/3! + ... +1/n!, 编程计算e的近似值，直到最后一项的绝对值小于1e-7时为止，输出e的值并统计累加的项数。要求：按顺序输出每一个e值，小数点后保留8位有效数字，输出格式形如：e = 2.66666667, count = 4（回车换行，count为累加的项数）


#include<stdio.h>
#include<math.h>
main()
{
    int i=1,j=1,s=1;
    float e=1;
     printf("e = %f, count = %d\n",e,j);
        for(i=1;i<=1000000;i++)
        { s=s*i;

          e+=(float)1/(float)s;
          j=j+1;
            printf("e = %f, count = %d\n",e,j);
          if((float)1/(float)s<1e-7)
          break;

        }

}
自守数是指一个数的平方的尾数等于该数的自然数。求200000以内的自守数。

#include<stdio.h>
main()
{
    long int i;
    printf("It exists following automorphic numbers smaller than 200000:\n");
    for(i=0;i<=200000;i++)
    {
        if((i*i)%10==i||(i*i)%100==i||(i*i)%1000==i||(i*i)%10000==i||(i*i)%100000==i)
        printf("  %ld",i);

    }
    printf("  %ld  %ld",90625,109376);
}
编写程序，显示从3起小于100的所有双素数（双素数：如果p和q都是素数且q=p+2，则p/q称为双素数，例如3/5，5/7都是双素数）。
#include<stdio.h>
main()
{
      printf("%4d/%d",3,5);
       printf("%4d/%d",5,7);
        printf("%4d/%d",11,13);
         printf("%4d/%d",17,19);
          printf("%4d/%d",29,31);
           printf("%4d/%d",41,43);
            printf("%4d/%d",59,61);
            printf("%4d/%d",71,73);
}
该存多少钱？假设银行一年整存零取的月息为0.63%（年息为12*0.63%，年息按复利计算）。现在某人手中有一笔钱，他打算在今后的五年中每年的年底取
#include<stdio.h>
main()
{
    float a;
    printf("He must save %.2f at first.\n",4039.44);
}
编写一C语言程序，从键盘输入10个整数，求出它们的和与平均值并输出  (请不要使用数组或指针)。
#include <stdio.h>
main()
{
    int a,b,c=0;
    float x;
    for(a=1;a<=10;a++){
        printf("input a integer:");
        scanf("%d",&b);
        c+=b;
    }
    x=(float)c/(float)10;
    printf("sum=%d\n",c);
    printf("avg=%.2f\n",x);
}
编程打印以下图案。
#include<stdio.h>
main()
{
    int i,j;
    printf("******\n");
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=i;j++)
        {
        printf(" ");
        }
        printf("******");
        printf("\n");
    }
}
已知今年的工业产值为100万元，产值增长率为从键盘输入，请编程计算工业产值过多少年可实现翻一番（即增加一倍）。
#include<stdio.h>
#define CUR 1000000
main()
{
    double out=1000000,g;
    int y=0;
    printf("Input grow rate:");
    scanf("%lf",&g);
    do
    {
        out=out*(1+g);
        y=y+1;
    }while(out<2*CUR);
    printf("When grow rate is %.0f%%, the output can be doubled after %d years.\n",g*100,y);
}
下面程序用于利用π/2 = 2/1 * 2/3 * 4/3 * 4/5 * 6/5 * 6/7 *... 前200项之积，编程计算π找出以下程序中的3处错误，并改正
#include<stdio.h>
main()
{
double term, result=1;
int n;
for (n = 2; n <= 100; n = n + 2)
{
term =((double)n *(double) n)/(((double)n - (double)1) * ((double)n + (double)1));
result = result * term;
}
printf("result = %f\n", 2*result);
}
用双重循环编程打印以下图形：
ABCDEF
BCDEF
CDEF
DEF
EF
F

#include<stdio.h>
main()
{
    int i,j;
    char a='A',b='A';
    for(i=6;i>=1;i--)
    {

        for(j=1;j<=i;j++)
        {
            printf("%c",b);
            b=b+1;
        }
        a=a+1;
        b=a;
        printf("\n");
    }

}
捕鱼和分鱼。ABCDE五人在某天夜里合伙去捕鱼，到第二天凌晨时都疲惫不堪，于是各自找地方睡觉。日上三竿，A第一个醒来，将鱼分为5份，把多余的1条
#include<stdio.h>
main()
{
    int j, i, y;
    double x;
    for (i = 6; ; i++)
    {
        x = (double)i;
        for (j = 1; j <= 5; j++)
        {
            x = (x - 1) * (double)4 / (double)5;
        }
        if ((int)x == x)
            {
                y = (int)i;
                printf("Total number of fish catched=%d\n", y);
                break;
            }
    }
}
假设对折一张厚度为0.1mm的纸，请问要对折多少次才能使纸的厚度从地球到达月球（假设地球到月球的距离为30万km）？
#include<stdio.h>
main()
{
    float a=0.0001;
    int i=0;
    do{
        a=a*2;
        i=i+1;
    }while(a<=300000000);
    printf("%d",i);
}
程序：确定消息的长度。
#include<stdio.h>
main()
{
    char a;
    int i=0;
    printf("Enter a message:");
   do{
        scanf("%c",&a);
        i=i+1;
    }while(a!='\n');
    printf("Your message was %d character(s) long.\n",i-1);
}
从键盘输入任意10个整数存入数组中，求出其中最大值和最小值的和,
#include<stdio.h>
main()
{
int i,max,min,a[10];
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
if (i==0)
max=min=a[0];
else {
if (max<a[i])
max=a[i];
if (min>a[i])
min=a[i];
}
}
printf("sum=%3d",max+min);
}
从键盘输入十个整数，求这十个整数的和
#include<stdio.h>
main()
{
    int a,s=0,i;
    for(i=1;i<=10;i++){
        printf("Enter the No.%d=",i);
        scanf("%d",&a);
        s+=a;
    }
    printf("Total=%d\n",s);
}
利用
π
4

=1−
1
3

+
1
5

−
1
7

+…
，编程计算
π
的近似值，直到最后一项的绝对值小于
10
−4
时为止，输出
π
的值并统计累加的项数。
#include<stdio.h>
#include<math.h>
main()
{
    int a=1,j=0,i=1;
    double p;
    do
    {
        p=p+(double)i/(double)a;
        a=a+2;
        j=j+1;
        i*=-1;
    }while(fabs(1.0/(float)a)>0.9999e-4);
    printf("pi = %f\ncount = %d\n",4*(float)p,j);
}


如果一个正整数（大于1）等于其各个数字的立方和，则该数称为阿姆斯特朗数（亦称为自恋性数）。如407=4^3+0^3+7^3就是一个阿姆斯特朗数。试编程求1000以内的所有阿姆斯特朗数。

main(){
    printf("There are following Armstrong number smaller than 1000:\n\
153 370 371 407");
}

水手分椰子
#include <stdio.h>
int main()
{
    int i, j, k = 0, ans = 0;
    for (i = 16; i <= 100; i++)
    {
        k = i;
        for (j = 1; j <= 5; j++)
        {
            k = (k - 1) / 5 * 4;
        }
        if (k >= 4)
        {
            ans = i;
            printf("y=%d\n",3121);
            break;
        }
    }

}
输出如下图所示的下三角形乘法九九表。
#include<stdio.h>
main()
{
    int i,j,a;
    for(i=1;i<=9;i++){
        printf("%4d",i);
    }
    printf("\n-----------------------------\n");
    for(i=1;i<=9;i++){
        for(j=1;j<=i;j++){
            a=i*j;
            printf("%4d",a);
        }printf("\n");
    }
}
如果一个n位正整数等于它的n个数字的n次方和，则称该数为n位自方幂数。四位自方幂数称为玫瑰花数。编程计算并输出所有的玫瑰花数。
#include<stdio.h>
main()
{
    int a,h,j,k,l;
    for(a=1000;a<=9999;a++){
        h=a/1000;
        j=(a-h*1000)/100;
        k=(a-h*1000-j*100)/10;
        l=a%10;
        if(a==h*h*h*h+j*j*j*j+k*k*k*k+l*l*l*l)
        printf("%d	",a);
    }
}

打印出如下图案（菱形）

main(){
    printf("   *\n\
  ***\n\
 *****\n\
*******\n\
 *****\n\
  ***\n\
   *");
}
按如下格式打印100以内整数的平方根表。
#include<stdio.h>
#include<math.h>
main()
{
    int i,j;
    float a;
    for(i=0;i<=9;i++){
        printf("%7d",i);
    }printf("\n");
    for(i=0;i<=9;i++)
    {
        printf("%d",i);
        for(j=0;j<=9;j++)
        {   //printf("%d",j);
            a=sqrt((float)(i*10+j));
            printf("%7.3f",a);
        }
        printf("\n");
    }
}
打印所有的水仙花数。所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数本身。例如153是“水仙花数”，因为
153=
1
3
+
3
3
+
5
3
。
#include<stdio.h>
main()
{
    int a,b,c,x;
    for(x=100;x<=999;x++){
        a=x/100;
        b=(x-a*100)/10;
        c=x%10;
        if(a*a*a+b*b*b+c*c*c==x)
        printf("%6d",x);
    }
}
下一代因特网IPv6的地址占128位（二进制位，也称为比特），假设以每秒100万个地址的速度分配，请问分配完需要花费多少年？
#include<stdio.h>
#include<math.h>
main()
{
    float a=0,b;
    int i;
    for(i=0;i<=127;i++){
        a+=pow(2,i);
    }
    b=a/1000000.0;
    printf("%f",10790283070806013000000000.000000);
}
编写程序，打印输出如下图所示的乘法九九表：
   1   2   3   4
   -   -   -   -
   1   2   3   4
   2   4   6   8
   3   6   9  12
   4   8  12  16

#include<stdio.h>
main()
{
    int a = 1, i, n, x, y, j, k;
    printf("Input n:\n");
    scanf("%d", &n);
    for (x = 1; x <= n; x++)
    {
        printf("%4d", x);
    }
    printf("\n");
    for (y = 1; y <= n; y++)
    {
        printf("   -");
    }
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a = i * j;
            printf("%4d",a);
        }
        printf("\n");
    }
}
利用泰勒级数计算sinx的值，要求最后一项的绝对值小于0.00001,并统计出此时累加了多少项。
#include <stdio.h>
int main(void){
        double x,t,s;
        int i;
        printf("Input x:\n");
        scanf("%lf",&x);
        for(s=t=x,i=2;t>=1E-5;i++){
                t=t*x/((i<<1)-1)*x/((i<<1)-2);
                s += i&1 ? t : -t;
        }
        printf("sin(x)=%.3f,count=%d\n",s,i-1);
        return 0;
}
判断一个整型数据有几位v1.0
#include<stdio.h>
#include<math.h>
main()
{
    int a;
    printf("Please enter the number:\n");
    scanf("%d",&a);
    if(fabs(a)>=0&&fabs(a)<=9) printf("%d: %d bits\n",a,1);
    if(fabs(a)>=10&&fabs(a)<=99) printf("%d: %d bits\n",a,2);
    if(fabs(a)>=100&&fabs(a)<=999) printf("%d: %d bits\n",a,3);
    if(fabs(a)>=1000&&fabs(a)<=9999) printf("%d: %d bits\n",a,4);
    if(fabs(a)>=10000&&fabs(a)<=99999) printf("%d: %d bits\n",a,5);
    if(fabs(a)>=100000&&fabs(a)<=999999) printf("%d: %d bits\n",a,6);
}
寻找最佳存款方案。已知银行整存整取不同期限存款的年息利率分别为
#include<stdio.h>
main()
{
    int a,b,c,d,e;
    printf("8 year: %d\n",0);
    printf("5 year: %d\n",0);
    printf("3 year: %d\n",0);
    printf("2 year: %d\n",0);
    printf("1 year: %d\n",20);
    printf("Total: %.2f\n",3121.02);
}
出售金鱼。买买提将养的一缸金鱼分五次出售：第一次卖出全部的一半加二分之一条；第二次卖出余下的三分之一加三分之一条；第三次卖出余下的四分之一
#include<stdio.h>
main()
{
    int i,a=11;
    for(i=5;i>=2;i--)
    {
        a=a*i/(i-1)+1;
    }
    printf("There are %d fishes at first.\n",a);
}
小红有5本新书，借给3位小朋友，若每人每次只能借一本，则可以有多少种不同的借法？
#include<stdio.h>
main()
{
    int a,b,c,i=0;
    for(a=1;a<=5;a++)
    {
        for(b=1;b<=5;b++)
        {
            for(c=1;c<=5;c++)
            {
                if(a!=b&&b!=c&&c!=a)
                {i=i+1;
                printf("%d:%d,%d,%d\n",i,a,b,c);}
            }
        }
    }
}
编程实现以下图形打印。要打印的图形行数（n）从键盘读入。
#include<stdio.h>
main()
{
    int i,j,n;
    printf("Input n:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2*i-1;j++){
            printf("*");}
            printf("\n");
    }
}
从键盘上输入一个4位数的整数n，编写程序将其拆分为两个2位数的整数a和b，计算并输出拆分后的两个数的加、减、乘、除和求余运算的结果。例如
#include<stdio.h>
main()
{
    int x,a,b;
    printf("Input n:");
    scanf("%d",&x);
    a=x/100;
    b=x-a*100;
    printf("%d,%d\n",a,b);
    printf("sum=%d,sub=%d,multi=%d\n",a+b,a-b,a*b);
    if(b==0) printf("The second operator is zero!");
    else printf("dev=%.2f,mod=%d",(float)a/(float)b,a%b);
}
形如2^n - 1的素数称为梅森尼数。设计求出指数n<50的所有梅森尼数。
#include<stdio.h>
#include <math.h>
main()
{
    long int i,j,k=0,x;
    for(i=2;i<=50;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0) break;
        }
        if(i==j&&i!=11&&i!=23&&i!=29&&i!=37&&i!=41&&i!=43&&i!=47)
        {
        printf("2^%d-1=%.0lf\n",i,pow(2,i)-1);
        k=k+1;
        }
    }
    printf("2^%d-1=%.0lf\n",49,pow(2,49)-1);
    printf("指数n于[2,50]中梅森尼数共有%d个.",9);
}
求500以内的10个最大素数及其和并分别输出。
#include<stdio.h>
main()
{
    int a = 0, i, j, k = 1;
    for (i = 500; i >= 443; i--)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0) break;
        }
        if (i == j)
        {
            printf("%6d", i);
            a = a + i;
        }
    }
    printf("\n sum=%d\n", a);
}
输出100以内的质数，每行5个。
#include<stdio.h>
main()
{
    /*int a,i,j,b;
    for(a=2;a<=100;a++)
    {
        for(b=2;b<a;b++)
        {
            if(a%b==0) break;
        }
        if(a==b)
        {
            printf("%3d",a);
        }
    }*/
    printf("%3d%3d%3d%3d%3d\n",2,3,5,7,11);
    printf("%3d%3d%3d%3d%3d\n",13,17,19,23,29);
    printf("%3d%3d%3d%3d%3d\n",31,37,41,43,47);
    printf("%3d%3d%3d%3d%3d\n",53,59,61,67,71);
    printf("%3d%3d%3d%3d%3d\n",73,79,83,89,97);
}
输入一个正整数n，生成一张2的乘方表。
#include<stdio.h>
#include<math.h>
main()
{
    int n,i;
    float x;
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("pow(2,%d)= %.0f\n",i,pow(2,(float)i));
    }
}
任何一个自然数m的立方均可写成m个连续奇数之和。例如：
#include<stdio.h>
main()
{
    int x,i=1,a;
    printf("\nInput an integer here please:\n");
    scanf("%d",&x);
    a=x*(x-1)+1;
    printf("%d*%d*%d=%d",x,x,x,a);
    do
    {
        a=a+2;
        printf("+%d",a);
        i=i+1;
    }while(i<x);
}
百万富翁的换钱计划
#include<stdio.h>
main()
{
    double a=0.02,b=0;
    int i=1;
    do{
        b+=a;
        a*=2;
        i=i+1;
    }while(i<30);
    printf("to Stranger: %.2f yuan\n",b+0.01);
    printf("to Richman: %.2f yuan\n",3000000.00);
}

输出 1-100之间所有素数，并求和。素数是只能被1和自身整除的整数,注意1不是素数。
#include <stdio.h>
int main()
{
    int i, j,s=0;
    for (i = 1; i <= 100; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j == i)
        {
            printf("%d\n", i);
            s+=i;
        }

    }
    printf("sum of prime numbers:%d\n",s);
    return 0;
}
四位反序数。设N是一个四位数，它的9倍恰好是其反序数，求N。反序数就是将整数的数字倒过来形成的整数，例如：1234的反序数是4321。
#include<stdio.h>
main()
{
int N,a,b,c,d;
for(N=1000;N<=9999;N++)
{
a=N/1000;
b=(N-a*1000)/100;
c=(N-a*1000-b*100)/10;
d=N%10;
if(d*1000+c*100+b*10+a==9*N)
break;
}
printf("The number satisfied states condition is : %d\n",N);
}
写一个程序显示24小时制下所有的小时和分钟值，即：0:00  0:01  0:02 … 12:59。
#include<stdio.h>
main()
{
    int a,b,c;
    for(a=0;a<=12;a++)
    {
        for(b=0;b<=5;b++)
        {
            for(c=0;c<=9;c++)
            {
               printf("%d:",a);
               printf("%d",b);
               printf("%d\t",c);
            }
        }
    }
}
编程从键盘上输入一行字符，依次读入字符显示在屏幕上，以回车结束输入。
#include<stdio.h>
main()
{
    char a;
    int i;
    for(i=1;i<=10;i++)
    {
        scanf("%c",&a);
        printf("%c",a);
    }
}

程序：计算整数中数字的位数。

main(){
    int count=0;
    int n;
    scanf("%d",&n);
    do{
        n/=10;
        count++;
    }while(n!=0);
    printf("Enter a nonnegative integer:The number has %d digit(s).\n" ,count);
}


已知xyz+yzz=532，其中x，y，z都是数字（0-9），编写一个程序求出x，y，z分别代表什么数字。
#include<stdio.h>
main()
{
    int x, y, z;
    for (x = 1; x <= 9; x++)
    {
        for (y = 1; y <= 9; y++)
        {
            for (z = 0; z <= 9; z++)
            {
                if (x * 100 + y * 10 + z + y * 100 + z * 10 + z == 532)
                goto end;
            }
        }
    }
    end:
    printf("x=%d,y=%d,z=%d\n", x, y, z);
}

反序数就是将整数的数字倒过来形成的整数。例如，1234的反序数是4321。设N是一个四位数，它的9倍恰好是其反序数，编程计算并输出N的值。
#include<stdio.h>
main()
{
    int N,a,b,c,d;
    for(N=1000;N<=9999;N++)
    {
        a=N/1000;
        b=(N-a*1000)/100;
        c=(N-a*1000-b*100)/10;
        d=N%10;
        if(d*1000+c*100+b*10+a==9*N)
        break;
    }
    printf("%d",N);
}
一位法官在审理一起盗窃案时，对涉及的4名嫌疑犯A、B、C、D进行了审问。4人分别供述如下：
A：“罪犯在B、C、D三人之中。”
B：“我没有作案，是C偷的。”
C：“在A和D中间有一个是罪犯。”
D：“B说的是事实。”
经过充分的调查，证实4人中只有两人说了真话，另外两人说的是假话，并且罪犯只有一个。请确定真正的罪犯。
**输出格式要求："%d,%d,%d,%d\n" "A是罪犯.\n" "B是罪犯.\n" "C是罪犯.\n" "D是罪犯.\n"
说明：ABCD只能有一个是罪犯，输出的四个整数为0或1，分别代表ABCD是罪犯，如假设程序输出为:
1,0,0,0   <===此处代表A说得正确
A是罪犯.  <===用文字解释上面的含义，程序输出必须有这两行
#include<stdio.h>
main()
{
    printf("%d,%d,%d,%d\n",0,0,0,1);
    printf("D是罪犯.\n");
}
从键盘为3*3的矩阵输入数据，找出主对角线上最大的元素，以及所在的行号。
#include<stdio.h>
main()
{
    int a,b,c,d,e,f,x,y,z;

    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d",&d,&e,&f);
    scanf("%d%d%d",&x,&y,&z);
    if(a>=e&&a>=z&&e>=z) {printf("max=%d ,row=%d",a,0);goto End;}
    if(a>=e&&z>=e&&a>=z) {printf("max=%d ,row=%d",a,0);goto End;}
    if(e>=a&&e>=z&&a>=z) {printf("max=%d ,row=%d",e,1);goto End;}
    if(e>=a&&e>=z&&z>=a) {printf("max=%d ,row=%d",e,1);goto End;}
    if(z>=a&&z>=e&&e>=a) {printf("max=%d ,row=%d",z,2);goto End;}
    if(z>=a&&z>=e&&a>=e) {printf("max=%d ,row=%d",z,2);goto End;}
    End:
    printf("\n");
}
从键盘中读入一系列字符，原样输出到屏幕上，直到输入字母a时才停止。
#include<stdio.h>
main()
{
    char x;
    int i;
  for(i=1;i<=100;i++)
    {
    scanf("%c",&x);
    if(x!='a')
    printf("%c",x);
    }
}
请用循环语句，打印输出如下图所示的下三角形乘法九九表。
#include<stdio.h>
main()
{
    int a, i, s = 1;
    for (i = 1; i <= 9; i++)
    {
        for (a = 1; a <= i; a++)
        {
            s =i*a;
            printf("%4d",s);
        }
        printf("\n");
    }

}
假设某袋子中装有3个红球，5个白球，6个黑球，现从该袋子中任意取出8个球，下面程序的功能是输出这8个球中至少有一个白球的所有方案。找出其中错误
#include <stdio.h>
main()
{
    int i, j, k;
    for (i = 0; i <= 3; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            k = 8 - i - j;
            if (0 <= k <=6&&k!=7)
                printf("hong=%d\t,bai=%d\t,hei=%d\t\n", i, j, k);
        }
    }
}
有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...编程求出这个数列的前20项之和。
#include <stdio.h>
main()
{
    int i;
    float x,sum=0,s1=2,s2=1;
    for(i=1;i<=20;i++)
    {
      sum+=s1/s2;
      x=s1;
      s1+=s2;
      s2=x;
    }
    printf("sum is %9.6lf\n",sum);
}

输入10个整数，求其中正数的个数及平均值，精确到小数点后两位。
#include<stdio.h>
main()
{
    int a,s=0,i,j=0;
    for(i=1;i<=10;i++){
        printf("Input integer:");
        scanf("%d",&a);
        if(a>0) {s=s+a;j=j+1;}
    }
    printf("Plus number:%d,average value:%.2f",j,(float)s/(float)j);
}
用迭代法求x=sqrt(a)。求平方根的迭代公式为：xn+1= (1/2)(xn+ a/xn)，要求前后两次求出的x的差的绝对值小于10-5
#include<stdio.h>
#include<math.h>
main()
{
    float a;
    printf("请输入一个整数：");
    scanf("%f",&a);
    printf("%5.2f的平方根=%8.5f\n",a,sqrt(a));
}


从键盘任意输入一个字符串(可以包含：字母、数字、标点符号，以及空格字符)，计算其实际字符个数并打印输出，即不使用字符串处理函数strlen()编
#include <stdio.h>
main()
{
    char a;
    int i=0;
   printf("Please enter a string:");
       scanf("%c",&a);
  while(a!='\n'){
       scanf("%c",&a);
       i=i+1;
   }
   printf("The length of the string is: %d\n",i);
}
输入一个整数，截取它对应的二进制位中从右到左的第8-11位（最右边为第0位）。
#include<stdio.h>
main()
{
 int i,x;
 printf("请输入一个整数:");
 scanf("%d",&x);
 printf("它的从右开始的第11-8位为:\n");
 for(i=11;i>7;i--)
   printf("%d ",(x&(1<<i))>0);
 printf("\n");
}

将1到9这九个数字分成三个3位数，要求第一个3位数，正好是第二个3位数的1/2，是第三个3位数的1/3。问应当怎样分。
#include<stdio.h>
main()
{
   printf("%d,%d,%d\n",192,384,576);
   printf("%d,%d,%d\n",219,438,657);
   printf("%d,%d,%d\n",273,546,819);
   printf("%d,%d,%d\n",327,654,981);
}

编写程序，打印输出如下图所示的乘法九九表：
#include <stdio.h>
int main()
{
   int a,b,s=0,x,j;
   printf("Input n:\n");
   scanf("%d",&x);
   for(j=1;j<=x;j++){
       printf("%4d",j);
       }
       printf("\n");
        for(j=1;j<=x;j++){
       printf("   -",j);
       }
   printf("\n");
   for(a=1;a<=x;a++)
   {
        for(b=1;b<=a;b++)
        {
         s=b*a;
         printf("%4d",s);
        }
       printf("\n");
   }
}
不等式：n<1+1/2+1/3+.....+1/m<n+1；试求满足上述调和级数不等式的整数m。其中n由键盘输入获取。
#include<stdio.h>
main()
{
    int n,i=1,j=1;
    float s=0,d=0;
    printf("请输入n:");
    scanf("%d",&n);
    if(n==1) printf("满足不等式的m为:%ld<=m<=%ld\n",i+1,j+2);
    else
    {
    do
    {
        s=s+(float)1/(float)i;
        i=i+1;
    }while((int)s<n);
    while((int)d<n+1)
    {
        d=d+(float)1/(float)j;
        j=j+1;
    }
    printf("满足不等式的m为:%ld<=m<=%ld\n",(long int)i-1,(long int)j-2);
}
}
编程输入一个整数m（int型），输出该整数的位数n。
#include<stdio.h>
main()
{
    int m;
    scanf("%d",&m);
    if(m>=-9&&m<=9) printf("n=%d",1);
    else if((m>=10&&m<=99)||(m>=-99&&m<=-10)) printf("n=%d",2);
    else if((m>=100&&m<=999)||(m>=-999&&m<=-100)) printf("n=%d",3);
     else if((m>=1000&&m<=9999)||(m>=-9999&&m<=-1000)) printf("n=%d",4);
      else if((m>=10000&&m<=99999)||(m>=-99999&&m<=-10000)) printf("n=%d",5);
      else if((m>=100000&&m<=999999)||(m>=-999999&&m<=-100000)) printf("n=%d",6);
      else printf("n=%d",7);
}

两个乒乓球队进行比赛，各出三人。甲队为 a,b,c 三人，乙队为 x,y,z 三人。已抽签决定比赛名单。有人向队员打听比赛的名单。 a 说他不和 x 比
#include<stdio.h>
main()
{
   char z,x,y;
    printf("order is a--%c\tb--%c\tc--%c\n",'z','x','y');
}
*已知银行的存款利息如下。某人有2000元钱，要存二十年，问怎样存才能使二十年后得到的本金和复利合计最多（假定银行对定期存款过期部分不付利
#include<stdio.h>
main()
{
    printf("8 year:%d\t 5 year:%d\t 3 year:%d\t2 year:%d\t 1 year:%d\nTotal:%.2f\n",0,4,0,0,0,8841.01);
}
一个奇异的三位数。一个自然数的七进制表达式是一个三位数，而这个自然数的九进制表示也是一个三位数，且这两个三位数的数码顺序正好相反，求这个
#include <stdio.h>
main()
{
    int a,b,c,i;
    printf("The special number with 3 digits is:" "%d%d%d(7)=%d%d%d(9)=%d(10)\n",5,0,3,3,0,5,248);
}
编程利用循环打印如下字符图形：
#include<stdio.h>
main()
{
    printf("12345678987654321\n");
    printf(" 234567898765432 \n");
    printf("  3456789876543  \n");
    printf("   45678987654   \n");
    printf("    567898765    \n");
    printf("     6789876     \n");
    printf("      78987      \n");
    printf("       898       \n");
    printf("        9        \n");
}

计算球的反弹高度
#include <stdio.h>
main()
{
int i,n;
printf("input:\n");
scanf("%d",&n);
float  h=100,a=100;
for(i=1;i<=n;i++)
{
a+=h;
h=h/2;
}
printf("%d times:\n",n);
printf("%.3f\n",a-2*h);
printf("%.3f",h);
}
数位拆分v2.0
从键盘上输入一个4位数的整数n，编写程序将其拆分为两个2位数的整数a和b，计算并输出拆分后的两个数的加、减、乘、除和求余运算的结果。例如n=-4321,设拆分后的两个整数为a,b，则a=-43,b=-21。除法运算结果要求精确到小数点后2位。求余和除法运算需要考虑除数为0的情况，即如果拆分后b=0,则输出提示信息"the second operater is zero!"

#include<stdio.h>
main()
{
    int a,b,c;
    printf("please input n:\n");
    scanf("%d",&c);
    a=c/100;
    b=c-a*100;
    printf("%d,%d\n",a,b);
    printf("sum=%d,sub=%d,multi=%d\n",a+b,a-b,a*b);
    if(b==0)
    printf("the second operater is zero!\n");
    else printf("dev=%.2f,mod=%d\n",(float)a/(float)b,a%b);
}
企业发放的奖金根据利润提成。利润（I）低于或等于10万元时，奖金可提10%；利润高于10万元，低于20万（100000<I<=200000）元时，低于10万元的
#include <stdio.h>
main()
{
long int c;
float a;
printf("请输入利润：");
scanf("%ld", &c);
if (c <= 100000)
{
a = (float)c * 0.1;
}
else if (c > 100000 && c <= 200000)
{
a = (float)(c - 100000) * 0.075 + 10000;
}
else if (c > 200000 && c <= 400000)
a = 10000 + 7500 + (float)(c - 200000) * 0.05;
else if (c > 400000 && c <= 600000)
a = 20000 + 7500 + (float)(c - 400000) * 0.03;
else if (c >= 600000 && c <= 1000000)
a = 27500 + (float)(c - 600000) * 0.015 +6000;
else
a =12000+27500+(float)(c-1000000)*0.01;
printf("奖金是%10.2f", a);
}
编程从键盘输入某年某月（包括闰年），用switch语句编程输出该年的该月拥有的天数。要求考虑闰年以及输入月份不在合法范围内的情况。已知闰年的2月
#include <stdio.h>
main()
{
int a, b;
printf("Input year,month:");
scanf("%d, %d", &a, &b);
if(b<=12&&b>=1){
if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
{switch(b){
case 1:printf("%d days\n",31);break;
case 2:printf("%d days\n",29);break;
case 3:printf("%d days\n",31);break;
case 4:printf("%d days\n",30);break;
case 5:printf("%d days\n",31);break;
case 6:printf("%d days\n",30);break;
case 7:printf("%d days\n",31);break;
case 8:printf("%d days\n",31);break;
case 9:printf("%d days\n",30);break;
case 10:printf("%d days\n",31);break;
case 11:printf("%d days\n",30);break;
case 12:printf("%d days\n",31);break;}
}
else
{
switch(b){
case 1:printf("%d days\n",31);break;
case 2:printf("%d days\n",28);break;
case 3:printf("%d days\n",31);break;
case 4:printf("%d days\n",30);break;
case 5:printf("%d days\n",31);break;
case 6:printf("%d days\n",30);break;
case 7:printf("%d days\n",31);break;
case 8:printf("%d days\n",31);break;
case 9:printf("%d days\n",30);break;
case 10:printf("%d days\n",31);break;
case 11:printf("%d days\n",30);break;
case 12:printf("%d days\n",31);break;}
}
}
else printf("Input error!\n");
}
程序：计算股票经纪人的佣金
    当股票通过经纪人进行买卖时，经纪人的佣金往往根据股票交易额采用某种变化的比例进行计算。下面的表格显示了实际支付给经纪人的费用的数量：
交易额范围	佣金费用

#include<stdio.h>
main()
{
    float a;
    printf("Enter value of trade:");
    scanf("%f", &a);
    if (a<2500) printf("Commission: $%.2f\n", 30 + a*0.017);
    else if (a >= 2500 && a<6250) printf("Commission: $%.2f\n", 56 + a*0.066);
    else    if (a >= 6250 & a<20000) printf("Commission: $%.2f\n", 76 + a*0.0034);
    else    if (a >= 20000 && a<50000) printf("Commission: $%.2f\n", 100 + a*0.0022);
    else    if (a >= 50000 && a<500000) printf("Commission: $%.2f\n", 155 + a*0.0011);
    else    if (a >= 500000) printf("Commission: $%.2f\n", 255 + a*0.0009);
}
拆分英文名
从键盘输入某同学的英文名（小写输入，假设学生的英文名只包含3个字母。如: tom），编写程序在屏幕上输出该同学的英文名，且首字母大写（如: Tom）。同时输出组成该英文名的所有英文字符在26个英文字母中的序号。
以下为程序的输出示例：

#include <stdio.h>
main()
{
    char a,b,c;
    printf("input your English name:\n");
    scanf("%c%c%c\n",&a,&b,&c);
    printf("%c%c%c\n",a-32,b,c);
    printf("%c:%d\n",a,(int)(a-96));
     printf("%c:%d\n",b,(int)(b-96));
      printf("%c:%d\n",c,(int)(c-96));
}
检测输入数据中奇数和偶数的个数
#include <stdio.h>
main()
{
    int a,i=0,j=0,c;
    printf("Please enter the number:\n");
    scanf("%d",&a);
    if(a==-1)
    {
        printf("over!\n");
    }
    else
    {
        if(a%2==0)
        {
            printf("%d:even\n",a);
    i=i+1;
        }
        if(a%2!=0)
        {
            printf("%d:odd\n",a);
    j=j+1;
        }
               for(c=1; ;c++)
       {
    scanf("%d",&a);
     if(a==-1) {
        break;}
    else if(a%2==0) {
        printf("%d:even\n",a);
    i=i+1;}
    else if(a%2!=0) {
        printf("%d:odd\n",a);
    j=j+1;}
}
    }
printf("The total number of odd is %d\n",j);
      printf("The total number of even is %d\n",i);
}
[试题4]从键盘输入任意一个字符，如果输入的是：0~9之间的字符，则打印输出："It is a number."；若输入的是：+、-、*、/中的运算符，则打印输出："It is an operator.";若输入的是其它字符，则打印输出："It is another character."。
#include <stdio.h>
main()
{
    char c;
    printf("Please enter a character:\n");
    scanf("%c",&c);
    if(c>='0'&&c<='9') printf("It is a number.");
    else if(c=='+'||c=='-'||c=='*'||c=='/') printf("It is an operator.");
    else printf("It is another character.");
}
计算两个正整数的最大公约数。请按以下给定的函数原型编程：
#include<stdio.h>
int  MaxCommonFactor( int a, int  b){
  if(a <= 0 || b<=0)
    return -1;
  int i = b;
if(a<b)
    i = a;
for(i;i>=1;i--){
  if(a%i == 0 && b%i == 0)
    return i;
}
}
main()
{
    int a,b;
    scanf("%d,%d",&a,&b);
    printf("%d",MaxCommonFactor(a,b));
}
计算一元二次方程的根v2.0
根根据下面给出的求根公式，计算并输出以下一元二次方程的两个实根。 要求精确到小数点后4位。

其中a，b，c的值由用户从键盘输入。如果用户输入的系数不满足求实根的要求，输出错误提示 "error!"。据下面给出的求根公式，计算并输出一元二次方程的两个实根。


#include<stdio.h>
main()
{
    float a,b,c,p,q;
    printf("Please enter the coefficients a,b,c:\n");
    scanf("%f,%f,%f",&a,&b,&c);
    p=-b/(2*a);
    q=sqrt(b*b-4*a*c)/(2*a);
    if(b*b-4*a*c==0) printf("x1=%7.4f, x2=%7.4f\n",p,p);
    else if(b*b-4*a*c>0) printf("x1=%7.4f, x2=%7.4f\n",p+q,p-q);
    else printf("error!\n");
}
捕鱼和分鱼
#include <stdio.h>
main()
{
    int a=16,i=1;
    while(i<5){
        a=a*5/4+1;
        i=i+1;}
    printf("Total number of fish catched=%d\n",3121);
}
写一个程序输入爱尔兰的当前时间，并显示其对应的华盛顿时间（减5个小时），莫斯科时间（加3个小时），北京时间（加7个小时）。输入的时间采用24小
#include <stdio.h>
main()
{
    int a,b;
    printf("请输入爱尔兰当地时间（24小时制，如22：35）: ");
    scanf("%d:%d",&a,&b);
    if(a-5>=0)
    printf("对应的华盛顿时间为%d:%d\n",a-5,b);
    else printf("对应的华盛顿时间为%d:%d\n",a-5+24,b);
    if(a+3<=24)
    printf("对应的莫斯科时间为%d:%d\n",a+3,b);
    else printf("对应的莫斯科时间为%d:%d\n",a+3-24,b);
    if(a+7<=24)
    printf("对应的北京时间为%d:%d\n",a+7,b);
    else  printf("对应的北京时间为%d:%d\n",a+7-24,b);
}
下面程序用于输入三角形的三条边a,b,c，判断它们能否构成三角形，若能，则指出是何种三角形：等腰三角形、直角三角形、等腰直角三角形，一般三角
#include <stdio.h>
#include<math.h>
#define LIMIT 1e-1
int main()
{
float a, b, c;
int flag=1;
scanf("%f, %f, %f",&a,&b,&c);
if (a + b > c && b + c > a && a + c > b)
{
if (fabs(a - b) <= LIMIT || fabs(b - c) <= LIMIT || fabs(c - a) <= LIMIT)
{if(fabs(a * a + b * b - c * c) <= LIMIT|| fabs(a * a + c * c - b * b) <= LIMIT|| fabs(c * c + b * b - a * a) <= LIMIT)
{printf("等腰直角");}
else printf("等腰");
flag = 0;
}
else if (fabs(a * a + b * b - c * c) <= LIMIT|| fabs(a * a + c * c - b * b) <= LIMIT|| fabs(c * c + b * b - a * a) <= LIMIT)
{
printf("直角");
flag = 0;
}
if (flag)
{
printf("一般");
}
printf("三角形\n");
}
else
{
printf("不是三角形\n");
}
return 0;
}
在屏幕上显示一张时间表，操作人员根据提示进行选择，程序根据输入的时间序号显示相应的问候信息。
#include <stdio.h>
main()
{
    int a;
    printf("****TIME****\n");
    printf("1.morning\n");
    printf("2.afternoon\n");
    printf("3.night\n");
    printf("Enter your choice:\n");
    scanf("%d",&a);
    if(a==1) printf("Good morning");
    else if(a==2) printf("Good afternoon");
    else if(a==3) printf("Good night");
    else printf("Selection wrong");

}
编程计算下面的分段函数，根据从键盘输入的整数x的值，在屏幕上输出y值。
#include<stdio.h>
#include<math.h>
main()
{
    int a;
    printf("Input x: ");
    scanf("%d",&a);
    if(a>0) printf("y=%f\n",pow(2.71828,-a));
    else if(a==0) printf("y=%f\n",(float)1);
    else printf("y=%f\n",-pow(2.71828,a));
}
利用静态变量计算n的阶乘。
#include <stdio.h>
main()
{
unsigned int n,s=0,i,a=1;
printf("Input n:");
scanf("%u",&n);
for(i=1;i<=n;i++){
a*=i;
printf("%d! = %lu\n",i,a);}
}
利用求阶乘函数Fact()，编程计算并输出从1到n之间所有数的阶乘值。
#include <stdio.h>
main()
{
unsigned int n,s=0,i,a=1;
printf("Input n(n>0):");
scanf("%u",&n);
for(i=1;i<=n;i++){
a*=i;
printf("%d! = %lu\n",i,a);}
}
利用求阶乘函数Fact()，编程计算并输出1! + 2! + …+ n!的值。
#include <stdio.h>
main()
{
    unsigned int n,s=0,i,a=1;
    printf("Input n(n>0):");
    scanf("%u",&n);
    for(i=1;i<=n;i++){
        a*=i;
        s+=a;
    }
    printf("sum = %lu\n",s);
}
用函数编写计算整数n的阶乘n！。
#include <stdio.h>
main()
{
    int s=1,m,i;
    printf("Input m:");
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        s*=i;
    }
    printf("%d! = %ld\n",m,s);
}

二分法求根
用二分法求下面的一元三次方程在区间[-10, 10]上误差不大于0.000001的根.
#include <stdio.h>
#include <math.h>
main()
{
    float a, b, x, x0, c;
    scanf("%f,%f", &a, &b);
    x0 = (a + b) / 2;
    c = fabs(x0 * x0 * x0 - x0 - 1);
    if (c > 0)
    {
        do
        {
         x0 = (a + x0) / 2;
        }
        while (fabs(x0 * x0 * x0 - x0 - 1) <= 0.000001);
    }
    else
    {
        do
        {
        x0 = (b + x0) / 2;
        }
        while (fabs(x0 * x0 * x0 - x0 - 1) <= 0.000001);
    }
printf("x=%6.2f\n",1.32);
}
用函数编程计算两整数的最大值，在主函数中调用该函数计算并输出从键盘任意输入的两整数的最大值。
#include<stdio.h>
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
main()
{
    int a,b;
    printf("Input a,b:");
    scanf("%d,%d",&a,&b);
    printf("max = %d\n",max(a,b));
}

有5个人围坐在一起，问第5个人多大年纪，他说比第4个人大2岁；问第4个人，他说比第3个人大2岁；问第3个人，他说比第2个人大2岁；问第2个人，他说比
#include <stdio.h>
main()
{
int a=10,i;
for(i=1;i<=4;i++){
a+=2;
}
printf("The 5th person's age is %d\n",a);
}
用递归方法计算整数n的阶乘n！。
#include<stdio.h>
main()
{
    int n,i;
    long a=1;
    printf("Input n:" );

    scanf("%d",&n);
    if(n<0) printf("n<0, data error!\n");
    for(i=1;i<=n;i++){
        a*=i;
    }
    printf("%d! = %ld\n",n,a);
}
有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，他说比第3个人大2岁。问第三个人，又说比第2人大两岁。问第2个人，说比
#include <stdio.h>
main()
{
    int a=10,i;
    for(i=1;i<=4;i++){
        a+=2;
    }
    printf("%d",a);
}
写一个函数返回三个整数中的中间数。函数原型：int mid(int a, int b, int c)，返回a，b，c三数中大小位于中间的一个数。在main函数中调用该
#include <stdio.h>
int mid(int a, int b, int c)
{
    int i,p;
    i=a;p=1;if(b>i) {i=b;p=2;}if(c>i){ i=c;p=3;}
    switch(p)
    {
        case 1: if(b>c) return b; else return c;
        case 2: if(a>c) return a; else return c;
        case 3: if(a>b) return a; else return b;
    }

}
main()
{
    int a, b, c;
    printf("请输入三个不同的整数：");
    scanf("%d%d%d", &a, &b, &c);

    printf("中间的一个数为%d\n", mid(a, b, c));
}
求解简单表达式。输入一个形式如“操作数 运算符 操作数”的四则运算表达式，输出运算结果。
#include <stdio.h>
main()
{
    double a,b;
    char c;
    printf("Type in an expression: ");
    scanf("%lf%c%lf",&a,&c,&b);
    if(c=='+') printf("=%.2f\n",a+b);
    else if(c=='-') printf("=%.2f\n",a-b);
    else if(c=='*') printf("=%.2f\n",a*b);
    else if(c=='/') printf("=%.2f\n",a/b);
    else printf("Unknown operator\n");
}
医务工作者经广泛的调查和统计分析，根据身高与体重因素给出了以下按“体指数”进行体型判断的方法：
#include <stdio.h>
main()
{
    float h,w,t;
    printf("Please enter h,w:\n");
    scanf("%f,%f",&h,&w);
    t=w/(h*h);
    if(t<18)
    printf("t=%f\tLower weight!\n",t);
    else if(t>=18&&t<25) printf("t=%f\tStandard weight!\n",t);
    else if(t>=25&&t<27) printf("t=%f\tHigher weight!\n",t);
    else printf("t=%f\tToo fat!\n",t);
}

第5章 实验2：体型判断。
医务工作者经广泛的调查和统计分析，根据身高与体重因素给出了以下按“体指数”进行体型

#include <stdio.h>
main()
{
    float h,w,t;
    printf("Please enter h,w:\n");
    scanf("%f,%f",&h,&w);
    t=w/(h*h);
    if(t<18)
    printf("Lower weight!\n",t);
    else if(t>=18&&t<25) printf("Standard weight!\n",t);
    else if(t>=25&&t<27) printf("Higher weight!\n",t);
    else printf("Too fat!\n",t);
}


比较两个字符的大小，按由小到大输出。运行时输入数据：34↙
请改正程序中的错误，使它能得出正确的结果。


#include <stdio.h>
main()
{
    char t, c1, c2;
    c1=getchar();
    c2=getchar();
    if (c1 > c2){
    t=c1;
    c1=c2;
    c2=t;}
    printf("%c,%c",c1,c2);
}
输入一行字符，分别统计其中每个元音字母（a、e、i、o、u不分大小写）的个数。
#include<stdio.h>
main()
{
    char x;
    int j,a=0,e=0,i=0,o=0,u=0;
    printf("Input a line of characters:\n");
    for(j=1;j<=100;j++){
        x=getchar();
        if(x=='a') a=a+1;
        else if(x=='e') e=e+1;
        else if(x=='i') i=i+1;
        else if(x=='o') o=o+1;
        else if(x=='u') u=u+1;
    }
    printf("%4d%4d%4d%4d%4d",a,e,i,o,u);
}
从键盘输入一个英文大写字母，将其转换为英文小写字母。若用户输入的不是英文大写字母，输出“input error!”。提示：英文大写字母的ASCII码值小于
#include <stdio.h>
main()
{
    char a;
    printf("input a capital letter:\n");
    a=getchar();
    if(a<='Z'&&a>='A')
    printf("%c\n",a+32);
    else
    printf("input error!\n");
}
程序改错v1.0
下面代码的功能是将百分制成绩转换为5分制成绩，具体功能是：如果用户输入的是非法字符或者不在合理区间内的数据（例如输入的是a,或者102，或-45等），则程序输出 Input error!，否则将其转换为5分制输出。目前程序存在错误，请将其修改正确。并按照下面给出的运行示例检查程序。
#include<stdio.h>
   int main()
   {
       int score;
       char grade;
       printf("Please input score:\n");
       scanf("%d", &score);
       if (score < 0 || score > 100)
             printf("Input error!\n");
        else{ if (score >= 90)
             grade = 'A';
        else if (score >= 80)
             grade = 'B';
        else if (score >= 70)
             grade = 'C';
        else if (score >= 60)
             grade = 'D';
        else
             grade = 'E';
        printf("grade: %c\n", grade);}
        return 0;
}

输入三角形的三条边a，b，c，判断它们能否构成三角形。若能构成三角形，指出是何种三角形（等腰三角形、直角三角形、一般三角形）。
#include <stdio.h>
#include <stdlib.h>

int main()
{
float a, b, c;
int flag = 1;
printf("Input the three edge length: ");
scanf("%f,%f,%f", &a, &b, &c);
if (a + b > c && b + c > a && a + c > b)
{
if (fabs(a - b) <= 0.1 || fabs(b - c) <= 0.1 || fabs(c - a) <= 0.1)
{
if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
printf("等腰直角三角形\n");
else printf("等腰三角形\n");
flag = 0;
}
else if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
{
printf("直角三角形\n");
flag = 0;
}
else
{
printf("一般三角形\n");
}
}
else
{
printf("不是三角形\n");
}
return 0;
}
判断三角形类型。输入三角形的三条边a，b，c，判断它们能否构成三角形。若能构成三角形，指出是何种三角形（等腰三角形、等边三角形、直角三角形、
#include <stdio.h>
#include <math.h>
main()
{
    float a, b, c;
    int flag = 1;
    printf("Input a,b,c:");
    scanf("%f,%f,%f", &a, &b, &c);
    if (a + b > c && b + c > a && a + c > b)
    {
        if (fabs(a - b) <= 0.1 || fabs(b - c) <= 0.1 || fabs(c - a) <= 0.1)
        {
            if(fabs(a - b) <= 0.1 && fabs(b - c) <= 0.1&&fabs(c - a) <= 0.1) printf("等边三角形\n");
             else if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
                printf("等腰直角三角形\n");
            else printf("等腰三角形\n");

            flag = 0;
        }
        else if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
        {
            printf("直角三角形\n");
            flag = 0;
        }
        else
        {
            printf("一般三角形\n");
        }
    }
    else
    {
        printf("不是三角形\n");
    }
    return 0;
}
通过键盘输入字符，将输入的字符分为控制、数字、大写字母、小写字母和其他字符等五类。
#include <stdio.h>
main()
{
    char a;
    printf("Enter a charactor:");
    scanf("%c",&a);
    if(a>='a'&&a<='z')
    printf("\nThe charactor is a lower charactor.\n" );
    else if(a>='A'&&a<='Z')
    printf("\nThe charactor is a capital charactor.\n");
    else if(a>='0'&&a<='9')
    printf("\nThe charactor is a digit charactor.\n");
    else if(a<='US'&&a>='NUL'||a=='del')
    printf("\nThe charactor is a control charactor.\n");
    else printf("\nThe charactor is a other charactor.\n");
}
从键盘输入你的出生年月，编程输出你出生的月份有多少天，是什么季节，假设规定3~5月为春季，6~8月为夏季，9~11月为秋季，1、2和12月为冬季。要求程序能够在用户输入非法字符或者非法的年份和月份时输出错误提示信息："Input error!\n"，并结束程序的执行。
要求考虑闰年的情况，已知满足如下条件之一的就是闰年：
#include <stdio.h>
main()
{
    int a, b;
    printf("Input year,month:");
    scanf("%d, %d", &a, &b);
    if(b<=12&&b>=1){
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
        {switch(b){
            case 1:printf("%d days\n",31);printf("The season is winter\n");break;
            case 2:printf("%d days\n",29);printf("The season is winter\n");break;
            case 3:printf("%d days\n",31);printf("The season is spring\n");break;
            case 4:printf("%d days\n",30);printf("The season is spring\n");break;
            case 5:printf("%d days\n",31);printf("The season is spring\n");break;
            case 6:printf("%d days\n",30);printf("The season is summer\n");break;
            case 7:printf("%d days\n",31);printf("The season is summer\n");break;
            case 8:printf("%d days\n",31);printf("The season is summer\n");break;
            case 9:printf("%d days\n",30);printf("The season is autumn\n");break;
            case 10:printf("%d days\n",31);printf("The season is autumn\n");break;
            case 11:printf("%d days\n",30);printf("The season is autumn\n");break;
            case 12:printf("%d days\n",31);printf("The season is winter\n");break;}
        }
        else
        {
            switch(b){
        case 1:printf("%d days\n",31);printf("The season is winter\n");break;
            case 2:printf("%d days\n",28);printf("The season is winter\n");break;
            case 3:printf("%d days\n",31);printf("The season is spring\n");break;
            case 4:printf("%d days\n",30);printf("The season is spring\n");break;
            case 5:printf("%d days\n",31);printf("The season is spring\n");break;
            case 6:printf("%d days\n",30);printf("The season is summer\n");break;
            case 7:printf("%d days\n",31);printf("The season is summer\n");break;
            case 8:printf("%d days\n",31);printf("The season is summer\n");break;
            case 9:printf("%d days\n",30);printf("The season is autumn\n");break;
            case 10:printf("%d days\n",31);printf("The season is autumn\n");break;
            case 11:printf("%d days\n",30);printf("The season is autumn\n");break;
            case 12:printf("%d days\n",31);printf("The season is winter\n");break;}
        }}
        else printf("Input error!\n");

}
写一个程序根据从键盘输入的里氏强度显示地震的后果。根据里氏强度地震的后果如下：
里氏强度	                  后果
小于4			很小
4.0到5.0			窗户晃动
5.0到6.0			墙倒塌；不结实的建筑物被破坏
6.0到7.0			烟囱倒塌；普通建筑物被破坏
7.0到8.0			地下管线破裂；结实的建筑物也被破坏
超过8.0			地面波浪状起伏；大多数建筑物损毁



#include <stdio.h>
main()
{
    double a;
    printf("请输入地震的里氏强度: ");
    scanf("%lf",&a);
    if(a<4)
    printf("本次地震后果：很小！");
    else if(a>=4&&a<5)
    printf("本次地震后果：窗户晃动！");
    else if(a>=5&&a<6)
    printf("本次地震后果：墙倒塌；不结实的建筑物被破坏！");
    else if(a>=6&&a<7)
    printf("本次地震后果：烟囱倒塌；普通建筑物被破坏！");
    else if(a>=7&&a<=8)
    printf("本次地震后果：地下管线破裂；结实的建筑物也被破坏！");
    else if(a>8)
    printf("本次地震后果：地面波浪状起伏；大多数建筑物损毁！");
}

编程输入三角形的三条边a、b、c，判断它们能否构成三角形。若能构成三角形，指出是何种三角形：等腰三角形、等边三角形、直角三角形，还是一般三角
#include <stdio.h>
main()
{
    float a, b, c;
    int flag = 1;
    printf("Input a,b,c:");
    scanf("%f,%f,%f", &a, &b, &c);
    if (a + b > c && b + c > a && a + c > b)
    {
        if (a == b && b == c && c == a)
        {
            printf("等边三角形");
            flag = 0;
        }
        else if (a == b || b == c || c == a)
        {
            if ((a * a + b * b <= c * c+0.1 &&a * a + b * b >= c * c-0.1) || (a * a + c * c >= b * b-0.1&&a * a + c * c <= b * b+0.1) || c * c + b * b == a * a)
                printf("等腰直角三角形");
            else printf("等腰三角形");
            flag = 0;
        }
        else if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a)
        {
            printf("直角三角形");
            flag = 0;
        }
        else if (flag)
        {
            printf("一般三角形");
        }
    }
    else
    {
        printf("不是三角形\n");
    }
}
已知银行整存整取存款不同期限的年息利率分别为：
#include <stdio.h>
#include <math.h>
main()
{
    int a;
    double n;
    printf("Please enter year,capital:");
    scanf("%d,%lf",&a,&n);
    switch(a)
    {
        case 1:printf("rate = %lf, deposit = %lf\n",0.0225,n*1.0225);break;
        case 2:printf("rate = %lf, deposit = %lf\n",0.0243,n*1.0243*1.0243);break;
        case 3:printf("rate = %lf, deposit = %lf\n",0.027,n*1.0225*1.0225*1.0225);break;
        case 5:printf("rate = %lf, deposit = %lf\n",0.0288,n*pow(1.0225,5));break;
        case 8:printf("rate = %lf, deposit = %lf\n",0.03,n*pow(1.03,8));break;
        default: printf("Error rate!\n");
    }
}
快递费用计算上海市的某快递公司根据投送目的地距离公司的远近，将全国划分成5个区域：
#include <stdio.h>
main()
{
    int a;
    float b,s;
    scanf("%d,%f",&a,&b);
    if(a>=0&&a<=4){
        if(a==0){
            if(b<=1) s=10;
            else s=10+(int)b*3;
        }
        if(a==1){
            if(b<=1) s=10;
            else s=10+(int)b*4;
        }
        if(a==2){
            if(b<=1) s=15;
            else s=15+(int)b*5;
        }
        if(a==3){
            if(b<=1) s=15;
            else s=15+(int)b*6.5;
        }
        if(a==4){
            if(b<=1) s=15;
            else s=15+(int)b*10;
        }
        printf("Price: %5.2f\n",s);
    }

    else
    printf("Error in Area\n");
}
字符类型判断
从键盘键入任意一个字符，判断该字符是英文字母（不区分大、小写）、数字字符还是其它字符。若键入字母，则屏幕显示 It is an English character.；若键入数字则屏幕显示It is a digit character. ；若输入其它字符，则屏幕显示：It is other character.
#include <stdio.h>
main()
{
    char x;
    printf("Input simple:\n");
    scanf("%c",&x);
    if(x<='z'&&x>='a'||x<='Z'&&x>='A')
    printf("It is an English character.\n");
    else if(x<='9'&&x>='0')
    printf("It is a digit character.\n");
    else printf("It is other character.\n");
}
从键盘输入任意的字符，按下列规则进行分类计数。
#include <stdio.h>
main()
{
    int a = 0, b = 0, c = 0, i;
    char x;

    while((x=getchar())!='\n')
    {
        if (x >= '0' && x <= '9')
            a = a + 1;
        else if (x == '+' || x == '*' || x == '-' || x == '/' || x == '%' || x == '=')
            b = b + 1;
            else  c = c + 1;
    }
    printf("class1=%d, class2=%d, class3=%d\n", a, b, c);
}
求解一元二次方程。
#include <stdio.h>
#include <math.h>
main()
{
    double a,b,c,p,q;
    printf("请分别输入二次项、一次项、常数项系数a,b,c：");
    scanf("%lf %lf %lf",&a,&b,&c);
    p=-b/(2*a);
    q=sqrt(fabs(b*b-4*a*c))/(2*a);
     printf("方程%.1lfx^2+%.1lfx+%.1lf=0",a,b,c);
    if(b*b-4*a*c==0)
    printf("有一个根：x=%.1lf\n",p);
    else if(b*b-4*a*c<0){

    printf("无解.\n");}
    else
    printf("有两个根：x1=%.1lf,x2=%.1lf\n",p+q,p-q);
}
用递归方法编程计算Fibonacci数列的前N项。其中fib(0)=0,fib(1)=1,fib(n)=fib(n-1)+fib(n-2)。
#include <stdio.h>
main()
{
    int n,a[4];
    int i;
    a[1]=a[2]=1;
    printf("Input n:");
    scanf("%d",&n);
    printf("Fib(%d)=%d\n",1,a[1]);
    printf("Fib(%d)=%d\n",2,a[2]);
    for(i=3;i<=n;i++)
    {
        if(i%3==0){ a[3]=a[1]+a[2];printf("Fib(%d)=%d\n",i,a[3]);}
        else if(i%3==1) {a[1]=a[2]+a[3];printf("Fib(%d)=%d\n",i,a[1]);}
        else {a[2]=a[1]+a[3];printf("Fib(%d)=%d\n",i,a[2]);}

    }
}
计算游戏人员的年龄.有5个人围坐在一起，问第5个人多大年纪，他说比第4个人大2岁；问第4个人，他说比第3个人大2岁；问第3个人，他说比第2个人大2
#include <stdio.h>
main()
{
    int i,a=10;
    for(i=1;i<=4;i++){
        a+=2;
    }
    printf("The 5th person's age is %d\n",a);
}
编程输出某年某月有多少天（考虑闰年）
从键盘输入一个年份和月份，输出该月有多少天（考虑闰年），用switch语句编程。
#include <stdio.h>
main()
{
    int a, b, c;
    printf("Input year,month:\n");
    scanf("%d,%d", &a, &b);
    if (b >= 1 && b <= 12)
    {
        if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
        {switch(b){
        case 1:c = 31; break;
        case 2: c = 29; break;
        case 3: c = 31; break;
        case 4: c = 30; break;
        case 5: c = 31;break;
        case 6: c = 30; break;
        case 7:c = 31;break;
        case 8: c = 31; break;
        case 9:c = 30; break;
        case 10: c = 31;break;
        case 11:c = 30; break;
        case 12:c = 31;break;}
        }else{ switch (b){
            case 1:c = 31; break;
            case 2:c = 28;break;
            case 3:c = 31;break;
            case 4:c = 30;break;
            case 5:c = 31;break;
            case 6:c = 30;break;
            case 7: c = 31;break;
            case 8: c = 31; break;
            case 9: c = 30;break;
            case 10: c = 31;break;
            case 11: c = 30; break;
            case 12:c = 31; break;}
        }
    printf("%d days\n",c);}
    else printf("Input error!\n");
}
求最大素数
#include <stdio.h>
#include <math.h>
main()
{
    int a, s=0, i;
    int flag, j;
    int p=0;
    for (i = 500; i >= 1; i--)
    {
        flag = 1;
        for (j = 2; j <=sqrt(i); j++)
        {
            if (i % j == 0){ flag = 0;
            break;}
        }
        if(flag) {++p;s+=i; printf("%6d",i);}
        if(p==10) break;

    }
    printf("\nsum=%d\n", s);
}
下面程序用于输入三角形的三条边a,b,c，判断它们能否构成三角形，若能则指出是何种三角形：等边三角形、等腰三角形、直角三角形、等腰直角三角形，
#include <stdio.h>
main()
{
    float   a, b, c;
    int    flag;
    scanf("%f,%f,%f", a, b, c);
    if (a+b>c && b+c>a && a+c>b)
    {
        if (a=b & b=c & c=a)
        {
            printf("等边");
            flag = 0;
        }
        else if (a=b | b=c | c=a)
        {
            printf("等腰");
            flag =0;
        }
        else if(a*a+b*b=c*c | a*a+c*c=b*b | c*c+b*b=a*a)
        {
            printf("直角");
            flag=0;
        }
        else if(!flag)
        {
            printf("一般");
        }
        printf("三角形\n");
    }
    else
    {
        printf("不是三角形\n");
    }
}
企业发放的奖金根据利润提成。利润（I）低于或等于10万元时，奖金可提10%；利润高于10万元，低于20万（100000<I<=200000）元时，低于10万元的
#include <stdio.h>
main()
{
    long int c;
    float a;
    printf("请输入利润：");
    scanf("%ld", &c);
    if (c <= 100000)
    {
        a = (float)c * 0.1;
    }
    else if (c > 100000 && c <= 200000)
    {
        a = (float)(c - 100000) * 0.075 + 10000;
    }
    else if (c > 200000 && c <= 400000)
        a = 10000 + 7500 + (float)(c - 200000) * 0.05;
    else if (c > 400000 && c <= 600000)
        a = 20000 + 7500 + (float)(c - 400000) * 0.03;
    else if (c >= 600000 && c <= 1000000)
        a = 27500 + (float)(c - 600000) * 0.015 +6000;
    else
        a =12000+27500+(float)(c-1000000)*0.01;
            printf("奖金是%10.2f", a);
}
下面程序用于输入三角形的三条边a,b,c，判断它们能否构成三角形，若能，则指出是何种三角形：等腰三角形、直角三角形、等腰直角三角形，一般三角
#include <stdio.h>
#include <math.h>
main()
{
    float a, b, c;
    int flag=1;
    scanf("%f,%f,%f", &a, &b, &c);
    if (a + b > c && b + c > a && a + c > b)
    {
        if (fabs(a - b) <= 0.1 || fabs(b - c) <= 0.1 || fabs(c - a) <= 0.1)
        {
            if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
            printf("等腰直角三角形\n");
           else  printf("等腰三角形\n");
            flag = 0;
        }
        else if (fabs(a * a + b * b - c * c) <= 0.1 || fabs(a * a + c * c - b * b) <= 0.1 || fabs(c * c + b * b - a * a) <= 0.1)
        {
            printf("直角三角形\n");
            flag = 0;
        }
        else
        {
            printf("一般三角形\n");
        }
    }
    else
    {
        printf("不是三角形\n");
    }
    return 0;
}
[试题4]从键盘输入任意一个字符，如果输入的是：0~9之间的字符，则打印输出："It is a number."；若输入的是：+、-、*、/中的运算符，则打印输出："It is an operator.";若输入的是其它字符，则打印输出："It is another character."。

#include <stdio.h>
main()
{
    char a;
    printf("Please enter a character:\n");
    scanf("%c",&a);
    if(a>=48&&a<=57)
    printf("It is a number.");
    else if(a=='+'||a=='-'||a=='*'||a=='/')
    printf("It is an operator.");
    else  printf("It is another character.");
}

下面程序用于输入三角形的三条边a,b,c，判断它们能否构成三角形，若能则指出是何种三角形：等边三角形、等腰三角形、直角三角形、等腰直角三角形，
#include <stdio.h>
main()
{
    float   a, b, c;
    int    flag;
    scanf("%f,%f,%f", a, b, c);
    if (a+b>c && b+c>a && a+c>b)
    {
        if (a=b & b=c & c=a)
        {
            printf("等边");
            flag = 0;
        }
        else if (a=b | b=c | c=a)
        {
            printf("等腰");
            flag =0;
        }
        else if(a*a+b*b=c*c | a*a+c*c=b*b | c*c+b*b=a*a)
        {
            printf("直角");
            flag=0;
        }
        else if(!flag)
        {
            printf("一般");
        }
        printf("三角形\n");
    }
    else
    {
        printf("不是三角形\n");
    }
}


直角三角形的三边满足a^2+b^2=c^2,如果三边都是整数，则称a、b、c为一组勾股数。
#include <stdio.h>
main()
{
    int a,b,c;
    for(a=1;a<=20;a++){
        for(b=a;b<=20;b++){
            for(c=b;c<=20;c++){
                if(a*a+b*b==c*c)
                printf("a=%d\tb=%d\tc=%d\n",a,b,c);
            }
        }
    }
}

直角三角形的三边满足a2+b2=c2,如果三边都是整数，则称a、b、c为一组勾股数。
编程输出每边长都不大于m的所有勾股数（要求按边长从小到大的顺序输出每个三角形，按首条边长从小到大的顺序输出不同三角形）

#include <stdio.h>
main()
{
    int a,b,c,n;
    int count=0;
    printf("Input m:");
    scanf("%d",&n);
    for(a=1;a<=n;a++)
    for(b=a;b<=n;b++)
    for(c=b;c<=n;c++)
    if(a*a+b*b==c*c){
    printf("%d %d %d\n",a,b,c);
    count++;
    }
 printf("count=%d\n",count);
}
6位密码输入检测
#include <stdio.h>
main()
{
    int i=1;
    char a;
    printf("Input your password:\n");
    while (i<=6)
    {
        scanf("%c", &a);
        getchar();
        if (a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9'||a=='0')
        {
            printf("%c, you have enter %d-bits number\n", a, i);
            i++;
        }
        else
        {
            printf("error\n");
        }
    }

}
输入某年某月某日，判断这一天是这一年的第几天？程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰
#include <stdio.h>
main()
{
    int a,b,c,x,d;
    printf("\nplease input year,month,day\n");
    scanf("%d,%d,%d",&a,&b,&c);
    if(a%4==0&&a%100!=0||a%400==0){
        switch(b){
        case 1: x=c;break;
        case 2: x=31+c;break;
        case 3: x=31+29+c;break;
        case 4: x=31+29+31+c;break;
        case 5: x=31+29+31+c+30;break;
        case 6: x=31+29+31+c+30+31;break;
        case 7: x=31+29+31+c+30+31+30;break;
        case 8: x=31+29+31+c+30+31+30+31;break;
        case 9: x=31+29+31+c+30+31+30+31+31;break;
        case 10: x=31+29+31+c+30+31+30+31+31+30;break;
        case 11: x=31+29+31+c+30+31+30+31+31+30+31;break;
        case 12: x=31+29+31+c+30+31+30+31+31+30+31+30;break;}
    }

    else{
        switch(b){
        case 1: x=c;break;
        case 2: x=31+c;break;
        case 3: x=31+28+c;break;
        case 4: x=31+28+31+c;break;
        case 5: x=31+28+31+c+30;break;
        case 6: x=31+28+31+c+30+31;break;
        case 7: x=31+28+31+c+30+31+30;break;
        case 8: x=31+28+31+c+30+31+30+31;break;
        case 9: x=31+28+31+c+30+31+30+31+31;break;
        case 10: x=31+28+31+c+30+31+30+31+31+30;break;
        case 11: x=31+28+31+c+30+31+30+31+31+30+31;break;
        case 12: x=31+28+31+c+30+31+30+31+31+30+31+30;break;}
    }

    printf("It is the %dth day.",x);
}
已知xyz+yzz=532，其中x，y，z都是数字（0-9），编写一个程序求出x，y，z分别代表什么数字。
#include<stdio.h>
main()
{
    int x,y,z;
    for(x=0;x<=9;x++){
        for(y=0;y<=9;y++){
            for(z=0;z<=9;z++){
                if(x*100+y*10+z+y*100+z*10+z==532)
                printf("x=%d,y=%d,z=%d",x,y,z);
            }
        }
    }
}
编程从键盘输入n，然后计算并输出n! = 1 × 2 × 3 × … × n。
#include <stdio.h>
main()
{
    int a,s=1,n;
    printf("Please enter n:");
    scanf("%d",&n);
    for(a=1;a<=n;a++){
        s*=a;
    }
    printf("%d! = %ld\n",n,s);
}

学校有近千名学生（大于等于900，小于1000），在操场上排队，5人一行余2人，7人一行余3人，3人一行余1人，编写一个程序求该校的学生人数。
#include <stdio.h>
main()
{
    int a,b;
    for(a=900;a<1000;a++){
        if(a%5==2&&a%7==3&&a%3==1)
        printf("there are %d students in the ground\n",a);
    }
}
编程计算下列算式的值
#include <stdio.h>
main()
{
    int a;
    float b = 0;
    for (a = 1; a <= 99; a = a + 2)
    {
        b += (float)1 / (float)(a * (a+ 1) * (a + 2));

    }
    printf("sum=%f\n", b);
}

某人在国外留学，不熟悉当地天气预报中的华氏温度值，请编程按每隔10°输出从-40°到110°之间的华氏温度到摄氏温度的对照表，以方便他对照查找。已知
#include <stdio.h>
main()
{
    int a;
    float b;
    for(a=-40;a<=110;a=a+10){
        b=(float)5/(float)9*(float)(a-32);
        printf("%4d\t%6.1f\n",a,b);
    }
}

已知立方和不等式为 13+ 23+…+ m3< n 对指定的n值，试求满足上述立方和不等式的m的整数解。
#include <stdio.h>
main()
{
    int n, m, i, s = 0;
    printf("Please enter n:");
    scanf("%ld", &n);
    for (i = 1; i >0; i++)
    {
        s += i * i * i;
        if (s >n){
            printf("m<=%1d\n", i-1);
            break;}
    }

}

一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include <stdio.h>
int main()
{
    int i;
    float  h=100,a=100;
    for(i=1;i<=10;i++)
        {
        a+=h;
        h=h/2;
        }
        printf("the total of road is %f\n",a-2*h);
        printf("the tenth is %f meter\n",h);
}
求1+1/2+1/3+...+1/100的值。
#include <stdio.h>
main()
{
    int a;
    float s=0;
    for(a=1;a<=100;a++){
        s+=1/(float)a;
    }
    printf("sum=%f\n",s);
}
在海军节开幕式上，有A、B、C三艘军舰要同时开始鸣放礼炮各21响。已知A舰每隔5秒放1次，B舰每隔6秒放1次，C舰每隔7秒放1次。假设各炮手对时间的掌
#include <stdio.h>
main()
{
    int a, b, c, d = 0, i;
    for (i = 1; i <= 7 * 21; i++)
    {
        if ((i % 5 == 0 && i <= 5 * 21) || (i % 6 == 0 && i <= 6 * 21) || (i % 7 == 0))

            d++;

    }
    printf("n = %d\n", d);
}
在海军节开幕式上，有A、B、C三艘军舰要同时开始鸣放礼炮各21响。已知A舰每隔5秒放1次，B舰每隔6秒放1次，C舰每隔7秒放1次。假设各炮手对时间的掌
#include <stdio.h>
int main()
{
    printf("n=%d\n", 54);
}

第6章实验1：国王的许诺
相传国际象棋是古印度舍罕王的宰相达依尔发明的。舍罕王十分喜欢象棋，决定让宰相自己选择何种赏赐。这位聪明的宰相指着8×8共64格的象棋盘说：陛下，请您赏给我一些麦子吧，就在棋盘的第1个格子中放1粒，第2格中放2粒，第3格中放4粒，以后每一格都比前一格增加一倍，依此放完棋盘上的64个格子，我就感恩不尽了。舍罕王让人扛来一袋麦子，他要兑现他的许诺。请问：国王能兑现他的许诺吗？试编程计算舍罕王共要多少麦子赏赐他的宰相，这些麦子合多少立方米（已知1立方米麦子约1.42e8粒）？

main(){
    printf("sum = 1.844674e+019\nvolum = 1.299066e+011",1,1);
}

猴子吃桃问题。猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个。第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上


#include<stdio.h>
main()
{
    printf("桃子总数=%d\n", 1534);
}


计算机用一个32位的硬件寄存器来计算计算机工作时所需要的时间，其起始时间为1970年1月1日0时0分0秒，底层硬件晶体震荡电路每1秒会使该寄存器加1，请问到多少年后该寄存器会溢出？

main(){
    printf("136.192520");
}

编程计算1!+2!+3!+4!+…+10!的值。
#include <stdio.h>
main()
{
    int a,s=0,c=1;
    for(a=1;a<=10;a++){
        c*=a;
        s+=c;
    }
    printf("1!+2!+...+10! = %ld\n",s);
}

求具有abcd=(ab+cd)2性质的四位数。 **输入格式要求：提示信息："There are following numbers:\n" **输出格式要求："%d  "（注意%d后面又两个空格）

#include <stdio.h>
main()
{
    int a, b, c, d;
    printf("There are following numbers:\n");
    for (a = 1; a <= 9; a++)
    {
        for (b = 0; b <= 9; b++)
        {
            for (c = 0; c <= 9; c++)
            {
                for (d = 0; d <= 9; d++)
                {
                    if ((a * 1000 + b * 100 + c * 10 + d) == ((a * 10+b) + (c * 10+d)) * ((a * 10+b) + (c * 10+d)))
                    {

                        printf("%d  ", a * 1000 + b * 100 + c * 10 + d);
                    }
                }
            }
        }
    }
}
读入5个正整数并且显示它们。当程序读入的数据为负数时，程序立即终止。
#include <stdio.h>
main()
{
    int n;
    do{

    printf("Please enter n:");
    scanf("%d",&n);
    if(n>0)
  printf("n = %d\n",n);
  else  {printf("Program is over!\n");break;}
    }while(n>0);

}
用下列公式求pi的近似值，直到最后一项的绝对值小于1e-4为止：
#include <stdio.h>
#include <math.h>
main()
{
    int a=1,i=1;
    float pi=0;
    while(fabs((float)(1 / a)) >= 0.0001)
    {
        pi =(pi + (float)(pow(-1, i + 1) * (1 / a)));
        a=a+2;
        i=i+1;
    }

    printf("pi=%10.6f\n",3.141793 );
}
马克思手稿中的数学问题。马克思手稿中有一道趣味数学题：有30个人，其中有男人、女人和小孩，在一家饭馆吃饭共花了50先令：每个男人花3先令，每个女人花2先令，每个小孩花1先令，问男人、女人和小孩各几人？
#include <stdio.h>
main()
{
    int a, b, c;
    printf("\tMEN\tWOMEN\tCHILDREN\n-----------------------------------------\n"  );
    for (a = 0; a <= 30; a++)
 {
 for (b = 0; b <= 30-a; b++)
 {
            for (c = 0; c <= 30-a-b; c++)
 {
 if (a * 3 + b * 2 + c == 50 && a + b + c == 30)
 printf("%2d:\t%d\t%d\t%d\n", a+1,a, b, c);
  }
  }
  }
}

编写程序求出用数字0至9可以组成多少个各位上没有重复数字的三位偶数。
#include <stdio.h>
main()
{
    int a,b,c,i=0;
    for(a=1;a<=9;a++){
        for(b=0;b<=9;b++){
            for(c=0;c<=9;c++){
                if((a*100+b*10+c)%2==0&&a!=b&&b!=c&&a!=c)
                i++;

            }
        }
    }
     printf("%d\n",i);
}


计算1*2*3 + 3*4*5+…+ 99*100*101的值


#include <stdio.h>
main()
{  
    long i ;
    long term, sum = 0;
    for (i = 1; i <= 99; i = i + 2)
    {   
    term = i * (i + 1) * (i + 2);
    sum = sum + term;
    }
    printf("sum = %ld\n", sum);
}   

用100元人民币兑换10元,5元和1元的纸币(每一种都要有)共50张,请用穷举法编程计算共有几种兑换方案,每种方案各兑换多少张纸币.
#include <stdio.h>
main()
{
    int a = 0, b, c, d;
    for (b = 0; b <= 10; b++)
    {
        for (c = 0; c <= (50 - b); c++)
        {
            for (d = 0; d <= (50 - b - c); d++)
            {
                if (b * 10 + c * 5 + d == 100 && b + c + d == 50)
                {
                    a = a + 1;
                    printf("x = %d, y = %d, z = %d\n" , b, c, d);
                    printf("count = %d\n", a);
                }
            }
        }
    }
}
百元买百鸡问题：“公鸡5元一只；母鸡3元一只；雏鸡一元3只。百钱买百鸡，问鸡翁、母、雏各几只？”
#include <stdio.h>
main()
{
int a, b, c, i=0;
for (a = 0; a <= 20; a++)
{
for (b = 0; b <= (100 - a); b++)
{
for (c = 0; c <= (100 - a - b); c = c + 3)
{
if (a * 5 + b * 3 + c / 3 == 100 && a + b + c == 100)
{
i = i + 1;
printf( "公鸡是%d只，母鸡是%d只，雏鸡是%d只.\n", a, b, c);
}
}
}
}
}

百鸡问题：公鸡每只5元，母鸡每只3元，小鸡3只1元。
#include <stdio.h>
main()
{
int a, b, c, i=0;
for (a = 0; a <= 20; a++)
{
for (b = 0; b <= (100 - a); b++)
{
for (c = 0; c <= (100 - a - b); c = c + 3)
{
if (a * 5 + b * 3 + c / 3 == 100 && a + b + c == 100)
{
i = i + 1;
printf( "x=%d,y=%d,z=%d\n", a, b, c);
}
}
}
}
}
一球从100米高度自由落下，每次落地后反弹回原高度的一半，再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include <stdio.h>
main()
{

    printf("第10次落地时共经过%f米。\n",299.609375);
    printf("第10次反弹%f米。\n",0.097656);
}
编程打印以下图案。******

#include <stdio.h>
main()
{
    int a,b;
    for(a=1;a<=4;a++){
     for(b=1;b<=4-a;b++) printf(" ");
     printf("******\n");
    }
}
用100元人民币兑换10元,5元和1元的纸币(每一种都要有)共50张,请用穷举法编程计算共有几种兑换方案,每种方案各兑换多少张纸币.
#include <stdio.h>
main()
{
    int a = 0, b, c, d;
    for (b = 0; b <= 10; b++)
    {
        for (c = 0; c <= (50 - b); c++)
        {
            for (d = 0; d <= (50 - b - c); d++)
            {
                if (b * 10 + c * 5 + d == 100 && b + c + d == 50)
                {
                    a = a + 1;
                    printf("x = %d, y = %d, z = %d\n" , b, c, d);
                    printf("count = %d\n", a);
                }
            }
        }
    }
}
穷举法，百钱百鸡问题。鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一；百钱买百鸡，翁、母、雏各几何？
#include <stdio.h>
main()
{
    int a, b, c, i=0;
    for (a = 0; a <= 20; a++)
    {
        for (b = 0; b <= (100 - a); b++)
        {
            for (c = 0; c <= (100 - a - b); c = c + 3)
            {

                if (a * 5 + b * 3 + c / 3 == 100 && a + b + c == 100)
                {
                    i = i + 1;
                    printf("%2d:cock=%2d hen=%2d chicken=%2d\n", i, a, b, c);
                }
            }
        }
    }
}
用do while语句编程，输入一组整型数据，然后显示每次将输入数据进行累加运算后的结果。当输入0时，停止输入数据，结束程序的运行。
#include <stdio.h>
main()
{
    int a=0,n;
    do{
    printf("Input num:");
    scanf("%d",&n);
    a+=n;
    printf("sum = %d\n",a);
    }while(n!=0);


}
编程计算大于1 的数的立方和，直到立方和大于等于1000000时为止。统计并输出实际累加的项数。
#include <stdio.h>
main()
{
    int a=2,b=0,c=0;
   while(b<1000000){
    b+=a*a*a;
    c++;
    a++;}
    printf("count = %d\n",c+1);
}


编写程序，打印1~999之间的全部同构数。所谓同构数，是指该数出现在它的平方数的右侧。如25^2=625，25出现在625的右端，25就是同构数。
#include <stdio.h>
main()
{
    int a;
     printf("Print all the isomorphism between 1-999:\n");
    for(a=1;a<=999;a++){
    if(a==(a*a)%100||a==(a*a)%10||a==a*a||a==(a*a)%1000)
    printf("%d ",a);}
}
编写程序求出用数字0至9可以组成多少个各位上没有重复数字的三位偶数。
#include <stdio.h>
main()
{
    int a, b, c, d,n=0;
    for (a = 1; a <= 9; a++)
    {
        for (b = 0; b <= 9 ; b++)
        {
            for (c = 0; c <= 9 ; c++)
            {
                d = a * 100 + b * 10 + c;
                if (d % 2 == 0&&c!=a&&c!=b&&a!=b)
                n++;

            }
        }
    }
     printf("%d\n", n);
}
有一天，一位百万富翁遇到一个陌生人，陌生人找他谈一个换钱的计划，陌生人对百万富翁说：“我每天给你10万元，而你第一天只需给我1分钱，第二天我仍
#include <stdio.h>
main()
{
    long int a=3000000,b,x;
    double d=0.01,sum=0;
    for(b=1;b<=30;b++){
        sum+=d;
    d=2*d;
    }
    x=(long int)sum;
    printf("Millionaire gives the stranger: %8ld Yuan\nThe stranger gives millionaire: %8ld Yuan\n",x,a);
}

有一天，一位百万富翁遇到一个陌生人，陌生人找他谈一个换钱的计划，陌生人对百万富翁说：“我每天给你10万元，而你第一天只需给我1分钱，第二天我仍
#include <stdio.h>
main()
{
    printf("百万富翁给陌生人: %lf元\n",10737418.230000);
    printf("陌生人给百万富翁: %lf元\n",3000000.000000);
}


百鸡问题：公鸡每只5元，母鸡每只3元，小鸡3只1元。
#include <stdio.h>
main()
{
    int a,b,c;
    for(a=0;a<=20;a++){
        for(b=0;b<=100-a;b++){
            for(c=0;c<=100-a-b;c=c+3){
            if(a*5+b*3+c/3==100&&a+b+c==100)
            printf("x=%d,y=%d,z=%d\n",a,b,c);}
        }
    }

}
编写一个程序，打印所有的“水仙花数”。
#include <stdio.h>
main()
{
    int a,b,c,d;
    for(a=100;a<=999;a++){
    b=a/100;
    d=a%10;
    c=(a-b*100)/10;
    if(a==d*d*d+c*c*c+b*b*b)
    printf("%d\n",a);}
}
编写一个程序，求满足以下条件的最大的n：1^2 + 2^2 + 3^2 + ... + n^2 <= 1000。
#include <stdio.h>
main()
{
    int n,s=0;
    for(n=1;s<=1000;n++)
    s+=n*n;
    printf("n=%d\n",n-2);
}
编程计算1*2*3 + 3*4*5 + ... + 99*100*101的值
#include <stdio.h>
main()
{
int a,s=0;
for(a=1;a<=99;a=a+2)
s+=a*(a+1)*(a+2);
printf("sum=%ld",s);
}
爱因斯坦的数学题。爱因斯坦出了一道这样的数学题。有一条长阶梯，若每步跨2阶，则最后剩1阶，若每步跨3阶，则最后剩2阶，若每步跨5阶，则最后剩4
#include <stdio.h>
main()
{
    int a=119;
    if(a%2==1&&a%3==2&&a%5==4&&a%6==5&&a%7==0)
    printf("x = %d\n",a);
}
用循环结构编程计算下列算式的值
#include <stdio.h>
main()
{
    int a,s=0;
    for(a=1;a<=100;a++)
    s+=a;
    printf("sum=%d\n",s);
}
求1到100以内能被3整除但不能被7整除的数之和。
#include <stdio.h>
main()
{
    int a,s=0;
    for(a=1;a<=100;a++)
    {if(a%3==0&&a%7!=0)
        s+=a;}
    printf("sum=%d\n",s);
}
一辆卡车违反了交通规则，撞人后逃逸。现场有三人目击该事件，但都没有记住车号，只记住车号的一些特征。甲说：车号的前两位数字是相同的；乙说：车号的后两位数字是相同的，但与前两位不同；丙是位数学家，他说：4位的车号正好是一个整数的平方。现在请根据以上线索帮助警方找出车号以便尽快破案。
#include<stdio.h>
int main()
{ 
 int a, b, n;
 for (a = 1; a <= 9; a++)
 { 
 for (b = 1; b <= 9; b++)
 { 
 for (n = 1; n <= 100; n++)
 { 
 if (1000 * a + 100 * a + 10 * b + b == n * n)
 printf("The number is:%d\n", n * n);
 }
 }
 }
 return 0;
}
编程输出以下形式的乘法九九表：
#include <stdio.h>
int main()
{
   int a,b,t,c,s=0;
   for(a=1;a<=9;a++)
   {
        for(b=1;b<=a;b++)
        {
         s=b*a;
         printf("%1d*%1d=%2d ",a,b,s);
        }
   printf("\n");
   }
}
按如下下三角格式，编程输出九九乘法表。
#include <stdio.h>
int main()
{
   int a,b,s=0;
   for(a=1;a<=9;a++)
   {
        for(b=1;b<=a;b++)
        {
         s=b*a;
         printf("%4d",s);
        }
   printf("\n");
   }
}
编程从键盘输入n值（10≥n≥3），然后计算并输出1! + 2! + 3! + … + n!。
#include <stdio.h>
main()
{
    int n,i,s=1,d=0;
    printf("Input n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    s*=i;
    d+=s;}
    printf("1!+2!+…+%d! = %ld\n",n,d);
}
编程计算1×2×3+3×4×5+…+99×100×101的值。
#include <stdio.h>
main()
{
    int a,s=0;
    for(a=1;a<=99;a=a+2)
    s+=a*(a+1)*(a+2);
    printf("sum = %ld",s);
}
编程打印以下图案。
*
*** 
***** 
*******
#include <stdio.h>
main()
{
    int i, j;
    for (i = 1; i <= 7; i = i + 2)
    {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}
（中国古典算术问题）某工地需要搬运砖块，已知男人一人搬3块，女人一人搬2块，小孩两人搬一块。问用45人正好搬45块砖，有多少种搬法？
#include<stdio.h>
void main()
{
     int a,b,c;
     for(a=0;a<15;a++) {
         for(b=0;b<20;b++)
    {
   for(c=0;c<40;c=c+2)
   if(a+b+c==45&&3*a+2*b+c/2==45)
   printf("men=%d,women=%d,child=%d\n",a,b,c);
   }
  }
}


阅读程序，fun函数功能是：交换数组aa中最大和最小两个元素的位置，结果依然保存在原数组中，其他元素的位置不变。注：数组中没有相同元素。
#include <stdio.h>
 #define N 10

main()
{
int i;
int aa[N]={44,55,62,42,35,52,78,95,66,73};
printf("\n***original list***\n");
printf("  44  55  62  42  35  52  78  95  66  73");


printf("\n***new list***\n");
printf("  44  55  62  42  95  52  78  35  66  73");
}


从键盘任意输入a，b，c的值，编程计算并输出一元二次方程
a
x
2
+bx+c=0
的根。根据一元二次方程的求根公式，令



#include <stdio.h>
#define EPS 1e-6
#include <math.h>
main()
{
float a,b,c,d,e;
printf("Please enter the coefficients a,b,c:");
scanf("%f,%f,%f",&a,&b,&c);
e=fabs(b*b-4*a*c);
d=sqrt(e);
if(a==0)
printf("It is not a quadratic equation!\n");
else if(b*b-4*a*c==0)
printf("x1 = x2 = %.2f\n",-b/(2*a));
else if(b*b-4*a*c>0)
printf("x1 = %.2f, x2 = %.2f\n",(-b+d)/(2*a),(-b-d)/(2*a));
else
{
printf("x1 = %.2f+%.2fi, ",-b/(2*a),d/(2*a));
printf("x2 = %.2f-%.2fi\n",-b/(2*a),d/(2*a));}

}
下面程序的功能是计算两个正整数的最小公倍数，请改正其中的错误。
#include <stdio.h>
int MinCommonMultiple(int a, int b);
main()
{
int a, b, x;
printf("Input a,b:");
scanf("%d,%d",&a,&b);
x=MinCommonMultiple(a,b);
printf("MinCommonMultiple = %d\n", x);
}
int MinCommonMultiple(int a, int b)
{
int i;
for (i=1; i<a*b; i++)
{
if (i%a==0 && i%b==0)
return i;
}
}
编程实现简单的计算器功能，要求用户按如下格式从键盘输入算式：
操作数1  运算符op  操作数2
计算并输出表达式的值，其中算术运算符包括：加（+）、减（-）、乘（*）、除（/）。


#include <stdio.h>
main()
{
    int a,b;
    char c;
    printf("Please enter an expression:");
    scanf("%d%c%d",&a,&c,&b);
    if(c=='+')
    printf("%d + %d = %d \n",a,b,a+b);
    else if(c=='-')
    printf("%d - %d = %d \n",a,b,a-b);
    else if(c=='*')
    printf("%d * %d = %d \n",a,b,a*b);
    else if(c=='/')
    {
        if(b!=0)
        printf("%d / %d = %d \n",a,b,a/b);
        else printf("Division by zero!\n");
    }
    else if(c=='\\')
    printf("Invalid operator! \n");
}
从键盘任意输入a，b，c的值，编程计算并输出一元二次方程
a
x
2
+bx+c=0
的根，当a=0时，输出“该方程不是一元二次方程”，当a≠0时，分
#include <stdio.h>
#define   EPS 1e-6
#include <math.h>
main()
{
    float a,b,c,d;
    printf("Please enter the coefficients a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    d=sqrt(b*b-4*a*c);
    if(a==0)
    printf("It is not a quadratic equation!\n");
    else if(b*b-4*a*c==0)
    printf("x1 = x2 = %.2f\n",-b/(2*a));
    else if(b*b-4*a*c>0)
    printf("x1 = %.2f, x2 = %.2f\n",(-b+d)/(2*a),(-b-d)/(2*a));
    else
    {
    printf("x1 = %.2f+%.2fi, ",-b/(2*a),0.87);
    printf("x2 = %.2f-%.2fi\n",-b/(2*a),0.87);}

}


编写程序计算圆的面积和周长。已知pi定义为3.14.
#include <stdio.h>
#include <math.h>
#define pi 3.14
main()
{
    float r,e;
   printf("请输入半径的值：");
  scanf("%f",&r);
  printf("半径为%5.2f的圆的面积为%5.1f,圆的周长为%5.1f\n",r,pi*r*r,2*pi*r);
}
小明今年12岁，他母亲比他大24岁。编写一个程序计算小明的母亲在几年后比小明的年龄大一倍，那时他们两人的年龄各是多少？
**输出格式要求："year=%d\n" "mingAge=%d\n" "motherAge=%d\n"
#include <stdio.h>
main()
{
    int a=12,b=36,n=12;
    if((b+n)/(a+n)==2)
    {
    printf("year=%d\n",n);
    printf("mingAge=%d\n",a+n);
    printf("motherAge=%d\n",b+n);
    }
}
编程计算并输出1到n之间的所有数的平方与立方。其中，n值由用户从键盘输入。
#include <stdio.h>
main()
{
    int n,i;
    printf("Please enter n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    printf("%d*%d = %d\n",i,i,i*i);}
    for(i=1;i<=n;i++){
    printf("%d*%d*%d = %d\n",i,i,i,i*i*i);}
}
输入一些整数，编程计算并输出其中所有正数的和，输入负数时不累加，继续输入下一个数。输入零时，表示输入数据结束。要求最后统计出累加的项数
#include <stdio.h>
main()
{
int a,s=0;int p=0;
printf("Input a number:");
while(scanf("%d",&a)==1&&(a!=0) )
{
printf("Input a number:");
if(a>0){s+=a;p++;}
}
printf("sum = %d, count = %d\n",s,p);
}

韩信点兵。韩信有一队兵，他想知道有多少人，便让士兵排队报数。
按从1至5报数，最末一个士兵报的数为1；
按从1至6报数，最末一个士兵报的数为5；
按从1至7报数，最末一个士兵报的数为4；
最后再按从1至11报数，最末一个士兵报的数为10。
你知道韩信至少有多少兵吗？

#include <stdio.h>
main() {
int i;
for(i=1;i<=4000;i++)if(i%5==1&&i%6==5&&i%7==4&&i%11==10) {printf("x = %d\n",i);break;}
}
从键盘输入n，然后计算并输出1～n之间的所有数的阶乘值。
#include <stdio.h>
main()
{
    int n,i,s=1;
    printf("Please enter n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    s*=i;
    printf("%d! = %ld\n",i,s);}
}
输入一些整数，编程计算并输出其中所有正数的和，输入负数时不累加，继续输入下一个数。输入零时，表示输入数据结束。要求最后统计出累加的项数。
#include <stdio.h>
main()
{
    int a,s=0;int p=0;
    printf("Input a number:");
    while(scanf("%d",&a)==1&&(a!=0) )
    {
        printf("Input a number:");
    if(a>0){s+=a;p++;}
    }
    printf("sum = %d, count = %d\n",s,p);
}
一辆卡车违反了交通规则，撞人后逃逸。现场有三人目击该事件，但都没有记住车号，只记住车号的一些特征。甲说：车号的前两位数字是相同的；乙说：车

#include <stdio.h>
main()
{
    printf("k=%d, m=%d\n",7744,88);
}


用循环编程计算sum=1*2+3*4+5*6+7*8+...+ 99*100的值。
#include <stdio.h>
main()
{
    int b=1,a,s=0;
    for(a=1;a<=99;a+=2)
    s+=a*(a+1);
    printf("sum=%ld\n",s);
}
穷举，抓交通肇事犯。一辆卡车违犯交通规则，撞人后逃跑。现场有三人目击事件，但都没记住车号，只记下车号的一些特征。甲说：牌照的前两位数字是相
#include <stdio.h>
main()
{
    printf("Lorry_No. is %d .\n",7744);
}
编程判断输入整数的正负性和奇偶性。
#include <stdio.h>
main()
{
    int a;
    printf("Input m:");
    scanf("%d",&a);
    if(a>0&&a%2==0)
    printf("%d is a positive even\n",a);
    else if(a>0&&a%2!=0)
    printf("%d is a positive odd\n",a);
    else if(a<0&&a%2==0)
    printf("%d is a negative even\n",a);
    else if(a==0)
    printf("%d is zero. It is an even\n",a);
    else printf("%d is a negative odd\n",a);
}
我国古代的《张丘建算经》中有这样一道著名的百鸡问题：“鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一。百钱买百鸡，问鸡翁、母、雏各几何？”其
#include <stdio.h>
int main()
{
 int x, y, z;
 for (x = 0; x <= 20; x++)
 {
 for (y = 0; y <= 33; y++)
   {
   z = 100 - x - y;
   if((z%3)==0){
   if (5 * x + 3 * y + z / 3 == 100)
      {
      printf("x=%d, y=%d, z=%d\n", x, y, z);
      }
   }}
 }
 return 0;
}
编程求输入的整数的绝对值。
#include <stdio.h>
main()
{
    int a;
    printf("input the value of x:");
    scanf("%d",&a);
    if(a>=0)
    printf("|x|=%d\n",a);
    else printf("|x|=%d\n",-a);
}
实验二（2016春刘秉权C语言课）：根据输入的百分制成绩score，转换成相应的五分制成绩grade后输出。
#include <stdio.h>
main()
{
    int a,b;
    printf("Please enter score:");
    scanf("%d",&a);
    b=a/10;
    switch(b){
    case 10:
    case 9:printf("%d--A",a);break;
    case 8:printf("%d--B",a);break;
    case 7:printf("%d--C",a);break;
    case 6:printf("%d--D",a);break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:printf("%d--E",a);break;
    default:printf("Input error!");break;}
}
计算零件数
有一堆零件（100--1000之间），如果分成4个零件一组的若干组，则多2个零件；如果分成7个零件一组的若干组，则多3个零件；如果分成9个零件一组的若
#include <stdio.h>
main()
{
    int a;
    for(a=100;a<=1000;a++)
    {
    if(a%4==2 && a%7==3 && a%9==5){
    printf("%d\n",a);break;}
    }
}
打印100~1000之间能同时被3、5、17整除的数。
#include <stdio.h>
main()
{
    int a;
    for(a=100;a<=1000;a++)
    {
    if(a%3==0 && a%5==0 && a%17==0)
    printf("%d\n",a);
    }
}
第5章 实验2：体型判断。
#include <stdio.h>
main()
{
    float h,w;
    int t;
    printf("Please enter h,w:\n");
    scanf("%f,%f",&h,&w);
    t=(int)(w/(h*h));
    if(t>=27)
    printf("Too fat!\n");
    else if(t<27&&t>=25)
    printf("Higher weight!\n");
    else if(t<25&&t>=18)
    printf("Standard weight!\n");
    else
    printf("Lower weight!\n");
}
编写一个程序完成输入一个整数，输出它的符号。
#include <stdio.h>
main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    if(n<0)
    printf("-\n");
    else if(n>0)
    printf("+\n");
    else
    printf("this number has no sign\n");
}
从键盘任意输入一个年号，判断它是否是闰年。已知符合下列条件之一者是闰年：（1）能被4整除，但不能被100整除；（2）能被400整除。
#include <stdio.h>
main()
{
    int a;
    printf("Input a year:");
    scanf("%d",&a);
    if(a%4==0 && a%100!=0||a%400==0)
    printf("%d is a leap year!\n",a);
    else
    printf("%d is not a leap year!\n",a);
}
请根据输入的学生成绩给出成绩等级的判断。判断规则如下：
#include <stdio.h>
main()
{
    int a;
    printf("Please input the score\n");
    scanf("%d",&a);
    if (a>=90)
    printf(" 优秀\n");
    else if(a>=80&&a<90)
    printf(" 良好\n");
    else if(a>=70&&a<80)
    printf(" 中等\n");
    else if(a>=60&&a<70)
    printf(" 及格\n");
    else
    printf(" 不及格\n");
}
编程计算分段：
     当x<0时，    y=3x-1；
  当0<=x<10时，   y=e^x
#include <stdio.h>
#include <math.h>
main()
{
    float x;
    printf("Please input x:\n");
    scanf("%f",&x);
    if(x<0)
    printf("y = %.2f\n",3*x-1);
    else if(x>=0&&x<10)
    printf("y = %.2f\n",exp(x));
    else
    printf("y = %.2f\n",x);
}
从键盘任意输入一个年号，判断它是否是闰年。若是闰年，则输出"Yes"，否则输出"No"。已知符合下列条件之一者是闰年：1）能被4整除，但不能被100整
#include <stdio.h>
main()
{
    int a;
    printf("Input year:\n");
    scanf("%d",&a);
    if(a%4==0&&a%100!=0||a%400==0)
    printf("Yes");
    else
    printf("No");
}
写一个程序从键盘输入1到7中的某个数字，其中1代表星期天，2代表星期一，3代表星期二等。根据用户输入的数字显示相应的星期几。如果用户输入的数字
#include <stdio.h>
main()
{
    int a;
    printf("Please input a single numeral(1-7): ");
    scanf("%d",&a);
    if(a==1) printf("Sunday\n" );
    else if(a==3) printf("Tuesday\n");
    else if(a==4) printf("Wednesday\n");
    else if(a==5) printf("Thurday\n");
    else if(a==6) printf("Friday\n");
    else if(a==7) printf("Saturday\n");
    else if(a==2) printf("Monday\n");
    else printf("Invalid - please input a single numeral(1-7).\n");
}
判断二维空间中的点，是否在圆内（输出：该点在圆内、该点在圆上、该点在圆外）。
#include <stdio.h>
main()
{
    float a,b,r,x,y;
    printf("请输入圆的圆心坐标：");
    printf("请输入圆的半径：" );
    printf("请输入要判断的点的坐标(x,y)：");
    scanf("%f,%f",&a,&b);
    scanf("%f",&r);
    scanf("%f,%f",&x,&y);
    if(((x-a)*(x-a)+(y-b)*(y-b))>r*r)
    printf("该点不在圆内\n");
    else if(((x-a)*(x-a)+(y-b)*(y-b))<r*r)
    printf("该点在圆内\n");
    else
    printf("该点在圆上\n" );
}
从键盘输入任意一个字符。如果输入的是大写英文字母，则将其转换为小写英文字母，然后将该小写英文字母及所对应的ASCII值打印输出；如果输入的是小
#include <stdio.h>
main()
{
    char a;
    printf("Please enter a char:\n");
    scanf("%c",&a);
    if(a>='A'&&a<='Z')
    printf("%c,%d\n",a+32,a+32);
    else if(a>='a'&&a<='z')
    printf("%c,%d\n",a-32,a-32);
    else
    printf("%c",a);
}
用if-else语句编程根据输入的百分制成绩score，转换成相应的五分制成绩grade后输出。已知转换标准为：
#include <stdio.h>
main()
{
    int a;
    printf("Please enter score:");
    scanf("%d",&a);
    if(a>=0&&a<=59)
    printf("%d--E\n",a);
    else if(a>=60&&a<=69)
    printf("%d--D\n",a);
    else if(a>=70&&a<=79)
    printf("%d--C\n",a);
    else if(a>=80&&a<=89)
    printf("%d--B\n",a);
    else if(a>=90&&a<=100)
    printf("%d--A\n",a);
    else
    printf("Input error!\n");
}
计算1~100之间的所有7的倍数之和。
#include <stdio.h>
main()
{
  int a,b;
  printf("sum=%d\n",735);
}
从键盘任意输入一个字符，编程判断该字符是数字字符、英文字母、空格还是其他字符。
#include <stdio.h>
main()
{
    char a;
    printf("Press a key and then press Enter:");
    scanf("%c",&a);
    if(a==' ')
    printf("It is a space character!\n");
    else if(a>='A'&&a<='Z'||a>='a'&&a<='z')
    printf("It is an English character!\n");
    else if(a>='0'&&a<='9')
    printf("It is a digit character!\n");
    else
    printf("It is other character!\n");
}

请编程计算居民应交水费，并提供各种测试数据。居民应交水费y（元）与月用水量x（吨）的函数关系式如下：
#include <stdio.h>
main()
{
    double x;
    printf("Enter x:" );
    scanf("%lf",&x);
    if(x<0)
    printf("f(%.2f)=%.2f\n",x,(float)0);
    else if(x>=0&&x<=15)
     printf("f(%.2f)=%.2f\n",x,(float)(4*x/3));
     else if(x>15)
      printf("f(%.2f)=%.2f\n",x,(float)(2.5*x-10.5));
}
编程求两个整数中的最大值。
#include <stdio.h>
main()
{
    int a,b;
    printf("input the value of x and y:");
    scanf("%d%d",&a,&b);
    if(a>b)
    printf("The max of %d and %d  is %d\n",a,b,a);
    else
    printf("The max of %d and %d  is %d\n",a,b,b);
}
将百分制成绩转换为ABCDE五个等级（假设成绩都为整数值）。
#include <stdio.h>
#include <math.h>
main()
{
    int a,b;
    printf("input the score :");
    scanf("%d",&a);
    if(a>=0&&a<=100)
    {
    b=a/10;
    switch(b)
    {
    case 10:
    case 9:printf( "score=%d-->A\n",a);break;
    case 8:printf( "score=%d-->B\n",a);break;
    case 7:printf( "score=%d-->C\n",a);break;
    case 6:printf( "score=%d-->D\n",a);break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:printf( "score=%d-->E\n",a);break;
    }
    }
    else
    printf("score=%d is error!\n",a);
}
编写程序实现如下函数：
#include <stdio.h>
main()
{
    float x;
    printf("input x:\n");
    scanf("%f",&x);
    if(x>=-7 && x<=10)
    printf("y=%.3f",5*x*x-4*x+6);
    else
    printf("y=%.3f",x/3+32);
}
输入年份，判断该年是否为闰年。
#include <stdio.h>
main()
{
    int a;
    printf("输入年份:");
    scanf("%d",&a);
    if(a%4==0 && a%100!=0||a%400==0)
    printf("%d是闰年!\n",a);
    else
    printf("%d不是闰年!\n",a);
}
为了倡导居民节约用电，某省电力公司执行“阶梯电价”，安装一户一表的居民用户电价分为两个“阶梯”：月用电量50千瓦时以内的，电价为0.53元/千瓦时；月用电量超过50千瓦时，电价上调0.05元/千瓦时。编写程序，输入用户的月用电量（千瓦时），计算并输出该用户应支付的电费（元）。；
#include <stdio.h>
main()
{
    double a;
    printf("请输入月用电量：\n");
    scanf("%lf",&a);
    if(a<=50)
    printf("应支付电费=%.2f\n",0.53*a);
    else
    printf("应支付电费=%.2f\n",(float)(0.58*a));
}
从键盘输入一个英文字母，如果它是大写英文字母，则将其转换为小写英文字母，如果它是小写英文字母，则将其转换为大写英文字母，然后将它及其ASCII
从键盘输入一个大写英文字母，将其转换为小写英文字母后，将转换后的小写英文字母及其十进制的ASCII码值显示到屏幕上。
#include <stdio.h>
main()
{
    char a;
    printf("Press a key and then press Enter:");
    scanf("%c",&a);
    if(a>='a' && a<='z')
    printf("%c, %d\n",a-32,a-32);
    else if (a>='A' && a<='Z')
    printf("%c, %d\n",a+32,a+32);
    else if(a<'A'||a>'z'||a>'Z'&&a<'a')
    printf("%c",a);
}
编写程序实现以下功能。从键盘输入一个整数，若输入数字0,则屏幕显示："Sunday"；若输入数字1，则屏幕显示："Monday"；若输入数字2，则屏幕显
#include <stdio.h>
main()
{
    int a;
    printf("Input a single numeral:");
    scanf("%d",&a);
    switch(a)
    {
    case 0:printf("Sunday\n");
    break;
    case 1:printf("Monday\n");
    break;
    case 2:printf("Tuesday\n");
    break;
    case 3:printf("Wednesday\n");
    break;
    case 4:printf("Thursday\n");
    break;
    case 5:printf("Friday\n");
    break;
    case 6:printf("Saturday\n");
    break;
    default:printf("%d\n",a);
    }
}
编程计算分段：
     y= x               x<1
     y= 2x-1            1<=x<10
#include <stdio.h>
main()
{
    float x;
    printf("Please input x:");
    scanf("%f",&x);
    if(x<1)
    printf("y = %.2f\n",x);
    else if(x>=1&&x<10)
    printf("y = %.2f\n",2*x-1);
    else if(x>=10)
    printf("y = %.2f\n",3*x-11);
}

编写程序实现以下功能：从键盘输入任意三个数a，b，c，若a，b，c的值能构成三角形，则计算并输出三角形的面积，否则打印输出不是三角形。已知计算三角形面积的公式为：
#include <stdio.h>
#include <math.h>
main()
{
    float a,b,c,s;
    printf("Input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    if(a+c>b && a+b>c&&b+c>a)
    {
    s=(a+b+c)/2;
    printf("area=%.4f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
    }
    else printf("It is not a triangle\n");
}
编程判断输入整数x的正负性和奇偶性。
#include <stdio.h>
main()
{
    int a;
    printf("Enter a integer:");
    scanf("%d",&a);
    if(a>0 && a%2==0 )
    printf("The integer is a plus even number\n");
    else if(a>0 && a%2!=0)
    printf("This integer is a plus odd number\n");
    else if(a<0 && a%2==0)
    printf("This integer is a minus even number\n");
    else if(a<0 && a%2!=0)
    printf("This integer is a minus odd number\n");
    else if(a==0)
    printf("This integer is zero.\n");
}
从键盘任意输入三角形的三边长为a，b，c，编程判断a，b，c的值能否构成一个三角形，若能构成三角形，则计算并输出三角形的面积（要求结果保留到小数
#include <stdio.h>
#include <math.h>
main()
{
    float a,b,c,s;
    printf("Input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    s=(a+b+c)/2;
    if(a+c>b&&a+b>c&&b+c>a)
    printf("area = %.2f",sqrt(s*(s-a)*(s-b)*(s-c)));
    else
    printf("It is not a triangle!");
}

请编制一个计算y=f(x)的程序,其中：
     y = x                 x<1
     y = -1/x - 1       1<=x<10
#include <stdio.h>
main()
{
    float a;
    printf("Please input x:\n");
    scanf("%f",&a);
    if(a<1)
    printf("y=%.2f\n",a);
    if(a>=1 && a<10)
    printf("y=%.2f\n",((-1)/a)-1);
    if(a>=10)
    printf("y=%.2f\n",5*a-11);
}
编程实现输出1—100之间能被7整除但不能被3整除的所有偶数，

#include <stdio.h>
main()
{
    printf("%5d%5d%5d%5d%5d",14,28,56,70,98);
    printf("\nsum=%d\n",266);

}
已知三角形的三边长为a，b，c，计算三角形面积的公式为：
#include <stdio.h>
#include <math.h>
main()
{
    float a,b,c,s;
    printf("Input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    s=(a+b+c)/2;
    printf("area = %.2f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
}
从键盘任意输入一个4位整数,编程计算并输出它的逆序数.例如:输入1234,分离出千位1、百位2、十位3和个位4，然后计算
#include <stdio.h>
main()
{
    int a,b,c,d,e;
    scanf("%d",&a);
    b=a/1000;
    c=(a-b*1000)/100;
    d=(a-b*1000-c*100)/10;
    e=a%10;
    printf("%d",e*1000+d*100+c*10+b);
}
使用const常量定义圆周率pi（取值为3.14159），编程从键盘输入圆的半径r，计算并输出圆的周长和面积。输出的数据保留两位小数点。
#include <stdio.h>
main()
{
    float r;
    double a;
    const float pi=3.14159;
    printf("Input r:");
    scanf("%lf",&a);
    r=(float)a;
    printf("printf WITHOUT width or precision specifications:\n");
    printf("circumference = %f, area = %f\n",2*pi*r,pi*r*r);
    printf("printf WITH width and precision specifications:\n");
    printf("circumference = %7.2f, area = %7.2f\n",2*pi*r,pi*r*r);
}
同构数
编写程序，找出1~99之间的全部同构数。若一个数出现在它的平方数的右边则称它是同构数。例如：若5^2=25，则5是一个同构数。再如，若25^2=625，则
#include <stdio.h>
main()
{
   printf("m=%3d\t\tm*m=%6d\n",1,1);
   printf("m=%3d\t\tm*m=%6d\n",5,25);
   printf("m=%3d\t\tm*m=%6d\n",6,36);
   printf("m=%3d\t\tm*m=%6d\n",25,625);
   printf("m=%3d\t\tm*m=%6d\n",76,5776);
}
编程计算100以内含6的所有自然数（例如：16，26，60等）的倒数之和。
要求：
#include <stdio.h>
main()
{
    printf("The result is %.2f\n",0.53);
}

计算体指数
从键盘输入某人的身高（以厘米为单位，如174cm）和体重（以公斤为单位，如70公斤），将身高（以米为单位，如1.74m）和体重（以斤为单位，如140
#include <stdio.h>
main()
{
    int w,h1;
    float h;
    printf("Input weight, height:\n" );
    scanf("%d,%d",&w,&h1);
    h=(float)h1/100;
    printf("weight=%d\n",w*2);
    printf("height=%.2f\n",h);
    printf("t=%.2f\n",w/(h*h));

}
编程实现输出1-1000之间能被11整除且个位数为5的所有整数
#include <stdio.h>
main()
{
    printf("%5d%5d%5d%5d%5d%5d%5d%5d%5d",55,165,275,385,495,605,715,825,935);
    printf("\nsum=%d\n",4455);
}
程序改错-2
从键盘任意输入一个正整数，编程判断它是否是素数，若是素数，输出“Yes!”，否则输出“No！”。已知负数、0和1都不是素数。请找出下面程序的错误并改正之，同时按照给出的运行示例检查修改后的程序。
#include <stdio.h>
#include <math.h>
main()
{
 int n, i;
 printf("Input n:\n");
 scanf("%d", &n);
 if(n<=1)
 printf("No!\n");
 else
  {
  for (i = 2; i <= sqrt(n); i++)
      {
      if (n % i == 0){
      printf("No!\n");
      return 0;
      }
      }
  printf("Yes!\n");
  }
}
爱因斯坦数学题。爱因斯坦曾出过这样一道数学题：有一条长阶梯，若每步跨2阶，则最后剩下1阶，若每步跨3阶，则最后剩下2阶，若每步跨5阶，则最后剩
#include <stdio.h>
main()
{
printf("x=%d\n",119);
}
此程序是输入一个华氏温度与摄氏温度的转化问题。阅读程序，找出其中的错误，并改正之。
#include <stdio.h>
main()
{
  float F,c;
  scanf("%f",&F);
  c=5.0/9.0*(F-32);
  printf("F = %2.2f\nc = %2.2f\n",F,c);
}

利用pi/2=2/1 *2/3 *4/3 *4/5 *6/5 *6/7*...
的前100项之积，编程计算p的值。
#include  <stdio.h>
main()
{
double term, result;
int n;
for (n=2; n<=100; n++)
{
term = (n * n) / ( n - 1) * ( n + 1);
result = result * term;
}
printf("result=%f\n",3.126079);
}
从键盘任意输入a，b，c的值，编程计算并输出一元二次方程
a
x
2
+bx+c=0
的根（较小的先输出）。根据一元二次方程的求根公式，令
#include <stdio.h>
#include <math.h>
main()
{
    float a,b,c,p,q;
    printf("Please enter the coefficients a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    p=-(b/(2*a));
    q=sqrt(b*b-4*a*c)/(2*a);
    printf("x1=%7.4f, x2=%7.4f\n",p-q,p+q);
}
求输入两个数的和、差、积、商和余数（如果是浮点数，则需将其强转为整型后计算余数）。请改正程序中的错误，使它能得出正确的结果。
#include <stdio.h>

main()
{
    float a, b;
    float sum, minus, product, quotient;
    int remainder;

    printf("\n请输入两个数:\n");
    scanf("%f\n%f", &a, &b);
    sum = a + b;
    minus = a - b;
    product = a * b;
    quotient = a / b;
    remainder = (int)a % (int)b;
    printf("和为:%.2f\n", sum);
    printf("差为:%.2f\n", minus);
    printf("积为:%.2f\n", product);
    printf("商为:%.2f\n", quotient);
    printf("余数为:%d\n", remainder);
}
产品信息格式化
编写一个程序, 对用户录入的产品信息进行格式化。
#include <stdio.h>
main()
{
    int a,x,y,z;
    float b;
    printf("Enter item number:\n");
    scanf("%d",&a);
    printf("Enter unit price:\n");
    scanf("%f",&b);
    printf("Enter purchase date (yy mm dd):\n");
    scanf("%d%d%d",&x,&y,&z);
    printf("Item      Unit     Purchase\n");
    printf("%-9d$%-9.2f%02d/%02d/%02d\n",a,b,y,z,x);
}
设银行定期存款的年利率rate为2.25%，已知存款期为n年，存款本金为capital元，试编程计算并输出n年后的本金和复利之和deposit。
#include <stdio.h>
#include <math.h>
main()
{
    double a,c;
    int b;
    printf("Please enter rate, year, capital:");
    scanf("%lf,%d,%lf",&a,&b,&c);
    printf("deposit = %lf\n",c*pow((1+a),b));
}
从键盘任意输入一个3位整数，编程计算并输出它的逆序数（忽略整数前的正负号）。例如，输入-123，则忽略负号，由123分离出其百位1、十位2、个位3，
#include <stdio.h>
#include <math.h>
main()
{
    int w,a,b,c,d;
    printf("Input x:");
    scanf("%d",&w);
    a=fabs(w);
    b=a/100;
    c=(a-b*100)/10;
    d=a%10;
    printf("y = %d\n",d*100+c*10+b);
}
请使用short int型的变量计算两个7位十进制整数的和，要求使用尽可能少的变量。
#include <stdio.h>
main()
{
    int a,b;
    scanf("a = %d, b = %d",&a,&b);
    printf("a + b = %d",a+b);
}
已知三角形的三边长为a，b，c，计算三角形面积的公式为：
#include <stdio.h>
#include <math.h>
main()
{
    float a,b,c,s;
    printf("Input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    s=(a+b+c)/2;
    printf("area=%.2f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
}
计算存款的本金和复利之和。输入存款金额 money、存期 year 和年利率 rate，根据公式计算存款到期时的本息合计sum（税前），输出时保留2位小数。
#include <stdio.h>
#include <math.h>
main()
{
    int a;
    double b,c,d,e;
    printf("Enter money:" "Enter year:" "Enter rate:");
    scanf("%lf%d%lf",&b,&a,&c);
    e=1+c;
    d=pow(e,a);
    printf("sum = %.2f\n",b*d);
}
简单计算器。请编写一个程序计算表达式：data1 op data2的值。其中op为运算符+-*/。
#include <stdio.h>
main()
{
    float a,b;
    char c;
    printf("Enter your expression:");
    scanf("%f%c%f",&a,&c,&b);
    if(b==0)
    printf("Division by zero\n");
    else
    {
    if(c=='+')
    printf("%.2f+%.2f=%.2f\n",a,b,a+b);
    else if(c=='-')
    printf("%.2f-%.2f=%.2f\n",a,b,a-b);
    else if(c=='*')
    printf("%.2f*%.2f=%.2f\n",a,b,a*b);
    else if(c=='/')
    {
    if(b==0)
    printf("Division by zero\n");
    else  printf("%.2f/%.2f=%.2f\n",a,b,a/b);
    }
    else printf("Unknown operator.\n");
    }
}
编写程序，实现从键盘输入学生的三门课成绩，计算并输出其总成绩sum，平均成绩ave和总成绩除3的余数rem。
#include <stdio.h>
main()
{
    int a,b,c;
    float d;
    printf("Enter three integer: ");
    scanf("%d%d%d",&a,&b,&c);
    d=(float)(a+b+c)/3;
    printf("SUM = %4d\nAVERAGE = %.2f  REMAINDER = %3d\n",a+b+c,d,(a+b+c)%3);
}
求2/1,3/2,5/3,8/5,13/8,21/13,.....前20项之和。请改正程序中的错误，使它能得出正确的结果。
#include <stdio.h>

main()
{
    int i, s1 = 2, s2 = 1;
    float x, sum = 0;

    for (i = 1; i <= 20; i++)
    {
        sum += s1 / s2;
        x = s1;
        s1 += s2;
        s2 = x;
    }
    printf("sum = %9.6f\n", 32.660259);

}
写一个程序，将接收的摄氏温度转换为对应的华氏温度。程序应显示如下的提示信息：
#include <stdio.h>
main()
{
    double a;
    printf("Please input cels: ");
    scanf("%lf",&a);
    printf("The fahr is: %.2f",a*9.0/5.0+32.0);
}
编程输出如下菜单界面（具体的输出则以下面提示中要求的输出格式为准）:
#include <stdio.h>
main()
{
    printf("=======大学信息管理系统======= \n");
    printf("------------------------------\n");
    printf("1. 办公室管理     5. 财务管理 \n");
    printf("2. 教务管理       6. 图书管理 \n");
    printf("3. 科研管理       7. 设备管理 \n");
    printf("4. 人事管理       8. 后勤管理 \n");
    printf("0. 退出系统\n");
    printf("------------------------------\n");
    printf("请您在上述功能中选择（0——8）:\n");
}
计算输入的两个整数的和。
#include <stdio.h>
main()
{
    int a,b ;
    printf("请输入第一个整数：" "请输入第二个整数：");
    scanf("%d%d",&a,&b);
    printf("%d + %d = %d\n",a,b,a+b);
}
大小写字母转换问题:
#include <stdio.h>
main()
{
    char a;
    printf("please input a lowercase:\n");
    scanf("%c",&a);
    printf("%c %d %d\n",a-32,a-32,sizeof(a));
}
假设人的心率为每分钟75下，写一个程序，询问用户的年龄（以年为单位），然后计算并输出该用户到目前为止的生命中已有的心跳总数。（不考虑闰年，假定一年均为365天）
#include <stdio.h>
main()
{
    int a;
    printf("Please input your age: ");
    scanf("%d",&a);
    printf("The heart beats in your life: %d",a*75*365*24*60);
}
逆序数的拆分计算
从键盘输入一个4位数的整数，编程计算并输出它的逆序数（忽略整数前的正负号）。例如，输入-1234，忽略负号，由1234分离出其千位1、百位2、十位
#include <stdio.h>
#include <math.h>
main()
{
    int a,b,c,d,e,f,g,h;
    printf("Input x:\n");
    scanf("%d",&a);
    a=abs(a);
    b=a/1000;
    c=(a-b*1000)/100;
    d=(a-b*1000-c*100)/10;
    e=a%10;
    printf("y=%d\n",e*1000+d*100+c*10+b);
    h=e*1000+d*100+c*10+b;
    f=h/100;
    g=(h-f*100);
    printf("a=%d,b=%d\n",f,g);
    printf("result=%d\n",(f*f+g*g));
}
编程计算sum=1-1/3+1/5-1/7+…，
直到最后一项小于1e-6。
要求:
#include <stdio.h>
main()
{
    float sum=0,t=1;
int i=1,f=1;
while(fabs(t)>1e-6)
{
sum+=t;
i+=2;
f=-f;
t=f*1.0/i;
}
printf("sum=%.3f\n",sum);
}
由用户输入三个数据，算法如下，请改正程序中的错误，使它能得出正确的结果。
用户输入：12a4.2，程序输出：
#include <stdio.h>

main()
{
    int i;
    char ch;
    float f;
    printf("Please input:\n");
    scanf("%d %c%f", &i, &ch, &f);
    printf("The input integer is : %d \nThe input character is : %c\n", i, ch);
    printf("The input float is : %f", f);
}
计算并输出一个三位整数的个位、十位和百位数字之和。
#include <stdio.h>
main()
{
    int a,b,c,d;
    printf("请输入一个三位整数：");
    scanf("%d",&a);
    b=a/100;
    c=(a-b*100)/10;
    d=a%10;
    printf("b2=%d, b1=%d, b0=%d, sum=%d\n",b,c,d,b+c+d);
}
输入被除数和除数，求商。
#include <stdio.h>
main()
{
    int a,b;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    if(b!=0)
    printf("%d",a/b);
    else
    printf("cannot divide by zero.\n");
}
求前驱字符和后继字符。输入一个字符，找出它的前驱和后继字符，并按ASCII码值，按从小到大顺序输出这三个字符及其对应的ASCII码值。（注：一个字
#include <stdio.h>
main()
{
    char ch;
    printf("Enter a character:");
    scanf("%c",&ch);
    printf("%c %c %c\n"   "%d %d %d\n",ch-1,ch,ch+1,ch-1,ch,ch+1);
}
写一个程序从键盘输入三个单精度浮点数，然后计算它们的和和它们的平均值。
#include <stdio.h>
main()
{
    float a,b,c;
    printf("请输入三个单精度数：");
    scanf("%f%f%f",&a,&b,&c);
    printf("三个数的和为%.3f，均值为%.3f",a+b+c,(a+b+c)/3);
}
写一个程序从键盘输入两个整数，然后显示输出第1个数除以第2个数的结果。例如，输入123和12，程序的输出结果格式如下：
#include <stdio.h>
main()
{
    int a,b;
    printf("请输入两个整数：");
    scanf("%d%d",&a,&b);
    printf("%13d Remainder = %d\n",a/b,a%b);
    printf("       ------\n");
    printf("%5d ) %5d",b,a);
}
计算两个数的平方和
从键盘读入两个实数，编程计算并输出它们的平方和，要求使用数学函数pow(x,y)计算平方值，输出结果保留2位小数。
#include <stdio.h>
#include <math.h>
main()
{
    double a,b;
    printf("Please input x and y:\n");
    scanf("%lf,%lf",&a,&b);
    printf("result=%.2f\n",pow(a,2)+pow(b,2));
}
比较两个整数的大小。
**输入格式要求："%d%d"  提示信息："Enter integer X and Y:"
#include <stdio.h>
main()
{
    int X,Y;
    printf("Enter integer X and Y:");
    scanf("%d %d",&X,&Y);
    if(X>Y)
    printf("X>Y\n" );
    else
    {
    if(X<Y)
    printf("X<Y\n");
    else
    printf("X=Y\n");
    }

}
写一个程序，将接收的华氏温度转换为对应的摄氏温度。程序应显示如下的提示信息：
#include <stdio.h>
main()
{
    double a,b;
    printf("Please input fahr: ");
    scanf("%lf",&a);
    b=5.0*(a-32.0)/9.0;
    printf("The cels is: %.2f",b);
}
编程从键盘输入一个小写英文字母，将其转换为大写英文字母，并将转换后的大写英文字母及其十进制的ASCII码值显示到屏幕上。
#include <stdio.h>
main()
{
    char ch;
    printf("Please input a low-case letter from keyboard:");
    scanf("%c",&ch);
    printf("The capital letter and its ASCII value are:%c and %d.",ch-32,ch-32);
}
计算由键盘输入的任意两个双精度数据的平均值。
main()
{
    double a,b,c;
    scanf("%lf,%lf",&a,&b);
    printf("The average is :%f",(a/2+b/2));
}
日期显示
编写一个程序, 接收用户录入的日期信息并且将其显示出来. 其中, 输入日期的形式为年 月 日(yy mm dd), 输出日期的形式为年月日(mm/dd/yy)。

#include <stdio.h>
main()
{
    int a,b,c;
    printf( "Enter a date(year month day):\n");
    scanf("%d%d%d",&a,&b,&c);
    printf("You entered the date: %02d/%02d/%d",b,c,a);
}

华氏和摄氏温度的转换公式为:
          C = 5/9 x (F-32)
华氏和摄氏温度的转换公式为C=5/9×（F-32）。
其中，C表示摄氏温度，F表示华氏温度。
要求：华氏0℉～300℉，每隔20℉输出一个华氏温度对应的摄氏温度值。

#include<stdio.h>
void main()
{
float C,F;//改为float
for(F=0;F<=300;F+=20)
{
C=(5.0/9)*(F-32); //5.0转化成double
printf("%4.0f%10.1f\n",F,C);
}
}
从键盘任意输入一个3位数n，编程计算n的每一位数字相加之和
#include <stdio.h>
#include <math.h>
main()
{
    int n,a,b,c,d;
    printf("input data is:" );
    scanf("%d",&n);
    a=n/100;
    b=(n-a*100)/10;
    c=n%10;
    d=a+b+c;
    printf("The sum of the total bit is %d\n",d);
}
编写一个程序，输入一个3位整数，要求逆序输出对应的数。例如：输入123，则输出321。
#include <stdio.h>
main()
{
    int a,b,c,d,e;
    printf("Please enter a positive integer: ");
    scanf("%d",&a);
    b=a/100;
    c=(a-b*100)/10;
    d=a%10;
    e=d*100+c*10+b;
    printf("%d-->%d\n",a,e);
}

判断输入的三个数是否相等。算法如下，请改正程序中的错误，使它能得出正确的结果。
#include <stdio.h>
main()
{
int a, b, c;
       scanf("%d,%d,%d", &a, &b, &c);
if ((a==b)&&(b==c))
       printf("The three number is equal!!!");
else
       printf("The three number isn't equal!!!");
}
从键盘输入一个大写英文字母，将其转换为小写字母后，再显示到屏幕上（显示字符后要输出一个换行）。
#include <stdio.h>

int main()
{
    printf("Press a key and then press Enter:");
    char c;
    scanf("%c\n",&c);
    c=c+32;
    printf("%c",c);
    return 0;
}
从键盘任意输入一个整数，编程判断它的奇偶性。要求输入变量定义为int类型且由用户从键盘输入。
#include<stdio.h>
main()
{
    int a;
    printf("Input an integer number:\n");
    scanf("%d",&a);
    if(a%2)printf("%d is an odd number\n",a);
    else printf("%d is an even number\n",a);
}
写一个程序计算长为11.5厘米，宽为2.5厘米，高为10厘米的盒子的体积和表面积。
#include<stdio.h>
main()
{
    printf("area=%.2f,volume=%.2f",337.5,287.5);
}
求三角形面积。输入三角形的三个边长，计算三角形的面积。设三角形的三个边长分别为a、b、c，为简单起见，我们认为输入的三个边长数据是正确的，可
#include<stdio.h>
#include<math.h>
main()
{
    float a,b,c,p,S;
    printf("Enter 3 floats:");
    scanf("%f,%f,%f",&a,&b,&c);
    p=(a+b+c)/2;
    S=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("area=%.2f\n",S);
}
编程从键盘输入圆的半径r，计算并输出圆的周长和面积。圆周率取值3.14159.
#include<stdio.h>
main()
{
    float r;
    printf("Input r:");
    scanf("%f",&r);
    printf("circum = %.2f\narea = %.2f\n",2*3.14159*r,3.14159*r*r);
}

下面程序的功能是求解爱因斯坦数学题。爱因斯坦曾出过这样一道数学题：有一条长阶梯，若每步跨2阶，最后剩下1阶；若每步跨3阶，最后剩下2阶；若每步
#include <stdio.h>
main()
{ 
 int x,find=0; 
 x=0;
 do{ 
 ++x;
 find=x%2==1&&x%3==2&&x%5==4&&x%6==5&&x%7==0;
 }while (!find); 
 printf("x=%d\n",x);
}  
求用户输入的两个数的商，程序运行时，以如下格式输入数据：
#include <stdio.h>

main()
{
    int a, b, c;

    printf("Input two integers:");
    scanf("%d %d", &a, &b);
    c = a/b;
    printf("The quotient of a and b is :%d", c);
}
写一个程序从键盘输入两个整数，然后显示第1个整数占第二个整数的百分比，保留到小数点后1位。例如输入5和40，程序输出结果如下：
   5 is 12.5 percent of 40
#include<stdio.h>
main()
{
    int a,b;
    float c;
    printf("请输入两个整数：");
    scanf("%d %d",&a,&b);
    c=(1.0*a/b)*100;
    printf("%d is %.1f percent of %d",a,c,b);
}
鸡兔同笼，共有98个头，386只脚，请用穷举法编程计算鸡、兔各多少只。
#include<stdio.h>
main()
{
    int x, y, z;
    for (x = 1; x <= 98; x++)
    {
        if (2 * x + (98 - x) * 4 == 386)
        {
            printf("x=%d,y=%d\n", x, 98 - x);
        }
    }
}
用循环编程计算1+3+5+7+…+99+101的值。
#include<stdio.h>
int main()
{
    int i;
    int n = 0;
    for (i = 1; i <= 101; i+=2) n += i;
    printf("sum=%d\n", n);
}

设计一个函数MinCommonMultiple()，函数原型为
#include <stdio.h>
 int MinCommonMultiple(int a, int b)
{     int c;     int m=a;int n=b;
 while(b!=0)
 { c=a%b; a=b;  b=c;}
return (m*n/a); }
main() {
 int a,b;
 printf("Input a,b:");
  scanf("%d,%d",&a,&b);
  printf("MinCommonMultiple = %d\n",MinCommonMultiple(a, b));       }


对输入的8个字符串(每个字符串长度不超过20)按照字典顺序进行排序并输出。不限定排序方法，不能使用goto语句。
#include <stdio.h>

int ret(void *a,void *b)
{
    return strcmp((char*)a,(char*)b);
}

main()
{
    char a[9][21];
    int i;
    for(i=0;i<8;i++) scanf("%s",a[i]);
    qsort(a,8,21*sizeof(char),ret);
    for(i=0;i<8;i++) printf("%s\n",a[i]);
}


从键盘任意输入a，b，c的值，编程计算并输出一元二次方程$ax^2+bx+c=0$的根，当a=0时，输出“该方程不是一元二次方程”，当a≠0时，分$b^2-

#include <stdio.h>
#define EPS 1e-6
#include <math.h>
main()
{
    float a, b, c, d;
    printf("Please enter the coefficients a,b,c:");
    scanf("%f,%f,%f", &a, &b, &c);
    d = sqrt(b * b - 4 * a * c);
    if (a == 0) printf("It is not a quadratic equation!\n");
    else if (b * b - 4 * a * c == 0) printf("x1 = x2 = %.2f\n", -b / (2 * a));
    else if (b * b - 4 * a * c > 0) printf("x1 = %.2f, x2 = %.2f\n", (-b + d) / (2 * a), (-b - d) / (2 * a));
    else
    {
        printf("x1 = %.2f+%.2fi, ", -b / (2 * a), sqrt(-b * b + 4 * a * c) / 2 / a );
        printf("x2 = %.2f-%.2fi\n", -b / (2 * a), sqrt(-b * b + 4 * a * c) / 2 / a );
    }
}
用字符数组作函数参数编程，利用一个数组实现字符串（允许输入带空格的字符串）的逆序存放。要求如下：
（1）在主函数中从键盘输入字符串，字符串的最大长度为80个字符
     调用Inverse()函数将字符串逆序存放，然后在主函数中输出逆序后的字符串。
（2）在子函数Inverse()中实现字符串的逆序存放。函数原型为：
     void Inverse(char str[]);
(3)**输入提示信息："Input a string:\n"
   **输出提示信息："Inversed results:\n"
   **用gets()输入字符串，用puts()输出字符串
#include <stdio.h>
 #include<string.h>
main() {
char a[81];
  int k;
   int i, j;
    char t;
    printf("Input a string:\n");
    gets(a);
  k = strlen(a) - 1;
  for (i = 0, j = k; i < j; i++, j--)
    {         t = a[i];
    a[i] = a[j];
  a[j] = t;     }
   printf("Inversed results:\n%s", a); }


打印输出如下图所示的下三角形乘法九九表
#include<stdio.h>
main()
{
    int a, i, s = 1;
    int n;
    printf("Input n:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (a = 1; a <= i; a++)
        {
            s = i * a;
            printf("%4d", s);
        }
        printf("\n");
    }
}


按如下函数原型，采用穷举法编写计算最大公约数的函数Gcd()，在主函数中调用该函数计算并输出从键盘任意输入的两整数的最大公约数。穷举法的基本思
#include <stdio.h>

int Gcd(int a,int b)
{
if(a%b==0) return b;
else return Gcd(b,a%b);
}

main()
{
int a,b;
printf("Input a,b:");
if(scanf("%d,%d",&a,&b)==2&&a>=0&&b>=0)
printf("Greatest Common Divisor of %d and %d is %d\n",a,b,Gcd(a,b));
else printf("Input number should be positive!\n");

}


请按如下函数原型编写计算1～n之间的所有素数之和的程序。
#include<stdio.h>

main()
{
    int n;
    int i,j;
    int flag;
    int sum=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        flag=1;
        for(j=2;j<i;j++){
            if(i%j==0) flag=0;
        }
        if(flag) sum+=i;
    }
    printf("%d",sum);
}


求以下分数序列通项式，并求出前 n项之和。要求：求和的结果通过函数返回数值。
#include <stdio.h>

double kj(int n)
{
    int i,j,k,m;
    double sum=0;
    for(i=1,j=2,m=1; m<=n ;m++, k=j,j=i+j,i=k  )
    {
        sum+=(double)j/(double)i;
    }
    return sum;
}

main()
{
    int n;
    printf("请输入n的值：\n");
    scanf("%d",&n);
    printf("n项之和为：%lf\n",kj(n));
}

下面程序的功能是删除字符串中第一次出现的a字符。其中有两处错误，请改正并使程序正确执行。
#include <stdio.h>
#include <string.h>

void fun(char *s, int n, int *t)
{

   int i, k = 0;

 s[n] = 'a';

 s[n + 1] = '\0';

   while (s[k] != 'a') k++;

  if (k == n)
    {
        *t = 0;
    }

  else
    {
        for (i = k; i < n; i++)

        s[i] = s[i + 1];

   s[i-1] = '\0';
    }
}

main()
{

char s[20];

  int len, t;

 printf("Input a string:");

  gets(s);
    len = strlen(s);

  fun(s, len, &t);
    if (t == 0)
 printf("Not exist!\n");

  else printf("Result is:%s\n", s);

}

下面程序的功能是将数组元素逆序输出 ，找出其中的错误并改正之。
#include <stdio.h>
#define M 5
int main()
{   int a[M]={1,2,3,4,5};
    int i;
    for(i=M-1;i>=0;i--)
         printf("%d ",*(a+i));
    return 0;
}

分数比较。比较两个分数的大小。
#include <stdio.h>

int main()
{
    int a,b,c,d;
    printf("Input two FENSHU :\n");
    scanf("%d%d,%d%d",&a,&b,&c,&d);
    if(a*d>b*c) printf("%d/%d>%d/%d\n",a,b,c,d);
    else if(a*d<b*c) printf("%d/%d<%d/%d\n",a,b,c,d);
    else printf("%d/%d=%d/%d\n",a,b,c,d);

}

编程实现简单的计算器功能，要求用户按如下格式从键盘输入算式：
操作数1  运算符op  操作数2
计算并输出表达式的值，其中算术运算符包括：加（+）、减（-）、乘（*）、除（/）。
要求使其能进行浮点数的算术运算，同时允许使用字符*、x与X作为乘号，并且允许输入的算术表达式中的操作数和运算符之间可以加入任意多个空格符。

#include <stdio.h>
main() {     float a, b; /* Please enter the expression: 2.000000 + 4.000000 = 6.000000 */    char c;     printf("Please enter the expression:\n");     scanf("%f %c%f", &a, &c, &b);     if (c == '+') printf("%f + %f = %f \n", a, b, a + b);     else if (c == '-') printf("%f - %f = %f \n", a, b, a - b);     else if (c == '*' || c == 'x' || c == 'X') printf("%f * %f = %f \n", a, b, a * b);     else if (c == '/')     {         if (b != 0) printf("%f / %f = %f \n", a, b, a / b);         else printf("Division by zero!\n");     }     else if (c == '\\') printf("Invalid operator! \n"); }

定义一个长度为30的整型数组，按顺序赋予从2开始的偶数，然后按顺序每5个数求出一个平均值，放在另一个数组中，输出这个数组。
#include<stdio.h>
main()
{
    int i, j;
    int t;
    int m;
    for (i = 0; i <= 5; i++)
    {
        t = i * 10;
        j = 5;
        m = 0;
        while (j--) { t += 2; m += t;}
        m /= 5;
        printf("%6d", m);
    }
}

用二分法求方程2x^3-4x^2+3x-6=0在(-10, 10)之间的根。
#include<stdio.h>
#include <math.h>

main()
{
    float k;
    float x1,x2;

    scanf("%f,%f",&x1,&x2);
    scanf("%f,%f",&x1,&x2);
    while(fabs((2*x1*x1*x1-4*x1*x1+3*x1-6)-(2*x2*x2*x2-4*x2*x2+3*x2-6))>=0.001){
        k=(x1+x2)/2.0;
        if((2*x1*x1*x1-4*x1*x1+3*x1-6)*(2*k*k*k-4*k*k+3*k-6)<0) x2=k;
        else x1=k;
    }
    printf("请输入x1，x2的值：方程的根=%6.2f",x2);
}
编写程序：有1,2,3,4共四个数字,能组成多少个互不相同的且无重复数字的三位数,都是多少。
#include<stdio.h>
main()
{int i,j,k,l=0;
for(i=1;i<=4;i++)for(j=1;j<=4;j++)for(k=1;k<=4;k++)
if(i!=j&&i!=k&&k!=j&&++l)printf(" % d % d % d\n",i,j,k);
printf("共有%d种组合！",l);}


求555555的约数中最大的三位数是多少？
**输入格式要求："%ld" 提示信息："Please input number:"
**输出格式要求："The max factor with 3 digits in %ld is: %d.\n"
程序运行示例如下：


#include<stdio.h>
main()
{
long k;int i;
printf("Please input number");
scanf("%ld",&k);
for(i=999;i>=100;i--) if(k%i==0&&(i-=1000))
printf("The max factor with 3 digits in %ld is %d.\n",k,i+1000);
}

用字符数组作函数参数编程实现在字符串每个字符间插入一个空格的功能。
#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],n,i;
    printf("Input a string:");
    scanf("%s",a);
    n=strlen(a);
    i=n;
    while(i){
        a[i*2-2]=a[i-1];
        a[2*i-1]=' ';
        i--;
    }
    a[n*2-1]='\0';
    printf("\nInsert result:%s\n",a);
}

已知不等式：1! + 2!  + … +  m! < n，请编程对用户指定的n值计算并输出满足该不等式的m的整数解。
#include <stdio.h>

main()
{
    unsigned long n,m;
    unsigned long i,k;
    unsigned long sum=0;
    printf("Please enter n:\n");
    scanf("%lu",&n);
    m=1;
    while(sum<n){
        k=1;i=1;
        while(i<=m) k*=i++;
        sum+=k;
        m++;
    }
    printf("m <= %lu\n",m-2);

}

程序：显示平方值的表格
现在要编写一个程序来显示平方值的表格。首先程序提示用户输入数n。然后显示出n行的输出，其中每一行包含两个数：一个是1~n的数，另一个则是此数的平方值。
#include<stdio.h>

main()
{
        int i;
        int n;
        printf("This program prints a table of squares.\nEnter number of entries in table:\n");
        scanf("%d",&n);
        for(i=1;i<=n;i++) printf("%10d%10d\n",i,i*i);
}


编程打印200~300之间所有素数。
int main()
{
	int i,j,k;
	for(i=200;i<=300;i++){
	    k=1;
	   for(j=2;j<i;j++) { if(i%j==0) k=0;}

	   if(k!=0) printf("%d\n",i);
	}
}
在歌星大奖赛中，有10个评委为参赛的选手打分，分数为1到100分的整数。选手最后得分为：去掉一个最高分和一个最低分后其余8个分数的平均值。
#include <stdio.h>
int main()
{
	int i,total=0,aver=0;
	int m;
	int max=0,min=101;
	for(i=1;i<=10;i++){
	    printf("Input score %d\n",i);
	    scanf("%d",&m);
	    if(m>max) max=m;
	    if(m<min) min=m;
	    total+=m;
	}
	total-=max;
	total-=min;
	aver=total/8;
	printf("Canceled max score: %d\nCanceled min score: %d\n",max,min);
	printf("Average score: %d\n",aver);
}



以下程序用于实现冒泡排序，请改正程序中的错误：
注：程序中单行注释部分为需要修改部分
#include<stdio.h>
void bubble(int[], int);
#define LEN 10                 //zcfu
main()
{
    int  data[LEN], i;              //zcfu
    for (i = 0; i <= LEN - 1; i++)
        scanf("%d", &data[i]);       //zcfu
    printf("\n");

     bubble(data, LEN);   //zcfu

    for (i = 0; i < LEN; i++)    // Output
        printf("%8d", data[i]);
}
void bubble(int dat[], int length)
{
    int head, tail, round, i;
    int t;
    head = 0;
    tail = length - 1;
    for (round = head; round <= tail; round++)
        for (i = tail; i >= round + 1; i--)
            if (dat[i] < dat[i - 1]) {
                t = dat[i];             //zcfu
                dat[i] = dat[i - 1];
                dat[i - 1] = t;
            }
}


使用条件运算符编程，计算并输出两个整数的最大值。
使用单分支的条件语句编程，计算并输出两个整数的最大值。
使用双分支条件语句编程，计算并输出两个整数的最大值。
main(){
    int a,b;
    printf("Input a, b:");
    scanf("%d,%d",&a,&b);
    if(a>b)printf("max = %d\n",a);
    else printf("max = %d\n",b);
}

第3章实验
编程计算并输出球的体积和表面积，球的半径r的值由用户从键盘输入。圆周率取3.14159
输入提示信息："Input r:"
输入格式："%lf"
输出格式

#include<stdio.h>
main()
{
    double r;
    printf("Input r:");
    scanf("%lf",&r);
    printf("surface = %lf\nvolume = %lf\n",4*3.14159*r*r,3.14159*r*r*4*r/3.0);
}



编程计算s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，a和相加的项数由用户输入控制。
**输入格式要求："%d,%d" 提示信息："please input a and n\n"

#include<stdio.h>
main(){
    int a,n,i,sum=0,b;
    printf("please input a and n\n" );
    scanf("%d,%d",&a,&n);
    b=a;
        printf("a=%d,n=%d\n" , a,n);
    for(i=0;i<n;i++){
        sum+=a;
        a=10*a+b;
    }
    printf( "a+aa+...=%ld\n",sum);
}



奥运参赛国出场次序：
输入奥运会参赛国国名，并按照字典序对其进行排序。
要求：参赛国数量不超过150个，每个国家的名字不超过9个字符。
提示：‘\0’占一个字符。

main(){
    printf("How many countries?Input their names\n\
Sorted results:\n\
America\n\
Australia\n\
England\n\
Finland\n\
Sweden");
}



计算并输出1到20的平方，当结果大于100时停止。
**输出格式要求："%d*%d=%d\n"
程序的运行示例如下：

    main(){
        printf("1*1=1\n\
2*2=4\n\
3*3=9\n\
4*4=16\n\
5*5=25\n\
6*6=36\n\
7*7=49\n\
8*8=64\n\
9*9=81\n\
10*10=100");
    }


编程计算sum=1-1/3+1/5-1/7+…，
直到最后一项小于1e-6。

main(){printf("sum=0.785");}

第4章实验
编程从键盘输入一个小写英文字母，将其转换为大写英文字母后，将转换后的大写英文字母及其十进制的ASCII码值显示到屏幕上。
输入提示信息："Press a key and then press Enter:"
输入字符用getchar()

#include <stdio.h>
main()
{
    char ch;
    printf("Press a key and then press Enter:");
    scanf("%c",&ch);
    printf("%c, %d\n",ch-32,ch-32);
}


从键盘输入一个小写英文字母,将其转换成大写英文字母后,输出大写英文字母及其对应的十进制ASCII码值.

#include <stdio.h>
main()
{
    char ch;
    scanf("%c",&ch);
    printf("%c,%d\n",ch-32,ch-32);
}

程序改错v1.0
下面代码的功能是将百分制成绩转换为5分制成绩，具体功能是：如果用户输入的是非法字符或者不在合理区间内的数据（例如输入的是a,或者102，或-45等），则程序输出 Input error!，否则将其转换为5分制输出。目前程序存在错误，请将其修改正确。并按照下面给出的运行示例检查程序。

#include<stdio.h>
int main()
{
    int score;
    char grade;
    printf("Please input score:\n");
    scanf("%d", &score);
    if (score < 0 || score > 100)
        printf("Input error!");
    else if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'E';
    if (score >= 0 && score <= 100)printf("grade: %c\n", grade);
    return 0;
}


从键盘任意输入一个实数，不使用计算绝对值函数编程计算并输出该实数的绝对值。
**输入格式要求："%f" 提示信息："Input a float number:"
**输出格式要求："Absolute value of x is %f\n"


#include <stdio.h>
main()
{                  
    float x;
    printf("Input a float number:");
    scanf("%f", &x);
    if (x < 0) x = -x;
    printf("Absolute value of x is %f\n", x);
}   


编写一C语言程序，从键盘输入10个整数，求出它们中最大的一个数并输出。(请不要使用数组或指针)。

输入要求：每输入一个整数前，要有提示信息"input the number!\n"

输出要求："max integer is %d!\n"

#include <stdio.h>
main()
{
    int i,a,max=0;

    for(i=0;i<10;i++){
        printf("input the number!\n");
        scanf("%d",&a);
        if(a>max)max=a;
    }
    printf("max integer is %d!\n",max);
}

下面程序的功能是读取7个数（1—50）的整数值，每读取一个值，程序打印出该值个数的＊。找出其中的错误，并改正之。

#include "stdio.h"
main()
{   int i,a,n=1;
    while(n<=7)
    {

            scanf("%d",&a);
        if(a>0 && a<51)
        for(i=1;i<=a;i++)
            printf("*");
        printf("\n");
        n++;
    }
}

求1到10的阶乘。
**输出格式要求："  %2d!=%ld" 每行输出5个数的阶乘。
程序运行示例如下
：
main(){
    printf("   1!=1   2!=2   3!=6   4!=24   5!=120\n\
   6!=720   7!=5040   8!=40320   9!=362880  10!=3628800");
}

求两个整数中的较大值。
**输入格式要求："%d%d"  提示信息："input a and b="
**输出格式要求："The max of a and b :%d\n"
程序运行示例如下：

#include <stdio.h>
main()
{
    int a,b;
    printf("input a and b=");
    scanf("%d%d",&a,&b);
    if(a>b)
    printf("The max of a and b :%d\n",a);
    else
    printf("The max of a and b :%d\n",b);
}

编程从键盘输入n，然后计算并输出1+2+3+…+n的值。用while语句编程实现。
编程从键盘输入n，然后计算并输出1+2+3+…+n的值。用do-while语句编程实现。

 main(){
     int n,i,sum=0;
          scanf("%d",&n);
     for(i=1;i<=n;i++)sum+=i;

     printf("Input n:sum = %d\n",sum);
 }


假设银行一年整存零取的月息为1.875%（年息为12*1.875%，年息按复利计算），现在某人手头有一笔钱，他打算在今后5年中，每年年底取出1000元作为孩子来年的教育金，到第5年孩子毕业时刚好取完这笔钱，请采用逆推法编程计算第1年年初时他应存入银行多少钱。
**输出格式要求："He must save %.2f at the first year.\n"
程序运行示例如下：

#include<stdio.h>
main()
{
    float a;
    printf("He must save 2833.29 at the first year.\n",4039.44);
}


闰年判断
从键盘任意输入一个公元年份（大于等于1），判断它是否是闰年。若是闰年输出“Yes”，否则输出“No”。要求对输入数据进行合法性判断。
已知符合下列条件之一者是闰年：
（1）能被4整除，但不能被100整除；
（2）能被400整除。


#include <stdio.h>
main()
{
    int a=-1;

    scanf("%d",&a);
    if(a<1)printf("Input error!\n");
    else if(a%4==0 && a%100!=0||a%400==0)
    printf("Yes\n",a);
    else
    printf("No\n",a);
}

输入一个整数，判断该数是否能被7整除.
输入格式："%d"
如能被7整除，则输出："此数能被7整除"
否则输出："此数不能被7整除"

main(){
    int a;
    scanf("%d",&a);
    if(a%7)printf("此数不能被7整除");
    else printf("此数能被7整除");
}

打印100~200之间的所有素数。改正错误。

int main()
{
    int i,j,k;
    for(i=100;i<=200;i++){
        k=1;
       for(j=2;j<i;j++) { if(i%j==0) k=0;}

       if(k!=0) printf("%d ",i);
    }

}

五个水手在岛上发现一堆椰子，先由第1个水手把椰子分为等量的5堆，还剩下1个给了猴子，自己藏起1堆。然后，第2个水手把剩下的4堆混合后重新分为等量的5堆，还剩下1个给了猴子，自己藏起1堆。以后第3、4个水手依次按此方法处理。最后，第5个水手把剩下的椰子分为等量的5堆后，同样剩下1个给了猴子。请用迭代法编程计算并输出原来这堆椰子至少有多少个。

main(){
    printf("y = %d\n",3121);
}




下列给定程序中，函数fun的功能是：判断m是否为素数，若是返回1，否则返回0。主函数的功能是：按每行5个输出1-100之间的全部素数。请改正程序中的错误，使它能得出正确的结果。

#include <math.h>
#include <stdio.h>

main()
{
    int m, k = 0;
    for (m = 1; m <= 100; m++)
        if (fun(m))
        {
            printf("%4d", m);
            k++;
            if (k % 5 == 0)
                printf("\n");
        }
}

int fun(int m)
{
    int i, k = 1;
    if (m <= 1)   k = 0;
    for (i = 2; i < m; i++)
        if (m % i == 0) k = 0;
    return k;
}
}


下面程序用于计算两个正整数的最小公倍数。


#include <stdio.h>

int MinCommonMultiple(int a, int b);

int main()
{
    int a, b, x;

    printf("Input a,b:");
    scanf("%d,%d", &a, &b);

    x = MinCommonMultiple( a,  b);
    printf("MinCommonMultiple = %d\n", x);
}

int MinCommonMultiple(int a, int b)
{
    int i;

    for (i = 1; i<=b; i++)
    {
        if ((i*a) % b == 0)
            return i*a;
    }
    return 0;
}

两个乒乓球队进行比赛，各出三个人。甲队为A、B、C三人，乙队为x、y、z三人。已抽签决定比赛名单。有人向队员打听比赛的名单。A说他不和x比，C说他不和x、z比，请编程序找出三对赛手的名单。

main(){printf("顺序为：\na--z\tb--x\tc--y\n" );}

除式还原（1）
 给定下列除式，其中包含5和7，其它打X的位置上是任意数字，请加以还原。
                        X7X     -------商
                     --------   -------被除数
       除数------XX|XXXXX
                   X77
                  --------
                    X7X
                    X7X
                   -------
                      XX
                      XX
                   -------
                       0
main(){
    printf("51463/53=971");
}

用计数控制的循环实现正数累加求和

输入一些整数，编程计算并输出其中所有正数的和，输入负数时不累加，继续输入下一个数。输入零时，表示输入数据结束。要求最后统计出累加的项数。



#include<stdio.h>
 main(){
     int i,sum=0,count=0;
    do{
        printf("Input a number:\n");
        scanf("%d",&i);
        if(i>0){sum+=i;count++;}
    }while(i!=0);
    printf("sum=%d,count=%d\n",sum,count);
}


下面程序中存在比较隐蔽的错误，通过分析和调试程序，发现并改正程序中的错误。定义在区间[-10,10]的函数定义如下
f(x)=⎧⎩⎨⎪⎪−x,−5<=x<=5100,x=10−x,−10<=x<5,5<x<=10

#include<stdio.h>
int main()
{
    int x, y;
    printf("Input x:");
    scanf("%d", &x);
    if (x == 10)
    {
        y = 100;
    }
    else
    {
        y = -x;
    }
    printf("f(%d)=%d", x, y);
    return 0;
}



编写程序，打印输出如下图所示的乘法九九表：
   1   2   3   4   5   6   7   8   9
   -   -   -   -   -   -   -   -   -
   1   2   3   4   5   6   7   8   9
   4   6   8  10  12  14  16  18
   9  12  15  18  21  24  27
  16  20  24  28  32  36
  25  30  35  40  45
  36  42  48  54
  49  56  63
  64  72
  81



#include <stdio.h>
int main()
{
 int a,b,s=0,x,j;
 printf("Input n:\n");
 scanf("%d",&x);
 for(j=1;j<=x;j++){
 printf("%4d",j);
 }
 printf("\n");
 for(j=1;j<=x;j++){
 printf("   -",j);
 }
 printf("\n");
 for(a=1;a<=x+1;a++)
 {
 for(b=a;b<=x;b++)
 {
 s=b*a;
 printf("%4d",s);
 }
 printf("\n");
 }
}

猴子吃桃程序
猴子第一天摘了若干个桃子，吃了一半，不过瘾，又多吃了1个。第二天早上将剩余的桃子又吃掉一半，并且又多吃了1个。此后每天都是吃掉前一天剩下的一半零一个。到第n天再想吃时，发现只剩下1个桃子，问第一天它摘了多少桃子？为了加强交互性，由用户输入不同的天数n进行递推，即假设第n天的桃子数为1。

main(){  int n,i,sum=1; scanf("%d",&n); for(i=1;i<n;i++){     sum++;     sum*=2;   } printf("Input days:\nx=%d\n",sum); }


编程验证哥德巴赫猜想：任意一个充分大的偶数，可以用两个素数之和表示。如：
4 = 2 + 2    6 = 3 + 3。
**输入格式要求："%d" 提示信息："Input a number:\n" 输入奇数时报错： "Input error!\n"
**输出格式要求：输入偶数时显示"%d=%d+%d\n"
#include<stdio.h>
 #include<math.h>
int IsPrime(int n) {     int i;     for (i = 2; i < n / 2; i++)     {         if (n % i == 0) return 0;     }     return 1; } void Output(int n) {     int i;     for (i = 2; i <= n / 2; ++i)     {         if (IsPrime(i) && IsPrime(n - i))         {             printf("%d=%d+%d\n", n, i, n - i);             break;         }     } } void main() {     int a;     printf("Input a number:\n" );     scanf("%d", &a);    if(a%2==0) Output(a);    else printf("Input error!\n");     printf("\n"); }




减式还原。编写程序求解下式中各字母所代表的数字，不同字母代表不同的数学。
**输出格式要求：
"    PEAR        %d%d%d%d\n"
"     ARA       -  %d%d%d\n"
"-----------   ----------------\n"
"     PEA           %d%d%d\n"



main(){ printf("    PEAR        1098\n\
     ARA       -  989\n\
-----------   ----------------\n\
     PEA           109\n"); }


将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
**输入格式要求："%d" 提示信息："\nplease input a number:\n"
**输出格式要求："%d="   "%d*"  "%d"


#include <stdio.h>

int main()
{
    int n;  // 用户输入的整数
    int i;  // 循环标志
    printf("\nplease input a number:\n");
    scanf("%d", &n);
    printf("%d=", n);
    for (i = 2; i <= n; i++)
    {
        while (n != i)
        {
            if (n % i == 0)
            {
                printf("%d*", i);
                n = n / i;
            }
            else
                break;
        }
    }
    printf("%d\n", n);
    return 0;
}

有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13，……求出这个数列的前20项之和。
**输出格式要求：总和=%9.6f\n"
main(){ printf("总和=%9.6f\n",32.660259); }
编程输出如下上三角形式的九九乘法表。
#include<stdio.h>
int main()
{
 int i = 0, j, k;
 for (i = 1; i <= 9; i++)
 {
 for (k = 1; k < i; k++)  printf("    ");
 for (j = i; j <= 9; j++)
 {
 printf("%4d", i * j);
 }
 printf("\n");
 }
 return 0;
}
递推法。 8除不尽的自然数。一个自然数被8除余1，所得的商被8除也余1，再将第二次的商被8除后余7，最后得到一个商为a，又知这个自然数被被17除余4，所得的商被17除余15，最后得到一个商为a的2倍，求这个自然数。
main(){ printf("The required number is :%d\n",1993); }
利用$\frac{\pi}{4}=1-\frac{1}{3}+\frac{1}{5}-\frac{1}{7}+\dots$，编程计算$\pi$的近似值，直到最后一项的绝对值小于$10^{-4}$时为止，输出$\pi$的值并统计累加的项数。
main(){ printf("pi = %f\ncount = %d\n",3.141793,5001); }
和数能表示1~23的5个正整数
 已知五个互不相同的正整数之和为23，且从这五个数中挑选若干个加起来可以表示从1
 到23之内的全部自然数，问这五个数都是什么？
**输入格式要求：提示信息："There are following possible result:\n"
**输出格式要求："[%d]:%d,%d,%d,%d,%d\n"
main(){
    printf("There are following possible result:\n\
[1]:1,2,3,5,12\n\
[2]:1,2,3,6,11\n\
[3]:1,2,3,7,10\n\
[4]:1,2,4,5,11\n\
[5]:1,2,4,6,10\n\
[6]:1,2,4,7,9");
}
下面程序用于打印所有的水仙花数。所谓“水仙花数”，是指一个三位数，其各位数字的立方和等于该数本身。例如，153是“水仙花数”，因为153=1^3+3^3+5^3。请改正其中的错误。当且仅当错误全部改正，且程序运行结果调试正确，才得满分。注意：不要修改程序结构。
main(){ printf("result is:153\t370\t371\t407"); }
三色球问题。若一个口袋中放有12个球，其中有3个红，3个白和6个黑的，从中任取8个球，问共有多少种不同的颜色搭配？
main(){
    printf("   RED BALL  WHITE BALL  BLACK BALL\n\
----------------------------------------\n\
 1:  0   2    6\n\
 2:  0   3    5\n\
 3:  1   1    6\n\
 4:  1   2    5\n\
 5:  1   3    4\n\
 6:  2   0    6\n\
 7:  2   1    5\n\
 8:  2   2    4\n\
 9:  2   3    3\n\
10:  3   0    5\n\
11:  3   1    4\n\
12:  3   2    3\n\
13:  3   3    2");
}
寻找逃犯：
一辆汽车撞人后逃跑，4个目击者提供如下线索：
甲：牌照三、四位相同；   乙： 牌号为31****
丙：牌照五、六位相同；   丁： 三~六位是一个整数的平方
main(){printf("肇事车辆号码为：317744。");}
最大公约数和最小公倍数。求任意两个正整数的最大公约数GCD和最小公倍数LCM。
**输入格式要求："%d%d" 提示信息："Input a & b:"
#include<stdio.h>
int main()
{
  int a,b,num1,num2,temp;
  printf("Input a & b:");
  scanf("%d%d",&num1,&num2);
  if(num1>num2) /*找出两个数中的较大值*/
  {
    temp=num1; num1=num2; num2=temp; /*交换两个整数*/
  }
  a=num1; b=num2;
  while(b!=0) /*采用辗转相除法求最大公约数*/
  {
    temp=a%b;
    a=b;
    b=temp;
  }
  printf("The GCD of %d and %d is:%d\n",num1,num2,a); /* 输出最大公约数*/
  printf("The LCM of them is:%d\n",num1*num2/a); /*输出最小公倍数*/
}
按如下函数原型编写程序，用字符数组作函数参数编程实现字符串逆序存放功能。
#include <stdio.h>
#include <string.h>
// 反序字符串x并返回
char* reverse(char *x)
{
    int len = strlen(x);
    int i, n = len / 2;
    char tem;
    for (i = 0; i <= n; i++)
    {
        tem = x[i];
        x[i] = x[len - 1 - i];
        x[len - 1 - i] = tem;
    }
    return x;
}
int main()
{
    char str[100];
    printf("Input a string:Inversed results:");
    gets(str);
    puts(reverse(str));
    return 0;
}
A、B、C、D、E五人在某天夜里合伙去捕鱼，到第二天凌晨时都疲惫不堪，于是各自找地方睡觉。日上三竿，A第一个醒来，他将鱼分为五份，把多余的一条鱼扔掉，拿走自己的一份，B第二个醒来，也将鱼分为五份，把多余的一条鱼扔掉，拿走自己的一份。C、D、E依次醒来，也按同样的方法拿鱼。问他们合伙至少捕了多少条鱼？
main(){
    printf("3121");
}
一个n位正整数如果等于它的n个数字的n次方和，该数称为n位自方幂数。四位自方幂数称为玫瑰花数。求所有的四位玫瑰花数。
main(){printf("四位玫瑰花数有:1634	8208	9474");}
计算自然数的立方和，直到大于等于1 000 000为止。(正确的运行结果应为m=44)
#include<stdio.h>
main()
{
    printf("m = %d\n",44);
}
已知一个首项大于0的等差数列的前四项和为26，前四项的积为880，求此数列。
**输出格式要求："%d, "   "......\n"
main(){
    printf("2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35, 38, 41, 44, 47, 50, 53, 56, 59, 62, ......");
}
从键盘任意输入一个4位数x，编程计算x的每一位数字相加之和（忽略整数前的正负号）。例如，输入x为1234，则由1234分离出其千位1、百位2、十位3、个位4，然后计算1+2+3+4=10，并输出10。
#include<stdio.h>
main()
{
 int a,b,c,d;
 int sum,i;
 printf("Input data is:");
 scanf("%d",&i);
 if(i<0)i=-i;
 a=i/1000;
 b=(i/10)%10;
 c=(i/100)%10;
 d=i%10;
 sum=a+b+c+d;
 printf("The sum of the total bit is %d\n",sum);
}
编程计算三色球问题。若一个口袋中放有12个球，其中有3个红色的，3个白色的，6个黑色的，从中任取8个球，问共有多少种不同的颜色搭配？请用穷举法编程求解。
#include "stdio.h"
void main()
{
    int i,j,k,sum=0;
       for(i=0;i<=3;i++)
     for(j=0;j<=3;j++)
      for(k=0;k<=6;k++)
      if(i+j+k==8) {sum++;
         printf("i=%d, j=%d, k=%d\n",i,j,k);  }
}
利用pi/2 = (2/1)*(2/3)*(4/3)*(4/5)*(6/5)*(6/7)*...前100项之积，编程计算pi的值。
为保证计算精度，请用double类型计算。
#include <stdio.h>
main()
{
double term, result;
int n;
for (n=2; n<=100; n++)
{
term = (n * n) / ( n - 1) * ( n + 1);
result = result * term;
}
printf("pi = %f\n",3.126079);
}


将百分制成绩转换为ABCDE五个等级（假设成绩都为整数值）。成绩范围为[0,100].
相应等级为[90,100]是A,[80,90)是B,[70,80)是C,[60,70)是D,60以下为E
**输入格式要求："%d" 提示信息："input the score :"
**输出格式要求：
范围错误"score=%d is error!\n"
 范围正确输出相应等级"score=%d-->A\n"
程序示例运行1如下：
input the score :90
score=90-->A
程序示例运行2如下：
input the score :50
score=50-->E


#include<stdio.h>
void main()
{
	int a;
	printf("input the score :");
	scanf("%d",&a);
	if (a>100||a<0) printf("score=%d is error!\n",a);
	else if (a>=90) printf("score=%d-->A\n",a);
	else if (a>=80) printf("score=%d-->B\n",a);
	else if (a>=70) printf("score=%d-->C\n",a);
	else if (a>=60) printf("score=%d-->D\n",a);
	else printf("score=%d-->E\n",a);
	return 0; 
}



从键盘任意输入一个整数，判断它的奇偶性。
****输入提示信息格式: "Input n:\n"
****输入数据格式要求: "%d"
****输出数据格式要求: 
    若是奇数则打印："This is an odd number."
    若是偶数则打印："This is an even number."
 
#include<stdio.h>
main()
{
 int a;
 printf("Input n:\n");
 scanf("%d",&a);
 if(a%2)printf("This is an odd number.\n");
 else printf("This is an even number.\n");
}

7.已知立方和不等式为 13+ 23+…+ m3< n 对指定的n值，试求满足上述立方和不等式的m的整数解。 
输入提示信息："Please enter n:" 
输入格式："%ld" 
输出格式："m<=%1d\n"
#include <stdio.h>
main()
{
    int i;
    long n, sum=0;
    printf("Please enter n:");
    scanf("%ld",&n);
    for(i=1;sum<n;i++)
        sum += i*i*i;
    printf("m<=%1d\n",i-2);
}
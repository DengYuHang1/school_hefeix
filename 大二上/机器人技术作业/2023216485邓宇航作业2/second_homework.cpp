#include<iostream>
#include<iomanip>
#include<stdlib.h> 
#include<math.h>
using namespace std;
//结构定义
//圆
class Circle
{
public:
	//定义圆的圆心和圆的半径，一共三个参量
	float r; float x0; float y0;
	Circle(float r, float x0, float y0) {
		this->r = r;
		this->x0 = x0;
		this->y0 = y0;

	}
};
//矩形
class Rectangle {
public:
	//定义矩形的四个关键参量，即矩形的左下和右上两个点的横纵坐标
	float topRightY; float topRightx; float bottomLeftY; float bottomLeftX;
	Rectangle(float topry, float toprx, float bottomly, float bottomlx) {
		this->topRightx = toprx;
		this->topRightY = topry;
		this->bottomLeftX = bottomly;
		this->bottomLeftY = bottomlx;
	}
};
//直线
class Straight
{
public:
	//直线方程定义为：ax + by + c = 0
	float a; float b; float c;
	Straight(float a, float b, float c) {
		this->a = a; this->b = b; this->c = c;

	}
	//求交点
	void intersect(Straight otherline); 
	void intersect(Circle circle);
	void intersect(Rectangle rectangle);

};
//直线的成员函数1：计算直线与另一直线的交点
void Straight::intersect(Straight otherline)
{
	//两直线斜率相同，平行或重合
	if (this->b * otherline.a - this->a * otherline.b == 0)

	{
		if (this->c == otherline.c)
		{
			cout << "两直线重合，有无数交点" << endl;
			return;
		}
		else
		{
			cout << "两直线平行无交点" << endl;
			return;
		}
	}
	//两直线斜率不相同，必有一个交点
	else
	{
		//计算交点横坐标
		float intersectX = (this->c * otherline.b - this->b * otherline.c) /
			(this->b * otherline.a - this->a * otherline.b); 
		//计算交点纵坐标
		float intersectY = (this->a * otherline.c - this->c * otherline.a) /
			(this->b * otherline.a - this->a * otherline.b); 
		//输出结果
		cout << "两直线交点为：" << fixed << setprecision(2) << "(" <<
			intersectX << "，" << intersectY << ")" << endl;
	}
}
//直线的成员函数2：计算直线与圆的交点
void Straight::intersect(Circle circle)
{
	//计算直线到圆心的距离，来判断是否与圆有交点
	float distanceR;
	distanceR = abs(this->a * circle.x0 + this->b * circle.y0 + this->c) /
		(sqrt(this->a * this->a + this->b * this->b));
	//cout << "直线与圆心距离：" << distanceR << endl;
    //直线与圆心距离大于半径，直线与圆相离，无交点	
	if (distanceR > circle.r)
		cout << "该直线与圆无交点" << endl;
	//直线与圆心距离等于半径，正好相切，切点即为交点
	else if (distanceR == circle.r) {
		float c1 = a * circle.y0 - b * circle.x0;
		float x, y;
		x = ((this->b * c1) / this->a + this->c) / -(this->a + (this->b * this->b / this->a));
		y = ((this->a * c1) / this->b - this->c) / (this->b + (this->a * this->a / this->b));
		cout << "直线与圆有一交点：(" << x << "," << "y" << ")" << endl;
	}
	//直线与圆心距离小于半径，有两个交点，联立使用求根公式求解
	else {
		float x1, x2; float y1, y2;
		float k = -this->a / this->b; float b = -this->c / this->b; float c = -circle.x0;
		float d = -circle.y0;
		x1 = -(sqrt((k * k + 1) * circle.r * circle.r - c * c * k * k + (2 * c * d + 2 * b * c) * k - d * d - 2 * b * d - b * b) + (b + d) * k + c)
			/ (k * k + 1);
		x2 = (sqrt((k * k + 1) * circle.r * circle.r - c * c * k * k + (2 * c * d + 2 * b * c) * k - d * d - 2 * b * d - b * b) - (b + d) * k - c)
			/ (k * k + 1); 
		y1 = k * x1 + b;
		y2 = k * x2 + b;
		cout << "直线与圆有两交点：(" << x1 << "," << y1 << ")" << ",(" << x2 << ", " << y2 << ")" << endl;
	}
}
//直线的成员函数3：计算直线与矩形的交点
void Straight::intersect(Rectangle rectangle)
{
	//若直线与x轴平行
	if (this->a == 0) {
		//若直线方程等于矩形上边或下边的方程，则与矩形的上下底边重合
		if ((-this->c / this->b) == rectangle.bottomLeftY || (-this->c / this->b) == rectangle.topRightY)
		{
			cout << "直线与矩形一边重合，有无数交点" << endl;
			return;
		}
		//若直线方程位于矩形上边上方或下边下方，则与矩形无交点
		else if ((-this->c / this->b) < rectangle.bottomLeftY || (-this->c / this->b) > rectangle.topRightY)
		{
			cout << "直线与矩形无交点<<endl";
			return;
		}
		else
		{
			cout<< endl;
		}
		//除此之外，与矩形交于两点
		cout << "直线与矩形两交点：（" << rectangle.bottomLeftX << "," << (-this->c / this->b) << "),(" << rectangle.topRightx << "," << (-this->c / this->b) << ")";
		return;
	}
	//与上同理，若直线与y轴平行
	if (this->b == 0) {
		if ((-this->c / this->a) == rectangle.bottomLeftX || (-this->c / this->a) == rectangle.topRightx)

		{
			cout << "直线与矩形一边重合，有无数交点" << endl;
			return;
		}
		else if ((-this->c / this->a) < rectangle.bottomLeftX || (-this->c / this->a) > rectangle.topRightx)
		{
			cout << "直线与矩形无交点<<endl";
			return;
		}
		else
		{
			cout<<endl;
		}

		cout << "直线与矩形两交点：（" << -this->c / this->a << "," << rectangle.bottomLeftY << "),(" << -this->c / this->a << "," << rectangle.topRightY << ")";
			return;
	}
	//若直线为一般直线
	float X1, X2, X3, X4; float Y1, Y2, Y3, Y4;
	bool isHvae = false;
	/*
	判断矩形与直线是否相交的依据是，矩形给定了右上和左下两个点，考虑以这
	两个点的横纵坐标为已知量，带入直线方程，计算出另外四个坐标，从而得到
	四个新的点的坐标，判断这四个新的点是否在矩形的四个边上即可
	*/
	X1 = rectangle.bottomLeftX;
	Y1 = -(this->a * X1 + this->c) / this->b; 
	X2 = rectangle.topRightx;
	Y2 = -(this->a * X2 + this->c) / this->b; 
	Y3 = rectangle.bottomLeftY;
	X3 = -(this->b * Y3 + this->c) / this->a; 
	Y4 = rectangle.topRightY;
	X4 = -(this->b * Y4 + this->c) / this->a;
	if (Y1 <= rectangle.topRightY && Y1 >= rectangle.bottomLeftY){
		cout << "直线与矩形存在交点：（" << X1 << "," << Y1 << ")"; isHvae = true;
	}
	if (Y2 <= rectangle.topRightY && Y2 >= rectangle.bottomLeftY){
		cout << "直线与矩形存在交点：（" << X2 << "," << Y2 << ")"; isHvae = true;
	}
	if (X3 < rectangle.topRightx && X3 > rectangle.bottomLeftX){
		cout << "直线与矩形存在交点：（" << X3 << "," << Y3 << ")"; isHvae = true;
	}
	if (X4 < rectangle.topRightx && X4 > rectangle.bottomLeftX){
		cout << "直线与矩形存在交点：（" << X4 << "," << Y4 << ")"; isHvae = true;
	}
	if (!isHvae)
		cout << "直线与矩形无交点" << endl; cout << endl;

}
//main
int main() {
	//初始化所有的几何元素
	Straight straight(1, 2, -1);
	Straight otherStraight(-1, 1, 0);
	Rectangle rectangle(2, 2, 1, -1);
	Circle circle(0.5, 0.5, 0.5);
	//输出直线、矩形、圆的方程
	cout << "直线：方程为：" << straight.a << "x+" << straight.b << "y+" << straight.c << "=0;" << endl;
	cout <<"圆：圆心坐标为：（" << circle.x0 << "," << circle.y0 << "）,半径为" << circle.r << endl;
	cout << "矩形：右上顶点坐标为(" << rectangle.topRightx << "," << rectangle.topRightY << ")左下顶点坐标为(" << rectangle.bottomLeftX << "," << rectangle.bottomLeftY << ")" << endl; 
	straight.intersect(otherStraight); 
	straight.intersect(rectangle); 
	straight.intersect(circle);
}

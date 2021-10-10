#include <stdio.h>
#include <math.h>
#define PI 3.14F
#define POW(a) pow(a,2)
#define lin(x1, y1, x2, y2) sqrt(POW(x2 - x1)+POW(y2 - y1))

struct Str
{
	float P;
	float S;
};

struct Str Func(int x1, int y1, int x2, int y2, int x3, int y3)
{
	struct Str a = { -1,-1 };
	if (((x3 - x1) / (x2 - x1)) == ((y3 - y1) / (y2 - y1)))
	{
		return a;
	}
	float P = lin(x1, y1, x2, y2) + lin(x2, y2, x3, y3) + lin(x3, y3, x1, y1);
	float p = P / 2;
	float S = sqrt(p * (p - lin(x1, y1, x2, y2)) * (p - lin(x2, y2, x3, y3)) * (p - lin(x3, y3, x1, y1)));
	a.P = P;
	a.S = S;
	return a;
}

int main()
{
	system("chcp 1251>nul");
	float* p = malloc(sizeof(float));
	float x1, x2, y1, y2, x3, y3;
	int x;
	printf("Выберите действие (1 - Замена констант, 2 - Нахождение длины отрезка по координатам двух его точек, 3 - Функция):\n");
	scanf_s("%i", &x);
	switch (x)
	{
	case 1:
		printf("\ndefine PI = %f", PI);
		printf("\nВведите новое значение: ");
		scanf_s("%f", p);
#define PI *p
		printf("\ndefine PI = %f", PI);
		break;
	case 2:
		printf("\nВведите x1: ");
		scanf_s("%f", &x1);
		printf("\nВведите y1: ");
		scanf_s("%f", &y1);
		printf("\nВведите x2: ");
		scanf_s("%f", &x2);
		printf("\nВведите y2: ");
		scanf_s("%f", &y2);
		printf("Длина отрезка: %f", lin(x1, y1, x2, y2));
		break;
	case 3:
		printf("\nВведите x1: ");
		scanf_s("%f", &x1);
		printf("\nВведите y1: ");
		scanf_s("%f", &y1);
		printf("\nВведите x2: ");
		scanf_s("%f", &x2);
		printf("\nВведите y2: ");
		scanf_s("%f", &y2);
		printf("\nВведите x3: ");
		scanf_s("%f", &x3);
		printf("\nВведите y3: ");
		scanf_s("%f", &y3);
		struct Str an = Func(x1, y1, x2, y2, x3, y3);
		printf("\nОтвет: P = %f, S = %f", an.P, an.S);
		break;
	}
	return 0;
}
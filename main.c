#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

//Функция проверки типа данных
void checkFormat(float *num){
  char buffer[300];
  do{
    fgets(buffer, sizeof(buffer), stdin);
    if (sscanf(buffer, "%f", num) != 1) printf("Ошибка ввода данных.\nПопробуйте снова: ");
  } while (sscanf(buffer, "%f", num) != 1);
}

//Функция проверки диапазона
void checkType(float *num){
  if (errno == ERANGE){
    printf("Выход за диапазон типа. Программа предварительно завершена.\n");
    exit(1);
  }
}

int main(){
  float a, b, c;

  printf("Нахождение корней функции y = a*x^2 + b*x + c.\nВведите а: ");
  checkFormat(&a);
  checkType(&a);
  printf("Введите b: ");
  checkFormat(&b);
  checkType(&b);
  printf("Введите c: ");
  checkFormat(&c);
  checkType(&c);

  if (a == 0){
    if (b == 0){
      if (c == 0){
        printf("Данное уравнение имеет бесконечное кол-во решений.");
        return 0;
      }else{
        printf("Данное уравнение не имеет решений.");
        return 0;
      }
    }else{
      float x = -c/b;
      printf("Уравнение имеет один корень, x = %f", x);
      return 0;
    }
  }else{
    float d = b*b - 4*a*c;
    if (d < 0){
      printf("Уравнение не имеет вещественных корней.");
      return 0;
    }else if (d == 0){
      float x = (-b)/(2*a);
      printf("Уравнение имеет один корень, x = %f", x);
      return 0;
    }else{
      float x1 = (-b + sqrt(d))/(2*a);
      float x2 = (-b - sqrt(d))/(2*a);
      printf("Уравнение имеет два корня, x1 = %f и x2 = %f", x1, x2);
      return 0;
    }
  }
}

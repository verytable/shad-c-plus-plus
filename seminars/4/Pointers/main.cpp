#include <iostream>

using namespace std;

bool Less(int a, int b) {
  return (a < b);
}

typedef bool (*TCmpFun)(int, int);
TCmpFun f = &Less;

/*
  * Класс комплекных чисел
  * */
class TComplex {
  //обычно, данные private
private:
  double Real;
  double Img;
  //TComplex z;
  //z.Real = 1.5; //не будет работать
public:
  /*
  * Метод осуществляющий инициализацию называется конструктором:
  * */

  /*
  * Конструктор по-умолчанию
  * через список инициализации
  * */
  TComplex()
    :Real(0.0) //на разных строчках для того, чтобы diff был более информативен
    ,Img(0.0)
  {}
  /*
  * Последний конструктор можно переписать по-другому:
  * TComplex() {
  *   Real = 0.0;
  *   Img = 0.0;
  * }
  *
  * Через список инициализации обычно эффективнее, в данном случае все-равно.
  * */


  TComplex(double r, double i = 0.0) //i - параметр по умолчанию, для функций лучше использовать перегрузку
    :Real(r)
    ,Img(i)
  {}

  ~TComplex(){} //уничтожает объект, в нашем случае ничего можно не делать


  TComplex& operator +=(const TComplex& b) {
    Real += b.Real; //в классе имеем доступ к private членов этого класса
    this->Img += b.Img;
    return *this; //this имеет тип (TComplex *)
  }

  double GetReal() const {
    return Real;
  }
};

/*
* не in-place конструкторы, лучше писать снаружи
* */
TComplex operator +(const TComplex &a, const TComplex &b) const {
  /*
  * Реализация + через +=
  * */
  TComplex tmp(a);
  tmp += b;
  return tmp;
}
/*
* TComplex operator +(TComplex a, TComplex b) const {
*   return (a += b);
* }
*
* */



int main() {
  /*
  * Тема: Указатели на функции
  * */
  /*
  * Рассмотрим задачу: есть массив A[100], нужно его отсортировать.
  * Есть функция std::sort(A, A + 100);
  * Функция сравнения по-умолчанию:  std::less<int>
  * std::sort(A, A + 100, &std::lest<int>);
  *
  * пишем свой Sort
  * void Sort(int *b, int *e, cmp) { //тип cmp определим позже
  *   for (i...) {
  *     int k = Find(b + i, e, cmp);
  *     swap(i, k);
  *   }
  * }
  *
  * int* Find(int *b, int *e, cmp) {
  *   int *best = b;
  *   for (int *t = b + 1; t != e; ++t) {
  *     if (cmp(*t, *best)) {
  *       best = t;
  *     }
  *   }
  *   return best; //для сортировки важен не сам минимальный элемент, а его индекс
  * }
  *
  * bool Less(int a, int b) {
  *   return (a < b);
  * }
  *
  * Такая функция - тоже тип.
  * А именно bool (*)(int, int)
  * Для создания переменной такого типа, можем написать:
  * bool (*cmp)(int, int) = &Less; //не очень удобно
  *
  * Можно задать синоним с помощью ключевого слова typedef
  * typedef bool (*TCmpFun)(int, int);
  * TCmpFunc f = &Less;
  *
  * Далее можем обращаться к функции так: f(1, 2)
  * */

  std::cout << f(1, 2) << "\n";

  /*
  * Функтор - класс с перегруженным оператором ()
  * */
  struct TLess {
    //перегрузка оператора ()
    bool operator ()(int a, int b) const { //const - обещаем не менять объект
      return (a < b);
    };
  };

  /*
  * Пример использования этого класса
  * */
  TLess cmp;
  std::cout << cmp(3, 4) << "\n";

  /*
  * Классы нужны для энкапсуляции данных и функций,
  * работающих с этими данными
  * */



  /*
  * struct отличается от class только модификаторами доступа по-умолчанию
  * struct - логически упрощенная версия class
  *
  * */


  TComplex z; //создали объект класса TComplex

  TComplex a(1.0); //инициализация вторым конструктором, используя значение по-умолчанию
  TComplex b(0.0, 1.0);

  /*
  * Каждый объект живет от момента вызова конструктора,
  * до момента вызова деструктора.
  * Деструктор обычно вызывается автоматически при выходе из области видимости.
  * */



























  return 0;
}
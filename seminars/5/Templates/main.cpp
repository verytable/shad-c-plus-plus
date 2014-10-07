#include <iostream>
#include <vector>
#include <algorithm>

/*
* Максимум из двух чисел для int, int
* */
int max(int a, int b) {
  return a >= b ? a : b;
}

/*
* Перегрузка функции (должно отличатся число параметров или типы)
* Максимум из двух чисел для float, float
* */
float max(float a, float b) {
  return a >= b ? a : b;
}

/*
* Чтобы не писать для разных типов функцию с одной реализацией используются шаблоны
* */
template <typename T>
T max(T a, T b) {
  return a >= b ? a : b;
}

/*
* Параметров шаблона может быть несколько
* */
template <typename T, typename U = T>
T max(T a, U b) {
  return a >= b ? a : b;
}

/*
* Параметр может быть константным перечислимым типом и только им
* */
template <int s> //нельзя написать float вместо int, ибо у одного float могут быть разные представления
int Add(int arg) {
  return arg + s;
}

/*
* Предположим, мы реализовали свой тип TInt
* который умеет сравниваться с помощью Compare
* Хотим уметь вызывать максимум типов TInt
* */
/*template <>
const TInt &max<Tint>(const TInt &a, const TInt &b) {
  //...
}*/

/*
* Шаблоны функций и шаблоны параметров - разные шаблоны
* нельзя не указывать все параметры шаблона функции
* */

/*
* Раньше, когда не было языка C++ ползовались #define:
*   #define max(a, b) ((a) >= (b)) ? (a) : (b)
*
* Этим нельзя пользоваться сейчас (плохо, например, из-за повторных вызывов)
* */

template <typename T>
struct TLessCount {
  static size_t Count; //ведет себя как глобальная перменная

  bool operator ()(const T &a, const T &b) const {
    ++Count; //хотим узнать, сколько раз вызывается функция сравнения
    return a < b;
  }
};

template <typename T>
size_t TLessCount<T>::Count = 0;



/*
* Шаблоны классов
* Подсчет факториала
* */

template <int n>
struct F {
  enum {
    Result = n * F<n - 1>::Result
  };
};
template <>
struct F<0> {
  static const size_t Result = 1;
};

/*
* Посчитаем Cnk
* */
template <int n, int k>
struct C {
  enum {
    Result = C<n - 1, k - 1>::Result + C<n - 1, k>::Result
  };
};
template <int n> //частичная специализация
struct C<n, n> {
  enum {
    Result = 1
  };
};
template <int n> //частичная специализация
struct C<n, 0> {
  enum {
    Result = 1
  };
};
//template <> //полная специализация, мб не нужна
//struct C<0, 0> {
//  enum {
//    Result = 1
//  };
//};

//template <typename T, typename Alloc = std::allocator<T>>
//template <typename Alloc = std::allocator<char>>
//class vector<bool, Alloc> {
  /*
  * вектор bool'ов хранит bool в сжатом виде, в виде битов некоторого другого типа
  * чтобы переопределить оператор [], нужно удовлетворять
  * выражениям вида if(v[100]) и v[99] = 100
  *
  * Чтобы это сделать нужно возвращать новую прокси-структру
  * */
//};

/*
* Хотим определить структуру, котороя определяет является ли T указателем
* пример использования: if(TIsPointer<T>::Result)
* */

template <typename T>
struct TIsPointer {
  static const bool Result = false;
};
template <typename T>
struct TIsPointer<T*> { //???порядок выбора шаблонов - минимальный подходящий
  static const bool Result = true;
};

int main() {
  /*
  * использование шаблонной функции
  * */
  std::cout << max<int>(1, 0) << "\n";//реальная функция max<int> возникает только при использовании

  std::cout << max<float> (1.0, 2.9) << "\n";

  std::cout << Add<2>(5) << "\n";//аргумент устанавливается в момент компиляции

  /*
  * Дедукция типов
  * */
  int a = 1, b = 2;
  std::cout << max(a, b) << "\n";//???

  /*
  * Примеры функций, использующих шаблоны:
  * template <typename TIter, typename TCmp> //вместо слова typename можно написать class
  * sort(TIter begin, TIter end, TCmp cmp) {
  *
  * }
  * */

  std::vector<int> v = {1, 2, 3, 2, 4, 1};
  std::sort(v.begin(), v.end(), TLessCount<int>());

  std::cout << F<10>::Result << "\n"; //создастся 11 классов, F(10), который поймет, что ему нужно F(9)...

  std::cout << C<10, 5>::Result << "\n";

  return 0;
}

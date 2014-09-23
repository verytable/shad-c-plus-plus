#include <iostream>
#include <string.h>
#include <vector>

/*
* Вместе с массивом обычно передают его размер чтобы избежать обращения по индексам вне границ
* */
int a(int* a, int n) {
  int result = a[0] + a[1];
  if(a[2] > 3 && n >= 5) {
    result += a[4];
  }
  return result;
}

int main() {
  int array[5];
  /*
  * array - не просто имя, это еще и указатель на начало
  * */
  array[0] = 42;
  /*
  * инициализация
  * */
  for(int i = 0; i < 5; ++i) {
    std::cin >> array[i];
  }
  int a[5] = {1, 2, 3}; //все оставшиеся элементы будут нулями
  /*
  * вывод
  * */
  for(int i = 0; i < 5; ++i) {
    std::cout << i[array] << " "; //не ошибка, потому, [] <=> it + it; а + коммутативен
  }

  std::cout << std::endl;
  /*
  * C - строки
  * хорошо бы иметь Тип для строк; можно сделать это с помощью массива Char
  * */
  char s[] = "Hello!";
  /*
  * через списко инициализации:
  * */
  char ss[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};

  std::cout << s << std::endl; //выводит строку
  std::cout << strcmp(s, ss); //сравнивает две C-строки, лежит в string.h
  std::cout << a << std::endl; //выводит указатель

  /*
  * Вывод через указатель. (В духе итераторов для коллекций)
  * */
  const int size = 5;
  int b[size] = {1, 2, 3};
  for(int* it = b; it < b + size; ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::string str("String");
  /*
  * Можно перейти от string к C-строке с помощью c_str
  * */

  /*
  * std::vector<T> - шаблонный тип
  * */
  std::vector<int> v(10); //создание вектора размера 10, со значениями int()
  std::vector<double> d(5, 1.0); //вектор размера 5, со значениями 1.0
  std::vector<std::vector<int>> v2; //двумерный вектор, в старых стандартах языка между ">>" должен быть пробел

  std::cout << v.size() << "\n"; //текущий размер вектора, выведется 10
  std::cout << v.capacity() << "\n\n"; //число добавлений (push_back) до реаллокации

  v.reserve(20); //меняет capacity
  std::cout << v.capacity() << "\n\n"; //20

  v.resize(40); //массив дополнится int() = 0
  std::cout << v.size() << "\n";
  std::cout << v.capacity() << "\n\n"; //тоже изменится;

  v.resize(9); //массив обрежется до размера 9
  std::cout << v.size() << "\n";
  std::cout << v.capacity() << "\n\n"; //может изменится;

  /*
  * Вывод элементов вектора:
  * */
  /*
  * По индексам:
  * */
  for(size_t idx = 0; idx < v.size(); ++idx) {} // не стоит закладываться на оптимизацию компилятора не вычисления v.size
  for(size_t idx = 0, cnt = v.size(); idx < cnt; ++idx) {
    std::cout << v[idx] << " ";
  }
  std::cout << "\n";
  /*
  * Через итераторы:
  * */
  for(std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
    *iter += 2; // меняем значения вектора
    std::cout << *iter << " ";
  }
  std::cout << "\n";
  /*
  * Если хотим запретить менять элементы
  * */
  for(std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << "\n";
  /*
  * Через auto
  * */
  for(auto id : v) {
    std::cout << id << " ";
  }
  std::cout << "\n";

  /*
  * Полезныем методы vector:
  *   clear
  *   erase
  *   insert
  * */
  return 0;
}
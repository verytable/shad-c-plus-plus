#include <iostream>

/*
* namespace std {
*
* }
*
* вызов функции пространства имен: std::...
* */
using namespace std;

void Print() {
  std::cout << "Hello, World" << std::endl;
}
/*
* функция имеет имя (Print)
* функция имеет список параметров в скобках ()
* */

/*
* const: не можем написать name = ..., обещание компилятору
* если бы мы убрали const, то не смогли бы передать временный объект, ибо не плохо бы его не менять
* можно убрать одновременно const и &
* & передает объект по ссылке
* */
void Print(const std::string &name) {
  std::cout << "Hello, " << name << std::endl;
}

/*
* точка входа
* */
int main() {
  /*
  * Строковая константа = массив символов
  * В C++ пишуются в двойных кавычках
  *
  * "<<" - перегруженный оператор сдвига
  * "<<" возвращает объект, который стоит слева
  *
  * std::endl - манипулятор, перевод строки
  * */
  cout << "Hello, World!" << endl;
  /*
  * Объекты в c++ характеризуются адресом, временем жизни, имеют тип
  * Тип std::cout что-то вроде basic_ios<...>
  * std::cout << s - возвращает значение типа, которого был cout, поэтому можно продолжить "<<" каскадно
  *
  * "\n" отличается от std::endl тем, что первый не сбрасывает буффер
  * буффер сбрасывается, например, и тогда, когда уничтожается объект cout
  *
  * std::cout << s; std::cout << std::endl; <=> std::cout << s;
  * */

  /*
 * Объявление переменной:
 * */
  int a(5);
  int b = 5;
  // Сразу несколько переменных
  int c, d = 5, e;
  /*
  * что будет в переменных c и е не известно
  * std::cout << c; - undefined behaviour
  *
  * Разные реализации языка в разной степени соответсвуют стандарту языка.
  * */
  /*
  * a + b; - выражение, у него есть тип - int
  * */
  a + b; //результат выражения потеряется
  e = (a + b * c) << 1; //положили значение выражения в e
  /*
  * положить значение можно и с помощью блока
  * */
  if (d == 5) {
    e = a + b;
    std::cout << e;
  }
  /*
  * создание переменной типа int - резервирования места в стеке
  * */

  /*
  * переменные находящиеся в статической памяти инициализируются значением по-умолчанию
  * */

  a = b = 3; //так можно после объявления == a = (b = 5);

  /*
  * при вызове функции запоминается адрес возврата, по завершению выполняются дальнейшие инструкции
  * */
  Print(); // != print(); e.g. case sensitive

  /*
  * inline - рекомендация по подстановке кода
  * */

  Print("Max"); // <=> Print(std::string("Max")), создается еще один объект, временный

  /*
  * к моменту вызова нужно иметь декларацию или дефиницию функции
  * декларация: void Print(const std::string & name);
  * */

  return 0;
}
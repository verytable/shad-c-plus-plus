#include <iostream>
#include <string>
#include <memory>

/*
* На платформе x86 каждая программа думает, что других программ нет
* и у нее есть кусок памяти.
*
* У программы есть область на диске, в которой лежит ее код. И область, в которой
* лежат статические данные.
*
* Программа выгружается в память: копируется код, статические данные (которые могут
* расшириться из-за перменных инициализирующихся нулем ???).
*
* Еще есть стек. Он уже где-то в другой области памяти.
* */

/*
* Инициализация глобальных переменных происходит до входа в main,
* порядок инициализации переменных из разных модулей не определен, то есть
* на усмотрение линковщика.
* В одном модуле инициализация сверху вниз. Поэтому можно пользоваться верхними
* при инициализации нижних.
* */
std::string s("Hello"); //"Hello" хранится в статическом файле

/*
* Подсчет факториала.
* Допустим мы считаем f(10), заходим в функцию, требуется f(9) итд
* Умножение происходит при обратном разворачивании.
* Где хранятся вот эти числа 9, 8, 7 ...?
* В стеке:
*   адрес возврата
*   регистр //пока не говорим об этом
*   локальные переменные
* Можно повыводить адрес переменной n и увидеть, что он меняестя на какое-то
* константное число.
*
* Стековая память называется - автоматической памятью.
* */
int fact(int n) {
  if (n <= 0) {
    return 1;
  } else {
    return fact(n - 1) * n;
  }
}

class T {
  static std::string S;
};

std::string T::S("Hello");

int main() {
  int a = 5;

  /*
  * В момент вызова функции f. Должны сходить к месту хранения инструкций функции f.
  * Но мы должны запомнить куда вернуться. Эта информация и хранится в стеке,
  * а именно - адрес возврата.
  * */
  int f = fact(10);

  /*
  * Наша программа = наш код + код библиотеки.
  * Стандартная библиотека уже выделяет большой кусок для динамической памяти.
  * Динамическая память - для больших долго-используемых объектов.
  * А затем выдает пользователю маленькие кусочки.
  * Как попросить память под кусочки?
  * Оператором new.
  * */
  std::cin >> a;
  int * A = new int[a]; //вернется не менее чем sizeof(int)*n подряд идущих элементов в памяти
  /*
  * Все объекты будут инициализированны чем то.
  * Для целочисленных типов нет конструктора по умолчанию.
  * А для многих других типов будет инициализация с помощью конструктура по умолчанию.
  * */
  std::string *ss = new std::string[a];

  /*
  * Деструкторы должны быть no-throw
  * */

  /*
  * Удалять массив нужно оператором delete []
  * */

  std::string *s1 = new std::string("hello"); // выделение памяти под один объект

  /*
  * new и new []. возвращают только указатель, которые не отличаются
  * с точки зрения программы. Поэтому нужно знать, что именно удаляешь
  * при вызове деструктора и вызывать либо delete, либо delete [].
  * При вызове delete [] стандарт гарантирует, что удалится столько сколько нужно
  * элементов.
  * */
  delete []ss;
  delete s1;

  std::string *s2 = new std::string("text");
  /*
  * Работа с s2
  * */
  delete s2;
  /*
  * Если при работе с s2 будет исключение или выход из программы
  * может произойти утечка памяти,
  * поэтому нужно использовать умные указатели
  * */
  /*
  * Этот указатель будет гарантированно уничтожен, что бы не произошло.
  * */
  std::auto_ptr<std::string> s3(new std::string); // deprecated ???

  s3.reset(new std::string); // удаляется то, что было внутри s3 ???
  s3.reset(nullptr);

  /*
  * std::auto_ptr<std::string> t(new std::string[100]);
  * не будет так работать, ибо будет вызываться delete, а не delete []
  * Как сделть, чтобы работало? Нельзя сделать вектор авто_птр ов, ибо вектор считает,
  * что его элементы копируемые.
  * Правильный ответ: использовать вектор вместо массива.
  */

  return 0;
}

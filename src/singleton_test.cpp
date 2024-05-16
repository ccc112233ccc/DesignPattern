#include "Singleton.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
  Singleton& instance = Singleton::getInstance();
  Singleton& instance2 = Singleton::getInstance();
  instance.print();
  instance2.print();

  std::cout << (&instance == &instance2) << std::endl;
  return 0;
}
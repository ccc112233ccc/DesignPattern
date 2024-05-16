#include <iostream>

class Singleton {
 public:
  static Singleton& getInstance() {
    static Singleton instance;
    return instance;
  }

  void print() { std::cout << "Singleton" << std::endl; }

  private:
  Singleton() { std::cout << "Singleton constructor" << std::endl; }
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  ~Singleton() { std::cout << "Singleton destructor" << std::endl; }
};
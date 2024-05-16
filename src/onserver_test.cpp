#include "Observer.h"

int main() {
  auto observer1 = std::make_shared<ConcreteObserver>();
  auto observer2 = std::make_shared<ConcreteObserver>();
  auto observer3 = std::make_shared<ConcreteObserver>();

  auto subject = std::make_shared<ConcreteSubject>();
  subject->registerObserver(observer1);
  subject->registerObserver(observer2);
  subject->registerObserver(observer3);

  subject->notifyObservers();

  subject->removeObserver(observer2);

  subject->notifyObservers();
  return 0;
}
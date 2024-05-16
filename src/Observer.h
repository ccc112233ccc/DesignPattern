#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class Observer {
 public:
  virtual void update() = 0;
  virtual ~Observer() = default;
};

class Subject {
 public:
  virtual void registerObserver(std::weak_ptr<Observer> observer) = 0;
  virtual void removeObserver(std::weak_ptr<Observer> observer) = 0;
  virtual void notifyObservers() = 0;
  virtual ~Subject() = default;
};

class ConcreteObserver : public Observer {
 public:
  void update() override {
    std::cout << "ConcreteObserver update" << std::endl;
  }

  ~ConcreteObserver() override = default;
};

class ConcreteSubject : public Subject {
 public:
  void registerObserver(std::weak_ptr<Observer> observer) override {
    observers.push_back(observer);
  }

  void removeObserver(std::weak_ptr<Observer> observer) override {
    auto it = std::find_if(observers.begin(), observers.end(),
                           [&observer](const std::weak_ptr<Observer>& o) {
                             return o.lock() == observer.lock();
                           });
    if (it != observers.end()) {
      observers.erase(it);
    }
  }

  void notifyObservers() override {
    auto it = observers.begin();
    while (it != observers.end()) {
      if (auto observer = it->lock()) {
        observer->update();
        ++it;
      } else {
        it = observers.erase(it);
      }
    }
  }

  ~ConcreteSubject() override = default;

 private:
  std::vector<std::weak_ptr<Observer>> observers;
};

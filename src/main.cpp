#include <iostream>
#include <vector>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void attach(Observer* obs) {
        observers.push_back(obs);
    }
    void notify(const std::string& message) {
        for (auto obs : observers) {
            obs->update(message);
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Received: " << message << std::endl;
    }
};

int main() {
    Subject subj;
    ConcreteObserver obs1, obs2;
    subj.attach(&obs1);
    subj.attach(&obs2);
    subj.notify("Hello Observer Pattern!");
    return 0;
}

#include <gtest/gtest.h>
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
private:
    std::string last_message;
public:
    void update(const std::string& message) override {
        last_message = message;
    }
    std::string getLastMessage() const {
        return last_message;
    }
};

TEST(ObserverTest, NotifyUpdatesObserver) {
    Subject subj;
    ConcreteObserver obs;
    subj.attach(&obs);
    subj.notify("Hello");
    EXPECT_EQ(obs.getLastMessage(), "Hello");
}

TEST(ObserverTest, MultipleObservers) {
    Subject subj;
    ConcreteObserver obs1, obs2;
    subj.attach(&obs1);
    subj.attach(&obs2);
    subj.notify("Test");
    EXPECT_EQ(obs1.getLastMessage(), "Test");
    EXPECT_EQ(obs2.getLastMessage(), "Test");
}

TEST(ObserverTest, EmptySubject) {
    Subject subj;
    subj.notify("Nothing");
    SUCCEED();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

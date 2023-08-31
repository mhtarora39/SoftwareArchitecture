#include <iostream>
#include <vector>
#include <memory>
#include <utility>


struct ISubscriber {
    virtual void receiveMsg(const std::string& msg) = 0;
};


class MySubscriber : public ISubscriber {

    public:
    MySubscriber(const std::string& msg) : m_name(msg) {

    }
    virtual void receiveMsg(const std::string& msg) {
        std::cout << "Signal Received in MySubscriber : " << m_name << " --> " << msg << std::endl;
    }

    private:
    std::string m_name;
};


class Publisher {
    
    public:
    void addSubscriber(std::unique_ptr<ISubscriber>&& sub) {
        subscribers.emplace_back(std::move(sub)); 
    }

    void run(const std::string& msg) {
        for(auto& sub : subscribers) {
            sub->receiveMsg(msg);
        }
    }

    private:
    std::vector<std::unique_ptr<ISubscriber>> subscribers; 
};



int main() {
    auto sub1 = std::make_unique<MySubscriber>("SUB1");
    auto sub2 = std::make_unique<MySubscriber>("SUB2");
    Publisher pub;
    pub.addSubscriber(std::move(sub1));
    pub.addSubscriber(std::move(sub2));
    pub.run("This is Test");

}



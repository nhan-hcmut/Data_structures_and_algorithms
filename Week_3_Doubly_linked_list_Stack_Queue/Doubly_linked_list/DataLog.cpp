#include <iostream>
#include <list>
using namespace std;

class DataLog {
    
    private:
    list<int> logList;
    list<int>::iterator currentState;

    public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData() {
        return *currentState;
    }
    
    void printLog() {
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if (i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog() {
    /*
     * TODO: add the first state with 0
    */
    this->logList.push_back(0);
    this->currentState = logList.begin();
}

DataLog::DataLog(const int &data) {
    /*
     * TODO: add the first state with data
    */
    this->logList.push_back(data);
    this->currentState = logList.begin();
}

void DataLog::addCurrentState(int number) {
    /*
     * TODO: Increase the value of current state by number
    */
    *this->currentState += number;
}

void DataLog::subtractCurrentState(int number) {
    /*
     * TODO: Decrease the value of current state by number
    */
    *this->currentState -= number;
}

void DataLog::save() {
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the
     *       currentState Iterator, we delete them all before creating a new state.
    */
    list<int>::iterator newState = this->currentState;
    newState++;
    while (newState != this->logList.end()) newState = this->logList.erase(newState);
    this->logList.push_back(*this->currentState);
    this->currentState++;
}

void DataLog::undo() {
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
    */
    if (this->currentState != this->logList.begin()) this->currentState = prev(this->currentState, true);
}

void DataLog::redo() {
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
    */
    list<int>::iterator newState = this->currentState;
    list<int>::iterator nextState = ++newState;
    if (nextState != this->logList.end()) this->currentState++;
}

int main() {

    // Test 1
    DataLog log(10);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.addCurrentState(15);
    log.undo();
    log.printLog(); // result: [ 10 ] => Current state: [ 25 ] => [ 40 ] => END_LOG

    /* Test 2
    DataLog log(10);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.subtractCurrentState(5);
    log.printLog(); // result: [ 10 ] => [ 25 ] => [ 40 ] => Current state: [ 35 ] => END_LOG
    */
    return 0;
}
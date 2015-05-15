
class Employee {
    int ID;
    bool Busy;

    public:
    bool getIsBusy();
    void handleCall();
};

class Fresher : Employee {

};

class TechnicalLead : Employee {

};

class ProductManager : Employee {

};

class Company {
    Fresher[] Freshers;
    TechnicalLead TL;
    ProductManager PM;

    public:
    void getCallHandler();
};

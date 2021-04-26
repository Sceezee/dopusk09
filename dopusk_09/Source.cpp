#include <iostream>
#include <string>

using namespace std;

class Credit {
protected:
	double sum;
public:
	virtual void SetCreditSum(double sum) = 0;
	void UpdateCredit(double update) {
		sum = sum + update;
	}
};

class Installments : public virtual Credit {
protected:
	double countOfPayments;
public:
	void SetCreditSum(double sum) override {
		this->sum = sum;
	}
	double GetMonthPayment() {
		return (sum / countOfPayments);
	}
	double UpdateCredit() {
		this->sum = sum - GetMonthPayment();
		countOfPayments--;
		return sum;
	}
};

class ResidualÑredit : public virtual Credit {
protected:
	double percent;
public:
	void SetCreditSum(double sum) override {
		this->sum = sum;
	}
	double CurrentPayment() {
		return (sum + (sum * (percent/100.0)));
	}
	void UpdateCredit() {
		this->sum = sum - CurrentPayment();
	}
};

class SoftLoan : protected Installments, protected ResidualÑredit {
protected:
	double softProcent;
public:
	void SetCreditSum(double sum) override {
		this->sum = sum;
	}
	double CurrentPayment() {
		return (sum + (sum * ((percent - softProcent) / 100.0)));
	}
	void UpdateCredit() {
		this->sum = sum - CurrentPayment();
	}
};

int main() {
	Installments inst;
	ResidualÑredit resc;
	SoftLoan sofl;
	Credit* arr[3];
	arr[0] = &inst;
	arr[1] = &resc;
	arr[2] = &sofl;
	arr[0]->SetCreditSum(500.0);
	arr[0]->UpdateCredit();
	arr[1]->SetCreditSum();
	arr[1]->






	return 0;
}
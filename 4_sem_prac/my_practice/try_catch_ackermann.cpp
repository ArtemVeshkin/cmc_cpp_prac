#include <iostream>

class Result
{
	int result_;
public:
	Result(int result) : result_(result) {}

	int result() const { return result_; }
};

void a(int m, int n)
{
	if (!m) {
		throw Result{n + 1};
	}

	try {
		if (!n) {
			a(m - 1, 1);
		} else {
			a(m, n - 1);
		}
	} catch(const Result& ex) {
		if (!n) {
			throw ex;
		}
		n = ex.result();
	}

	try {
		a(m - 1, n);
	} catch(const Result& ex) {
		throw ex;
	}
}

int main()
{
	int m, n;
	std::cin >> m >> n;

	try {
		a(m, n);
	} catch (const Result& ex) {
		std::cout << ex.result() << std::endl;
	}
}
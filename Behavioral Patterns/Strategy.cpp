//Strategy is a behavioral design pattern that lets you define a family of algorithms, put each of them
// into a separate class, and make their objects interchangeable.

#include <iostream>
using namespace std;

class Solution {
public:
    virtual void theSolution() = 0;
};

class Problem {
public:
    Solution *solution;

    Problem(Solution *solution) : solution(solution) {}

    void solve() {
        this->solution->theSolution();
    }

    void setSolution(Solution *solution) {
        this->solution = solution;
    }
};

class SolutionA : public Solution {
    void theSolution() override {
        cout << "The problem solved with A" << endl;
    }
};

class SolutionB : public Solution {
    void theSolution() override {
        cout << "The problem solved with B" << endl;
    }
};

class SolutionC : public Solution {
    void theSolution() override {
        cout << "The problem solved with C" << endl;
    }
};

int main() {
    Problem problem(new SolutionA());
    problem.solve();
    problem.setSolution(new SolutionB());
    problem.solve();
    problem.setSolution(new SolutionC);
    problem.solve();

    return 0;
}

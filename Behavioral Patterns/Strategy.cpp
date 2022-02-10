#include <iostream>
using namespace std;

class Solution {
public:
    Solution() {}

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

public:
    SolutionA() {}
};

class SolutionB : public Solution {
public:
    SolutionB() {}

    void theSolution() override {
        cout << "The problem solved with B" << endl;
    }
};

class SolutionC : public Solution {
public:
    SolutionC() {}
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


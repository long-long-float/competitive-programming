#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <limits.h>

using namespace std;

int comp(int a, int b){ return a == b; }

class SingingEasy {
    public:
    int solve(vector<int> pitch) {
        vector<int> pitch2 = pitch;
        sort(pitch2.begin(), pitch2.end());

        int len = pitch.size();
        int ans = INT_MAX;
        set<int> exclusive;
        for(int i = -1;i < len;i++) {
          if(i != -1) {
            exclusive.insert(pitch2[i]);
          }
          vector<int> tp1, tp2;
          tp1.reserve(len); tp2.reserve(len);
          for(int j = 0;j < len;j++) {
            int p = pitch[j];
            if(exclusive.find(p) != exclusive.end()) {
              tp1.push_back(p);
            }
            else {
              tp2.push_back(p);
            }
          }
          int vh = 0;
          if(tp1.size() > 1) {
            for(int j = 1;j < tp1.size();j++) {
              vh += abs(tp1[j - 1] - tp1[j]);
            }
          }
          int vl = 0;
          for(int j = 1;j < tp2.size();j++) {
            vl += abs(tp2[j - 1] - tp2[j]);
          }
          ans = min(ans, vh + vl);
        }

        return ans;
    }
};

// CUT begin
ifstream data("SingingEasy.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> pitch, int __expected) {
    time_t startClock = clock();
    SingingEasy *instance = new SingingEasy();
    int __result = instance->solve(pitch);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> pitch;
        from_stream(pitch);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pitch, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1426592394;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "SingingEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

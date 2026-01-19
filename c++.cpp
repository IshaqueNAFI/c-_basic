// Student Report System — Simple & Authentic (VS-Ready, Single File)
// Menu: 1) student records  2) calculate grades  3) generate report  0) exit
// Meets course topics (lightweight):
// - C++ Basics, Flow Control, Functions, Arrays
// - Structures & Classes, Operator Overloading
// - Pointers + Recursion (for average)
// - Namespaces (ready for separate compilation later)
// - Files + Exception Handling (I/O guarded)
// - Inheritance & Polymorphism (Person -> Student, virtual report())
// - Template Programming + STL (mean<T>(), vector/array/accumulate)

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <numeric>
#include <limits>
#include <stdexcept>

using namespace std;

namespace srs { // (could be split later into headers/sources)

    // -------------------- Types --------------------
    // Simple struct for marks (Arrays)
    struct Marks { array<float, 5> v{}; }; // PHYS, CHEM, MATH, PROG, ENG

    // Base class (Inheritance & Polymorphism)
    class Person {
    public:
        virtual ~Person() = default;
        virtual void report(ostream& os) const = 0; // Polymorphic output
    };

    // Derived class (Classes) + Pointers & Recursion for average
    class Student : public Person {
    public:
        string name, roll;
        Marks marks;

        static float sumRec(const float* p, int n) { // Pointers + Recursion
            return n ? *p + sumRec(p + 1, n - 1) : 0.0f;
        }
        float average() const { return sumRec(marks.v.data(), 5) / 5.0f; }

        char grade() const {                       // simple grading rule
            float a = average();
            if (a >= 80) return 'A';
            if (a >= 60) return 'B';
            if (a >= 40) return 'C';
            if (a >= 35) return 'D';
            return 'E';
        }

        void report(ostream& os) const override {  // virtual (Polymorphism)
            os << "\n------------------ REPORT CARD ------------------\n";
            os << "Name: " << name << "   Roll: " << roll << "\n";
            os << "PHYS " << marks.v[0] << " | CHEM " << marks.v[1]
                << " | MATH " << marks.v[2] << " | PROG " << marks.v[3]
                << " | ENG " << marks.v[4] << "\n";
            os << "PERCENTAGE: " << fixed << setprecision(2) << average()
                << "%   GRADE: " << grade() << "\n";
            os << "-------------------------------------------------\n";
        }
    };

    // Operator Overloading (pretty one-line print)
    inline ostream& operator<<(ostream& os, const Student& s) {
        os << s.name << " (" << s.roll << ")  "
            << "PH " << s.marks.v[0] << "  CH " << s.marks.v[1]
            << "  MA " << s.marks.v[2] << "  PR " << s.marks.v[3]
            << "  EN " << s.marks.v[4];
        return os;
    }

    // Template Programming + STL
    template <typename It>
    double mean(It b, It e) {
        if (b == e) return 0.0;
        return accumulate(b, e, 0.0) / static_cast<double>(distance(b, e));
    }

    // -------------------- Helpers (Functions) --------------------
    inline void flushLine() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }

    inline string readNonEmpty(const string& label) {
        cout << label;
        string s; getline(cin, s);
        while (s.empty()) { cout << "  ! Cannot be empty. Try again: "; getline(cin, s); }
        return s;
    }
    inline float readMark(const string& label) {
        float x;
        while (true) {
            cout << label << " (0-100): ";
            if (cin >> x && x >= 0 && x <= 100) { flushLine(); return x; }
            cout << "  ! Enter a number between 0 and 100.\n";
            cin.clear(); flushLine();
        }
    }
    inline int readInt(const string& label) {
        int v;
        while (true) {
            cout << label;
            if (cin >> v) { flushLine(); return v; }
            cout << "  ! Invalid. Try again.\n";
            cin.clear(); flushLine();
        }
    }
    inline int findByRoll(const vector<Student>& v, const string& r) {
        for (size_t i = 0;i < v.size();++i) if (v[i].roll == r) return (int)i;
        return -1;
    }

    // -------------------- Storage (Files + Exceptions) --------------------
    static const char* FILEPATH = "studentRecord.csv";

    inline vector<Student> loadAll() {
        vector<Student> v;
        ifstream in(FILEPATH);
        if (!in) return v; // first run: file not present yet

        string line;
        while (getline(in, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            Student s; string cell;

            getline(ss, s.name, ',');
            getline(ss, s.roll, ',');
            for (int i = 0;i < 5;i++) {
                if (!getline(ss, cell, i < 4 ? ',' : '\n')) cell = "0";
                try { s.marks.v[i] = cell.empty() ? 0.0f : stof(cell); } // parsing guard
                catch (...) { s.marks.v[i] = 0.0f; }                      // simulate error-check
            }
            v.push_back(s);
        }
        return v;
    }

    inline void saveAll(const vector<Student>& v) {
        ofstream out(FILEPATH, ios::trunc);
        if (!out) throw runtime_error("Cannot open file for writing.");
        for (const auto& s : v) {
            out << s.name << ',' << s.roll << ','
                << s.marks.v[0] << ',' << s.marks.v[1] << ','
                << s.marks.v[2] << ',' << s.marks.v[3] << ','
                << s.marks.v[4] << '\n';
        }
    }

    // -------------------- Core Features (match your flowchart) --------------------
    // choice 1: student records -> input >> student name/ID -> output << Show records (+ summary)
    inline void student_records() {
        auto all = loadAll();

        cout << "\n[Student records]\n";
        string name = readNonEmpty("Enter student name: ");
        string roll = readNonEmpty("Enter roll/ID: ");

        if (findByRoll(all, roll) != -1) {
            cout << "  ! Duplicate roll. Record not added.\n";
        }
        else {
            Student s; s.name = name; s.roll = roll;
            const char* labs[5] = { "PHYSICS","CHEMISTRY","MATHEMATICS","PROGRAMMING","ENGLISH" };
            for (int i = 0;i < 5;i++) s.marks.v[i] = readMark(labs[i]);
            all.push_back(s);

            try { saveAll(all); cout << "Saved.\n"; }
            catch (const exception& e) { cout << "File save error: " << e.what() << "\n"; }
        }

        if (all.empty()) { cout << "No data.\n"; return; }
        cout << "\n-- Show records --\n";
        int i = 1; for (const auto& s : all) cout << i++ << ") " << s << '\n';

        // Summary statistics (Integration)
        vector<double> avgs; avgs.reserve(all.size());
        for (const auto& s : all) avgs.push_back(s.average());
        cout << "Class average (%): " << mean(avgs.begin(), avgs.end()) << "\n";
    }

    // choice 2: calculate grades -> input >> ID -> output << Grades
    inline void calculate_grades() {
        cout << "\n[Grade-calculator]\n";
        string r = readNonEmpty("Enter roll/ID: ");
        auto all = loadAll();
        int idx = findByRoll(all, r);
        if (idx == -1) { cout << "Not found.\n"; return; }
        float a = all[idx].average();
        cout << "Average: " << fixed << setprecision(2) << a
            << "%  Grade: " << all[idx].grade() << "\n";
    }

    // choice 3: generate report -> input >> ID -> output << Report
    inline void generate_report() {
        cout << "\n[Generate report]\n";
        string r = readNonEmpty("Enter roll/ID: ");
        auto all = loadAll();
        int idx = findByRoll(all, r);
        if (idx == -1) { cout << "Not found.\n"; return; }

        const Person& p = all[idx];  // Polymorphism (call virtual through base)
        p.report(cout);
    }

} // namespace srs

// -------------------- Main (Basics + Flow Control) --------------------
int main() {
    using namespace srs;
    cout << fixed << setprecision(2);

    while (true) {
        cout << "\nStart Program\n";
        cout << "MAIN MENU (Read User's Choice)\n"
            << "choice 1: student records\n"
            << "choice 2: calculate grades\n"
            << "choice 3: generate report\n"
            << "choice 0: exit\n";
        int ch = readInt("Enter choice: ");

        if (ch == 1) { student_records();   cout << "\nBack to main menu\n"; }
        else if (ch == 2) { calculate_grades();  cout << "\nBack to main menu\n"; }
        else if (ch == 3) { generate_report();   cout << "\nBack to main menu\n"; }
        else if (ch == 0) { cout << "End program\n"; break; }
        else { cout << "Invalid choice.\n"; }
    }
    return 0;
}


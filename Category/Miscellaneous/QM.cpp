// Quine-McCluskey Tabular Method
// Find a minimum expression for Boolean functions

/*
Reference: 
https://www.tutorialspoint.com/digital_circuits/digital_circuits_quine_mccluskey_tabular_method.htm

Follow these steps for simplifying Boolean functions using Quine-McClukey tabular method.

    Step 1 − Arrange the given min terms in an ascending order and make the 
    groups based on the number of ones present in their binary representations. 
    So, there will be at most 'n+1' groups if there are 'n' Boolean variables 
    in a Boolean function or 'n' bits in the binary equivalent of min terms.

    Step 2 − Compare the min terms present in successive groups. If there is a 
    change in only one-bit position, then take the pair of those two min terms. 
    Place this symbol '_' in the differed bit position and keep the remaining 
    bits as it is.

    Step 3 − Repeat step2 with newly formed terms till we get all prime implicants.

    Step 4 − Formulate the prime implicant table. It consists of set of rows and 
    columns. Prime implicants can be placed in row wise and min terms can be placed 
    in column wise. Place '1' in the cells corresponding to the min terms that are 
    covered in each prime implicant.

    Step 5 − Find the essential prime implicants by observing each column. If the 
    min term is covered only by one prime implicant, then it is essential prime 
    implicant. Those essential prime implicants will be part of the simplified 
    Boolean function.

    Step 6 − Reduce the prime implicant table by removing the row of each essential 
    prime implicant and the columns corresponding to the min terms that are covered 
    in that essential prime implicant. Repeat step 5 for Reduced prime implicant table. 
    Stop this process when all min terms of given Boolean function are over.
*/

#include <algorithm>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Tabular {
    // limits
    enum : short {
        MAX_NUM_VAR = 6,
        MAX_NUM_MIN_TERM = 1 << MAX_NUM_VAR,
    };
    const string mVarList = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int mNumVar;
    int mNumMinTerm;
    int mNumTab;
    vector<int> mMinTermInt;
    map<int, vector<int>, less<int>> mGroup;
    vector<vector<int>> mTab;
    vector<string> mBinEqu;  // binary equivalent

    vector<string> func;

   private:
    auto countBits(int i) -> int {
        return bitset<MAX_NUM_VAR>(i).count();
    }

    auto countBits(const string& s) -> int {
        int cnt = 0;
        for (auto c : s)
            if (c == '1') cnt++;
        return cnt;
    }

    auto bitStr(int i) -> string {
        return bitset<MAX_NUM_VAR>(i).to_string().substr(MAX_NUM_VAR - mNumVar);
    }

    auto primeImplicant(const string& s) -> string {
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '-') ans.append(1, mVarList[i]);
            if (s[i] == '0') ans.append(1, '\'');
        }
        return ans;
    }

    auto canMerge(const string& l, const string& r) -> string {
        int diffCnt = 0, diff = -1;
        for (int i = 0; i < l.length(); ++i) {
            if (l[i] != r[i]) {
                diff = i;
                diffCnt++;
            }
        }
        if (diffCnt == 0) {
            return string(l);
        } else if (diffCnt > 1) {
            return "";
        } else {
            string ret(l);
            ret[diff] = '-';
            return ret;
        }
    }

   public:
    Tabular() : mNumVar(0), mNumMinTerm(0){};

    auto showTable() -> void {
        cout << setw(3 * MAX_NUM_VAR) << "Min Terms"
             << setw(MAX_NUM_VAR * 3) << "Logic Variables" << endl;
        for (const auto& g : mGroup) {
            cout << "Group " << g.first << ":" << endl;
            for (auto t : g.second) {
                string curTabLine = "";
                for (auto i : mTab[t]) {
                    curTabLine += to_string(i) + " ";
                }
                cout << setw(3 * MAX_NUM_VAR) << curTabLine
                     << setw(MAX_NUM_VAR);
                for (auto i : mBinEqu[t]) {
                    cout << i << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    // Step 0: input data
    // Format:
    //      1-st Line: [number of logic variables] [number of minimum terms]
    //      2-nd Line: [minimum terms in interger format]
    auto initialize(const string& inFilePath) -> bool {
        fstream fin(inFilePath);
        if (!fin.is_open()) {
            cout << "Cannot open "
                 << inFilePath << "!" << endl;
            return false;
        }

        fin >> mNumVar >> mNumMinTerm;
        if (mNumVar > MAX_NUM_VAR) {
            cout << "Too many variables!" << endl;
            return false;
        }
        if (mNumMinTerm > MAX_NUM_MIN_TERM) {
            cout << "Too many terms!" << endl;
            return false;
        }

        mMinTermInt.resize(mNumMinTerm);
        for (auto& i : mMinTermInt) {
            if (fin.eof()) {
                cout << "Unexpected EOF!" << endl;
                return false;
            }
            fin >> i;
        }
        return true;
    };
    // Step 1: divide
    auto divide() -> void {
        mNumTab = mNumMinTerm;
        mTab.resize(mNumTab);
        mBinEqu.resize(mNumTab);
        int tol = 0;
        for (auto i : mMinTermInt) {
            mGroup[countBits(i)].push_back(tol);
            mTab[tol].push_back(i);
            mBinEqu[tol] = bitStr(i);
            tol++;
        }
    }
    // Step 2&3: reduce and repeat
    auto reduce() -> bool {
        // result of this step of reduction
        decltype(mGroup) rGroup;
        decltype(mTab) rTab;
        decltype(mBinEqu) rBinEqu;

        auto mergeGroup = [&](const vector<int>& g, const vector<int>& ng) -> void {
            string cBinEqu;
            vector<int> cTab;
            for (auto t : g) {
                for (auto nt : ng) {
                    cBinEqu = canMerge(mBinEqu[t], mBinEqu[nt]);
                    if (cBinEqu == "") continue;
                    bool uni = true;
                    for (const auto& s : rBinEqu) {
                        if (cBinEqu == s) {
                            uni = false;
                            break;
                        }
                    }
                    if (uni) {
                        cTab.assign(mTab[t].begin(), mTab[t].end());
                        cTab.insert(cTab.end(), mTab[nt].begin(), mTab[nt].end());

                        auto last = unique(cTab.begin(), cTab.end());
                        cTab.erase(last, cTab.end());
                        sort(cTab.begin(), cTab.end());

                        rBinEqu.push_back(cBinEqu);
                        rTab.push_back(cTab);
                    }
                }
            }
        };

        auto g = mGroup.begin();
        auto ng = next(g);
        while (ng != mGroup.end()) {
            mergeGroup(g->second, ng->second);
            g++;
            ng++;
        }

        for (int i = 0; i < rTab.size(); ++i) {
            rGroup[countBits(rBinEqu[i])].push_back(i);
        }
        if (!rGroup.empty()) {
            mGroup.swap(rGroup);
            mBinEqu.swap(rBinEqu);
            mTab.swap(rTab);
            return true;
        }
        return false;
    }
    // Step 4&5&6: generate
    auto generate() -> void {
        map<string, vector<int>> primeTab;
        map<int, string> minTermToPrime;
        int tabSize = 1 << mNumVar;
        int cover = mNumMinTerm;
        vector<int> minTermsDep(tabSize, -1);

        for (int i = 0; i < mTab.size(); ++i) {
            auto curPrime = primeImplicant(mBinEqu[i]);
            primeTab[curPrime] = mTab[i];
            for (auto j : mTab[i])
                minTermToPrime[j] = curPrime;
        }

        for (auto i : mMinTermInt) {
            if (minTermsDep[i] == -1)
                minTermsDep[i] = 0;
            minTermsDep[i]++;
        }

        while (cover > 0) {
            int idx = 0;
            while (idx < tabSize) {
                if (minTermsDep[idx] == 1) break;
                idx++;
            }
            auto esPrime = minTermToPrime[idx];
            func.push_back(esPrime);
            for (auto i : primeTab[esPrime]) {
                minTermsDep[i]--;
                if (minTermsDep[i] == 0) {
                    cover--;
                }
            }
        }
    }
    // End
    auto getFunc() -> string {
        if (func.empty()) return "";
        sort(func.begin(), func.end());
        string ans = func[0];
        for (int i = 1; i < func.size(); ++i) {
            ans += " + " + func[i];
        }
        return ans;
    }
};

int main(void) {
    Tabular testTabular;
    testTabular.initialize("input");
    testTabular.divide();
    int c = 0;
    do {
        cout << endl
             << "Merge Step " << c++
             << endl
             << endl;
        testTabular.showTable();
    } while (testTabular.reduce());
    testTabular.generate();
    cout << endl
         << "Simplified Boolean Function: F = " << testTabular.getFunc() << endl;
    return 0;
}
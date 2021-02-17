#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void printResult(uint32_t val)
{
    uint32_t n = val;

    if (n <= 1)
    {
        cout << n << endl;
        return;
    }
    
    vector<string> work(n, "");
    work.resize(n);
    
    for (int i = 0; (i < n) && (pow(2, i) <= n); i++)
    {
        // Generate initial zeros
        size_t zeros = pow(2, i);
        std::string line{""};
        line.assign(zeros, '0');

        // Generate series
        volatile bool current_one = true;
        uint32_t serie = pow(2, (i+1));
        while(line.length() < n)
        {
            string tmp{""};
            if (current_one)
            {
                tmp.assign(serie, '1');
            }
            else
            {
                tmp.assign(serie, '0');
            }
            current_one = !current_one;
            line.append(tmp);
        }

        if (line.length() > n)
        {
            line = line.substr(0, n);
        }

        for (uint32_t m = 0; m < n; m++)
        {
            string work_tmp_string = work[m];
        
            std::string new_tmp_string = line.substr((n - m - 1), 1);
            new_tmp_string.append(work_tmp_string);
            work[m] = new_tmp_string;
        }
    }

    for (uint32_t i = 0; i < work.size(); i++)
    {
        string update{"1"};
        uint32_t needed_zeros = n - work[i].size() - 1;

        string tmp_zeros{""};
        tmp_zeros.assign(needed_zeros, '0');
        update.append(tmp_zeros).append(work[i]);
        
        //Print the resulting string
        cout << update << endl;
    }
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    uint32_t n;
    cin >> n;
    printResult(n);
    return 0;
}
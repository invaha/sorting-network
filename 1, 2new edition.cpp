#include <iostream>
#include <vector>
#include <string>
using namespace std;
void read_input(vector<int>&inp,vector<string>&ar,int &m,int&n)
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        ar.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        inp.push_back(b);
    }
}

void process(vector<int>&inp,bool &err,vector<string>ar,int m,int n)
{
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n - 1; i++)
            if (ar[i][j] != '-') {
                if (ar[i][j] < 'a' || ar[i][j] > 'z')
                {
                    cout << "Invalid Network\n";
                    err = true;
                    return;
                }

                if (!err)
                {
                    int cnt = 0;
                    for (int k = 0; k < n; k++)
                    {

                        if (ar[i][j] == ar[k][j])
                        {
                            cnt++;
                        }

                    }
                    if(cnt==2)
                    {
                        for (int k = i+1; k < n; k++)
                        {

                            if (ar[i][j] == ar[k][j])
                            {
                                if (inp[i] > inp[k])
                                {
                                    swap(inp[i] ,inp[k]);
                                }
                            }
                        }
                    }
                    else
                    {
                       cout << "Invalid Network\n";
                       err = true;
                       return;
                    }
                }
            }
}

void generate_output(vector<int> inp,int n)
{
    bool flag = false;
     for (int i = 0; i < n - 1; i++)
        if (inp[i] > inp[i+1])
        {
            cout << "Not sorted\n";
            flag = true;
        }
    if (!flag)
        cout << "Sorted\n";
}

int main()
{
    int m;
    int n;
    vector<string> ar;
    bool err = false;
    vector<int> inp;
    read_input(inp,ar,m,n);
    process(inp,err,ar,m,n);
    if(!err)
    {
        generate_output(inp,n);
    }
}

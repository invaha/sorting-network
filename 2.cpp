#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> read_numbers(int count) {
    vector<int> result;
    for (int i = 0; i < count; i++) {
        int number;
        cin >> number;
        result.push_back(number);
    }
    return result;
}

vector<string> read_network(int num_of_inputs) {
    vector<string> result;
    for (int i = 0; i < num_of_inputs; i++) {
        string line;
        cin >> line;
        result.push_back(line);
    }
    return result;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

bool is_valid_network(vector<string> network,unsigned int num_of_stages)
{
    for(unsigned int q=0;q<network.size();q++)
    {
        if(num_of_stages!=network.at(q).length())
        {
            return false;
        }
    }
    for(unsigned int q=0;q<network.size();q++)
    {
        for(unsigned int w=0;w<num_of_stages;w++)
        {
            //a:97
            //z:122
            if(network.at(q)[w]!='-')
            {
                if((((int)network.at(q)[w])>122)||(((int)network.at(q)[w])<97))
                {
                    return false;
                }
            }
        }
    }
    for(unsigned int q=0;q<num_of_stages;q++)
    {
        for(unsigned int w=0;w<network.size();w++)
        {
            int count=0;
            for(unsigned int e=0;e<network.size();e++)
            {
                if(network.at(w)[q]==network.at(e)[q])
                {
                    count++;
                }
            }
            if(count!=2)
            {
                return false;
            }
        }
    }
    return true;
}

void apply_stage(vector<string> network, int j,vector<int>& numbers) {
    for (unsigned int i = 0; i < network.size() - 1; i++) {
        if (network[i][j] == '-')
            continue;

        for (unsigned int k = i + 1; k < network.size(); k++)
            if (network[i][j] == network[k][j])
                if (numbers[i] > numbers[k])
                    swap(numbers[i], numbers[k]);
    }
}

void apply_network(vector<string> network,
                   vector<int>& numbers)
{
    for (unsigned int j = 0; j < network[0].size(); j++)
        apply_stage(network, j, numbers);
}

int main()
{
    int num_of_inputs;
    unsigned int num_of_stages;

    cin >> num_of_inputs >> num_of_stages;

    vector<string> network = read_network(num_of_inputs);
    vector<int> numbers = read_numbers(num_of_inputs);

    if (!is_valid_network(network, num_of_stages))
    {
        cout << "Invalid network\n";
        return -1;
    }

    apply_network(network, numbers);

    if (is_sorted(numbers.begin(), numbers.end()))
        cout << "Sorted";
    else
        cout << "Not sorted";
    cout << endl;
}

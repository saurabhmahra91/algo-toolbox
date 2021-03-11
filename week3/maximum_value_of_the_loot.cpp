#include <iostream>
#include <vector>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    while (capacity > 0 && weights.empty() == false)
    {

        double best = -1;
        int best_index = -1;
        for (int i = 0; i < weights.size(); i++)
        {
            double v_i = values.at(i);
            double w_i = weights.at(i);
            if ( v_i/w_i > best)
            {
                best = max(best, v_i/w_i);
                best_index = i;
            }
        }

        value += best*min(capacity, weights.at(best_index));
        values.erase(values.begin() + best_index);

        capacity -= min(capacity, weights.at(best_index));
        weights.erase(weights.begin() + best_index);


    }

    return value;
}

int main()
{
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}

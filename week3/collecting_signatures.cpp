#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Interval
{
    int start, end;
};

int d(Interval a)
{
    return a.end-a.start;
}

void sort(vector<Interval> &a)
{
    vector<Interval> b;
    int x = a.size();
    for (int t = 0; t < x; t++)
    {
        vector<Interval>::iterator minn = a.begin();
        for (vector<Interval>::iterator i = a.begin(); i != a.end(); i++)
        {
            if ((*i).start < (*minn).start)
            {
                minn = i;
            }
        }
        b.push_back(*minn);
        a.erase(minn);
    }
    a = b;
    return;
}

void sortByLength(vector<Interval> &a)
{
    vector<Interval> b;
    int x = a.size();
    for (int t = 0; t < x; t++)
    {
        vector<Interval>::iterator minn = a.begin();
        for (vector<Interval>::iterator i = a.begin(); i != a.end(); i++)
        {
            if (d(*i) < d(*minn))
            {
                minn = i;
            }
        }
        b.push_back(*minn);
        a.erase(minn);
    }
    a = b;
    return;
}

bool intersect(Interval &a, Interval b)
{
    if (a.start > b.end)
    {
        return false;
    }
    else if ((b.start <= a.start) && (a.start <= b.end))
    {

        if (a.end > b.end)
        {
            a.end = b.end;
        }
        return true;
    }
    else
    {
        if ((b.end >= a.end) && (a.end >= b.start))
        {
            a.start = b.start;
            return true;
        }
        else if (a.end > b.end)
        {
            a = b;
            return true;
        }
        else
        {
            return false;
        }
    }
}

// ! needs a sorted (by length) vector of intervals
vector<int> optimal_points(vector<Interval> &intervals)
{
    vector<int> points;

    while (!intervals.empty())
    {

        //! hope curr will not have its past value
        Interval intersection = intervals[0], curr;

        for (vector<Interval>::iterator i = intervals.begin(); i != intervals.end();)
        {
            if (intersect(intersection, *i))
            {
                i = intervals.erase(i);
            }
            else
            {
                i++;
            }
        }

        points.push_back(intersection.start);
    }


    return points;
}

int main()
{
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    for (size_t i = 0; i < intervals.size(); ++i)
    {
        cin >> intervals[i].start >> intervals[i].end;
    }
    sort(intervals);
    vector<int> points = optimal_points(intervals);
    cout << points.size() << "\n";

    for (int i = 0; i < points.size(); i++)
    {
        cout << points[i] << " ";
    }
    
}

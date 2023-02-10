// Priority scheduling algorithm
//Author : Syed Shafkatul Hassan
//ID=2012020130
//Section:G
//Batch:53
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define in insert
struct process
{
    ll pid;//process id
    ll att;//arival time
    ll bt;//birst time
    ll tat;//trun around time
    ll wt;//waiting time
    ll rt;//responsetime
    ll pt;//prioroty

    bool operator==(const process &p)//For using erase function
    {
        return pid == p.pid;
    }
};

bool cmp(process a, process b)//comparing function
{
    if (a.att== b.att)
        return a.pt< b.pt;
    return a.att < b.att;
}

signed main()
{
    ll n;
    cout << "Enter the number of process: ";
    cin >> n;//total process
    vector<process> p(n);
    for (ll i = 0; i < n; i++)
    {
        cout << "Enter  priority, arrival time and burst time of process ";
        cin >> p[i].pt >> p[i].att >> p[i].bt;//taking input
        p[i].pid = i + 1;//incrementing process id
        p[i].rt = -1;
    }
    sort(p.begin(), p.end(), [](process a, process b)//sorting acording to arival time
    {
        return a.att < b.att;
    });
    vector<ll> gantt;//gantt cchart
    vector<process> ready_queue;//vector of proceses
    ll time = 0;
    // int i = 0;
    while (gantt.size() != n)//till gantchart size will be not equal to n this loop will continue
    {
        // if (ready_queue.empty())
        // {
        for (ll i = 0; i < n; i++)
        {
            if (p[i].att == time)//if arival time ==time then it will continue
            {
                ready_queue.pb(p[i]);
            }
        }
        sort(p.begin(), p.end(), [](process a, process b)//sorting acording to prioroty
        {
            return a.pt < b.pt;
        });
        // }
        if (!ready_queue.empty())//while vcotor of process not empty iut will continue
        {
            process curr = ready_queue[0];
            ready_queue.erase(ready_queue.begin());//errasing from ready que
            if (curr.rt == -1) //when currtime will be -1 this will execute
                curr.rt = time - curr.att;
            gantt.pb(curr.pid);//pushing current process id
            for (ll timet = 0; timet < curr.bt; timet++)
            {
                time++;//incrementing time
                for (ll i = 0; i < n; i++)
                {
                    if (p[i].att == time)//when arival time will be time this will continue
                    {
                        ready_queue.pb(p[i]);
                    }
                }
                sort(ready_queue.begin(), ready_queue.end(), [](process a, process b)//sorting according to prioroty
                {
                    return a.pt < b.pt;
                });
            }

            curr.tat = time - curr.att;//finding tat time
            curr.wt = curr.tat - curr.bt;//finding waiting time
            for (ll i = 0; i < n; i++)
            {
                if (p[i].pid == curr.pid)
                {
                    p[i] = curr;
                    break;
                }
            }
        }
    }

    cout << "Gantt chart: ";
    for (ll i = 0; i < gantt.size(); i++)
        cout << gantt[i] << " ";
    cout << endl;
    cout << "Process\tArival time\tBurst time\tPriority\tTurn around time\tWaiting time\tResponse time" << endl;
    for (ll i = 0; i < n ; i++)
    {
        cout << p[i].pid << "\t" << p[i].att << "\t\t" << p[i].bt << "\t\t" << p[i].pt << "\t\t" << p[i].tat<< "\t\t" << p[i].wt << "\t\t" << p[i].rt << endl;
    }


}


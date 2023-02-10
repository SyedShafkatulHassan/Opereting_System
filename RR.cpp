// Round Robin
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
struct process //define and initialize structure
{
    ll pd;     //Process id
    ll att;   //Arrival time
    ll bt;     //Bust time
    ll tat;    //Turn around time
    ll wt;     //Waitnig time
    ll rem;    //Remaining time
    ll rt;     //Response time
    bool done;  //Done
    bool iqe;

    bool operator==(process &p)
    {
        return pd == p.pd;
    }
    bool operator!=( process &p)
    {
        return pd != p.pd;
    }
};

bool cmp(process a, process b)  //Compare between arrival time
{
    return a.att < b.att;
}

int main()
{
    int noproc;
    cout << "Enter total process:";
    cin >> noproc;  //input number of processes
    int qu;
    cout << "Enter the quantum: ";
    cin >> qu;      //input time quantum
    vector<process> p(noproc);
    for (int i = 0; i < noproc; i++)
    {
        cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        cin >> p[i].att >> p[i].bt; //input arrival time and bus time
        p[i].pd = i + 1;    //increamenting process id
        p[i].rem = p[i].bt; //setting rem to bus time
        p[i].rt = -1;       //setting rt to -1
        p[i].done = false;
    }
    sort(p.begin(), p.end(), cmp);  //sorting structure according to compare function
    int time = 0;       //setting time = 0
    vector<int> gantt;  //taking gang chart
    queue<process> q;   //taking a queue of processes
    q.push(p[0]);
    p[0].iqe = true;
    int i = 1;
    while (!q.empty())  //taking inputs till queue is not empty
    {
        process curr = q.front();   //taking current process at queue front
        q.pop();            //popping queue
        curr.iqe = false;
        if (curr.rt == -1)  //when current remaining time will be -1 then it will execute
        {
            curr.rt = time - curr.att;
        }
        if (curr.rem<= qu)  //when current remaining time is less then or erquals to qu, it will execute
        {
            time = time + curr.rem; //we will increament current remaining time with time
            curr.rem = 0;   //making current remaining time zero
            curr.done = true;
            curr.tat = time - curr.att;     //finding current turn arround time
            curr.wt = curr.tat - curr.bt;   //finding current waiting time
            gantt.pb(curr.pd);           //pushing current process id into gang chart
            for (; i < noproc; i++)
            {
                if (p[i].att <= time)   //when arrival time is less then or equals to time it will execuite
                {
                    q.push(p[i]);
                    p[i].iqe = true;
                }
                else    //Otherwise it will break
                {
                    break;
                }
            }
        }
        else
        {
            time =time+ qu;         //increamenting time with qu
            curr.rem =curr.rem- qu;
            gantt.pb(curr.pd);      //pushing current process id into gang chart
            for (; i < noproc; i++)
            {
                if (p[i].att <= time)   //when arrival time is less then or equals to time it will execuite
                {
                    q.push(p[i]);
                    p[i].iqe = true;
                }
                else                    //Otherwise it will break
                {
                    break;
                }
            }
            q.push(curr);
            curr.iqe = true;
        }
        if (curr.done)      //if currnt.done is true then it will exucute
        {
            for (auto &i : p)
            {
                if (i == curr)
                {
                    i = curr;
                    break;
                }
            }
        }
    }
      cout << "Gantt Chart: ";
    for (int i = 0; i < gantt.size(); i++)  //printing gang chart
        cout << gantt[i] << " ";
    cout << endl;
    cout << "PID\tAT\tBT\tRT\tTAT\tWT\n";
    for (auto i : p)
        cout << i.pd << "\t" << i.att << "\t" << i.bt << "\t" << i.rt << "\t" << i.tat << "\t" << i.wt << "\n";

}

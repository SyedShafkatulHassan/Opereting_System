//Author:Syed Shafkatyil Hassan
#include <bits/stdc++.h>
using namespace std;
struct process
{
    int ProcessID;
    int Arivaltime;
    int BirstTime;
    int TrunAroundTime;
    int WaitingTime;
    int ResponseTime;
    int complissionTime;
} ;

bool compare(process a, process b)
{
    return a.Arivaltime < b.Arivaltime;
}

int main()
{
    int no_of_process;
    cout << "Enter the number of process: ";
    cin >> no_of_process;
    vector<process> p(no_of_process);
    for (int i = 0; i < no_of_process; i++)
    {
        cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        cin >> p[i].Arivaltime >> p[i].BirstTime;
        p[i].ProcessID = i + 1;
    }
    sort(p.begin(), p.end(), compare);
    int CurentTime = 0;
    for (int i = 0; i < no_of_process; i++)
    {
        if (CurentTime < p[i].Arivaltime)
        {
            CurentTime = p[i].Arivaltime;
        }
        p[i].ResponseTime = CurentTime-p[i].Arivaltime;
        CurentTime = CurentTime+p[i].BirstTime;
        p[i].TrunAroundTime = CurentTime - p[i].Arivaltime;
        p[i].WaitingTime = p[i].TrunAroundTime - p[i].BirstTime;
        p[i].complissionTime=CurentTime;
    }
    cout << "Process        ArivalTime       BirstTime  ResponseTime  TrunAroundTime  WaitingTime  Complision time\n";
    for (int i = 0; i < no_of_process; i++)
    {
        cout << p[i].ProcessID << "\t" << p[i].Arivaltime << "\t" << p[i].BirstTime << "\t" << p[i].ResponseTime << "\t" << p[i].TrunAroundTime << "\t" << p[i].WaitingTime <<"\t"<<p[i].complissionTime <<"\n";
    }

}

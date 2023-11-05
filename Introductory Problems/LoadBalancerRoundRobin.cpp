#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int A_T;
    int C_T;
    int serv_idx;
    node(int A_T, int C_T, int serv_idx)
    {
        this->A_T = A_T;
        this->C_T = C_T;
        this->serv_idx = serv_idx;
    }
};
struct compare
{
    bool operator()(node *a, node *b)
    {
        return a->C_T > b->C_T;
    }
};

vector<int> getServerIndex(int NO_OF_REQUESTS, vector<int> A_T, vector<int> C_T,int NO_of_Servers)
{

    map<int, int> A_T_to_C_T;
    for (int i = 0; i < A_T.size(); i++)
    {
        A_T_to_C_T[A_T[i]] = C_T[i];
    }
    sort(A_T.begin(), A_T.end());

    priority_queue<node *, vector<node *>, compare> pq;

    vector<int> server_assignments(A_T.size(), -1);

    int server_idx = 1;
    server_assignments[0] = server_idx;

    pq.push(new node(A_T[0], A_T_to_C_T[A_T[0]], 1));

    for (int i = 1; i < A_T.size(); i++)
    {
        int Curr_AT = A_T[i];
        int Least_CT = pq.top()->C_T;
        int Least_ass_Serv = pq.top()->serv_idx;
        if (Least_ass_Serv > NO_of_Servers)
            continue;

        if (Curr_AT >= Least_CT)
        {
            pq.pop();
            pq.push(new node(Curr_AT, A_T_to_C_T[Curr_AT], Least_ass_Serv));
            server_assignments[i] = Least_ass_Serv;
        }
        else
        {
            server_idx++;
            pq.push(new node(Curr_AT, A_T_to_C_T[Curr_AT], server_idx));
            server_assignments[i] = server_idx;
        }
    }

    return server_assignments;
}

int main()
{

    int NO_OF_REQUESTS=3;
    int NO_OF_SERVERS=5;
    vector<int> A_T = {2, 4, 1, 8, 9};
    vector<int> C_T = {9, 13, 3, 12, 14};

    // Call the function
    vector<int> server_assignments = getServerIndex(NO_OF_SERVERS, A_T, C_T,NO_OF_REQUESTS);

    // Print the result
    for (int i = 0; i < server_assignments.size(); i++)
    {
        cout << server_assignments[i] << " ";
    }
    cout << endl;

    return 0;
}
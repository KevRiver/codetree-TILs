#include <bits/stdc++.h>

using namespace std;

struct Position{
    int l;
    int pos;
};

vector<string> tokenize(const string& s, const char* delimiter){
    vector<string> toks;
    size_t start, pos = 0;
    while((start = s.find_first_not_of(delimiter, pos)) != string::npos){
        pos = s.find_first_of(delimiter, start + 1);
        toks.push_back(s.substr(start, pos-start));
    }
    return toks;
}

int main() {
    
    int N, M, Q;
    cin >> N >> M >> Q;

    unordered_map<string, Position> tracker;
    vector<list<string>> lane(M);
    
    int X = N/M;
    for(int i=0; i<N; ++i){
        string name; cin >> name;
        lane[i/X].push_back(name);
        tracker[name] = {i/X, i%X};
    }

    function<void(int)> update_tracker = [&](int lane_idx){
        const list<string>& l = lane[lane_idx];
        for(auto it = l.begin(); it != l.end(); ++it){
            int pos = distance(l.begin(), it);
            tracker[*it] = {lane_idx, pos};
        }
    };

    for(int i=0; i<Q; ++i){
        int op; cin >> op; 
        switch(op){
            case 1:
            {
                string a; cin >> a;
                string b; cin >> b;

                Position p = tracker[a];
                Position q = tracker[b];

                list<string>& l1 = lane[p.l];
                auto it = next(l1.begin(), p.pos);
                auto jt = next(it, 1);

                list<string>& l2 = lane[q.l];
                auto kt = next(l2.begin(), q.pos);
                l2.splice(kt, l1, it, jt);

                update_tracker(p.l);
                update_tracker(q.l);
            }
            break;
            case 2:
            {
                string a; cin >> a;
                Position p = tracker[a];
                list<string>& l1 = lane[p.l];
                auto it = next(l1.begin(), p.pos);
                l1.erase(it);
                tracker.erase(a);
                update_tracker(p.l);
            }
            break;
            case 3:
            {
                string a; cin >> a;
                string b; cin >> b;
                string c; cin >> c;

                Position p = tracker[a];
                Position q = tracker[b];
                Position r = tracker[c];

                list<string>& l1 = lane[p.l];
                auto it = next(l1.begin(), p.pos);
                auto jt = next(l1.begin(), q.pos + 1);

                list<string>& l2 = lane[r.l];
                auto kt = next(l2.begin(), r.pos);
                l2.splice(kt, l1, it, jt);

                update_tracker(p.l);
                update_tracker(r.l);
            }
            break;
        }       
    }

    for(int i=0; i<M; ++i){
        if(lane[i].empty()){
            cout << -1 << '\n';
            continue;
        }
        for(const string& name: lane[i]){
            cout << name << " ";
        }
        cout << '\n';
    }

    return 0;
}
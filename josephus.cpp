#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

typedef struct _node 
{
	int flag;
	int id;
} node;

list<node> Init(int n);
void Out(list<node> &l, int m);
void Print(list<node> l);

list<node> Init(int n)
{
	list<node> rl;
    for(int i=0; i<n; i++) {
        node n;
		n.flag = 1;
		n.id   = i + 1;
        rl.push_back(n);
	}

	return rl;
}

void Out(list<node> &l, int m)
{
	int s = 0;
	int ss = 0;
	list<node>::iterator it;
	list<node>::iterator itt;

	Print(l);
	while(true) {
	    it=l.begin();
		ss = 0;
	    for(itt=l.begin(); itt!=l.end(); ++itt) {
            if(itt->flag == 1) {
		        ss ++;
	        }
	    }
	    if(ss < m) {
		    cout << "no out return" << endl;
		    return;
		}
	
	    while(it!=l.end()) {
            if(it->flag == 1) {
			    s ++;
				cout << "id: " << it->id << " say: "<< s;
		    }
		    if(s < m) {
				++ it;
				cout << endl;
			    continue;
			}else {
				cout << " out";
                s = 0;
		        //it->flag = 0;
				l.erase(it++);
	            for(itt=l.begin(); itt!=l.end(); ++itt) {
                    if(itt->flag == 1) {
			            ss ++;
	                }
	            }

	            if(ss < m) {
				    cout << " return" << endl;
					return;
				} else {
                    ss = 0;
					//++ it;
				    cout << " continue" << endl;
				}
				Print(l);
            }
	    }
	}
}

void Print(list<node> l)
{
	if((size_t)0 < l.size()) {
        cout << "********left number********" << endl;
	    for(list<node>::iterator it=l.begin(); it!=l.end(); it ++) {
            if(it->flag == 1) {
			    cout << it->id << "\t";
		    }
	    }
        cout << "\n***************************" << endl;
	}
}

int main(int argc, char *argv[])
{
    list<node> l = Init(atoi(argv[1]));
	Out(l, atoi(argv[2]));
	Print(l);

	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define BUFSIZE 20
using namespace std;

void FIFO(int size, string a) {
    int     hit = 0;
    char    buf[a.length() + 1];
    strcpy(buf, a.c_str());

    vector<char> cache;
    for (int i = 0; i < a.length(); i++)
    {
        cout << buf[i];
        if(find(cache.begin(),cache.end(),buf[i]) != cache.end()) {
            hit++;
            cout << "  hit     ";
        } 
        else {
            cout << "  miss  ";
            if(cache.size() == size) {
                cout << cache[0] << ' ';
                cache.erase(cache.begin());
                cache.push_back(buf[i]);
            } else {
                cout << "  ";
                cache.push_back(buf[i]);
            }
        }
        for (int i = 0; i < cache.size(); i++)
        {
            cout << cache[i];
        }
        cout << endl;
    }
    cout << "Hit : " << hit << " Miss : " << a.length() - hit << endl;
    cout << "Hit ratio : " << hit / (float)a.length() << endl;
}

void LRU(int size, string a) {
    int     hit = 0;
    char    buf[a.length() + 1];
    strcpy(buf, a.c_str());

    vector<char> cache;
    for (int i = 0; i < a.length(); i++)
    {
        cout << buf[i];
        vector<char>::iterator it = find(cache.begin(),cache.end(),buf[i]);
        if(it != cache.end()) {
            hit++;
            cout << "  hit     ";
            cache.erase(it);
            cache.push_back(buf[i]);
        } 
        else {
            cout << "  miss  ";
            if(cache.size() == size) {
                cout << cache[0] << ' ';
                cache.erase(cache.begin());
                cache.push_back(buf[i]);
            } else {
                cout << "  ";
                cache.push_back(buf[i]);
            }
        }
        for (int i = 0; i < cache.size(); i++)
        {
            cout << cache[i];
        }
        cout << endl;
    }
    cout << "Hit : " << hit << " Miss : " << a.length() - hit << endl;
    cout << "Hit ratio : " << hit / (float)a.length() << endl;
}

void MIN(int size, string a) {
    int     hit = 0;
    char    buf[a.length() + 1];
    strcpy(buf, a.c_str());
    vector<char> cache;

    int dist[size];

    for (int i = 0; i < a.length(); i++)
    {   
        for(int m = 0; m < size; m++) {
            dist[m] = 1;
        }
        cout << buf[i];
        if(find(cache.begin(),cache.end(),buf[i]) != cache.end()) {
            hit++;
            cout << "  hit     ";
        } 
        else {
            cout << "  miss  ";
            if(cache.size() == size) {
                for (int k = 0; k < size; k++) {
                    for (int j = i + 1; j < a.length(); j++) {
                        if(cache[k] != buf[j]) dist[k]++;
                        else break;
                    }
                }
                int max = dist[0];
                int max_idx = 0;
                for (int k = 1; k <size; k++) { 
                    if(max < dist[k]) {
                        max = dist[k];
                        max_idx = k;
                    }
                }
                cout << cache[max_idx] << ' ';
                vector<char>::iterator it = find(cache.begin(),cache.end(),cache[max_idx]);
                cache.erase(it);
                cache.push_back(buf[i]);
            } else {
                cout << "  ";
                cache.push_back(buf[i]);
            }
        }
        for (int i = 0; i < cache.size(); i++)
        {
            cout << cache[i];
        }
        cout << endl;
    }
    cout << "Hit : " << hit << " Miss : " << a.length() - hit << endl;
    cout << "Hit ratio : " << hit / (float)a.length() << endl;
}

int main() {
    int     cache_size;
    string  input;

    cout << "arr : ";
    getline(cin,input);
    
    cout << "size : ";
    cin >> cache_size;
    cout << "------FIFO-------" << endl;
    FIFO(cache_size, input);
    cout << "------LRU--------" << endl;
    LRU(cache_size, input);
    cout << "------MIN--------" << endl;
    MIN(cache_size, input);
    cout << "-----------------" << endl;
}

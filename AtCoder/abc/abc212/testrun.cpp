#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long getMemoryUsage() {
  struct rusage usage;
  if(0 == getrusage(RUSAGE_SELF, &usage))
    return usage.ru_maxrss; // bytes
  else
    return 0;
}

int main () {
    char filename[100];
    cout << "Enter file name to compile ";
    cin.getline(filename, 100);
  
    // Build command to execute.  For example if the input
    // file name is a.cpp, then str holds "gcc -o a.out a.cpp" 
    // Here -o is used to specify executable file name
    string str = "g++ -std=gnu++17 -Wall -Wextra -O2 -o ./a.out ";
    str = str + filename;
  
    // Convert string to const char * as system requires
    // parameter of type const char *
    const char *command = str.c_str();
  
    cout << "Compiling file using " << command << endl;
    system(command);
  
    cout << "---Result:---" << endl;

    str = "./a.out";
    str = str + " < samples/random_00.txt";

    const char *command2 = str.c_str();

    struct timeval tv, tv2;
    gettimeofday(&tv, NULL);
    ll starttime = tv.tv_sec*1000000 + tv.tv_usec;

    system(command2);

    gettimeofday(&tv2, NULL);

    cout << "-------------" << endl;

    ll endtime = tv2.tv_sec*1000000 + tv2.tv_usec;

    cout << "Time: " << (endtime - starttime)/1000000 << "s " << (ll)((((endtime - starttime)/(double)1000000)-((endtime - starttime)/1000000))*1000) << "ms" << endl; 
  
    return 0;
}
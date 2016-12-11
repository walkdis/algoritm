#include <iostream> 
#include <string> 
#include <fstream> 

using namespace std; 

int main() 

{ 
int q = 0; 
string s1,s2; 
ifstream file1("out.txt"); // проги 
ifstream file2("test.txt");//верный, вручную посчитан 

while (getline(file1, s1)) 
{ 
getline(file2, s2); 
if (s1 != s2){ q = 1; } 

} 

file1.close(); 
file1.close(); 
if (q == 1){ cout « "Не сходится"; } 
else{ cout « "Cходится"; } 
system("pause"); 
return 0; 
}

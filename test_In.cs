using System; 
using System.IO; 

namespace Test_in_out 
{ 
class Program 
{ 
static void Main(string[] args) 
{ 
string adres1; 
int N = 0, M = 0, Start1 = 0, ver = 0, zifra = 0,rowCount,colCount; 
string[] lines; 
string[] simbol; 
int[] array; 
try 

{ 
Console.Write("Ведите адрес входного файла и нажмите Enter.\n"); 
Console.Write(@"C:\Users\WalkDis\Desktop\qwe.txt"); 
Console.Write("\n"); 

adres1 = Console.ReadLine(); 

lines = File.ReadAllLines(@adres1); 
rowCount = lines.Length; 
colCount = lines[0].Split().Length; 

simbol = lines[0].Split(); 
zifra=lines[0].Length; 
array = new int[zifra]; 

Console.Write("\n\n"); 

try 
{ 
for (int i = 0; i < zifra; i++) 
{ 
array[i] = int.Parse(simbol[i]); 
if (simbol[i] != " ") { Start1++; } 
} 
} 
catch { } 

for (int i = 0; i < Start1; i++) 
{ 
N++; 
if (array[i] < 0) { M = 1; } 
array[i] = int.Parse(simbol[i]); 
if (N == 4) 
{ 
if (array[i] < 101 && array[i] > 0) {} 
else { ver = 1; } 
} 
Console.Write(array[i]); 
Console.Write(" "); 

} 
Console.Write("\n"); 
Console.Write("ОК Всего элементов:"); 


Console.Write(Start1); 
Console.Write("\n"); 
if (ver == 0) { Console.Write("ОК Вероятность от 1 до 100:"); } 
else { Console.Write("Error Вероятность указана с ошибкой:"); } 
Console.Write("\n"); 
if (Start1 % 4 == 0) 
Console.WriteLine("OK Количество элементов кратно 4"); 
else 
Console.WriteLine("OK Количество элементов не кратно 4"); 

if (M == 1) { Console.Write("ERROR Есть отрицательные элементы"); } 
else { Console.Write("OK Все элементы положительные"); } 
} 
catch 
{ 
Console.Write("\n"); 
Console.Write("Error.\n"); 

Console.Write("\n\n"); 
} 

Console.ReadKey(); 
} 
} 
}

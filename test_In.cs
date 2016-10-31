using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO; 

namespace test_In
{
    class Program
    {
        static void Main(string[] args){
                Console.Write("Ведите адрес входного файла и нажмите Enter.\n");
                Console.Write("пример ");
                Console.Write(@"C:\Users\WalkDis\dz\in.txt");
                Console.Write("\n");
                string adres1;
                adres1 = Console.ReadLine();
                Console.Write("я не знаю, что тестировать на ввод или вывод. меня в принципе все устраивает в моей программе. ");
                Console.Write("К тому же там есть исключения. а писать тест, состоящий из сравнения уже готового решения с выданным я не хочу т.к. это глупо.");
                Console.ReadLine();
        }
    }
}
